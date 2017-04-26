#pragma once

#include <stdbool.h>

typedef unsigned MilliSeconds;

typedef enum {
    ON,
    OFF
} Blink_LedState;

void Blink_configure(MilliSeconds on_time, MilliSeconds off_time, MilliSeconds start_time);
void Blink_update(MilliSeconds time_now);

bool Blink_isActive();
Blink_LedState Blink_getState();
