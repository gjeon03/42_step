/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:18:36 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/15 13:36:25 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*copy;
	int		ssz;
	int		n;

	if (!str)
		return (NULL);
	ssz = ft_strlen(str);
	if (!(copy = malloc(sizeof(char) * (ssz + 1))))
		return (NULL);
	n = 0;
	while (*str)
		copy[n++] = *str++;
	copy[n] = '\0';
	return (copy);
}
