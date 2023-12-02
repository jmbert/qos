#ifndef _MULTIBOOT_HEADER_BITS_H
#define _MULTIBOOT_HEADER_BITS_H

#define MULTIBOOT_HEADER_MAGIC 0x1BADB002

#ifdef __ASSEMBLER__

#define MULTIBOOT_HEADER_FLAGS_PAGE_ALIGN 0
#define MULTIBOOT_HEADER_FLAGS_MEMORY_INFO 1
#define MULTIBOOT_HEADER_FLAGS_VIDEO_INFO 2

#define MULTIBOOT_HEADER_MODE_LINEAR_GRAPHICS 0
#define MULTIBOOT_HEADER_MODE_EGA_TEXT_MODE 0

#else

enum multiboot_header_flags
{
    MULTIBOOT_HEADER_FLAGS_PAGE_ALIGN,
    MULTIBOOT_HEADER_FLAGS_MEMORY_INFO,
    MULTIBOOT_HEADER_FLAGS_VIDEO_INFO,
};

enum multiboot_header_video_info_modes
{
    MULTIBOOT_HEADER_MODE_LINEAR_GRAPHICS,
    MULTIBOOT_HEADER_MODE_EGA_TEXT_MODE,
};

#endif
#define CHECKSUM(_flags) -(MULTIBOOT_HEADER_MAGIC + _flags)

#endif