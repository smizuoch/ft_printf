/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:39:49 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/14 18:48:14 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	printnbr_bighex(unsigned int p, int *printf_len)
{
	char	c;

	if (p >= 16)
	{
		printnbr_bighex(p / 16, printf_len);
		printnbr_bighex(p % 16, printf_len);
	}
	else
	{
		if (p < 10)
			c = ('0' + p);
		else
			c = ('A' + p - 10);
		if (write (1, &c, 1) == -1)
		{
			*printf_len = -1;
			return ;
		}
		*printf_len += 1;
	}
}

void	printnbr_hexp(unsigned long p, int *printf_len)
{
	char	c;

	if (p >= 16)
	{
		printnbr_hexp(p / 16, printf_len);
		printnbr_hexp(p % 16, printf_len);
	}
	else
	{
		if (p < 10)
			c = ('0' + p);
		else
			c = ('a' + p - 10);
		if (write (1, &c, 1) == -1)
		{
			*printf_len = -1;
			return ;
		}
		*printf_len += 1;
	}
}

void	ft_printchar(int c, int	*printf_len)
{
	if (write (1, &c, 1) == -1)
	{
		*printf_len = -1;
		return ;
	}
	*printf_len += 1;
}
