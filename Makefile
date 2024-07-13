NAME = push_swap

BONUS_NAME = checker

SRC_PUSH_SWAP = mandatory/algo.c mandatory/ft_split.c mandatory/ft_strjoin.c \
				 mandatory/push_rotate.c mandatory/push_swap.c mandatory/rrotate.c \
				mandatory/swap.c mandatory/utils.c mandatory/utils2.c \
				mandatory/linkedlists/ft_lstadd_back.c \
				mandatory/linkedlists/ft_lstiter.c \
				mandatory/linkedlists/ft_lstlast.c \
				mandatory/linkedlists/ft_lstnew.c \
				mandatory/linkedlists/ft_lstsize.c \

SRC_BONUS = bonus/checker_bonus.c bonus/ft_split_bonus.c \
			bonus/ft_strjoin_bonus.c bonus/get_next_line_bonus.c \
			bonus/get_next_line_utils_bonus.c bonus/push_rotate_bonus.c \
			bonus/rrotate_bonus.c bonus/swap_bonus.c bonus/utils_bonus.c \
			bonus/utils2_bonus.c \
			bonus/linkedlists/ft_lstadd_back_bonus.c \
			bonus/linkedlists/ft_lstiter_bonus.c \
			bonus/linkedlists/ft_lstlast_bonus.c \
			bonus/linkedlists/ft_lstnew_bonus.c \
			bonus/linkedlists/ft_lstsize_bonus.c \

HEADER = mandatory/push_swap.h

HEADER_BONUS = bonus/push_swap_bonus.h

CC = cc
FLAGS = -Wall -Wextra -Werror

OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)
OBJ_CHECKER = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_PUSH_SWAP)
	$(CC) $(FLAGS) $^ -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_CHECKER)
	$(CC) $(FLAGS) $^ -o $@

mandatory/%.o : mandatory/%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

bonus/%.o : bonus/%.c $(HEADER_BONUS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_PUSH_SWAP) $(OBJ_CHECKER)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re : fclean all

.PHONY: clean
