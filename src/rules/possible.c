/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:52:04 by itan              #+#    #+#             */
/*   Updated: 2023/08/12 23:11:55 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

// position = row * size + col

int	check_repeat(t_rush01 *rush01, int row, int col, int num)
{
	int	i;

	i = -1;
	while (++i < rush01->size)
		if (rush01->table[get_pos(row, i, rush01->size)] == num)
			return (1);
	i = -1;
	while (++i < rush01->size)
		if (rush01->table[get_pos(i, col, rush01->size)] == num)
			return (1);
	return (0);
}

// val <= size - clue + distance
int	distance_check(t_rush01 *rush01, int row, int col, int num)
{
	int	size;

	size = rush01->size;
	if (num > size - rush01->clues[size + row] + col)
		return (0);
	if (num > size - rush01->clues[col] + row)
		return (0);
	if (num > size - rush01->clues[size * 2 + col] + (size - row - 1))
		return (0);
	if (num > size - rush01->clues[size * 3 + row] + (size - col - 1))
		return (0);
	return (1);
}

int	get_possible(t_rush01 *rush01, int row, int col, int num)
{
	if (check_repeat(rush01, row, col, num))
		return (0);
	if (!distance_check(rush01, row, col, num))
		return (0);
	if (vc_top(rush01, col) == 0)
		return (0);
	if (vc_bottom(rush01, col) == 0)
		return (0);
	if (vc_left(rush01, row) == 0)
		return (0);
	if (vc_right(rush01, row) == 0)
		return (0);
	return (1);
}
