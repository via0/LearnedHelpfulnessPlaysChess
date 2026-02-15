
#ifdef TEST

#include "unity.h"

#include "AbstractInputs.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_AbstractInputs_Clear(void){
    AbstractInputs inputs;
    TEST_ASSERT_EQUAL(0, AbstractInputs_Clear(&inputs));
    TEST_ASSERT_EQUAL(0, inputs.up   );
    TEST_ASSERT_EQUAL(0, inputs.down );
    TEST_ASSERT_EQUAL(0, inputs.left );
    TEST_ASSERT_EQUAL(0, inputs.right);
    TEST_ASSERT_EQUAL(0, inputs.j    );
    TEST_ASSERT_EQUAL(0, inputs.k    );
    TEST_ASSERT_EQUAL(0, inputs.pause);
}

void test_AbstractInputs_AreAnyInputsSet(void){
    AbstractInputs inputs;
    TEST_ASSERT_EQUAL(0, AbstractInputs_Clear(&inputs));
    TEST_ASSERT_EQUAL(0, AbstractInputs_AreAnyInputsSet(&inputs));
    inputs.j = 1;
    TEST_ASSERT_EQUAL(1, AbstractInputs_AreAnyInputsSet(&inputs));
}

void test_AbstractInputs_SettersAndClearers(void){
    AbstractInputs inputs;
    TEST_ASSERT_EQUAL(0, AbstractInputs_Clear(&inputs));

    TEST_ASSERT_EQUAL(0, AbstractInputs_SetInputUp(&inputs));
    TEST_ASSERT_EQUAL(1, AbstractInputs_GetInputUp(&inputs));
}

#endif // TEST
