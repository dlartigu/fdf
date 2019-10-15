/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorcmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlartigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 16:24:48 by dlartigu          #+#    #+#             */
/*   Updated: 2019/08/16 16:24:49 by dlartigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

void	ft_ctrlaltcmd(int keycode, t_map *fdf)
{
	if (fdf->ctrl == 0 && fdf->alt == 0 && fdf->cmd == 0)
	{
		if (keycode == 18)
			fdf->colorbase1 = COL_DISCO;
		else if (keycode == 19)
			fdf->colorbase1 = COL_BL;
		else if (keycode == 20)
			fdf->colorbase1 = COL_RED;
		else if (keycode == 21)
			fdf->colorbase1 = COL_GREEN;
		else if (keycode == 22)
			fdf->colorbase1 = COL_YELLOW;
		else if (keycode == 23)
			fdf->colorbase1 = COL_ORANGE;
		else if (keycode == 24)
			fdf->colorbase1 = COL_PURPLE;
		else if (keycode == 25)
			fdf->colorbase1 = COL_SUPERNOVA;
		else if (keycode == 26)
			fdf->colorbase1 = COL_PINK;
		else if (keycode == 27)
			fdf->colorbase1 = CL_AZ;
		else if (keycode == 28)
			fdf->colorbase1 = COL_BROWN;
	}
}

void	ft_ctrlcl(int keycode, t_map *fdf)
{
	if (fdf->ctrl == 1)
	{
		if (keycode == 18)
			fdf->color = COL_DISCO;
		else if (keycode == 19)
			fdf->color = COL_BL;
		else if (keycode == 20)
			fdf->color = COL_RED;
		else if (keycode == 21)
			fdf->color = COL_GREEN;
		else if (keycode == 22)
			fdf->color = COL_YELLOW;
		else if (keycode == 23)
			fdf->color = COL_ORANGE;
		else if (keycode == 24)
			fdf->color = COL_PURPLE;
		else if (keycode == 25)
			fdf->color = COL_SUPERNOVA;
		else if (keycode == 26)
			fdf->color = COL_PINK;
		else if (keycode == 27)
			fdf->color = CL_AZ;
		else if (keycode == 28)
			fdf->color = COL_BROWN;
	}
}

void	ft_altcl(int keycode, t_map *fdf)
{
	if (fdf->alt == 1)
	{
		if (keycode == 18)
			fdf->color2 = COL_DISCO;
		else if (keycode == 19)
			fdf->color2 = COL_BL;
		else if (keycode == 20)
			fdf->color2 = COL_RED;
		else if (keycode == 21)
			fdf->color2 = COL_GREEN;
		else if (keycode == 22)
			fdf->color2 = COL_YELLOW;
		else if (keycode == 23)
			fdf->color2 = COL_ORANGE;
		else if (keycode == 24)
			fdf->color2 = COL_PURPLE;
		else if (keycode == 25)
			fdf->color2 = COL_SUPERNOVA;
		else if (keycode == 26)
			fdf->color2 = COL_PINK;
		else if (keycode == 27)
			fdf->color2 = CL_AZ;
		else if (keycode == 28)
			fdf->color2 = COL_BROWN;
	}
}

void	ft_cmdcl(int keycode, t_map *fdf)
{
	if (fdf->cmd == 1)
	{
		if (keycode == 18)
			fdf->color3 = COL_DISCO;
		else if (keycode == 19)
			fdf->color3 = COL_BL;
		else if (keycode == 20)
			fdf->color3 = COL_RED;
		else if (keycode == 21)
			fdf->color3 = COL_GREEN;
		else if (keycode == 22)
			fdf->color3 = COL_YELLOW;
		else if (keycode == 23)
			fdf->color3 = COL_ORANGE;
		else if (keycode == 24)
			fdf->color3 = COL_PURPLE;
		else if (keycode == 25)
			fdf->color3 = COL_SUPERNOVA;
		else if (keycode == 26)
			fdf->color3 = COL_PINK;
		else if (keycode == 27)
			fdf->color3 = CL_AZ;
		else if (keycode == 28)
			fdf->color3 = COL_BROWN;
	}
}
