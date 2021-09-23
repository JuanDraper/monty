#define  _GNU_SOURCE
#include <stdio.h>
#include "monty.h"
#include <ctype.h>
glob_t my_global;
/**
* main - blabla
* @argc: blabla
* @argv: blabla
* Return: blabla
*/
int main(int argc, char *argv[])
{
	instruction_t options[14] = {{"push", push_s}, {"pall", pall}, {"pint", pint},
	{"pop", pop}, {"swap", swap}, {"add", add}, {"sub", sub}, {"div", divi},
	{"mul", mul}, {"mod", mod}, {"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl},
	{"rotr", rotr}};
	int line_number = 1, getl_res = 0;
	size_t bsize = 0;
	stack_t *stack = NULL;

	if (argc != 2)
		error_mes("USAGE: monty file", "", &stack);
	my_global.file = fopen(argv[1], "r");
	if (!my_global.file)
		error_mes("Error: Can't open file ", argv[1], &stack);
	while (1)
	{
		getl_res = getline(&my_global.lbuffer, &bsize, my_global.file);
		if (getl_res == EOF)
			break;
		check_opc(strtok(my_global.lbuffer, " \t"), &options, line_number,
			&stack);
		line_number++;
	}
	free_all(&stack);
	return (EXIT_SUCCESS);
}
/**
* check_opc - blalba
* @lbuffer: blalba.
* @options: blalbal
* @line_number: blalba
* @stack: blabla
*/
void check_opc(char *lbuffer, instruction_t (*options)[], int line_number,
stack_t **stack)
{
	int i, len = strlen(lbuffer);
	char message[100];

	if (lbuffer[len - 1] == '\n')
		lbuffer[len - 1] = 0;
	if (!strcmp(lbuffer, "nop") || lbuffer[0] == '#')
		return;
	if (!strcmp(lbuffer, ""))
		return;
	if (!strcmp(lbuffer, "queue"))
	{
		(*options)[0].f = push_q;
		return;
	}
	if (!strcmp(lbuffer, "stack"))
	{
		(*options)[0].f = push_s;
		return;
	}
	for (i = 0; i < 14; i++)
	{
		if (!strcmp(lbuffer, (*options)[i].opcode))
		{
			(*options)[i].f(stack, line_number);
			return;
		}
	}
	if (i == 14)
	{
		sprintf(message, "L%d: unknown instruction %s", line_number, lbuffer);
		error_mes(message, "", stack);
	}
	return;

}
/**
* isnumber - blabla
* @str: bllablaba
* Return: blabla
*/
short isnumber(char *str)
{
	short i;

	if (*str == '\n')
		return (0);
	for (i = 0; *(str + i) && *(str + i) != '\n'; i++)
		if (!isdigit(*(str + i)) && *(str + i) != '-')
			return (0);
	return (1);
}
