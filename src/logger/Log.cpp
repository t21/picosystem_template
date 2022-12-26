#include "logger/Log.hpp"

#include <cstdarg>

// #include "../../external/SEGGER_RTT_V752a/RTT/SEGGER_RTT.h"
#include "SEGGER_RTT.h"

void Log::printDebug(const char* format, ...) {
  va_list ParamList;

  SEGGER_RTT_printf(0, "[DBG]:");

  va_start(ParamList, format);
  SEGGER_RTT_vprintf(0, format, &ParamList);
  va_end(ParamList);
}

void Log::printError(const char* format, ...) {
  va_list ParamList;

  SEGGER_RTT_printf(0, "[ERR]:");

  va_start(ParamList, format);
  SEGGER_RTT_vprintf(0, format, &ParamList);
  va_end(ParamList);
}

void Log::printInfo(const char* format, ...) {
  va_list ParamList;

  SEGGER_RTT_printf(0, "[INF]:");

  va_start(ParamList, format);
  SEGGER_RTT_vprintf(0, format, &ParamList);
  va_end(ParamList);
}
