#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include <stdint.h>
#include <inttypes.h>

// Use this wrapper to call your assembly functions from C code
// The first argument of the wrapper is a function pointer to the wrapped function, then add as many arguments as needed by the wrapped function
int64_t wrapper(int64_t (*fn)(int64_t, int64_t, int64_t), int64_t n, int64_t high, int64_t low);

int64_t clamp(int64_t, int64_t, int64_t);

typedef struct {
    int64_t n;
    int64_t high;
    int64_t low;
    int64_t res;
} test_case;

test_case cases[] = {
       {5, 10, 1, 5},
    {11, 10, 1, 10},
    {0, 10, 1, 1}
};

void run_test(test_case *data) {
  int64_t res = wrapper(clamp, data->n, data->high, data->low);
  cr_assert_eq(res, data->res,
               "Invalid result for clamp(%" PRId64 ", %" PRId64 ", %" PRId64 "). Expected '%" PRId64 "', got '%" PRId64 "'", data->n, data->high, data->low, data->res, res);
}

Test(clamp, test_easy_0) {
    run_test(&cases[0]);
}

Test(clamp, test_easy_1) {
    run_test(&cases[1]);
}

Test(clamp, test_easy_2) {
    run_test(&cases[2]);
}

