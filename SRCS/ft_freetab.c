/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:33:25 by dlartigu          #+#    #+#             */
/*   Updated: 2019/07/18 14:33:27 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	ft_freetab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_memdel((void **)&(tab[i]));
		i++;
	}
	ft_memdel((void **)&(tab));
}