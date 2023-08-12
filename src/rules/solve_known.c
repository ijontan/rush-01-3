/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_known.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 23:03:03 by itan              #+#    #+#             */
/*   Updated: 2023/08/12 23:39:29 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	solve_1(t_rush01 *rush01)
{
	int	i;

	i = -1;
	while (++i < rush01->size)
	{
		if (rush01->clues[i] == 1)
			rush01->table[i] = rush01->size;
		if (rush01->clues[i] == 1 && rush01->clues[rush01->size + i] == 2)
			rush01->table[(rush01->size - 1) * rush01->size + i] = rush01->size;
		if (rush01->clues[rush01->size + i] == 1)
			rush01->table[(rush01->size - 1) * rush01->size + i] = rush01->size;
		if (rush01->clues[rush01->size + i] == 1 && rush01->clues[i] == 2)
			rush01->table[i] = rush01->size;
		if (rush01->clues[rush01->size * 2 + i] == 1)
			rush01->table[i * rush01->size] = rush01->size;
		if (rush01->clues[rush01->size * 2 + i] == 1
			&& rush01->clues[rush01->size * 3 + i] == 2)
			rush01->table[i * rush01->size + rush01->size - 1] = rush01->size;
		if (rush01->clues[rush01->size * 3 + i] == 1)
			rush01->table[i * rush01->size + rush01->size - 1] = rush01->size;
		if (rush01->clues[rush01->size * 3 + i] == 1
			&& rush01->clues[rush01->size * 2 + i] == 2)
			rush01->table[i * rush01->size] = rush01->size;
	}
}

static void	seen_all(t_rush01 *rush01, int row, int col)
{
	int	i;

	i = 0;
	if (row == 0)
		while (++i <= rush01->size)
			rush01->table[get_pos(row, i, rush01->size)] = i;
	if (col == 0)
		while (++i <= rush01->size)
			rush01->table[get_pos(i, col, rush01->size)] = i;
	if (row == rush01->size - 1)
		while (++i <= rush01->size)
			rush01->table[get_pos(row, rush01->size - i, rush01->size)] = i;
	if (col == rush01->size - 1)
		while (++i <= rush01->size)
			rush01->table[get_pos(rush01->size - i, col, rush01->size)] = i;
}

void	solve_known(t_rush01 *rush01)
{
	int	i;
	int	size;

	i = -1;
	size = rush01->size;
	solve_1(rush01);
	while (++i < size)
	{
		if (rush01->clues[i] == size)
			seen_all(rush01, 0, i);
		if (rush01->clues[size + i] == size)
			seen_all(rush01, size - 1, i);
		if (rush01->clues[size * 2 + i] == size)
			seen_all(rush01, i, 0);
		if (rush01->clues[size * 3 + i] == size)
			seen_all(rush01, i, size - 1);
		if (rush01->clues[i] + rush01->clues[size + i] == size + 1)
			rush01->table[get_pos(rush01->clues[i], i, size)] = size;
		if (rush01->clues[size * 2 + i] + rush01->clues[size * 3 + i] == size
			+ 1)
			rush01->table[get_pos(i, rush01->clues[size * 2 + i], size)] = size;
	}
}
