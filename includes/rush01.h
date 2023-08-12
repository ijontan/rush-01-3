/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:12:48 by itan              #+#    #+#             */
/*   Updated: 2023/08/12 23:17:25 by itan             ###   ########.fr       */
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

/* ---------------------------------- rule ---------------------------------- */
int			check_repeat(t_rush01 *rush01, int row, int col, int num);
int			distance_check(t_rush01 *rush01, int row, int col, int num);
int			get_possible(t_rush01 *rush01, int row, int col, int num);

int			vc_top(t_rush01 *rush01, int col);
int			vc_bottom(t_rush01 *rush01, int col);
int			vc_left(t_rush01 *rush01, int row);
int			vc_right(t_rush01 *rush01, int row);

/* ---------------------------------- utils --------------------------------- */
void		ft_free_2d(char **arr);
int			get_pos(int row, int col, int size);
int			get_clue(int row, int col, int opt, t_rush01 *rush01);

#endif
