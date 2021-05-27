NAME = client
NAME2 = server

FUNCTIONS = ./client/client \
			./client/utils

FUNC = 		./server/server \
			./server/utils

FLAGS = -Wall -Wextra -Werror

SRC = $(addsuffix .c, $(FUNCTIONS))
EXCH = $(addsuffix .o, $(FUNCTIONS))

SRC2 = $(addsuffix .c, $(FUNC))
EXCH2 = $(addsuffix .o, $(FUNC))

all: $(NAME) $(NAME2)

$(NAME): $(EXCH)
	gcc $(FLAGS) $(EXCH) -o $(NAME)

$(NAME2): $(EXCH2)
	gcc $(FLAGS) $(EXCH2) -o $(NAME2)

%.o: %.c     
	gcc $(FLAGS) -o $@ -c $<

clean:
	/bin/rm -f ./client/*.o
	/bin/rm -f ./server/*.o

fclean: clean
	/bin/rm -f $(NAME) $(NAME2)

re: fclean all