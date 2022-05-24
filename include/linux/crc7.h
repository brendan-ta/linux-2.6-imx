#ifndef _LINUX_CRC7_H
#define _LINUX_CRC7_H
#include <linux/types.h>

extern const u8 crc7_be_syndrome_table[256];
extern const u8 crc7_uboot_syndrome_table[256];

/*
 * CRC7 Checksum with a left shift to match U-Boot's CRC7
 * implementation
 */
static inline u8 crc7_uboot_byte(u8 crc, u8 data)
{
	return crc7_uboot_syndrome_table[(crc << 1) ^ data];
}

static inline u8 crc7_be_byte(u8 crc, u8 data)
{
	return crc7_be_syndrome_table[crc ^ data];
}

extern u8 crc7_uboot(u8 crc, const u8 *buffer, size_t len);
extern u8 crc7_be(u8 crc, const u8 *buffer, size_t len);

#endif
