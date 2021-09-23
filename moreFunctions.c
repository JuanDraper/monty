#include "monty.h"

/**
* del_node_index - blalba
* @head: blalba
* @idx: blalba
* Return: blalbal
*/

int del_node_index(stack_t **head, unsigned int idx)
{
	stack_t *no, *dn;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);
	no = *head;
	while (no && i < idx)
	{
		no = no->next;
		i++;
	}
	if (i < idx)
		return (-1);
	if (i == 0 && no->next)
	{
		dn = no;
		no = no->next;
		no->prev = NULL;
		*head = no;
		free(dn);
		return (1);
	}
	else if (i > 0)
	{
		dn = no;
		no = no->prev;
		no->next = dn->next;
		free(dn);
	}
	else
	{
		*head = no->next;
		free(no);
	}
	return (1);
}

/**
* len_stack - blalba
* @head: blalbal
* Return: blalbal
*/

size_t len_stack(const stack_t *head)
{
	unsigned int len = 0;

	while (head != NULL)
	{
		head = head->next;
		len++;
	}
	return (len);
}

/**
* swap - blabla
* @stack: blalba
* @line_number: blallba
* Return: blalbla
*/

void swap(stack_t **stack, unsigned int line_number)
{
	char msg[100];
	stack_t *f, *s;
	int tmp;

	if (len_stack(*stack) < 2 || *stack == NULL)
	{
		sprintf(msg, "L%u: can't swap, stack too short", line_number);
		error_mes(msg, "", stack);
	}

	f = *stack;
	s = f->next;
	tmp = s->n;
	s->n = f->n;
	f->n = tmp;
}

/**
* rotl - blalba
* @stack: blalbla
* @line_number: blabla
* Return: blalbla
*/

void rotl(stack_t **stack, unsigned int line_number)
{
	int tmp;
	stack_t *h, *nw, *r;

	(void) line_number;
	h = *stack;
	if (*stack == NULL)
		return;
	if (len_stack(*stack) > 1)
	{
		tmp = h->n;
		del_node_index(stack, 0);
		nw = malloc(sizeof(*nw));
		if (!nw)
			error_mes("Error: malloc failed", "", stack);
		r = *stack;
		nw->n = tmp;
		nw->next = NULL;
		if (h == NULL)
		{
			nw->prev = NULL;
			h = nw;
		}
		while (r->next)
			r = r->next;
		nw->prev = r;
		r->next = nw;
	}
}

/**
* rotr - blablal
* @stack: blalbla
* @line_number: blalba
* Return: blalbla
*/

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *e1, *e2;

	(void) line_number;
	e1 = *stack;
	if (e1 == NULL)
		return;
	e2 = e1;
	if (e1->next == NULL)
		;
	else
	{
		while (e2->next != NULL)
			e2 = e2->next;
		e2->prev->next = NULL;
		e2->prev = NULL;
		e2->next = e1;
		e1->prev = e2;
		*stack = e2;
	}
}
