#ifndef LOGGER_LOG_HPP
#define LOGGER_LOG_HPP

#ifndef LOG_LEVEL
#define LOG_LEVEL 3
#endif

#ifndef LOG_LEVEL
  #error "Error: LOG_LEVEL has not been defined (can be defined in module CMakeLists.txt)"
#endif

#define LOG_LEVEL_NONE  0
#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_INFO  2
#define LOG_LEVEL_DEBUG 3

#ifdef LOG_LEVEL

#if LOG_LEVEL >= LOG_LEVEL_DEBUG
  #ifdef __cplusplus
    #define LOG_D(...) Log::printDebug(__VA_ARGS__)
  #else
    #define LOG_D(...) LogPrintDebug(__VA_ARGS__)
  #endif
#else
  #define LOG_D(...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_INFO
  #ifdef __cplusplus
    #define LOG_I(...) Log::printInfo(__VA_ARGS__)
  #else
    #define LOG_I(...) LogPrintInfo(__VA_ARGS__)
  #endif
#else
  #define LOG_I(...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_ERROR
  #ifdef __cplusplus
    #define LOG_E(...) Log::printError(__VA_ARGS__)
  #else
    #define LOG_E(...) LogPrintError(__VA_ARGS__)
  #endif
#else
  #define LOG_E(...)
#endif

#ifdef __cplusplus

class Log {
  public:
    static void printDebug(const char* format, ...);
    static void printError(const char* format, ...);
    static void printInfo(const char* format, ...);
};

#else   // #ifdef __cplusplus

void LogPrintDebug(const char* format, ...);
void LogPrintError(const char* format, ...);
void LogPrintInfo(const char* format, ...);

#endif  // #ifdef __cplusplus

#endif  // #ifdef LOG_LEVEL

#endif  // #ifndef LOGGER_LOG_HPP