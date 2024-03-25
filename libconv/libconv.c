#include <stdint.h>
#include <string.h>

uint64_t charuint(const char* ptr) {
    uint64_t result = 0;
    // Ensure that the pointer is not NULL
    if (ptr != NULL) {
        // Copy bytes from the char pointer to the uint64_t
        memcpy(&result, ptr, sizeof(uint64_t));
    }
    return result;
}
