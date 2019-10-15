/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valide_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:09:58 by jcharrou          #+#    #+#             */
/*   Updated: 2019/07/02 10:29:53 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

int			ft_check_params(int ac)
{
	if (ac != 2)
	{
		ft_putendl_fd("Usage : ./fdf <filename> [ case_size z_size ]", 2);
		return (-1);
	}
	return (1);
}

int			ft_check_content(char **av)
{
	int		ret;
	int		fd;
	char	*line;

	line = NULL;
	fd = (open(av[1], O_RDONLY));
	ret = get_next_line(fd, &line);
	if (ret == -1)
	{
		ft_putendl_fd("No content", 2);
		ft_strdel(&line);
		return (-1);
	}
	ft_strdel(&line);
	while (get_next_line(fd, &line))
		ft_strdel(&line);
	if ((close(fd)) == -1)
	{
		ft_strdel(&line);
		return (-1);
	}
	return (1);
}

int			ft_check_data2(char *tmp)
{
	int		i;
	int		digit;

	i = 0;
	digit = 0;
	while (tmp[i])
	{
		if (ft_isdigit(tmp[i]) == 1)
			digit = 1;
		i++;
	}
	if (digit == 0)
		return (0);
	return (1);
}

int			ft_check_data(char *tmp)
{
	int		i;

	if (ft_check_data2(tmp) == 0)
	{
		ft_putendl_fd("wrong type of datas", 2);
		ft_strdel(&tmp);
		return (-1);
	}
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] != ' ' && tmp[i] != '\n' && tmp[i] != '\0'
			&& tmp[i] != '-' && ft_isdigit(tmp[i]) != 1)
		{
			ft_putendl_fd("wrong type of datas", 2);
			ft_strdel(&tmp);
			return (-1);
		}
		i++;
	}
	ft_strdel(&tmp);
	return (1);
}

int			ft_valide_file(int ac, char **av, t_map *fdf)
{
	int		i;

	i = 0;
	fdf->cmp = "fdf.";
	if (ft_check_params(ac) == -1)
		return (0);
	av[1] = ft_strrev(av[1]);
	while (i < 4)
	{
		if (av[1][i] != fdf->cmp[i])
		{
			ft_memdel((void **)&(fdf));
			ft_putendl_fd("wrong type of datas", 2);
			return (0);
		}
		i++;
	}
	av[1] = ft_strrev(av[1]);
	if (ft_check_content(av) == -1
		|| ft_check_data(ft_fil_content(av, fdf)) == -1)
	{
		ft_memdel((void **)&(fdf));
		return (0);
	}
	return (1);
}
