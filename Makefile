CC = gcc
AS = nasm

CFLAGS = -Wall -Wextra -Werror
ASFLAGS = -f elf64

SRCS_C = src/main.c
SRCS_ASM = src/function/ft_strlen.s \
			src/function/ft_strcmp.s \
			src/function/ft_strcpy.s \
			src/function/ft_strdup.s \
			src/function/ft_write.s \
			src/function/ft_read.s

OBJS_C = $(SRCS_C:.c=.o)
OBJS_ASM = $(SRCS_ASM:.s=.o)

NAME = libasm.a
OUTPOUT = ./test

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

$(NAME): $(OBJS_C) $(OBJS_ASM)
	ar -rc $(NAME) $(OBJS_C) $(OBJS_ASM)

test : all $(NAME)
	$(CC) $(CFLAGS) $(SRC_C) -o $(OUTPOUT) $(NAME)

clean:
	rm -f $(OBJS_C) $(OBJS_ASM)

fclean: clean
	rm -f $(NAME) $(OUTPOUT)

re: fclean all


.PHONY: all test clean fclean re