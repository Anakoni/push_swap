void	sort_radix(t_stack **a, t_stack **b)
{
	t_radix	radix;

	radix.max_num = find_max(*a);
	radix.max_bits = 0;
	radix.size = list_length(*a);
	while ((radix.max_num >> radix.max_bits) != 0)
		radix.max_bits++;
	radix.i = 0;
	while (radix.i < radix.max_bits)
	{
		radix.j = 0;
		while (radix.j < radix.size)
		{
			radix.num = (*a)->value;
			if (((radix.num >> radix.i) & 1) == 1)
				rotate(a, 'a');
			else
				push(a, b, 'b');
			radix.j++;
		}
		while (*b)
			push(b, a, 'a');
		radix.i++;
	}
}

typedef struct s_radix
{
	int	max_num;
	int	num;
	int	max_bits;
	int	size;
	int	i;
	int	j;
}	t_radix;
