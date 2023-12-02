.PHONY: install-system-headers build clean docs

ROOTDIR=$(realpath $(CURDIR))/

KERNEL=qos

SOURCES=\
init/boot/boot.S\

OBJECTS=$(patsubst %.S,%.o,$(SOURCES:.c=.o))
DEPENDENCIES=$(OBJECTS:.o=.d)

KERNEL_INCLUDE=$(ROOTDIR)include/

LINK_SCRIPT=$(ROOTDIR)link.ld

CPPFLAGS+= -D__is_kernel -I$(KERNEL_INCLUDE)
LDFLAGS+=-T$(LINK_SCRIPT)

KERNEL_BINARY=$(KERNEL).bin

ISODIR=$(ROOTDIR)isodir/
ISOBOOT=$(ISODIR)boot/
KERNEL_ISO=$(ISOBOOT)$(KERNEL)
ISOGRUB=$(ISOBOOT)grub/

GRUB_CFG=$(ROOTDIR)grub.cfg

KERNEL_BOOT=$(ROOTDIR)$(KERNEL).boot

export CPPFLAGS

install-system-headers:
	cp -r --preserve=all $(KERNEL_INCLUDE) $(SYSROOT_INCLUDE)kernel

build: $(OBJECTS) $(KERNEL_BINARY) $(KERNEL_BOOT)

clean:
	rm $(OBJECTS) $(DEPENDENCIES) $(ISODIR) $(KERNEL_BOOT)

$(KERNEL_BOOT): $(KERNEL_BINARY)
	@echo $(ISODIR)
	-mkdir -p $(ISOGRUB)
	cp $< $(KERNEL_ISO)
	cp $(GRUB_CFG) $(ISOGRUB)
	grub-mkrescue -o  $@ $(ISODIR)

docs:
	$(shell cd docs; doxygen)

# Build rules

$(KERNEL_BINARY): $(OBJECTS) | $(LINK_SCRIPT)
	$(LD) $(LDFLAGS) -o $@ $^ $(LDLIBS)
	cp $@ $(SYSROOT_BOOT)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ $(CPPFLAGS)
%.o: %.S
	$(CC) -c $(CFLAGS) $< -o $@ $(CPPFLAGS)