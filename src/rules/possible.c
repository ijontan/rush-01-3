/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:52:04 by itan              #+#    #+#             */
/*   Updated: 2023/08/11 20:59:45 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_repeat(t_rush01 *rush01, int row, int col, int num)
{
	int	i;

	i = -1;
	while (++i < rush01->size)
		if (rush01->table[row * rush01->size + i] == num)
			return (1);
	i = -1;
	while (++i < rush01->size)
		if (rush01->table[i * rush01->size + col] == num)
			return (1);
	return (0);
}

// val <= size - clue + distance
int	distance_check(t_rush01 *rush01, int row, int col, int num)
{
}