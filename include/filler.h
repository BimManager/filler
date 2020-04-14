/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:41:41 by kkozlov           #+#    #+#             */
/*   Updated: 2020/02/07 20:05:47 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define TRACE	"./kkozlov.filler.trace"

typedef struct	s_piece
{
	int			rows;
	int			cols;
	char		**shape;
}				t_piece;

typedef struct	s_filler
{
	char		mytoken;
	char		optoken;
	int			rows;
	int			cols;
	int			**heatmap;
}				t_filler;

typedef struct	s_ply
{
	int			row;
	int			col;
}				t_ply;

void			filler(void);
t_filler		*ft_fillernew(void);
void			ft_fillerdel(t_filler **filler);

void			ft_nbsparse(const char *line, int *a, int *b);
void			ft_tokensparse(t_filler *filler, const char *line);
void			ft_sizeparse(t_filler *filler, const char *line);

void			ft_heatmapupdate(t_filler *filler);
void			ft_heatmaprecalc(t_filler *filler);
void			ft_heatmapput(int fd, t_filler *filler);

t_piece			*ft_piecenew(void);
void			ft_piecedel(t_piece **piece);
void			ft_pieceplace(t_filler *filler, t_piece *piece);

#endif
