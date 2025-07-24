# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 15:44:46 by mmarsa-s          #+#    #+#              #
#    Updated: 2025/07/24 15:44:48 by mmarsa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe
CC = c++
CFLAGS = -Wall -Werror -Wextra -MMD -MP -std=c++98
RM = rm -f

SRC =	main.cpp \
		PmergeMe.cpp
D_OBJ = obj/
OBJ = $(addprefix $(D_OBJ), $(SRC:.cpp=.o))
DEP = $(addprefix $(D_OBJ), $(SRC:.cpp=.d))

$(D_OBJ)%.o: %.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: dir $(NAME)

dir:
	@mkdir -p obj/

-include $(DEP)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ) $(DEP)
	$(RM) -r $(D_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all dir clean fclean re