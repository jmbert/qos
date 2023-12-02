.PHONY: all create-sysroot build-kernel

ifndef CC_PREFIX
IGNORE := $(error "Set CC_PREFIX as according to README.md")
endif

ROOTDIR=$(realpath $(CURDIR))/

SYSROOT=$(ROOTDIR)sysroot/
SYSROOT_INCLUDE=$(SYSROOT)usr/include/
SYSROOT_LIB=$(SYSROOT)usr/lib/
export SYSROOT SYSROOT_INCLUDE SYSROOT_LIB

KERNEL_ROOT=$(ROOTDIR)kernel/

TARGET?=i686-elf

CC=$(CC_PREFIX)/bin/$(TARGET)-gcc
GCC_VERSION = $(shell $(CC) -dumpversion)
AS=$(CC)
AR=$(CC_PREFIX)/bin/$(TARGET)-ar
LD=$(CC_PREFIX)/bin/$(TARGET)-ld

CFLAGS?=-O2 -g
CPPFLAGS?=
LDFLAGS?=
LDLIBS?=
ASFLAGS?=
LIBGCC?=$(CC_PREFIX)/lib/gcc/$(TARGET)/$(GCC_VERSION)/libgcc.a

CFLAGS+=--sysroot=$(SYSROOT) -Wall -Wpedantic --std=gnu23
CPPFLAGS+=-MD
LDFLAGS+=--sysroot=$(SYSROOT)
LDLIBS+=-lgcc

export CC GCC_VERSION AS AR LD CFLAGS CPPFLAGS LDFLAGS LDLIBS LIBGCC ASFLAGS



all: create-sysroot build-kernel

clean: clean-kernel
	rm -rf sysroot

create-sysroot:
	-mkdir $(SYSROOT)
	-mkdir -p $(SYSROOT_INCLUDE)
	$(MAKE) -C $(KERNEL_ROOT) install-system-headers
	-mkdir -p $(SYSROOT_LIB)
	-cp -L $(LIBGCC) $(SYSROOT_LIB)

build-kernel: create-sysroot
	$(MAKE) -C $(KERNEL_ROOT) build

clean-kernel:
	$(MAKE) -C $(KERNEL_ROOT) clean