/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:32:06 by itan              #+#    #+#             */
/*   Updated: 2023/08/13 00:22:10 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	free_constraint(void *content)
{
	free(content);
}

void	rush01_init(t_rush01 *rush01)
{
	rush01->constraints = NULL;
}

int	main(int ac, char const **av)
{
	t_rush01	rush01;

	if (ac != 2)
		return (0);
	ft_printf("Input:\n%s\n\n", av[1]);
	rush01_init(&rush01);
	if (!parser((char *)av[1], &rush01))
		return (0);
	ft_printf("Output:\n");
	print_board(&rush01);
	free(rush01.table);
	free(rush01.clues);
	if (rush01.constraints)
		ft_lstclear(&(rush01.constraints), free_constraint);
	return (0);
}
