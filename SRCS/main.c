/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:55:21 by jcharrou          #+#    #+#             */
/*   Updated: 2019/07/10 12:13:56 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

int		main(int ac, char **av)
{
	t_map	*fdf;
	char	*str;

	str = "|!| FDF - Team Forains -  ./fdf/";
	if (!(fdf = (t_map*)ft_memalloc(sizeof(t_map))))
		return (0);
	if (ft_valide_file(ac, av, fdf) == 0)
		return (0);
	fdf = ft_int_tab(av, 0, 0, fdf);
	fdf->name = ft_strjoin(str, av[1]);
	ft_main_display(fdf);
	return (0);
}
