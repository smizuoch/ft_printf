/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:12:11 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/14 18:50:34 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_printstring(char *str, int *printf_len)
{
	if (!str)
	{
		if (write (1, "(null)", 6) == -1)
		{
			*printf_len = -1;
			return ;
		}
		*printf_len += 6;
	}
	else
	{
		if (write (1, str, ft_strlen(str)) == -1)
		{
			*printf_len = -1;
			return ;
		}
		*printf_len += ft_strlen(str);
	}
}

void	printnbr_hex(unsigned int p, int *printf_len)
{
	char	c;

	if (p >= 16)
	{
		printnbr_hex(p / 16, printf_len);
		printnbr_hex(p % 16, printf_len);
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

void	ft_printvoid(void *p, int *printf_len)
{
	unsigned long	num;

	num = (uintptr_t)p;
	if (write (1, "0x", 2) == -1)
	{
		*printf_len = -1;
		return ;
	}
	*printf_len += 2;
	printnbr_hexp(num, printf_len);
}

void	ft_printnbr(int n, int *printf_len)
{
	long long	num;
	char		c;

	num = n;
	if (num < 0)
	{
		num *= -1;
		if (write (1, "-", 1) == -1)
		{
			*printf_len = -1;
			return ;
		}
		*printf_len += 1;
	}
	if (num / 10 > 0)
	{
		ft_printnbr(num / 10, printf_len);
		c = num % 10 + '0';
		ft_printchar(c, printf_len);
	}
	else
	{
		c = num % 10 + '0';
		ft_printchar(c, printf_len);
	}
}

void	ft_printnbru(unsigned int num, int *printf_len)
{
	char	c;

	if (num / 10 > 0)
	{
		ft_printnbr(num / 10, printf_len);
		c = num % 10 + '0';
		ft_printchar(c, printf_len);
	}
	else
	{
		c = num % 10 + '0';
		ft_printchar(c, printf_len);
	}
}
