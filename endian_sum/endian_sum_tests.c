#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdalign.h>
#include "criterion/internal/assert.h"

int32_t endian_sum(const int32_t *data, size_t size);

typedef struct {
    int32_t data[64];
    size_t  size;
    int32_t res;
} test_case;

test_case cases[] = {
    // size == 0
    { .data = {0}, .size = 0, .res = INT32_C(0) },

    // single element
    { .data = { INT32_C(0) },          .size = 1, .res = INT32_C(0) },
    { .data = { INT32_C(1) },          .size = 1, .res = INT32_C(1) },

    // small mixes
    { .data = { INT32_C(100), INT32_C(-50), INT32_C(-25), INT32_C(-25) },
      .size = 4, .res = INT32_C(0) },

    // overflow / wrap-around behavior
    { .data = { INT32_C(0x7fffffff), INT32_C(1) },
      .size = 2, .res = (int32_t)0x80000000u }, // INT32_MAX + 1 -> INT32_MIN (wrap)
};

void run_test(test_case *data) {
    int32_t big_endian[64];

    for (int i = 0; i < data->size; i++) {
        big_endian[i] = __builtin_bswap32(data->data[i]);
    }

    int32_t res = endian_sum(&big_endian[0], data->size);

    cr_assert_eq(res, data->res,
                 "Invalid result: Expected '%" PRId32 "', got '%" PRId32 "'",
                 data->res, res);
}

Test(endian_sum, empty_array) { run_test(&cases[0]); }

Test(endian_sum, single_zero) { run_test(&cases[1]); }

Test(endian_sum, single_one) { run_test(&cases[2]); }

Test(endian_sum, small_mixes) { run_test(&cases[3]); }

Test(endian_sum, overflow) { run_test(&cases[4]); }
