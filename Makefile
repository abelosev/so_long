NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./headers
MINILIBX_PATH =	./mlx
MINILIBX = $(MINILIBX_PATH)/libmlx.a

SRCDIR = ./src/
OBJDIR = ./obj/

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

$(NAME) : $(OBJDIR) $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -Imlx_linux -g3 -c $< $ -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

all: $(NAME)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all