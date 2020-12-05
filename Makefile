NAME		=	libftprintf.a

SRCS		=	ft_printf.c \
				ft_format_check.c \
				ft_format_ini_par.c \
				ft_format_menu.c \
				ft_put_chr.c \
				ft_put_hex.c \
				ft_put_int.c \
				ft_put_per.c \
				ft_put_pnt.c \
				ft_put_str.c \
				ft_put_unt.c \
				ft_put_width.c \
				ft_util_0.c \
				ft_util_1.c \
				ft_util_2.c

OBJS		=	ft_printf.o \
				ft_format_check.o \
				ft_format_ini_par.o \
				ft_format_menu.o \
				ft_put_chr.o \
				ft_put_hex.o \
				ft_put_int.o \
				ft_put_per.o \
				ft_put_pnt.o \
				ft_put_str.o \
				ft_put_unt.o \
				ft_put_width.o \
				ft_util_0.o \
				ft_util_1.o \
				ft_util_2.o

INCLUDES	=	ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)

$(OBJS): $(SRCS) $(INCLUDES)
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all
bonus: