/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heatmaprecalc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 09:59:25 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/31 20:15:20 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	heatup(t_filler *f, int i, int r, int c)
{
	if (c + 1 < f->cols && f->heatmap[r][c + 1] == i)
		f->heatmap[r][c] = i + 1;
	if (c - 1 >= 0 && f->heatmap[r][c - 1] == i)
		f->heatmap[r][c] = i + 1;
	if (r + 1 < f->rows && f->heatmap[r + 1][c] == i)
		f->heatmap[r][c] = i + 1;
	if (r - 1 >= 0 && f->heatmap[r - 1][c] == i)
		f->heatmap[r][c] = i + 1;
	if (r - 1 >= 0 && c - 1 >= 0 && f->heatmap[r - 1][c - 1] == i)
		f->heatmap[r][c] = i + 1;
	if (r + 1 < f->rows && c + 1 < f->cols && f->heatmap[r + 1][c + 1] == i)
		f->heatmap[r][c] = i + 1;
	if (r + 1 < f->rows && c - 1 >= 0 && f->heatmap[r + 1][c - 1] == i)
		f->heatmap[r][c] = i + 1;
	if (r - 1 >= 0 && c + 1 < f->cols && f->heatmap[r - 1][c + 1] == i)
		f->heatmap[r][c] = i + 1;
}

void		ft_heatmaprecalc(t_filler *filler)
{
	int	r;
	int	c;
	int	i;

	i = 0;
	while (++i < filler->cols)
	{
		r = -1;
		while (++r < filler->rows)
		{
			c = -1;
			while (++c < filler->cols)
				if (0 == filler->heatmap[r][c])
					heatup(filler, i, r, c);
		}
	}
}
