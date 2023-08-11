/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:34:02 by itan              #+#    #+#             */
/*   Updated: 2023/08/11 20:48:52 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	count_2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	parser(char *input, t_rush01 *rush01)
{
	char	**vals;
	int		count;
	int		i;

	vals = ft_split(input, ' ');
	if (!vals)
		return (0);
	count = count_2d(vals);
	if (count % 4 != 0)
	{
		ft_free_2d(vals);
		return (0);
	}
	rush01->size = count / 4;
	rush01->table = ft_calloc(sizeof(int), rush01->size * rush01->size);
	rush01->clues = ft_calloc(sizeof(int), count);
	i = -1;
	while (++i < count)
		rush01->clues[i] = ft_atoi(vals[i]);
	ft_free_2d(vals);
	return (1);
}
