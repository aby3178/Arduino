#ifndef ARD_DEBUG_H
#define ARD_DEBUG_H

#include <stddef.h>
#include <stdint.h>

#ifdef DEBUG_ESP_CORE
#define DEBUGV(...) ets_printf(__VA_ARGS__)
#endif

#ifndef DEBUGV
#define DEBUGV(...)
#endif

#ifdef __cplusplus
void hexdump(const void *mem, uint32_t len, uint8_t cols = 16);
#else
void hexdump(const void *mem, uint32_t len, uint8_t cols);
#endif

#ifdef __cplusplus
extern "C" {
#endif

void __panic_func(const char* file, int line, const char* func) __attribute__((noreturn));
#define panic() __panic_func(__FILE__, __LINE__, __func__)

#ifdef __cplusplus
}
#endif


#endif//ARD_DEBUG_H

#ifdef DEBUG_IBRICKS_LEVEL0
#define RELEASE_PRINTLN(...) Serial.println(__VA_ARGS__)
#define RELEASE_PRINTF(...) Serial.printf(__VA_ARGS__)
#else
#define RELEASE_PRINTLN(...)
#define RELEASE_PRINTF(...)
#endif

#ifdef DEBUG_IBRICKS_LEVEL1
#define DEBUG_LOOP(...) Serial.println(__VA_ARGS__)
#define DEBUG_ERROR(...) Serial.println(__VA_ARGS__)
#define DEBUG_INFO(...) Serial.println(__VA_ARGS__)
#else
#define DEBUG_LOOP(...)
#define DEBUG_ERROR(...)
#define DEBUG_INFO(...)
#endif

#ifdef DEBUG_IBRICKS_LEVEL2
#define DEBUG_DEBUG(...) Serial.println(__VA_ARGS__)
#else
#define DEBUG_DEBUG(...)
#endif

