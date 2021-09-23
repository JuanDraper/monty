#include "monty.h"
/**
* error_mes - blalba
* error_mes - blabla.
* @msg: blalba
* @arg: blalba
* @stack: blalba
*/
void error_mes(char *msg, char *arg, stack_t **stack)
{
	free_all(stack);
	fprintf(stderr, "%s%s\n", msg, arg);
	exit(EXIT_FAILURE);
}

/**
* free_all -blalba
* @stack: blalba
* Return: blabla
*/

void free_all(stack_t **stack)
{
	stack_t *tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	if (my_global.lbuffer)
		free(my_global.lbuffer);
	if (my_global.file)
		fclose(my_global.file);
}
/**
* is_ascii - blabla
* @c: bablalba
* Return: blabla
*/

int is_ascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	return (1);
}
/**
* pstr - blalb
* @stack: blalb
* @line_number: blabla
* Return: blalbla
*/

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int i;

	(void) line_number;
	tmp = *stack;
	while (tmp != NULL && tmp->n != 0 && is_ascii(tmp->n))
	{
		i = tmp->n;
		putchar(i);
		tmp = tmp->next;
	}
	putchar('\n');
}
