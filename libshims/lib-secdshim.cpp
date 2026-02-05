#include <log/log.h>
#include <stdio.h>
extern "C" {
    void __stack_chk_fail() {
        ALOGE("SECD_SHIM: Prevented process exit by intercepting __stack_chk_fail");
    }

    int __vsnprintf_chk(char* dest, size_t size, int flags, size_t slen, const char* format, va_list args) {
        if (dest != nullptr && size > 0) {
            dest[0] = '\0';
        }
        return 0; 
    }
    int vsnprintf(char* dest, size_t size, const char* format, va_list args) {
        if (dest != nullptr && size > 0) {
            dest[0] = '\0';
        }
        return 0;
    }
}