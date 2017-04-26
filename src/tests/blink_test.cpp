#include <gtest.h>
#include <gmock.h>

#include "led_mock.hpp"

extern "C" {
#include "blink.h"
}

using namespace testing;

class SingleBlink : public Test {
public:
    static const MilliSeconds ON_TIME = 250;
    static const MilliSeconds OFF_TIME = 250;
    static const MilliSeconds START_TIME = 0;

    void SetUp() {
        Blink_configure(ON_TIME, OFF_TIME, START_TIME);
    }

    void TearDown() {
        LEDMock::validate();
    }
};

TEST_F(SingleBlink, EndOfOnTime_IsOn) {
    EXPECT_CALL(LEDMock::instance(), Mock_LED_turnOn());
    Blink_update(ON_TIME-1);

    EXPECT_TRUE(Blink_isActive());
    /* EXPECT_THAT(Blink_getState(), Eq(ON)); */
}

TEST_F(SingleBlink, AtStartTime_IsOn) {
    EXPECT_CALL(LEDMock::instance(), Mock_LED_turnOn());
    Blink_update(START_TIME);

    EXPECT_TRUE(Blink_isActive());
    /* EXPECT_THAT(Blink_getState(), Eq(ON)); */
}

TEST_F(SingleBlink, AtStartOfOffTime_IsOff) {
    EXPECT_CALL(LEDMock::instance(), Mock_LED_turnOff());
    Blink_update(ON_TIME);

    EXPECT_TRUE(Blink_isActive());
    /* EXPECT_THAT(Blink_getState(), Eq(OFF)); */
}

TEST_F(SingleBlink, AtEndOfOffTime_IsOff) {
    EXPECT_CALL(LEDMock::instance(), Mock_LED_turnOff());
    Blink_update(ON_TIME+OFF_TIME-1);

    EXPECT_TRUE(Blink_isActive());
    /* EXPECT_THAT(Blink_getState(), Eq(OFF)); */
}

TEST_F(SingleBlink, AfterPeriodHasExpired_IsNotActive) {
    Blink_update(ON_TIME+OFF_TIME);

    EXPECT_FALSE(Blink_isActive());
}
