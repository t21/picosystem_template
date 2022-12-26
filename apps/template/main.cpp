/**
 * @brief Template project for RP2040
 *
 * Copyright (c) 2021 Thomas Berg
 */

#include "pico/time.h"

#include "logger/Log.hpp"

int main() {
  LOG_D("Template application started\r\n");

  while (true) {
    LOG_D("Template application running\r\n");
    sleep_ms(1000);
  }

  return 0;
}
