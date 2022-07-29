/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_getters_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:29:20 by schuah            #+#    #+#             */
/*   Updated: 2022/07/29 14:11:27 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"

/* Turns all input into a string of numbers seperated by spaces */
static char	*get_inputstr(char **av)
{
	int		i;
	char	*temp;
	char	*temp2;
	char	*output;

	i = 0;
	output = malloc(sizeof(char));
	while (av[++i] != 0)
	{
		temp = ft_strjoin(output, av[i]);
		temp2 = output;
		output = ft_strjoin(temp, " ");
		free(temp2);
		free(temp);
	}
	return (output);
}

/* Puts the numbers into stack A after calculating the number of inputs,
** Returns errno if there is any input errors, 0 if none */
static int	get_input_from_av(t_psinfo *psinfo, char **av)
{
	char	**numbers;
	char	*str;
	int		i;
	int		j;
	int		errno;

	i = 0;
	str = get_inputstr(av);
	psinfo->stack_a = malloc(sizeof(int) * ft_getwc(str, ' '));
	psinfo->stack_b = malloc(sizeof(int) * ft_getwc(str, ' '));
	if (psinfo->stack_a == NULL || psinfo->stack_b == NULL)
		return (0);
	numbers = ft_split(str, ' ');
	j = 0;
	while (numbers[j] != 0)
	{
		if (errno == 0)
			errno = get_error(psinfo, numbers[j], j);
		psinfo->stack_a[i++] = ft_atoi(numbers[j]);
		free(numbers[j++]);
	}
	free(numbers);
	free(str);
	return (errno);
}

/* Calculates the number of input */
static void	get_input(t_psinfo *psinfo, char **av)
{
	int	i;
	int	j;

	i = 0;
	psinfo->len_a = 0;
	while (av[++i] != 0)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			while (ft_isspace(av[i][j]) || av[i][j] == '-' || av[i][j] == '+')
				j++;
			while (!ft_isspace(av[i][j]) && av[i][j] != '\0')
				j++;
			psinfo->len_a++;
			while (ft_isspace(av[i][j]) || av[i][j] == '-' || av[i][j] == '+')
				j++;
		}
	}
	psinfo->total_len = psinfo->len_a;
}

/* Gets necessary data and assigns the respective sorting algorithm,
** outputs the respective error messages based on the errno received */
int	get_data(t_psinfo *psinfo, char **av)
{
	int	errno;

	get_input(psinfo, av);
	errno = get_input_from_av(psinfo, av);
	if (errno == 1)
		return (write(2, "Error: Input is not a number\n", 29));
	if (errno == 2)
		return (write(2, "Error: Number smaller than INT_MIN\n", 35));
	if (errno == 3)
		return (write(2, "Error: Number greater than INT_MAX\n", 35));
	if (errno == 4)
		return (write(2, "Error: There is a duplicate number\n", 35));
	get_converted_stack(psinfo);
	if (is_sorted(psinfo->stack_a, psinfo->len_a) == 1)
		return (0);
	else if (psinfo->len_a <= 5)
		sort_small(psinfo);
	else
		ps_sorthundred(psinfo);
	return (0);
}

/* Creates a copy of a stack*/
int	*get_stack(t_psinfo *psinfo, char c)
{
	int	i;
	int	*output;

	if (c == 'a')
	{
		output = malloc(sizeof(int) * psinfo->len_a);
		if (output == NULL)
			return (NULL);
		i = -1;
		while (++i < psinfo->len_a)
			output[i] = psinfo->stack_a[i];
		return (output);
	}
	output = malloc(sizeof(int) * psinfo->len_b);
	if (output == NULL)
		return (NULL);
	i = -1;
	while (++i < psinfo->len_b)
		output[i] = psinfo->stack_b[i];
	return (output);
}
