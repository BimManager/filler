/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:02:39 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/31 12:17:41 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

extern int	g_fd;

void	filler(void)
{
	t_filler	*filler;
	t_piece		*piece;
	char		buffer[BUFF_SIZE];

	filler = ft_fillernew();
	while (read(STDOUT, buffer, BUFF_SIZE) > 0)
	{
		ft_heatmapupdate(filler);
		ft_heatmaprecalc(filler);
		piece = ft_piecenew();
		ft_pieceplace(filler, piece);
		ft_piecedel(&piece);
	}
	if (filler)
		ft_fillerdel(&filler);
}
