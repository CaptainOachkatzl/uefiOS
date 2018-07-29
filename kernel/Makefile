ARCH            = $(shell uname -m | sed s,i[3456789]86,ia32,)

OUTPUT 			= ../bin

SRC				= main.c
OBJS            = main.o
TARGET          = main.efi

EFIINC          = /usr/include/efi
EFIINCS         = -I$(EFIINC) -I$(EFIINC)/$(ARCH) -I$(EFIINC)/protocol
EFILIB          = /usr/lib
EFI_CRT_OBJS    = $(EFILIB)/crt0-efi-$(ARCH).o
EFI_LDS         = $(EFILIB)/elf_$(ARCH)_efi.lds

CFLAGS          = $(EFIINCS) -fno-stack-protector -fpic \
		  -fshort-wchar -mno-red-zone -Wall 
ifeq ($(ARCH),x86_64)
  CFLAGS += -DEFI_FUNCTION_WRAPPER
endif

LDFLAGS         = -nostdlib -znocombreloc -T $(EFI_LDS) -shared \
		  -Bsymbolic -L $(EFILIB) $(EFI_CRT_OBJS) 

all: $(OUTPUT)/$(TARGET)

$(OUTPUT)/main.so: $(OUTPUT)/$(OBJS)
	ld $(LDFLAGS) $^ -o $@ -lefi -lgnuefi

$(OUTPUT)/$(OBJS): $(SRC)
	cc $(CFLAGS) -c $^ -o $@

$(OUTPUT)/%.efi: $(OUTPUT)/%.so
	objcopy -j .text -j .sdata -j .data -j .dynamic \
		-j .dynsym  -j .rel -j .rela -j .reloc \
		--target=efi-app-$(ARCH) $^ $@

	@echo 	done building targets
