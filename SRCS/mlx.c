/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:11:05 by dlartigu          #+#    #+#             */
/*   Updated: 2019/07/15 13:11:09 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	ft_clear_fdf(t_map *fdf)
{
	int		i;

	i = 0;
	while (i < fdf->hight)
	{
		ft_memdel((void **)&(fdf->map[i]));
		i++;
	}
	ft_memdel((void **)&(fdf->map));
	ft_memdel((void **)&(fdf->name));
	ft_memdel((void **)&(fdf));
}

int		ft_mod(int keycode, t_map *fdf)
{
	ft_tooglemenu(keycode, fdf);
	if (keycode == 53)
		ft_exit(fdf);
	else if (keycode == 35)
		fdf->view = fdf->view == 1 ? 2 : 1;
	else if (keycode == 91 || keycode == 87
		|| keycode == 12 || keycode == 14)
		ft_zd(keycode, fdf);
	else if (keycode == 86)
		fdf->rotate = fdf->rotate + 0.1;
	else if (keycode == 88)
		fdf->rotate = fdf->rotate - 0.1;
	else if (keycode == 0 || keycode == 2
		|| keycode == 13 || keycode == 1)
		ft_move(keycode, fdf);
	else if (keycode >= 18 && keycode <= 29)
		ft_color(keycode, fdf);
	else
		return (0);
	mlx_clear_window(fdf->mlx_ptr, fdf->window_ptr);
	ft_draw(fdf);
	return (1);
}

void	ft_menu(t_map *fdf)
{
	ft_menufull(fdf);
	mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
		fdf->win_width - 350, 30, COL_WH, "Press 'R' for Auto Repeat:");
	if (fdf->hook == 0)
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			fdf->win_width - 80, 30, COL_RED, "OFF");
	if (fdf->hook == 1)
		mlx_string_put(fdf->mlx_ptr, fdf->window_ptr,
			fdf->win_width - 80, 30, COL_GREEN, "ON");
}

int		ft_exit(t_map *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->window_ptr);
	mlx_destroy_window(fdf->mlx_ptr, fdf->window_ptr);
	ft_clear_fdf(fdf);
	exit(0);
	return (0);
}
