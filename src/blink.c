#include "blink.h"

static MilliSeconds on_time_ = 0;
static MilliSeconds off_time_ = 0;
static MilliSeconds start_time_ = 0;
static Blink_LedState led_state_ = OFF;
bool is_active_ = false;

void Blink_configure(MilliSeconds on_time, MilliSeconds off_time, MilliSeconds start_time) {
    on_time_ = on_time;
    off_time_ = off_time;
    start_time_ = start_time;
}

void Blink_update(MilliSeconds time_now) {
    MilliSeconds elapsed = time_now - start_time_;

    if (elapsed < on_time_) {
        led_state_ = ON;
        is_active_ = true;
    } else if (elapsed < on_time_ + off_time_) {
        led_state_ = OFF;
        is_active_ = true;
    } else {
        is_active_ = false;
    }
}

bool Blink_isActive() {
    return is_active_;
}

Blink_LedState Blink_getState() {
    return led_state_;
}
