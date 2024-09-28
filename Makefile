LIB_NAME = SIMPL_libc.a
SO_NAME = SIMPL_libc.so
OBJ_DIR = obj
SRC_DIR = src
ASM_SRC_DIR = asm_src
INCLUDE_DIR = include
TEST_SRC = benchmark.c
TEST_BIN = benchmark

NASM_FLAGS = -g -F dwarf -I $(INCLUDE_DIR)
AS = nasm
CC = clang
AR = ar

CFLAGS = -O3 -mavx2 -masm=intel -mtune=native
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -MMD -MP -m64
PIC_FLAGS = -fPIC
LDFLAGS = -nostartfiles -nodefaultlibs 

ifeq ($(TARGET), apple)
	LDFLAGS += -lc -lSystem
	NASM_FLAGS += -f macho64
else
	NASM_FLAGS += -f elf64
endif

SRC = $(shell find $(SRC_DIR) -type f -name '*.c')
ASM_FILES = $(shell find $(ASM_SRC_DIR) -type f -name '*.s')

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
ASM_OBJ = $(patsubst $(ASM_SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(ASM_FILES))

INCLUDE = -I $(INCLUDE_DIR)
INCLUDE += -I $(SRC_DIR)/config

all: $(OBJ_DIR) $(LIB_NAME) $(SO_NAME)

# Création du répertoire obj s'il n'existe pas
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compilation des fichiers .c
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling $< into $@..."
	$(CC) $(CFLAGS) $(PIC_FLAGS) $(INCLUDE) -c $< -o $@
	@test -f $@ || (echo "Error: $@ is not a file! Something went wrong." && exit 1)

# Assemblage des fichiers .s
$(OBJ_DIR)/%.o: $(ASM_SRC_DIR)/%.s
	@mkdir -p $(dir $@)
	@echo "Assembling $< into $@..."
	$(AS) $(NASM_FLAGS) -o $@ $<
	@test -f $@ || (echo "Error: $@ is not a file! Something went wrong." && exit 1)

# Construction de la bibliothèque statique
$(LIB_NAME): $(OBJ) $(ASM_OBJ)
	@echo "Building static library $(LIB_NAME)..."
	@$(AR) rcs $@ $(filter %.o,$^)

# Construction de la bibliothèque partagée
$(SO_NAME): $(OBJ) $(ASM_OBJ)
	@echo "Building shared library $@..."
	@$(CC) $(LDFLAGS) $(PIC_FLAGS) $(INCLUDE) -shared -o $@ $(OBJ) $(ASM_OBJ)

# Nettoyage des fichiers objets
clean:
	@echo "Removing object files..."
	@rm -rf $(OBJ_DIR)

# Nettoyage complet des bibliothèques et exécutables
fclean: clean
	@echo "Removing libraries and executables..."
	@rm -f $(LIB_NAME) $(SO_NAME) $(TEST_BIN)

# Rebuild complet
re: fclean all

.PHONY: all clean fclean re
