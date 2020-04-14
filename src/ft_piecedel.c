/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piecedel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:52:16 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/31 10:11:14 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_piecedel(t_piece **piece)
{
	int	i;

	i = -1;
	while (++i < (*piece)->rows)
		free((*piece)->shape[i]);
	free((*piece)->shape);
	free(*piece);
	*piece = NULL;
}
