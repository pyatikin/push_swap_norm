#include "push_swap.h"

int	get_place(t_stack st, int value)
{
	int		i;
	Node	*tmp;

	i = 0;
	tmp = st.head;
	while (tmp->value != value)
		i++;
	return (i);
}

void	find_your_place(t_stack *a, t_stack *b)//!!!!!!!!!!!!!!!!!!!
{
	Node	*tmp;
	Node	*a2;
	int		i;
	int		j;

	i = 0;
	tmp = b->head;
	while (tmp != NULL)
	{
		tmp->b_place = i;
		a2 = a->head;
		j = 0;
		while (!(a2->value - tmp->value < 0 || a2->next->value - tmp->value > 0) && a2->next != NULL)
		{
			a2 = a2->next;
			j++;
		}
		if(a2->next == NULL)
			tmp->a_place = 0;
		else
			tmp->a_place = j;
		i++;
		tmp = tmp->next;
	}
}

Node *find_min_price(t_stack *b, int min_price)
{
	Node *tmp;

	tmp = b->head;
	while (tmp->price != min_price)
		tmp = tmp->next;
	return (tmp);
}

void sorting(t_stack *a, t_stack *b, int min_price)
{
	Node *a_tmp;
	Node *b_tmp;
	int	i;

	a_tmp = a->head;
	b_tmp = find_min_price(b, min_price);
	if (b_tmp->a_place > (a->size / 2) && b_tmp->b_place > (b->size / 2))
		{
			if (a->size - b_tmp->a_place > b->size - b_tmp->b_place){
				i = 0;
				while(i < b->size - b_tmp->b_place)
				{
					ft_rrr(a,b);
					i++;
				}
				i = 0;
				while(i < (a->size - b_tmp->a_place - b->size - b_tmp->b_place))
				{
					ft_reverce_rotate(a, "rra\n");
					i++;
				}
			} 
			else
			{
				i = 0;
				while(a->size - b_tmp->a_place)
				{
					ft_rrr(a,b);
					i++;
				}
				i = 0;
				while(i < ( b->size - b_tmp->b_place - a->size - b_tmp->a_place))
				{
					ft_reverce_rotate(b, "rrb\n");
					i++;
				}
			}
			
		}
		else if (b_tmp->a_place <= (a->size / 2) && b_tmp->b_place <= (b->size / 2))
		{
			if (b_tmp->a_place > b_tmp->b_place)
			{
				i=0;
				while(i < b_tmp->b_place){
					ft_rr(a,b);
					i++;
				}
				i = 0;
				while(i < b_tmp->a_place - b_tmp->b_place)
				{
					ft_rotate(a, "ra\n");
					i++;
				}
			}
			else
			{
				i=0;
				while(i < b_tmp->a_place){
					ft_rr(a,b);
					i++;
				}
				i = 0;
				while(i < b_tmp->b_place - b_tmp->a_place)
				{
					ft_rotate(b, "rb\n");
					i++;
				}
			}
		}
		else if (b_tmp->a_place > (a->size / 2) && b_tmp->b_place <= (b->size / 2))
		{
			i = 0;
			while(i < a->size - b_tmp->a_place){
				ft_reverce_rotate(a, "rra\n");
				i++;
			}
			i = 0;
			while(i < b_tmp->b_place){
				ft_rotate(b, "rb\n");
				i++;
			}
		}
		else if (b_tmp->a_place <= (a->size / 2) && b_tmp->b_place > (b->size / 2))
		{
			i = 0;
			while(i < b->size - b_tmp->b_place){
				ft_reverce_rotate(b, "rrb\n");
				i++;
			}
			i = 0;
			while(i < b_tmp->a_place){
				ft_rotate(a, "ra\n");
				i++;
			}
		}
		ft_push(b, a, "pa\n");
}

int	evaluation(t_stack *a, t_stack *b) //!!!!!!!!!!!!
{
	int		min_price;
	Node	*tmp;

	tmp = b->head;
	min_price = MAX_INT;
	while (tmp != NULL)
	{
		if (tmp->a_place > (a->size / 2) && tmp->b_place > (b->size / 2))
		{
			if (a->size - tmp->a_place > b->size - tmp->b_place)
				tmp->price = a->size - tmp->a_place;
			else
				tmp->price = b->size - tmp->b_place;
		}
		else if (tmp->a_place <= (a->size / 2) && tmp->b_place <= (b->size / 2))
		{
			if (tmp->a_place > tmp->b_place)
				tmp->price = tmp->a_place;
			else
				tmp->price = tmp->b_place;
		}
		else if (tmp->a_place > (a->size / 2) && tmp->b_place <= (b->size / 2))
			tmp->price = tmp->b_place + a->size - tmp->a_place;
		else if (tmp->a_place <= (a->size / 2) && tmp->b_place > (b->size / 2))
			tmp->price = tmp->a_place + b->size - tmp->b_place;
		if(tmp->price < min_price)
			min_price = tmp->price;
		tmp = tmp->next;
	}
	return (min_price);
}

void	triple_sort(t_stack *st)
{
	int	first;
	int	second;
	int	third;

	first = st->head->value;
	second = st->head->next->value;
	third = st->head->next->next->value;
	if (first < second && first < third && second > third)
		ft_swap(st, "sa\n");
	else if (first > second && first < third && second < third)
		ft_swap(st, "sa\n");
	else if (first > second && first > third && second > third)
		ft_swap(st, "sa\n");
}

void	parse_stack(t_stack *a, t_stack *b)
{
	int		max;
	int		min;
	int		mid;
	Node	*tmp;

	tmp = a->head;
	max = -2147483648;
	min = 2147483647;
	while (tmp != NULL)
	{
		if (tmp->value > max)
			max = tmp->value;
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	tmp = a->tail;
	mid = max;
	while (mid == max)
	{
		if (tmp->value != max && tmp->value != min)
		{
			mid = tmp->value;
			break ;
		}
		tmp = tmp->prev;
	}
	tmp = a->head;
	while (tmp != NULL)
	{
		if (a->size == 3)
			break ;
		if (tmp->value == max || tmp->value == min || tmp->value == mid)
		{
			tmp = tmp->next;
			ft_rotate(a, "ra\n");
		}
		else
		{
			tmp = tmp->next;
			ft_push(a, b, "pb\n");
		}
	}
}
