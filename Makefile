ARCH            = $(shell uname -m | sed s,i[3456789]86,ia32,)

SRC				= kernel
OUTPUT 			= bin

SOURCES 		:= $(shell find $(SRC) -name '*.c')
SRCFOLDER		:= $(subst $(SRC)/,,$(SOURCES))
# replace .c with .o appendix
OBJECTS 		:= $(addprefix $(OUTPUT)/, $(SRCFOLDER:%.c=%.o))
OBJSRIPTS		= bitannihilation.so
TARGET          = bitannihilation.efi

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

# read from bottom up

all: $(OUTPUT)/$(TARGET)

$(OUTPUT)/%.efi: $(OUTPUT)/$(OBJSRIPTS)
	objcopy -j .text -j .sdata -j .data -j .dynamic \
		-j .dynsym  -j .rel -j .rela -j .reloc \
		--target=efi-app-$(ARCH) $^ $@
	@echo 	done building targets

$(OUTPUT)/$(OBJSRIPTS): $(OBJECTS)
	ld $(LDFLAGS) $^ -o $@ -lefi -lgnuefi

$(OUTPUT)/%.o: $(SRC)/%.c
	@mkdir -p $(@D)
	cc $(CFLAGS) -I$(SRC) -c $< -o $@
