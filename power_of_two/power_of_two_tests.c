#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include <stdint.h>
#include <inttypes.h>

// Use this wrapper to call your assembly functions from C code
// The first argument of the wrapper is a function pointer to the wrapped function, then add as many arguments as needed by the wrapped function
int64_t wrapper(int64_t (*fn)(int8_t), int8_t pow);

int64_t power_of_two(int8_t);

typedef struct {
    int8_t pow;
    int64_t res;
} test_case;

test_case cases[] = {
    {0, 1},
    {1, 2},
       {10, 1024},
    {20, 1048576}
};

void run_test(test_case *data) {
  int64_t res = wrapper(power_of_two, data->pow);
  cr_assert_eq(res, data->res,
               "Invalid result for 2^'%" PRId8 "'. Expected '%" PRId64 "', got '%" PRId64 "'", data->pow, data->res, res);
}

Test(power_of_two, test_easy_0) {
    run_test(&cases[0]);
}

Test(power_of_two, test_easy_1) {
    run_test(&cases[1]);
}

Test(power_of_two, test_easy_2) {
    run_test(&cases[2]);
}

Test(power_of_two, test_easy_3) {
    run_test(&cases[3]);
}
