/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:52:23 by pthiruma          #+#    #+#             */
/*   Updated: 2023/07/13 22:05:06 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static	int	ft_contains(long num, char **args, int i)
{
	i++;
	while (args[i])
	{
		if (ft_atoi(args[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (!num)
		return (0);
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(int argc, char **args, int i)
{
	long	tmp;

	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
		{
			if (argc == 2)
				ft_free(args);
			ft_error("Error");
		}
		if (ft_contains(tmp, args, i))
		{
			if (argc == 2)
				ft_free(args);
			ft_error("Error");
		}
		if (tmp < -2147483648 || tmp > 2147483647)
		{
			if (argc == 2)
				ft_free(args);
			ft_error("Error");
		}
		i++;
	}
}

void	ft_create_args(int argc, char **argv)
{
	int		i;
	char	**args;

	i = 0;
	args = NULL;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	ft_check_args(argc, args, i);
	if (argc == 2)
		ft_free(args);
}
