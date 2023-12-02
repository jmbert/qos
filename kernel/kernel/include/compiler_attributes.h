#ifndef _COMPILER_ATTRS_H
#define _COMPILER_ATTRS_H

#define _align(_x) __attribute__((aligned(_x)))

#define _section(_s) __attribute__((section(#_s)))

#endif