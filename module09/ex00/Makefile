# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/14 12:09:23 by mmarsa-s          #+#    #+#              #
#    Updated: 2025/07/14 12:09:24 by mmarsa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc
CC = c++
CFLAGS = -Wall -Wextra -Werror -MMD -MP -g -std=c++98
RM = rm -fr

SRC =	main.cpp \
		BitcoinExchange.cpp
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