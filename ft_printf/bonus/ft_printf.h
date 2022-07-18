/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:49:25 by makhtar           #+#    #+#             */
/*   Updated: 2021/11/04 11:49:25 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define DEC "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

typedef struct s_flags
{
	int					spec;
	int					zero_pad;
	int					zero_length;
	int					dash;
	long long int		width;
	long long int		data_len;
	int					space;
	int					plus;
	int					hash;
	int					prec;
	long long int		prec_length;
	int					sp_length;
	int					printed_len;
}				t_flags;

size_t				ft_strlen(const char *str);

char				*ft_strdup(const char *s1);

long long int		ft_nbr_len_d(long long int num);
long long int		ft_nbr_len(unsigned long long int num);
long long int		ft_hex_len(unsigned long long int num);

void				ft_putchar(char c, t_flags *flags);
void				print_zero(t_flags *flags);
void				print_space(t_flags *flags);
void				ft_putstr(char *data_s, t_flags *flags);
void				ft_putnbr_base(long long int num, t_flags *flags);
void				ft_putnbr_xp(unsigned long long int num, t_flags *flags);
void				ft_putnbr_unx(unsigned int num, t_flags *flags);
void				ft_flags(t_flags *flags);
void				print_dec(va_list argptr, t_flags *flags);
long long int		plus_flag(long long int num, t_flags *flags);
void				hash_flag(t_flags *flags);
void				print_un_num(unsigned int num, t_flags *flags);
void				print_x(unsigned long long int num, t_flags *flags);
void				print_xp(unsigned long long int num, t_flags *flags);
void				print_uxp(va_list argptr, t_flags *flags);
void				print_diu(va_list argptr, t_flags *flags);
void				print_c(va_list argptr, t_flags *flags);
void				print_strings(va_list argptr, t_flags *flags);
void				work_flags_u1(t_flags *flags);
void				work_precision(t_flags *flags);
void				work_flags_space(t_flags *flags);
void				work_flags(t_flags *flags);
void				work_flags_ps(unsigned long long int num, t_flags *flags);
void				work_flags_pd(unsigned int num, t_flags *flags);
void				work_flags_pdx(unsigned long long int num, t_flags *flags);
void				work_flags_d1(long long int num, t_flags *flags);
void				work_flags_dpn(long long int num, t_flags *flags);
void				dec_sp(long long int num, t_flags *flags);
void				dec_dash(long long int num, t_flags *flags);
void				dec_flags(long long int num, t_flags *flags);
void				work_flags_dec(long long int num, t_flags *flags);
void				work_flags_hex(unsigned long long int num, t_flags *flags);
void				work_flags_xp(unsigned long long int num, t_flags *flags);
void				work_sp_zx(t_flags *flags);
void				work_flags_cs(t_flags *flags);
void				parse_flags1(char **format, t_flags *flags);
void				parse_flags2(char **format, t_flags *flags);
void				parse_precisions(char **format, t_flags *flags);

int					ft_printf(const char *format, ...);

#endif