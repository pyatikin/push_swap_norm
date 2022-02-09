#include "push_swap.h"

int	parse_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while(i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			if(!(ft_isdigit(argv[i][j]) || (argv[i][0] == '-' && (ft_isdigit(argv[i][1])))))
				return (1);
			j++;

		}
		i++;
	}
	return (0);
}

t_stack	*translate(int argc, char **argv)
{
	t_stack	*a;
	int	i;

	i = 1;
	a = createt_stack();
	while(i<argc)
	{
		if(argv[i][0] == '0' && argv[i][1] == '\0')
			pushBack(a, 0);
		else if(ft_atoi(argv[i]) == 0)
		{
			printf("WRONG NUM\n\0");
			exit(4);
		}
		else
			pushBack(a, ft_atoi(argv[i]));
		i++;
	}
	return (a);
}

void	duplicates(t_stack *st)
{
	int	i;
	int	j;

	i = 0;
	while(i < st->size-1){
		j=i+1;
		while (j<st->size)
		{
			if(getNvalue(st, i) == getNvalue(st, j))
			{
				printf("DUPLICATES\n\0");
				exit(2);
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char**argv)
{
	t_stack	*st;
	t_stack	*b;
	int min_price;

    if(argc <= 2)
        return (0);
    else
    {
        if(parse_argv(argc, argv))
		{
			printf("NOT NUM\n\0");
			exit (1);
		}
		st = translate(argc, argv);
		duplicates(st);
/*------------------------------------*/
		b = createt_stack();
		parse_stack(st, b);
		triple_sort(st);
		while(b->size > 0){
			find_your_place(st, b);
			min_price = evaluation(st, b);
			sorting(st,b, min_price);
		}
		printf("a\n\0");
			printt_stack(st);
			printf("b\n\0");
			printt_stack(b);
			Node *tmp = b->head;
			while(tmp != NULL)
			{
				printf("value = %d | place b = %d | place a = %d | price = %d\n", tmp->value, tmp->b_place, tmp->a_place, tmp->price);
				tmp = tmp->next;
			}
		
		printf("SIZE = %ld", b->size);
    }
}