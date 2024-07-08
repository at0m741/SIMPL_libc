LIB_NAME = libc_avx.a
ASM_DIR = asm_out
SRC_DIR = srcs

CC = clang
CFLAGS = -O3 -mavx2 -masm=intel -Wall -Wextra -Werror
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)#create a directory of .o files

#compile with -S to see the assembly code

asm : $(SRC)
	@mkdir -p $(ASM_DIR)
	@$(foreach src, $(SRC), $(CC) $(CFLAGS) -S -o $(ASM_DIR)/$(notdir $(src:.c=.s)) $(src);)

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	ar rcs $(LIB_NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re
