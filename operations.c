#include "monty.h"
/**
* add - blbla
* @stack: blalba
* @line_number: bllblalb
*/
void add(stack_t **stack, unsigned int line_number)
{
	char msg[100];

	sprintf(msg, "L%d: can't add, stack too short", line_number);
	if (!stack)
		error_mes("No stack present.", "", stack);
	if (!*stack || !(*stack)->next)
		error_mes(msg, "", stack);
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
/**
* sub - blblalba
* @stack: blabla
* @line_number: blalbla
*/
void sub(stack_t **stack, unsigned int line_number)
{
	char msg[100];

	sprintf(msg, "L%d: can't sub, stack too short", line_number);
	if (!stack)
		error_mes("No stack present.", "", stack);
	if (!*stack || !(*stack)->next)
		error_mes(msg, "", stack);
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
/**
* divi - blablalb
* @stack: blalba
* @line_number: blalbla
*/
void divi(stack_t **stack, unsigned int line_number)
{
	char msg[100];

	sprintf(msg, "L%d: can't div, stack too short", line_number);
	if (!stack)
		error_mes("No stack present.", "", stack);
	if (!*stack || !(*stack)->next)
		error_mes(msg, "", stack);
	sprintf(msg, "L%d: division by zero", line_number);
	if (!(*stack)->n)
		error_mes(msg, "", stack);
	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}
/**
* mul - blalbal
* @stack: blalbal.
* @line_number: balblal
*/
void mul(stack_t **stack, unsigned int line_number)
{
	char msg[100];

	sprintf(msg, "L%d: can't mul, stack too short", line_number);
	if (!stack)
		error_mes("No stack present.", "", stack);
	if (!*stack || !(*stack)->next)
		error_mes(msg, "", stack);
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
/**
* mod - blalbllab
* @stack: blalba
* @line_number: blalba
*/
void mod(stack_t **stack, unsigned int line_number)
{
	char msg[100];

	sprintf(msg, "L%d: can't mod, stack too short", line_number);
	if (!stack)
		error_mes("No stack present.", "", stack);
	if (!*stack || !(*stack)->next)
		error_mes(msg, "", stack);
	sprintf(msg, "L%d: division by zero", line_number);
	if (!(*stack)->n)
		error_mes(msg, "", stack);
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
