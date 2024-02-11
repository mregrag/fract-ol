# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 03:45:58 by mregrag           #+#    #+#              #
#    Updated: 2024/02/11 02:50:58 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	:= fractol
CFLAGS	:= -Wextra -Wall -Werror
CC      := cc

LIBS	:= ./lib/libmlx42.a -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"

SRCS	:= mandatory/main.c\
		   mandatory/string_utils.c\
		   mandatory/init.c\
		   mandatory/math_utils.c\
		   mandatory/hooks.c\
		   mandatory/draw_fractal.c\
		   mandatory/julia.c\
		   mandatory/mandelbrot.c\
		   mandatory/colors.c\
		   mandatory/parsing.c\
		   mandatory/ft_error.c

SRCSB	:= bonus/main_bonus.c\
		   bonus/string_utils_bonus.c \
		   bonus/init_bonus.c\
		   bonus/math_utils_bonus.c\
		   bonus/hooks_bonus.c\
		   bonus/julia_bonus.c\
		   bonus/mandelbrot_bonus.c\
		   bonus/draw_fractal_bonus.c\
		   bonus/burning_bonus.c\
		   bonus/colors_bonus.c\
		   bonus/parsing_bonus.c\
		   bonus/ft_error_bonus.c
		   

OBJS	:= ${SRCS:.c=.o}
OBJSB	:= ${SRCSB:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

bonus: $(OBJSB)
	$(CC) $(OBJSB) $(LIBS) -o $(NAME)
	
%.o: %.c ./include/fractal.h ./lib/MLX42.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJSB)

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re
