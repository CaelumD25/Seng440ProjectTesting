#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <time.h>
#include "main.c" // Include your main source file

// Test case
static void test_white_conversion(void **state) {
    clock_t start_time = clock();
    struct YCC actual = rgb_to_ycc(255, 255, 255);
    clock_t end_time = clock();

    assert_int_equal(actual.Y, 235);
    assert_int_equal(actual.Cb, 128);
    assert_int_equal(actual.Cr, 128);
    printf("Time to calculate: %ld", end_time-start_time);
}

// Main function to run tests
int main(void) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_white_conversion),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
