
#ifndef _MULTIBOOT_HEADER_H
#define _MULTIBOOT_HEADER_H

#include <bits/multiboot/header.h>

#ifdef __ASSEMBLER__

#define MULTIBOOT_FLAGS MULTIBOOT_HEADER_FLAGS_PAGE_ALIGN | MULTIBOOT_HEADER_FLAGS_MEMORY_INFO

.long MULTIBOOT_HEADER_MAGIC
.long MULTIBOOT_FLAGS
.long CHECKSUM(MULTIBOOT_FLAGS)

#else

#include <compiler_attributes.h>

_align(32)
_section("multiboot.header")
struct multiboot_header
{
    /* Must be set to MULTIBOOT_HEADER_MAGIC */
    unsigned int magic;
    /* Flags to tell the bootloader what to do */
    unsigned int flags;
    /* From CHECKSUM(flags) */
    unsigned int checksum;

    /* Header address fields (should be left unused) */
    unsigned int __header_addr;
    unsigned int __load_addr;
    unsigned int __load_end_addr;
    unsigned int __bss_end_addr;
    unsigned int __entry_addr;

    /* Video mode information */
    unsigned int mode_type;
    unsigned int width;
    unsigned int height;
    unsigned int bpp;
};

#endif


#endif