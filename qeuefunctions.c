#include "monty.h"
/**
 * push_q - blabla
 * @stack: bllba
 * @line_number: blblbla
 */
void push_q(stack_t **stack, unsigned int line_number)
{
	stack_t *nw, *h = *stack;
	char *arg, msg[100];

	if (!stack)
		error_mes("No stack present.", "", stack);
	arg = strtok(NULL, " \t");
	sprintf(msg, "L%d: usage: push integer", line_number);
	if (!arg || !isnumber(arg))
		error_mes(msg, "", stack);
	nw = malloc(sizeof(stack_t));
	if (!nw)
		error_mes("Error: malloc failed", "", stack);
	nw->n = atoi(arg);
	nw->next = NULL;
	if (!*stack)
	{
		nw->prev = *stack;
		*stack = nw;
		return;
	}
	while (h->next)
		h = h->next;
	h->next = nw;
	nw->prev = h;
}
