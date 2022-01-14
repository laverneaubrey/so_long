NAME = get_next_line.a

SRC =   get_next_line.c	get_next_line_utils.c get_next_line.h

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

DEL = rm

all		: $(NAME)


$(NAME)	: $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o : %.c get_next_line.h
	gcc $(FLAG) -c $< -o $@

clean   :
	$(RM)    *.o

fclean	:	clean
	$(RM) $(NAME)

re	    :	fclean all

.PHONY	:	all clean fclean re
