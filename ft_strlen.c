/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:51:24 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/14 18:04:48 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c])
	{
		c ++;
	}
	return (c);
}
