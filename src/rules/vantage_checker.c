/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vantage_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 22:47:26 by itan              #+#    #+#             */
/*   Updated: 2023/08/12 22:55:15 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	vc_top(t_rush01 *rush01, int col)
{
	int	count;
	int	tmp;
	int	i;

	count = 0;
	tmp = 0;
	i = 0;
	while (++i < rush01->size)
	{
		if (rush01->table[i * rush01->size + col] > tmp)
		{
			tmp = rush01->table[i * rush01->size + col];
			count++;
		}
	}
	if (count > rush01->clues[col])
		return (0);
	return (1);
}

int	vc_bottom(t_rush01 *rush01, int col)
{
	int	count;
	int	tmp;
	int	i;

	count = 0;
	tmp = 0;
	i = rush01->size;
	while (--i >= 0)
	{
		if (rush01->table[i * rush01->size + col] > tmp)
		{
			tmp = rush01->table[i * rush01->size + col];
			count++;
		}
	}
	if (count > rush01->clues[rush01->size + col])
		return (0);
	return (1);
}

int	vc_left(t_rush01 *rush01, int row)
{
	int	count;
	int	tmp;
	int	i;

	count = 0;
	tmp = 0;
	i = 0;
	while (++i < rush01->size)
	{
		if (rush01->table[row * rush01->size + i] > tmp)
		{
			tmp = rush01->table[row * rush01->size + i];
			count++;
		}
	}
	if (count > rush01->clues[rush01->size * 2 + row])
		return (0);
	return (1);
}

int	vc_right(t_rush01 *rush01, int row)
{
	int	count;
	int	tmp;
	int	i;

	count = 0;
	tmp = 0;
	i = rush01->size;
	while (--i >= 0)
	{
		if (rush01->table[row * rush01->size + i] > tmp)
		{
			tmp = rush01->table[row * rush01->size + i];
			count++;
		}
	}
	if (count > rush01->clues[rush01->size * 3 + row])
		return (0);
	return (1);
}
