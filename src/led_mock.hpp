#include <gmock.h>

extern "C" {
#include "led.h"
}

class LEDMock {
public:
    static LEDMock& instance() {
        static LEDMock instance;
        return instance;
    }

    static void validate() {
        testing::Mock::VerifyAndClearExpectations(&instance());
    }

    MOCK_METHOD0(Mock_LED_turnOn, void());
    MOCK_METHOD0(Mock_LED_turnOff, void());
};

void LED_turnOn() {
    LEDMock::instance().Mock_LED_turnOn();
}

void LED_turnOff() {
    LEDMock::instance().Mock_LED_turnOff();
}
