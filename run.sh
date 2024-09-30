gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./monty bytecodes/x.m

rm monty
