/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgur <mgur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:20:02 by mgur              #+#    #+#             */
/*   Updated: 2022/10/20 15:00:26 by mgur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_char_set(char a, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		first;
	int		last;
	char	*result;

	first = 0;
	last = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[first] && is_char_set(s1[first], set))
		first++;
	if (s1[first] == '\0')
	{
		result = ft_strdup("");
		return (result);
	}
	last = ft_strlen(s1) - 1;
	while (s1[last] >= 0 && is_char_set(s1[last], set))
		last--;
	last = last - first + 1;
	result = ft_substr(s1, first, last);
	return (result);
}
