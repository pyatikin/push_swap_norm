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

void	find_your_place(t_stack *a, t_stack *b)
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
		while (a2->value < tmp->value)
		{
			a2 = a2->next;
			j++;
		}
		tmp->a_place = j;
		i++;
		tmp = tmp->next;
	}
}

void	evaluation(t_stack *a, t_stack *b) //!!!!!!!!!!!!
{
	int		min_price;
	Node	*tmp;

	tmp = b->head;
	min_price = 0;
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
		tmp = tmp->next;
	}
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
		ft_swap(st, "sa");
	else if (first > second && first < third && second < third)
		ft_swap(st, "sa");
	else if (first > second && first > third && second > third)
		ft_swap(st, "sa");
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
			ft_rotate(a, "ra");
		}
		else
		{
			tmp = tmp->next;
			ft_push(a, b, "pb");
		}
	}
}
