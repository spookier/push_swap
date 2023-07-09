# Variables
NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra 

# COLOR CODES FOR DEBUG
COLOUR_GREEN=\033[0;32m
END_COLOR=\033[0m

# Path for push_swap algorithm
PUSH_SWAP_DIR = ./srcs/push_swap/

# Path for checker
BONUS_DIR = ./srcs/checker/

#path for LIBFT
LIBFT_DIR = ./libft
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

# path for header
INCS_DIR = ./incs

# Mandatory files
FILES =		$(PUSH_SWAP_DIR)main.c \
			$(PUSH_SWAP_DIR)operations_0.c \
			$(PUSH_SWAP_DIR)init_prog.c \
			$(PUSH_SWAP_DIR)memory_mng.c \
			$(PUSH_SWAP_DIR)parsing.c \
			$(PUSH_SWAP_DIR)parsing2.c \
			$(PUSH_SWAP_DIR)algorithm.c \
			$(PUSH_SWAP_DIR)algorithm2.c \
			$(PUSH_SWAP_DIR)rotations_type.c \
			$(PUSH_SWAP_DIR)case_check_a.c \
			$(PUSH_SWAP_DIR)case_check_ab.c \
			$(PUSH_SWAP_DIR)case_apply.c \


BONUS_FILES =	$(BONUS_DIR)main.c \
				$(BONUS_DIR)operation_parse.c \
				$(PUSH_SWAP_DIR)memory_mng.c \
				$(PUSH_SWAP_DIR)parsing.c \
				$(PUSH_SWAP_DIR)parsing2.c \
				$(PUSH_SWAP_DIR)operations_0.c \

OBJ_FILES = $(FILES:.c=.o)
BONUS_OBJ_FILES = $(BONUS_FILES:.c=.o)



.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCS_DIR)

all : $(LIBFT_NAME) $(NAME)
	@echo "$(COLOUR_GREEN)- BUILD SUCCESS\n$(END_COLOR)"

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

$(NAME) : $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ -I$(INCS_DIR)

$(BONUS_NAME) : $(BONUS_OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ -I$(INCS_DIR)

clean : 
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_FILES) $(BONUS_OBJ_FILES)
	@echo "$(COLOUR_GREEN)- DELETED ALL OBJECT FILES\n$(END_COLOR)"

fclean : clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME) checker
	@echo "$(COLOUR_GREEN)- DELETED EXEC FILES + ARCHIVE FILES \n$(END_COLOR)"

re : fclean
	make all

bonus : $(LIBFT_NAME) $(BONUS_NAME)
	@echo "$(COLOUR_GREEN)- BONUS BUILD SUCCESS\n$(END_COLOR)"

.PHONY : all clean fclean re bonus