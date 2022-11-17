/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:00:31 by berard            #+#    #+#             */
/*   Updated: 2022/11/17 18:04:15 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_new_stash(char *stash)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[i] != '\0' || stash[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (str == NULL)
		return (NULL);
	while (stash[i] != '\0')
	{
		str[j] = stash[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

static char	*ft_extract_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[i] != '\0' || stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*ft_fill_stash(int fd, char *stash)
{
	char	*buffy;
	int		byties;

	byties = 1;
	buffy = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffy == NULL)
		return (NULL);
	while (byties != 0 || ft_strchr(stash, '\n') == NULL)
	{
		byties = read(fd, buffy, BUFFER_SIZE);
		if (byties == -1)
		{
			free(buffy);
			return (NULL);
		}
		buffy[byties] = '\0';
		// if (stash == NULL)
		// 	stash = buffy;
		// else
		stash = ft_strjoin(stash, buffy);
	}
	free(buffy);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	stash = ft_fill_stash(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = ft_extract_line(stash);
	stash = ft_new_stash(stash);
	return (line);
	// return (stash); // Pour faire des tests
}

// int	main(void)
// {
// 	int	fd = open("test.txt", O_RDONLY);
// 	printf("Ceci est la stash : \n %s \n", get_next_line(fd));
// 	printf("Ceci est la first line :\n %s\n", get_next_line(fd));
// 	printf("Ceci est la second line :\n %s\n", get_next_line(fd));
// 	printf("Ceci est la third line :\n %s\n", get_next_line(fd));
// 	return (0);
// }
