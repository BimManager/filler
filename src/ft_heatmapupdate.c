/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heatmapupdate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 09:57:01 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/31 20:15:12 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_heatmapupdate(t_filler *filler)
{
	char	*line;
	char	*space_p;
	int		i;
	int		j;

	i = 0;
	while (i < filler->rows)
	{
		get_next_line(STDOUT, &line);
		if (ft_isdigit(*line) && (space_p = ft_strchr(line, ' ')) && ++space_p)
		{
			j = -1;
			while (*(space_p + ++j))
			{
				if (filler->mytoken == *(space_p + j))
					filler->heatmap[i][j] = -2;
				else if (filler->optoken == *(space_p + j))
					filler->heatmap[i][j] = 1;
				else
					filler->heatmap[i][j] = 0;
			}
			++i;
		}
		free(line);
	}
}
