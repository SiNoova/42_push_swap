NAME = push_swap


SRC_PUSH_SWAP = mandatory/algo.c mandatory/ft_split.c mandatory/ft_strjoin.c \
				 mandatory/push_rotate.c mandatory/push_swap.c mandatory/rrotate.c \
				mandatory/swap.c mandatory/utils.c mandatory/utils2.c \
				mandatory/linkedlists/ft_lstadd_back.c \
				mandatory/linkedlists/ft_lstiter.c \
				mandatory/linkedlists/ft_lstlast.c \
				mandatory/linkedlists/ft_lstnew.c \
				mandatory/linkedlists/ft_lstsize.c \



HEADER = mandatory/push_swap.h

CC = cc
FLAGS = -Wall -Wextra -Werror
OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)


all: $(NAME)

$(NAME): $(OBJ_PUSH_SWAP)
	$(CC) $(FLAGS) $^ -o $@

mandatory/%.o : mandatory/%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@


clean:
	rm -f $(OBJ_PUSH_SWAP) 

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean
