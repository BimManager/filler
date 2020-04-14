/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokensparse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 09:54:49 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/31 20:14:33 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_tokensparse(t_filler *filler, const char *line)
{
	const char	*num_p;

	if ((num_p = ft_strchr(line, 'p')))
	{
		filler->mytoken = '1' == *++num_p ? 'O' : 'X';
		filler->optoken = '1' == *num_p ? 'X' : 'O';
	}
}
