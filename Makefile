# ----------------------------------------Name
NAME = minishell

# ----------------------------------------FILES
FILES_SRCS =	main.c \
				cmd_parse.c \
				lexer.c \
				lexer_token.c \
				lexer_token_utils.c \


FILES_OBJS = $(FILES_SRCS:.c=.o)

# ----------------------------------------Directories
DIR_SRCS = ./src/
DIR_OBJS = ./obj/
DIR_LIBFT = ./src/libft

vpath %.c $(DIR_SRCS) $(DIR_OBJS)
vpath %.c $(DIR_SRCS)/lexer/ $(DIR_OBJS)


# ----------------------------------------Sources
SRCS = $(FILES_SRCS:%=$(DIR_SRCS)%)

# ----------------------------------------Objects
OBJS = $(FILES_OBJS:%=$(DIR_OBJS)%)

# ----------------------------------------Flags
CC = gcc
# CFLAGS = -Wall -Wextra -Werror
INC = -lreadline -Iinc -I$(DIR_LIBFT)

# ----------------------------------------Libraries
LIBFT = $(DIR_LIBFT)/libft.a

# ----------------------------------------Debug
ifdef WITH_ADDRESS
CFLAGS += -g -fsanitize=address
endif


# ----------------------------------------Making
all: $(NAME)

$(NAME): $(DIR_OBJS) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INC) $(LIBFT)

$(DIR_OBJS)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(DIR_OBJS):
	mkdir -p $@

$(LIBFT):
	make -C $(DIR_LIBFT)

# ----------------------------------------Debug
address:
	$(MAKE) re WITH_ADDRESS=1

# ----------------------------------------Cleaning
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re