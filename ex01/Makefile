# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 11:42:41 by alvicina          #+#    #+#              #
#    Updated: 2024/05/01 16:51:10 by alvicina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SETUP

NAME            = RPN
CC              = c++
RM              = rm -rf
FLAGS           = -Wall -Wextra -Werror -std=c++98 -g3

#FILES AND PATH

HEADER_SRCS =  RPN.hpp \
		      
HEADER_DIR  = includes/
HEADER      = $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS  =  main.cpp RPN.cpp \

MPATH_DIR   = mandatory/
MPATH       = $(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M       = $(MPATH:.cpp=.o)

#COMMANDS
all:        $(NAME)

$(NAME):    $(OBJ_M)
		    @$(CC) $(FLAGS) $(OBJ_M) -o $(NAME) 

%.o: %.cpp $(HEADER) Makefile
		    @$(CC) $(FLAGS) -c $< -o $@

clean:
	        @$(RM) $(OBJ_M)

fclean:	    clean
		    @$(RM) $(NAME)

re:         fclean all

.PHONY: all execute clean fclean re 