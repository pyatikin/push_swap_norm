#include "push_swap.h"

t_stack	*createt_stack(void)
{
	t_stack	*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (!tmp)
	{
		free(tmp);
		exit(1);
	}
	tmp->size = 0;
	tmp->head = NULL;
	tmp->tail = NULL;
	return (tmp);
}

void	deletet_stack(t_stack **list)
{
	Node	*tmp;
	Node	*next;

	tmp = (*list)->head;
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*list);
	(*list) = NULL;
}

void	pushFront(t_stack *list, int data)
{
	Node	*tmp;

	tmp = (Node *)malloc(sizeof(Node));
	if (tmp == NULL)
		exit(1);
	tmp->value = data;
	tmp->next = list->head;
	tmp->prev = NULL;
	if (list->head)
		list->head->prev = tmp;
	list->head = tmp;
	if (list->tail == NULL)
		list->tail = tmp;
	list->size++;
}

int	popFront(t_stack *list)
{
	Node	*prev;
	int		tmp;

	if (list->head == NULL)
		exit(2);
	prev = list->head;
	list->head = list->head->next;
	if (list->head)
		list->head->prev = NULL;
	if (prev == list->tail)
		list->tail = NULL;
	tmp = prev->value;
	free(prev);
	list->size--;
	return (tmp);
}

void	pushBack(t_stack *list, int value)
{
	Node	*tmp;

	tmp = (Node *)malloc(sizeof(Node));
	if (tmp == NULL)
		exit(3);
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = list->tail;
	if (list->tail)
		list->tail->next = tmp;
	list->tail = tmp;
	if (list->head == NULL)
		list->head = tmp;
	list->size++;
}

int	popBack(t_stack *list)
{
	Node	*next;
	int		tmp;

	if (list->tail == NULL)
		exit(4);
	next = list->tail;
	list->tail = list->tail->prev;
	if (list->tail)
		list->tail->next = NULL;
	if (next == list->head)
		list->head = NULL;
	tmp = next->value;
	free(next);
	list->size--;
	return (tmp);
}

void	printt_stack(t_stack *list)
{
	Node	*tmp;

	tmp = list->head;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}

int	getNvalue(t_stack *list, size_t index)
{
	Node	*tmp;
	size_t	i;

	tmp = NULL;
	if (index < list->size / 2)
	{
		i = 0;
		tmp = list->head;
		while (tmp && i < index)
		{
			tmp = tmp->next;
			i++;
		}
	}
	else
	{
		i = list->size - 1;
		tmp = list->tail;
		while (tmp && i > index)
		{
			tmp = tmp->prev;
			i--;
		}
	}
	return (tmp->value);
}
