NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

AR = ar rcs

RM = rm -f

SRC = ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isalnum \
		ft_isprint \
		ft_isupper \
		ft_isspace \
		ft_strlen \
		ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memmove \
		ft_strlcpy \
		ft_strlcat \
		ft_toupper \
		ft_tolower \
		ft_strchr \
		ft_strcmp \
		ft_strrchr \
		ft_strncmp \
		ft_memchr \
		ft_memcmp \
		ft_strnstr \
		ft_atoi \
		ft_calloc \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_striteri \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		get_next_line \
		gnl_utils
		
SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

.c.o: $(SRCS)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@$(AR) $@ $^
	@echo "Libft ready."

all: $(NAME)

clean:
	@rm -f *.o
	@echo "Libft: removed .o object files."

fclean: clean
	@rm -f $(NAME)
	@echo "Libft: removed libft.a file."

re: clean all

.PHONY: all clean fclean re
	