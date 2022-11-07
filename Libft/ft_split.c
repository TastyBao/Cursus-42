/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:12:17 by berard            #+#    #+#             */
/*   Updated: 2022/11/07 10:02:17 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (j);
		while (s[i] != c && s[i] != '\0')
			i++;
		j++;
		while (s[i] == c)
			i++;
	}
	return (j);
}

static int	ft_wordlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	return (i);
}

static char	*ft_strndup(const char *s, int n)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(char) * (n + 1));
	if (ptr == NULL)
		return (NULL);
	while (i < n)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static void	ft_initiate_vars(int *i, int *j)
{
	*i = -1;
	*j = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;

	ft_initiate_vars(&i, &j);
	ptr = malloc(sizeof(char **) * (ft_countword(s, c) + 1));
	if (ptr == 0)
		return (NULL);
	while (s[++i] != '\0')
	{
		if (s[i] != c)
		{
			ptr[j] = ft_strndup(&s[i], ft_wordlen(&s[i], c));
			if (ptr[j] == NULL)
			{
				while (j > 0)
					free(ptr[--j]);
				free(ptr);
				return (NULL);
			}
			i += ft_strlen(ptr[j++]) - 1;
		}
	}
	ptr[j] = (NULL);
	return (ptr);
}

// int	main(void)
// {
// 	char	tab[] = "       olol";
// 	char	c = ' ';

// 	printf("%s", ft_split(tab, c));
// 	return (0);
// }

// int	main(void)
// {
// 	char	*tab = "                  olol";
// 	char	c = ' ';

// 	printf("%d", ft_countword(tab, c));
// 	return (0);
// }

// int	main(void)
// {
// 	char	*tab = "ggggggggggg";
// 	char	c = 'g';

// 	printf("%s", ft_split(tab, c)[0]);
// 	printf("%s", ft_split(tab, c)[0]);
// 	printf("\n\n");

// 	printf("%s", ft_split(tab, c)[0]);

// 	return (0);
// }
