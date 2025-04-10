# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarsa-s <mmarsa-s@student.42fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 19:42:48 by mmarsa-s          #+#    #+#              #
#    Updated: 2025/04/10 19:42:51 by mmarsa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = realType
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRC =	main.cpp \
		realType.cpp
D_OBJS = obj/
OBJS = $(addprefix $(D_OBJS), $(SRC:.cpp=.o))
DEPS = $(addprefix $(D_OBJS), $(SRC:.cpp=.d))

all: dir $(NAME)

dir:
	@mkdir -p

$(D_OBJS)%.o: %.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)
	$(RM) -r obj/

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all dir clean fclean re

-include $(DEPS)
$(NAME): $(OBJS) $(DEPS)

