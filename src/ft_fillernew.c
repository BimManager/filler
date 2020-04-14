/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillernew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:16:23 by kkozlov           #+#    #+#             */
/*   Updated: 2020/01/31 20:14:52 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler	*ft_fillernew(void)
{
	t_filler	*filler;
	char		*line;

	filler = malloc(sizeof(t_filler));
	ft_bzero(filler, sizeof(t_filler));
	get_next_line(STDOUT, &line);
	ft_tokensparse(filler, line);
	free(line);
	if (!get_next_line(STDOUT, &line))
	{
		ft_fillerdel(&filler);
		return (NULL);
	}
	ft_sizeparse(filler, line);
	free(line);
	return (filler);
}
