#include <gtest.h>
#include <gmock.h>

extern "C" {
#include "blink.h"
}

using namespace testing;

class SingleBlink : public Test { };

TEST_F(SingleBlink, ShouldPass) {
    Blink_configure(250, 250, 0);
    Blink_update(0);

    EXPECT_TRUE(Blink_isActive());
    EXPECT_THAT(Blink_getState(), Eq(ON));
}
