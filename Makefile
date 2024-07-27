LIB_NAME = libc_avx.a
SO_NAME = libc_avx.so
OBJ_DIR = obj
SRC_DIR = src
ASM_SRC_DIR = asm_src
INCLUDE_DIR = include
TEST_SRC = benchmark.c
TEST_BIN = benchmark

NASM_FLAGS = -f elf64 -g -F dwarf -I $(INCLUDE_DIR)
AS = nasm
CC = clang

# optimisation flags
CFLAGS = -O3 -mavx2 -masm=intel -mtune=native 
# protection flags
CFLAGS += -Wall -Wextra -Werror
# dependency flags
CFLAGS += -MMD -MP -m64

PIC_FLAGS = -fPIC

LDFLAGS = -nostartfiles -nodefaultlibs

# Finding all C source files
SRC = $(shell find $(SRC_DIR) -name '*.c')
# Finding all assembly files
ASM_FILES = $(shell find $(ASM_SRC_DIR) $(SRC_DIR) -name '*.s')

# Generating object file names for C and assembly files
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
ASM_OBJ = $(patsubst $(ASM_SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(ASM_FILES))

INCLUDE = -I $(INCLUDE_DIR)
INCLUDE += -I $(SRC_DIR)/config


MODE := [

ifeq ($(VERBOSE),true)
	MODE += "verbose : $(GREEN)on$(NC) "
	CFLAGS += -D VERBOSE
else
	MODE += "verbose : $(RED)off$(NC) "
endif

ifeq ($(DEBUG),true)
	MODE += "debug : $(GREEN)on$(NC)"
	CFLAGS += -g
else
	MODE += "debug : $(RED)off$(NC)"
endif

MODE += ]

all: $(LIB_NAME) $(SO_NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%:
	@mkdir -p $(OBJ_DIR)/$*

# Rule to compile C source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "[$(YELLOW)$(CC)$(NC)] $(MODE) Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(PIC_FLAGS) $(INCLUDE) -c $< -o $@

# Rule to compile assembly files
$(OBJ_DIR)/%.o: $(ASM_SRC_DIR)/%.s | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "[$(YELLOW)$(AS)$(NC)] $(MODE) Assembling $<...$(NC)"
	@$(AS) $(NASM_FLAGS) -o $@ $<

# Static library
$(LIB_NAME): $(OBJ) $(ASM_OBJ)
	@echo "$(GREEN)building static library $(LIB_NAME)$(NC)"
	@ar rcs $@ $^

# Shared library
$(SO_NAME): $(OBJ) $(ASM_OBJ)
	@echo "$(GREEN)building Shared library $@...$(NC)"
	@$(CC) $(LDFLAGS) $(PIC_FLAGS) $(INCLUDE) -shared -o $@ $(OBJ) $(ASM_OBJ)

# Benchmark executable
$(TEST_BIN): $(TEST_SRC) $(LIB_NAME)
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $^ $(INCLUDE) -L. -l:$(LIB_NAME)

clean:
	@echo "$(RED)remove item $(OBJ_DIR)$(NC)"
	@rm -f $(OBJ_DIR)/*.o

fclean: clean
	@echo "$(RED)remove item $(SO_NAME)$(NC)"
	@echo "$(RED)remove item $(LIB_NAME)$(NC)"
	@echo "$(RED)remove item $(TEST_BIN)$(NC)"
	@rm -f $(LIB_NAME) $(SO_NAME) $(TEST_BIN)
	@rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re

##################################### COLORS ########################################

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[1;33m
PURPLE = \033[0;35m
NC = \033[0m
