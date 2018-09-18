# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/01 16:11:24 by cmbuyamb          #+#    #+#              #
#    Updated: 2018/09/05 18:01:01 by cmbuyamb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSHSWAP	=	push_swap
CHECKER		=	checker

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

SRCSFL		+=	check.c execute.c \
				rot.c rev_rot.c push_swap.c \
				find_ind.c helpers.c algo.c \
                
PSMAIN		=	push_swap_main.c
CHECKERMAIN	=	checker.c

SRCSFD		=	srcs
OBJSFD		=	objs
INCLFD		=	includes libft/includes

SRCS		=	$(addprefix $(SRCSFD)/, $(SRCSFL))
OBJS		=	$(addprefix $(OBJSFD)/, $(SRCSFL:.c=.o))
OBJSPS		+=	$(OBJS)
OBJSPS		+=	$(addprefix $(OBJSFD)/, $(PSMAIN:.c=.o))
OBJSCHECKER	+=	$(OBJS)
OBJSCHECKER	+=	$(addprefix $(OBJSFD)/, $(CHECKERMAIN:.c=.o))
LIBFT		=	libft/libft.a

LIBFTLIB	=	-Llibft -lft

RED			=	\033[0;31m
GREEN		=	\033[0;32m
NC			=	\033[0m

.PHONY: all clean fclean re leaks

all: $(PUSHSWAP) $(CHECKER)

$(PUSHSWAP): $(OBJSPS) $(LIBFT)
	@$(CC) $(CFLAGS) $(addprefix -I ,$(INCLFD)) $(OBJSPS) $(LIBFTLIB) -o $@
	@echo "$(GREEN)Pushswap created.$(NC)"

$(CHECKER): $(OBJSCHECKER) $(LIBFT)
	@$(CC) $(CFLAGS) $(addprefix -I ,$(INCLFD)) $(OBJSCHECKER) $(LIBFTLIB) -o $@
	@echo "$(GREEN)Checker created.$(NC)"

$(OBJSFD):
	@mkdir $@

$(LIBFT): $(LIBFTFD)
	@make -C libft re

$(OBJSFD)/%.o: $(SRCSFD)/%.c | $(OBJSFD)
	@$(CC) $(CFLAGS) $(addprefix -I ,$(INCLFD)) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJSFD)/$(PSMAIN:.c=.o) $(OBJSFD)/$(CHECKERMAIN:.c=.o)
	@echo "$(RED)Objects deleted$(NC)"
	@rm -rf $(OBJSFD)

fclean: clean
	@rm -rf $(PUSHSWAP)
	@echo "$(RED)Pushswap deleted.$(NC)"
	@rm -rf $(CHECKER)
	@echo "$(RED)Checker deleted.$(NC)"

re: fclean all
