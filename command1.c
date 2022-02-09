#include "push_swap.h"

void	ft_swap(t_stack *st, char *s)
{
	Node	*tmp;

	tmp = st->head->next;
	tmp->prev = NULL;
	st->head->next = tmp->next;
	tmp->next = st->head;
	st->head->prev = tmp;
	st->head = tmp;
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

void	ft_rotate(t_stack *st, char *s) // first->last
{
	Node	*tmp;

	tmp = st->head;
	st->head->next->prev = NULL;
	st->head = st->head->next;
	tmp->next = NULL;
	tmp->prev = st->tail;
	st->tail->next = tmp;
	st->tail = tmp;
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

void	ft_reverce_rotate(t_stack *st, char *s) // last->first
{
	Node	*tmp;

	tmp = st->tail;
	st->tail->prev->next = NULL;
	st->tail = st->tail->prev;
	st->head->prev = tmp;
	tmp->prev = NULL;
	tmp->next = st->head;
	st->head = tmp;
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

void	ft_push(t_stack *from, t_stack *to, char *s) //pb a->b
{
	Node	*tmp;

	tmp = from->head;
	from->head->next->prev = NULL;
	from->head = from->head->next;
	tmp->next = NULL;
	pushFront(to, tmp->value);
	from->size--;
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}
