/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pieceplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:38:56 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/31 20:11:24 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

extern int	g_fd;

static void	pieceadjust(t_piece *piece, int *rct)
{
	int	i;
	int	j;

	i = -1;
	while (++i < piece->rows)
	{
		j = -1;
		while (++j < piece->cols)
			if ('*' == piece->shape[i][j])
			{
				rct[0] = -i - 1;
				rct[1] = -j - 1;
				rct[2] = rct[1];
				return ;
			}
	}
}

static int	piece_isplaceable(t_filler *filler, t_piece *piece,
								int row, int col)
{
	int	i;
	int	j;
	int	n_match;

	i = -1;
	n_match = 0;
	while (++i < piece->rows)
	{
		j = -1;
		while (++j < piece->cols)
		{
			if ('.' == piece->shape[i][j])
				continue ;
			else if ((row + i) >= filler->rows || (col + j) >= filler->cols
					|| (row + i) < 0 || (col + j) < 0)
				return (0);
			else if (1 == filler->heatmap[row + i][col + j])
				return (0);
			if (-2 == filler->heatmap[row + i][col + j])
				if (1 < ++n_match)
					return (0);
		}
	}
	return (1 == n_match ? 1 : 0);
}

static int	scorecalc(t_filler *filler, t_piece *piece, int row, int col)
{
	int	r;
	int	c;
	int	score;

	score = 0;
	r = -1;
	while (++r < piece->rows)
	{
		c = -1;
		while (++c < piece->cols)
		{
			if ('.' == piece->shape[r][c])
				continue ;
			else if (0 < filler->heatmap[row + r][col + c])
				score += filler->heatmap[row + r][col + c];
		}
	}
	return (score);
}

void		ft_pieceplace(t_filler *filler, t_piece *piece)
{
	static t_ply	ply;
	int				min;
	int				cur;
	int				rct[3];

	min = INT_MAX;
	pieceadjust(piece, rct);
	while (++rct[0] < filler->rows)
	{
		rct[1] = rct[2];
		while (++rct[1] < filler->cols)
		{
			if (piece_isplaceable(filler, piece, rct[0], rct[1]))
				if (min > ((cur = scorecalc(filler, piece, rct[0], rct[1]))))
				{
					ply.row = rct[0];
					ply.col = rct[1];
					min = cur;
				}
		}
	}
	if (!piece_isplaceable(filler, piece, ply.row, ply.col))
		ft_printf("%d %d\n", 0, 0);
	ft_printf("%d %d\n", ply.row, ply.col);
}
