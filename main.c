#include"monty.h"

/**
 * main - Main entry
 * Description: Monty bytecodes file interpreter
 * @ac: argument count
 * @av: argument vector (monty files)
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	if (ac != 2)
		args_err();
	open_read(av);
	return (0);
}
