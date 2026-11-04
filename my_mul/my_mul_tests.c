#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include <stdint.h>
#include <inttypes.h>

// Use this wrapper to call my_add from C code
int64_t wrapper(int64_t (*fn)(int64_t, int64_t), int64_t a, int64_t b);

int64_t my_mul(int64_t, int64_t);

typedef struct {
    int64_t a;
    int64_t b;
    int64_t res;
} test_case;

test_case cases[] = {
       {1, 1, 1},
    {0, 0, 0},
    {42, 4242, 178164},
};

void run_test(test_case *data) {
  int64_t res = wrapper(my_mul, data->a, data->b);
  cr_assert_eq(res, data->res,
               "Invalid result when adding '%" PRId64 "' and '%"
               PRId64 "'. Expected '%" PRId64 "', got '%" PRId64 "'", data->a, data->b, data->res, res);
}

Test(my_mul, test_easy_0) {
    run_test(&cases[0]);
}

Test(my_mul, test_easy_1) {
    run_test(&cases[1]);
}

Test(my_mul, test_easy_2) {
    run_test(&cases[2]);
}

