/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeparse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 09:55:22 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/31 20:14:39 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_sizeparse(t_filler *filler, const char *line)
{
	int		i;
	size_t	n_bytes;

	ft_nbsparse(line, &filler->rows, &filler->cols);
	filler->heatmap = malloc(filler->rows * sizeof(void *));
	i = -1;
	n_bytes = filler->cols * sizeof(int);
	while (++i < filler->rows)
	{
		filler->heatmap[i] = malloc(n_bytes);
		ft_bzero(filler->heatmap[i], n_bytes);
	}
}
