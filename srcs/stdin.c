/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 00:41:29 by yepark            #+#    #+#             */
/*   Updated: 2020/07/22 22:30:07 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strndup_and_concat(char *dest, char *src, int size)
{
	char	*result;
	int		i;
	char	*ptr;

	ptr = dest;
	i = 0;
	if ((result = (char*)malloc(sizeof(char) * (size + 1))) == 0)
		return (0);
	while (i < size && *ptr)
	{
		result[i] = *ptr;
		i++;
		ptr++;
	}
	while (i < size && *src)
	{
		result[i] = *src;
		i++;
		src++;
	}
	result[i] = '\0';
	free(dest);
	return (result);
}

char	*get_stdin(void)
{
	char	*result;
	char	*buff;
	int		read_size;
	int		result_size;

	result_size = 0;
	if ((result = (char*)malloc(sizeof(char) * (1024 + 1))) == 0)
		return (0);
	if ((buff = (char*)malloc(sizeof(char) * (1024 + 1))) == 0)
		return (0);
	while ((read_size = read(0, buff, 1024)) > 0)
	{
		result_size += read_size;
		buff[read_size] = '\0';
		result = ft_strndup_and_concat(result, buff, result_size);
	}
	free(buff);
	return (result);
}
