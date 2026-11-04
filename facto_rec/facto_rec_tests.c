#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include <stdint.h>
#include <inttypes.h>

// Use this wrapper to call your assembly functions from C code
// The first argument of the wrapper is a function pointer to the wrapped function, then add as many arguments as needed by the wrapped function
uint64_t wrapper(uint64_t (*fn)(uint8_t), uint8_t n);

uint64_t facto_rec(uint8_t);

typedef struct {
    uint8_t n;
    uint64_t res;
} test_case;

test_case cases[] = {
       {0, 1},
       {1, 1},
       {10, 3628800},
       {15, 1307674368000},
};

void run_test(test_case *data) {
  uint64_t res = wrapper(facto_rec, data->n);
  cr_assert_eq(res, data->res,
               "Invalid result for facto_rec(%" PRId8 "). Expected '%" PRId64 "', got '%" PRId64 "'", data->n, data->res, res);
}

Test(facto_rec, test_easy_0) {
    run_test(&cases[0]);
}

Test(facto_rec, test_easy_1) {
    run_test(&cases[1]);
}

Test(facto_rec, test_easy_2) {
    run_test(&cases[2]);
}

Test(facto_rec, test_easy_3) {
    run_test(&cases[3]);
}

