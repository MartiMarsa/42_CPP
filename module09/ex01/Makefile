# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/17 19:21:06 by mmarsa-s          #+#    #+#              #
#    Updated: 2025/07/17 19:21:10 by mmarsa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN
CC = c++
CFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98
RM = rm -f

SRC =	main.cpp \
		RPN.cpp
D_OBJ = obj/
OBJ = $(addprefix $(D_OBJ), $(SRC:.cpp=.o))
DEP = $(addprefix $(D_OBJ), $(SRC:.cpp=.d))

$(D_OBJ)%o: %cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: dir $(NAME)

dir:
	@mkdir -p obj/

-include $(DEP)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ) $(DEP)
	$(RM) -r obj/

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all dir clean fclean re