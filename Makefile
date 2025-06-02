SOURCES=\
	src/main.c \
	src/parsing.c \
	src/parsing_utils.c \
	src/parse_data.c \
	src/init_data.c \
	src/errors.c \
	src/extract_map_info.c \
	src/manage_colors.c \
	src/creation_map.c \
	src/free.c

OBJECTS=$(SOURCES:.c=.o)
DEPENDENCIES=$(OBJECTS:.o=.d)

NAME=cube3D
CC=clang


DEBUG=-g3
CFLAGS=-Ilibft -MMD $(DEBUG) -Wall -Wextra #-Werror

all: $(NAME)

-include $(DEPENDENCIES)

libft/libft.a:
	make -C libft

$(NAME): $(OBJECTS) libft/libft.a 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) libft/libft.a $(LDFLAGS)

clean:
	rm -rf $(OBJECTS) $(DEPENDENCIES) 
	make -C libft fclean

fclean: clean
	rm -f cube3D

re: fclean all