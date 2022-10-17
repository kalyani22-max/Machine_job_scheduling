/* use the basic interface */
#include "Cunit/basic.h"
/* the file to test */
#include "../include/test.h"
/* the suite to test */
#include "../include/testsuite.h"

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* add a suite to the registry */
    
    pSuite = CU_add_suite("Suite valid or invalid", init_suite_func, clean_suite_func);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite,
                             "test of valid() in normal cases", testSunnyCases)) ||
        (NULL == CU_add_test(pSuite,
                             "test of invalid() in error cases", testRainyCases)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
