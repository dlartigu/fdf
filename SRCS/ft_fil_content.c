/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fil_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 16:51:11 by jcharrou          #+#    #+#             */
/*   Updated: 2019/07/01 17:25:05 by jcharrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

char		*join_free(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (str);
}

char		*ft_tmp_info(char **av, t_map *fdf)
{
	char	*line;
	char	*tmp;
	int		i;
	int		fd;

	i = 0;
	line = NULL;
	fd = (open(av[1], O_RDONLY));
	while (get_next_line(fd, &line))
	{
		i++;
		ft_strdel(&line);
	}
	close(fd);
	if (!(tmp = (char *)ft_memalloc(sizeof(char) * i)))
		return (NULL);
	fdf->hight = i;
	return (tmp);
}

void		ft_fil_col(char *tmp, t_map *fdf)
{
	int		col;
	int		i;
	int		last_space;

	i = 0;
	col = 0;
	last_space = 1;
	while (tmp[col] != '\n')
	{
		if (tmp[col] == ' ')
		{
			col++;
			last_space = 1;
		}
		else
		{
			col++;
			i += last_space ? 1 : 0;
			last_space = 0;
		}
	}
	fdf->width = i;
}

char		*ft_fil_content(char **av, t_map *fdf)
{
	char	*line;
	char	*tmp;
	int		fd;

	tmp = ft_tmp_info(av, fdf);
	fd = (open(av[1], O_RDONLY));
	while (get_next_line(fd, &line))
	{
		tmp = join_free(tmp, line);
		tmp = join_free(tmp, "\n");
		ft_strdel(&line);
	}
	close(fd);
	ft_strdel(&line);
	ft_fil_col(tmp, fdf);
	return (tmp);
}
