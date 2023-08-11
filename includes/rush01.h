/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:12:48 by itan              #+#    #+#             */
/*   Updated: 2023/08/11 20:59:56 by itan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <libft.h>

typedef struct val_pos
{
	int		num;
	int		pos;
}			t_val_pos;

typedef struct s_constraint
{
	int		value;
}			t_constraint;

typedef struct s_rush01
{
	int		*table;
	int		*clues;
	t_list	*constraints;
	int		size;
}			t_rush01;

#endif
