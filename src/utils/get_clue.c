/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_clue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 23:13:17 by itan              #+#    #+#             */
/*   Updated: 2023/08/12 23:15:36 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	get_clue(int row, int col, int opt, t_rush01 *rush01)
{
	if (opt == 0)
		return (rush01->clues[col]);
	if (opt == 1)
		return (rush01->clues[rush01->size + col]);
	if (opt == 2)
		return (rush01->clues[rush01->size * 2 + row]);
	if (opt == 3)
		return (rush01->clues[rush01->size * 3 + row]);
	return (0);
}
