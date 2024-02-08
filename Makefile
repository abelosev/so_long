NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./headers

SRCDIR = ./src
OBJDIR = ./obj

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

$(NAME) : $(OBJDIR) $(OBJ)
	make -C mlx_linux
	$(CC) $(OBJ) -Lmlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -Imlx_linux -g3 -c $< $ -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)


clean:
	@rm -rf $(OBJDIR)
	make clean -C mlx_linux

fclean: clean
	@rm -rf $(NAME)

re: fclean all
