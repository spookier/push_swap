# Variables
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

# path for srcs
SRCS_DIR = ./srcs/

#path for LIBFT
LIBFT_DIR = ./libft
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

# path for header
INCS_DIR = ./incs

# Mandatory files
FILES =		$(SRCS_DIR)main.c \
			$(SRCS_DIR)operations_0.c \
			$(SRCS_DIR)init_prog.c \
			$(SRCS_DIR)memory_mng.c \
			$(SRCS_DIR)parsing.c \
			$(SRCS_DIR)parsing2.c \
			$(SRCS_DIR)algorithm.c \
			$(SRCS_DIR)rotations_type.c \
			$(SRCS_DIR)case_check_a.c \
			$(SRCS_DIR)case_check_ab.c \
			$(SRCS_DIR)case_apply.c \
			

# Transform .c files into .o
OBJ_FILES = $(FILES:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCS_DIR)


all : $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)


$(NAME) : $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ -I$(INCS_DIR)

# Clean all object files created
clean : 
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_FILES)

# Clean all object files + the library created
fclean : clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

#Fclean then build all
re : fclean
	make all



.PHONY : all clean fclean re