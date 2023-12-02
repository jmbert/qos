#include <multiboot/header.h>

.section .text

boot_page_directory: .skip 4096
boot_kernel_identity: .skip 4096
boot_kernel_higher: .skip 4096

.global _start

_start:

_end:   
    cli; hlt
    jmp _end