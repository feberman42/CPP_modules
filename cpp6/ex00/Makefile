# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 14:30:52 by feberman          #+#    #+#              #
#    Updated: 2024/06/26 15:43:53 by feberman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		convert
CPP=		c++
CPPFLAGS=	-Wall -Werror -Wextra -std=c++98
SHELL= 		/bin/bash

OBJD=		objects/

SRCs= 		main.cpp ScalarConverter.cpp
HEADERS=	ScalarConverter.hpp
OBJs=		$(addprefix $(OBJD), $(SRCs:.cpp=.o))

all: $(NAME)

$(NAME): $(SRCs) $(HEADERS)
	@echo -ne "\015\tBuilding object-files:\t"
	@$(MAKE) -s $(OBJs)
	@echo ""
	@echo -ne "\tBuilding executable\t"
	@$(CPP) $(CPPFLAGS) $(OBJs) -o $(NAME)
	@echo -e "\033[32m\xE2\x9C\x94\033[0m"
	@echo -e "\t\033[1;5;93m$(NAME) is ready!!!\033[0m"

$(OBJD)%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJD)
	@echo -ne "\033[32m\xE2\x9C\x94\033[0m"
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@echo -ne "\tRemove object-files:\t"
	@rm -rf $(OBJD)
	@echo -e "\033[32m\xE2\x9C\x94\033[0m"

fclean: clean
	@echo -ne "\tRemove executable:\t"
	@rm -f $(NAME)
	@echo -e "\033[32m\xE2\x9C\x94\033[0m"

re: fclean all

.PHONY: all clean fclean re
