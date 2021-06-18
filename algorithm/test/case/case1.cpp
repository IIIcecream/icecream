#include "gtest/gtest.h"

class Case1 : public testing::Test
{
public:
    static void SetUpTestCase()
    {
        printf ("111\n");
    }

    static void TearDownTestCase() {}

};

TEST_F(Case1, case1)
{
    printf ("111\n");
    EXPECT_EQ(1, 1);
}
