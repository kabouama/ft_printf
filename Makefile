# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/29 18:41:23 by kabouama     #+#   ##    ##    #+#        #
#    Updated: 2018/12/12 21:20:11 by kabouama    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a

SRC = src/ft_printf.c			\
	  src/stock_in_list.c		\
	  src/process.c				\
	  src/actu_param.c			\
	  src/char_atoi.c			\
	  src/process_d.c			\
	  src/process_dd.c			\
	  src/process_dd2.c			\
	  src/ft_nbrlen_ll.c		\
	  src/ft_putnbr_u.c			\
	  src/ft_putnbr_base.c		\
	  src/process_s.c			\
	  src/process_p.c			\
	  src/process_percent.c		\
	  src/affiche_x.c			\
	  src/affiche_x.c			\
	  src/affiche_o.c			\
	  src/check_width_princi.c	\
	  src/width_neg.c			\
	  src/flagszer_and_preci.c	\
	  src/flags.c				\
	  src/ft_putnbr_ll.c		\
	  src/list_new_andback.c	\
	  src/actu_flags.c			\
	  src/process_cast.c		\
	  src/init_free_prm.c		\
	  src/prog_float.c			\
	  src/prog_float2.c			\

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(LIB):
	make -C libft

$(NAME): $(LIB) $(OBJ)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ) libft/libft.a

%.o : %.c
	gcc -I includes/ -o $@ -c $< $(FLAGS)

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all
