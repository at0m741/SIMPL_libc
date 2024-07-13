LIB_NAME = libc_avx.a
SO_NAME = libc_avx.so
ASM_DIR = asm_out
SRC_DIR = srcs
OBJ_DIR = obj

CC = clang
CFLAGS = -O3 -mavx2 -masm=intel -mtune=native -Wall -Wextra -Werror
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

asm: $(SRC)
	@mkdir -p $(ASM_DIR)
	@$(foreach src, $(SRC), $(CC) $(CFLAGS) -S -o $(ASM_DIR)/$(notdir $(src:.c=.s)) $(src);)

so: $(SRC)
	$(CC) $(CFLAGS) -shared -o $(SO_NAME) $(SRC)

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	ar rcs $(LIB_NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -rf $(ASM_DIR)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re asm

