#include "push_swap.h"

void	ft_swap(t_stack *st, char *s)
{
	
	Node	*tmp;

	tmp = st->head->next;
	st->head->next = tmp->next;
	tmp->next->prev = st->head;
	tmp->next = st->head;
	st->head->prev = tmp;
	tmp->prev = NULL;
	
	st->head = tmp;
	write(1, s, ft_strlen(s));
	
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
}
void ft_rr(t_stack *a, t_stack *b)
{
	ft_rotate(a, "");
	ft_rotate(b, "rr1\n");
}

void	ft_reverce_rotate(t_stack *st, char *s) // last->first
{
	Node	*tmp;

	
	tmp = st->tail;
	
	st->tail = st->tail->prev;
	st->tail->next = NULL;
	
	st->head->prev = tmp;
	tmp->prev = NULL;
	tmp->next = st->head;
	st->head = tmp;
	write(1, s, ft_strlen(s));
}
void ft_rrr(t_stack *a, t_stack *b)
{
	ft_reverce_rotate(a, "");
	ft_reverce_rotate(b, "rrr2\n");
}
void	ft_push(t_stack *from, t_stack *to, char *s) //pb a->b
{
	int	tmp;

	//printf("1= %d, 2 =%d\n", from->head->value, from->head->next->value);
	//if(from->head->next == NULL){
	//	tmp = from->head->value;
	//	from->head = NULL;
	//}
	//else
	//{
	//	tmp = from->head->value;
	//	from->head->next->prev = NULL;
	//	from->head = from->head->next;
	//}
	tmp = popFront(from);
	pushFront(to, tmp);
	//from->size--;
	write(1, s, ft_strlen(s));
}
