/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:58:14 by dlartigu          #+#    #+#             */
/*   Updated: 2019/07/08 15:00:47 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

char		**ft_create_tab(char **av, t_map *fdf)
{
	char	*str;
	char	**tab;

	str = ft_fil_content(av, fdf);
	tab = ft_strsplit(str, '\n');
	ft_strdel(&str);
	return (tab);
}

int			**ft_intalloc(int **map, int i, int j)
{
	int		k;

	k = 0;
	if (!(map = (int **)ft_memalloc(sizeof(int *) * i)))
		return (0);
	while (k < i)
	{
		if (!(map[k] = (int *)ft_memalloc(sizeof(int ) * j)))
			return (0);
		k++;
	}
	return (map);
}

void		ft_int_map(char **tab, int i, int j, t_map *fdf)
{
	char	**tab_nb;

	while (tab[i])
	{
		j = 0;
		tab_nb = ft_strsplit(tab[i], ' ');
		while (tab_nb[j])
		{
			fdf->map[i][j] = ft_atol(tab_nb[j]);
			if (fdf->map[i][j] > fdf->maxcolor)
				fdf->maxcolor = fdf->map[i][j];
			else if (fdf->map[i][j] < fdf->mincolor)
				fdf->mincolor = fdf->map[i][j];
			j++;
		}
		if (j > fdf->width || j < fdf->width)
			fdf->error = 1;
		ft_freetab(tab_nb);
		i++;
	}
	ft_freetab(tab);
}

t_map		*ft_int_tab(char **av, int i, int j, t_map *fdf)
{
	char	**tab;
	int		**map;

	tab = ft_create_tab(av, fdf);
	map = NULL;
	fdf->map = ft_intalloc(map, fdf->hight, fdf->width);
	ft_int_map(tab, i, j, fdf);
	return (fdf);
}
