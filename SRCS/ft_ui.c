/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:46:53 by dlartigu          #+#    #+#             */
/*   Updated: 2019/07/18 10:46:55 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	ft_move(int keycode, t_map *fdf)
{
	if (keycode == 0)
		fdf->move_x = fdf->move_x - 5;
	else if (keycode == 2)
		fdf->move_x = fdf->move_x + 5;
	else if (keycode == 13)
		fdf->move_y = fdf->move_y - 5;
	else if (keycode == 1)
		fdf->move_y = fdf->move_y + 5;
}

void	ft_zd(int keycode, t_map *fdf)
{
	if (keycode == 91)
		fdf->deep = fdf->deep + 0.5;
	else if (keycode == 87)
		fdf->deep = fdf->deep - 0.5;
	else if (keycode == 12)
		fdf->zoom = fdf->zoom - 2;
	else if (keycode == 14)
		fdf->zoom = fdf->zoom + 2;
}

void	ft_color(int keycode, t_map *fdf)
{
	ft_ctrlaltcmd(keycode, fdf);
	ft_ctrlcl(keycode, fdf);
	ft_altcl(keycode, fdf);
	ft_cmdcl(keycode, fdf);
}
