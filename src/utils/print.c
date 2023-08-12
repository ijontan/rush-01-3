/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 00:02:43 by itan              #+#    #+#             */
/*   Updated: 2023/08/13 00:21:15 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	print_line_clue(t_rush01 *rush01, int opt)
{
	int	i;

	i = -1;
	ft_putchar_fd(' ', 1);
	ft_putchar_fd(' ', 1);
	while (++i < rush01->size)
	{
		ft_putnbr_fd(rush01->clues[rush01->size * opt + i], 1);
		ft_putchar_fd(' ', 1);
	}
	ft_putchar_fd('\n', 1);
}

void	print_board(t_rush01 *rush01)
{
	int	i;

	print_line_clue(rush01, 0);
	i = -1;
	while (++i < rush01->size * rush01->size)
	{
		if (i % rush01->size == 0)
		{
			ft_putnbr_fd(rush01->clues[rush01->size * 2 + i / rush01->size], 1);
			ft_putchar_fd(' ', 1);
		}
		ft_putnbr_fd(rush01->table[i], 1);
		ft_putchar_fd(' ', 1);
		if (i % rush01->size == rush01->size - 1)
		{
			ft_putnbr_fd(rush01->clues[rush01->size * 3 + i / rush01->size], 1);
			ft_putchar_fd('\n', 1);
		}
	}
	print_line_clue(rush01, 1);
}
