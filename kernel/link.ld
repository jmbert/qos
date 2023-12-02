
ENTRY(_start)

SEARCH_DIR($SYSROOT/usr/lib)

SECTIONS
{
    _ld_kernel_start = .;

    .text :
    {
        * ( .text )
    }

    _ld_kernel_end = .;
}