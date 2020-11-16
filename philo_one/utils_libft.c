/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 00:24:21 by fkathryn          #+#    #+#             */
/*   Updated: 2020/11/16 02:27:05 by fkathryn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int	ft_size(int n)
{
	int size;

	size = 1;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n >= 10)
	{
		size++;
		n /= 10;
	}
	return (size);
}

size_t		ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (*s++ != '\0')
		len++;
	return (len);
}

char		*ft_itoa(long n)
{
	int		i;
	char	*res;

	i = ft_size(n);
	if (!(res = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	res[i--] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n >= 10)
	{
		res[i--] = n % 10 + '0';
		n /= 10;
	}
	res[i] = n + '0';
	return (res);
}

char		*ft_strjoin(char *s1, char *s2, char *s3)
{
	char		*str;
	const int	len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1;
	int			i;

	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	str[i++] = ' ';
	while (*s2)
		str[i++] = *s2++;
	while (*s3)
		str[i++] = *s3++;
	str[i] = '\0';
	return (str);
}

int			ft_atoi(const char *nptr)
{
	int i;
	int n;
	int ng;

	i = 0;
	n = 0;
	ng = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			ng = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
		n = n * 10 + (nptr[i++] - '0');
	return (n * ng);
}
