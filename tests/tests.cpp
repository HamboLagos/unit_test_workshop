#include <gtest.h>
#include <gmock.h>

using namespace testing;

class ExampleTest : public Test { };

TEST_F(ExampleTest, ShouldPass)
{
    int first = 1;
    int second = 2;
    EXPECT_NE(first, second);

    --second;
    EXPECT_EQ(first, second);
}
