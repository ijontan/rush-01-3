/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vantage_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 22:47:26 by itan              #+#    #+#             */
/*   Updated: 2023/08/13 00:01:47 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	vc_top(t_rush01 *rush01, int col)
{
	int	count;
	int	tmp;
	int	i;
	int	pos;

	count = 0;
	tmp = 0;
	i = 0;
	while (++i < rush01->size)
	{
		pos = get_pos(i, col, rush01->size);
		if (rush01->table[pos] > tmp)
		{
			tmp = rush01->table[pos];
			count++;
		}
	}
	if (count < rush01->clues[col])
		return (-1);
	return (count == rush01->clues[col]);
}

int	vc_bottom(t_rush01 *rush01, int col)
{
	int	count;
	int	tmp;
	int	i;
	int	pos;

	count = 0;
	tmp = 0;
	i = rush01->size;
	while (--i >= 0)
	{
		pos = get_pos(i, col, rush01->size);
		if (rush01->table[pos] > tmp)
		{
			tmp = rush01->table[pos];
			count++;
		}
	}
	if (count < rush01->clues[rush01->size + col])
		return (-1);
	return (count == rush01->clues[rush01->size + col]);
}

int	vc_left(t_rush01 *rush01, int row)
{
	int	count;
	int	tmp;
	int	i;
	int	pos;

	count = 0;
	tmp = 0;
	i = 0;
	while (++i < rush01->size)
	{
		pos = get_pos(row, i, rush01->size);
		if (rush01->table[pos] > tmp)
		{
			tmp = rush01->table[pos];
			count++;
		}
	}
	if (count < rush01->clues[rush01->size * 2 + row])
		return (-1);
	return (count == rush01->clues[rush01->size * 2 + row]);
}

int	vc_right(t_rush01 *rush01, int row)
{
	int	count;
	int	tmp;
	int	i;
	int	pos;

	count = 0;
	tmp = 0;
	i = rush01->size;
	while (--i >= 0)
	{
		pos = get_pos(row, i, rush01->size);
		if (rush01->table[pos] > tmp)
		{
			tmp = rush01->table[pos];
			count++;
		}
	}
	if (count < rush01->clues[rush01->size * 3 + row])
		return (-1);
	return (count == rush01->clues[rush01->size * 3 + row]);
}

int	vantage_checker(t_rush01 *rush01)
{
	int	i;
	int	val;

	val = 0;
	i = -1;
	while (++i <= rush01->size)
	{
		val += vc_top(rush01, i);
		val += vc_bottom(rush01, i);
		val += vc_left(rush01, i);
		val += vc_right(rush01, i);
	}
	return (val == rush01->size * 4);
}
