/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:26:16 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/14 18:48:24 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include<unistd.h>
# include<stdio.h>

int		ft_printf(const char *str, ...);
void	ft_printstring(char *str, int *printf_len);
void	ft_printvoid(void *p, int *printf_len);
void	ft_printnbr(int n, int *printf_len);
void	ft_printnbru(unsigned int num, int *printf_len);
void	printnbr_hex(unsigned int p, int *printf_len);
void	printnbr_bighex(unsigned int p, int *printf_len);
void	printnbr_hexp(unsigned long p, int *printf_len);
void	ft_printchar(int c, int	*printf_len);

size_t	ft_strlen(const char *s);

#endif