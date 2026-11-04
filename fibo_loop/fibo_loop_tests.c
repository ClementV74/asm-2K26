#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include <stdint.h>
#include <inttypes.h>

// Use this wrapper to call your assembly functions from C code
// The first argument of the wrapper is a function pointer to the wrapped function, then add as many arguments as needed by the wrapped function
int32_t wrapper(int32_t (*fn)(int32_t), int32_t n);

int32_t fibo_loop(int32_t);

typedef struct {
    int32_t n;
    int32_t res;
} test_case;

test_case cases[] = {
       {0, 0},
       {1, 1},
       {15, 610},
       {30, 832040},
};

void run_test(test_case *data) {
  int32_t res = wrapper(fibo_loop, data->n);
  cr_assert_eq(res, data->res,
               "Invalid result for fibo_loop(%" PRId32 "). Expected '%" PRId32 "', got '%" PRId32 "'", data->n, data->res, res);
}

Test(fibo_loop, test_easy_0) {
    run_test(&cases[0]);
}

Test(fibo_loop, test_easy_1) {
    run_test(&cases[1]);
}

Test(fibo_loop, test_easy_2) {
    run_test(&cases[2]);
}

Test(fibo_loop, test_easy_3) {
    run_test(&cases[3]);
}

