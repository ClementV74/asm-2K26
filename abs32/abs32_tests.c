#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include <stdint.h>
#include <inttypes.h>

// Use this wrapper to call your assembly functions from C code
// The first argument of the wrapper is a function pointer to the wrapped function, then add as many arguments as needed by the wrapped function
int32_t wrapper(int32_t (*fn)(int32_t), int32_t n);

int32_t abs32(int32_t);

typedef struct {
    int32_t n;
    int32_t res;
} test_case;

test_case cases[] = {
    {42, 42},
       {-42, 42},
       {0, 0},
    {-1, 1}
};

void run_test(test_case *data) {
  int32_t res = wrapper(abs32, data->n);
  cr_assert_eq(res, data->res,
               "Invalid result for abs(%" PRId32 "). Expected '%" PRId32 "', got '%" PRId32 "'", data->n, data->res, res);
}

Test(abs32, test_easy_0) {
    run_test(&cases[0]);
}

Test(abs32, test_easy_1) {
    run_test(&cases[1]);
}

Test(abs32, test_easy_2) {
    run_test(&cases[2]);
}

Test(abs32, test_easy_3) {
    run_test(&cases[3]);
}

