clear
gcc -Wall -Wextra -Werror -o fillit libft.a main.c map_general.c \
map_operations.c tetr.c
echo "The program started:"
echo "---------------------------------------"
./fillit
echo "\n---------------------------------------"
echo "The program finished"
echo "---------------------------------------"
echo "Norminette results:"
norminette | grep -v "Warning" | grep -v "comment"
echo "---------------------------------------"
echo "Don't forget about comments:"
norminette | grep "comment"
echo "---------------------------------------"
rm -f fillit
