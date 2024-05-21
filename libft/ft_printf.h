/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paribeir <paribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:32:12 by paribeir          #+#    #+#             */
/*   Updated: 2024/02/02 13:20:35 by paribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft.h"

# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# define FL "-+ 0#."
# define P "0x"
# define U "0X"

typedef struct flag {
	int	plus;
	int	space;
	int	hashtag;
	int	minus;
	int	zero;
	int	precision;
	int	min_width;
	int	negative;
	int	percent;
}	t_flags;

char	*ft_hex(unsigned long long nbr, char *base);
int		ft_if(t_flags *flag);
int		ft_putnbr_base(uintptr_t nbr, char *base);
int		ft_setflags(char *str, t_flags *flag);
int		ft_printf(const char *str, ...);
int		ft_mapping(char c, t_flags *flag, va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_print_char(int n, t_flags *flag);
int		ft_print_string(char *s, t_flags *flag);
int		ft_print_pointer(void *ptr, t_flags *flag);
int		ft_print_int(int n, t_flags *flag);
int		ft_zero(char *n, t_flags *flag);
int		ft_width(char *n, t_flags *flag);
int		ft_precision(char *n, t_flags *flag);
int		ft_sign(t_flags *flag);
int		ft_minus(char *n, t_flags *flag);
int		ft_print_unsigned(unsigned int n, t_flags *flag);
int		ft_print_hexlow(unsigned int n, t_flags *flag);
int		ft_print_hexup(unsigned int n, t_flags *flag);

//similar to libft functions
int		ft_isdigit_int(int c);
int		ft_strlen_int(const char *str);
int		ft_strlcpy_int(char *dest, const char *src, int dest_size);
char	*ft_itoa_printf(long n);

#endif
