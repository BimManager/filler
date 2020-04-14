/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillerdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:17:36 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/31 12:07:17 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_fillerdel(t_filler **filler)
{
	int	i;

	if ((*filler)->heatmap)
	{
		i = -1;
		while (++i < (*filler)->rows)
			free((*filler)->heatmap[i]);
		free((*filler)->heatmap);
	}
	free(*filler);
	*filler = NULL;
}
