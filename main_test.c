#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "main.c"

// Function to test
int add(int a, int b) {
    return a + b;
}

// Test case
static void conversion(void **state) {
    struct YCC expected;
    expected.Y = 235;
    expected.Cb = 128;
    expected.Cr = 128;

    struct YCC actual = rgb_to_ycc(255, 255, 255);
    assert_int_equal(actual.Y, 235);
    assert_int_equal(actual.Cb, 128);
    assert_int_equal(actual.Cr, 128);
}

// Main function to run tests
int main(void) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(conversion),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}