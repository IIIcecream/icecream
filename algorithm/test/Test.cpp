#include "gtest/gtest.h"
#include <string>

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "chs");
    testing::GTEST_FLAG(catch_exceptions) = 0;
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
