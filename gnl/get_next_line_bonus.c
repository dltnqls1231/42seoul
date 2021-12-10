/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:28:47 by sublee            #+#    #+#             */
/*   Updated: 2021/02/19 11:11:19 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		newline_idx(char *backup)
{
	int		idx;

	if (backup == 0 || *backup == 0)
		return (-1);
	idx = 0;
	while (backup[idx])
	{
		if (backup[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

int		split_line(char **backup, char **line, int newline_idx)
{
	char	*tmp;

	(*backup)[newline_idx] = '\0';
	*line = ft_strdup(*backup);
	tmp = ft_strdup(*backup + newline_idx + 1);
	free(*backup);
	*backup = tmp;
	return (1);
}

int		last_line(char **backup, char **line)
{
	if (*backup == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	*line = ft_strdup(*backup);
	free(*backup);
	*backup = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	int			line_size;
	int			nl_idx;
	char		*tmp;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	if ((nl_idx = newline_idx(backup[fd])) >= 0)
		return (split_line(&backup[fd], line, nl_idx));
	while ((line_size = read(fd, buffer, BUFFER_SIZE)) >= 0)
	{
		if (line_size == 0)
			return (last_line(&backup[fd], line));
		buffer[line_size] = '\0';
		tmp = ft_strjoin(backup[fd], buffer);
		if (backup[fd])
			free(backup[fd]);
		backup[fd] = tmp;
		if ((nl_idx = newline_idx(backup[fd])) >= 0)
			return (split_line(&backup[fd], line, nl_idx));
	}
	return (-1);
}
