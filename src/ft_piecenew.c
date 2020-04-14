/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piecenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:33:28 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/01 09:52:46 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

extern int	g_fd;

t_piece	*ft_piecenew(void)
{
	char	*line;
	t_piece	*piece;
	int		i;

	piece = malloc(sizeof(t_piece));
	get_next_line(STDOUT, &line);
	ft_nbsparse(line, &piece->rows, &piece->cols);
	free(line);
	i = -1;
	piece->shape = malloc(piece->rows * sizeof(void *));
	while (++i < piece->rows)
	{
		get_next_line(STDOUT, &line);
		piece->shape[i] = line;
	}
	return (piece);
}
