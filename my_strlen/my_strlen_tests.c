#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <stdint.h>
#include <inttypes.h>
#include <string.h>

uint64_t wrapper(uint64_t (*fn) (const char *), const char *str);
uint64_t my_strlen(const char *str);

char *test_cases[] = {
    "Hello World!",
    "Hello newline\n",
    ""
};

void run_test(char *str) {
    uint64_t ref = strlen(str);
    uint64_t res = wrapper(my_strlen, str);

    cr_assert_eq(ref, res, "Invalid length returned for '%s': Expected %" PRId64 ", got %" PRId64 "." , str, ref, res);
}

Test(strlen_rep, test_easy_0) {
    run_test(test_cases[0]);
}

Test(strlen_rep, test_easy_1) {
    run_test(test_cases[1]);
}

Test(strlen_rep, test_empty) {
    run_test(test_cases[2]);
}
