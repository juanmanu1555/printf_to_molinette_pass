/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:21:36 by jcorral-          #+#    #+#             */
/*   Updated: 2020/01/15 14:44:20 by jcorral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		j;

	j = ft_strlen(s);
	while (j >= 0)
	{
		if (s[j] == (char)c)
			return ((char *)s + j);
		j--;
	}
	return (NULL);
}
