#include "monty.h"
/**
* pall - blablabla
* @stack: blablab
* @line_number: bllabla
* Return: blabla
*/

void pall(stack_t **stack, unsigned int line_number)
{
	const stack_t *accesory;

	(void) line_number;
	accesory = *stack;
	while (accesory != NULL)
	{
		printf("%d\n", accesory->n);
		accesory = accesory->next;
	}
}
/**
* push_s - blalbalb
* @stack: blabla
* @line_number: blabla
*/
void push_s(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *arg, m[100];

	if (!stack)
		error_mes("No stack present.", "", stack);
	arg = strtok(NULL, " \t");
	sprintf(m, "L%d: usage: push integer", line_number);
	if (!arg || !isnumber(arg))
		error_mes(m, "", stack);
	new = malloc(sizeof(stack_t));
	if (!new)
		error_mes("Error: malloc failed", "", stack);
	new->n = atoi(arg);
	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}
/**
* pop - blabla
* @stack: blabla
* @line_number: blabla
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *i = *stack;
	char msg[100];

	if (!stack)
		error_mes("No stack present.", "", stack);
	sprintf(msg, "L%d: can't pop an empty stack", line_number);
	if (!*stack)
		error_mes(msg, "", stack);

	*stack = i->next;
	if (i->next)
		i->next->prev = NULL;
	free(i);
}
/**
* pint - blabla
* @stack: blalba
* @line_number: blabla
* Return: blalba
*/

void pint(stack_t **stack, unsigned int line_number)
{
	const stack_t *a;
	char msg[100];
	unsigned int len_stack = 0;

	a = *stack;

	while (a != NULL)
	{
		a = a->next;
		len_stack++;
	}

	if (*stack == NULL || len_stack < 1)
	{
		sprintf(msg, "L%u: can't pint, stack empty", line_number);
		error_mes(msg, "", stack);
	}
	printf("%d\n", (*stack)->n);
}
/**
* pchar - blabla
* @stack: blabla
* @line_number: blabla
* Return: bllabla
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	int i;
	stack_t *tmp;
	char msg[100];

	tmp = *stack;
	if (tmp == NULL)
	{
		sprintf(msg, "L%u: can't pchar, stack empty", line_number);
		error_mes(msg, "", stack);
	}
	i = tmp->n;
	if (!(is_ascii(i)))
	{
		sprintf(msg, "L%u: can't pchar, value out of range", line_number);
		error_mes(msg, "", stack);
	}
	putchar(i);
	putchar('\n');

}

