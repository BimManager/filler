/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbsparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:46:08 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/31 10:18:07 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_nbsparse(const char *line, int *a, int *b)
{
	while (*line && !ft_isdigit(*line))
		++line;
	*a = ft_strtol(line, 10);
	while (*line && ft_isdigit(*line))
		++line;
	*b = ft_strtol(line, 10);
}
