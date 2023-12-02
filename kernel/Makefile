
ROOTDIR=$(realpath $(CURDIR))/


SOURCES=\
init/boot/boot.S\

OBJECTS=$(patsubst %.S,%.o,$(SOURCES:.c=.o))
DEPENDENCIES=$(OBJECTS:.o=.d)

KERNEL_INCLUDE=$(ROOTDIR)include/

LINK_SCRIPT=$(ROOTDIR)link.ld

CPPFLAGS+= -D__is_kernel -I$(KERNEL_INCLUDE)
LDFLAGS+=-T$(LINK_SCRIPT)

KERNEL_BINARY=qoskernel.bin

export CPPFLAGS

install-system-headers:
	cp -r --preserve=all $(KERNEL_INCLUDE) $(SYSROOT_INCLUDE)kernel

build: $(OBJECTS) $(KERNEL_BINARY)

clean:
	rm $(OBJECTS) $(DEPENDENCIES)


# Build rules

$(KERNEL_BINARY): $(OBJECTS) | $(LINK_SCRIPT)
	$(LD) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ $(CPPFLAGS)
%.o: %.S
	$(CC) -c $(CFLAGS) $< -o $@ $(CPPFLAGS)