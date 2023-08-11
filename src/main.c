/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:32:06 by itan              #+#    #+#             */
/*   Updated: 2023/08/11 20:52:10 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int ac, char const **av)
{
	t_rush01	rush01;

	if (ac != 2)
		return (0);
	if (!parser((char *)av[1], &rush01))
		return (0);
	free(rush01.table);
	free(rush01.clues);
	ft_lstclear(&(rush01.constraints), free);
	return (0);
}
