#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>


uint32_t crc32(uint8_t *msg_ptr, uint32_t byte_cnt, uint32_t oldchksum, bool init, bool last);
