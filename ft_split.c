/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trischma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:09:30 by trischma          #+#    #+#             */
/*   Updated: 2024/05/15 13:09:48 by trischma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_segments(const char *s, char c)
{
	size_t	count;
	int		in_segment;

	count = 0;
	in_segment = 0;
	while (*s)
	{
		if (*s != c && !in_segment)
		{
			in_segment = 1;
			count++;
		}
		else if (*s == c)
		{
			in_segment = 0;
		}
		s++;
	}
	return (count);
}

static char	*copy_segment(const char *start, size_t len)
{
	char	*segment;
	size_t	i;

	segment = (char *)malloc((len + 1) * sizeof(char));
	if (!segment)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		segment[i] = start[i];
		i++;
	}
	segment[len] = '\0';
	return (segment);
}

static void	free_segments(char **segments, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(segments[i]);
		i++;
	}
	free(segments);
}

static char	**allocate_segments(char const *s, char c, size_t segment_count)
{
	char	**segments;
	size_t	i;
	size_t	len;

	segments = (char **)malloc((segment_count + 1) * sizeof(char *));
	if (!segments)
	{
		return (NULL);
	}
	i = 0;
	while (*s && i < segment_count)
	{
		while (*s == c)
		{
			s++;
		}
		len = 0;
		while (s[len] && s[len] != c)
		{
			len++;
		}
		segments[i] = copy_segment(s, len);
		if (!segments[i])
		{
			free_segments(segments, i);
			return (NULL);
		}
		s += len;
		i++;
	}
	segments[i] = NULL;
	return (segments);
}

char	**ft_split(char const *s, char c)
{
	size_t	segment_count;

	if (!s)
	{
		return (NULL);
	}
	segment_count = count_segments(s, c);
	return (allocate_segments(s, c, segment_count));
}
