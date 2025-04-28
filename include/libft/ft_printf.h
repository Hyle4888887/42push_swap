/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:52:02 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/25 16:00:04 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdarg.h>

/*
    Mon printf gère les bool !
*/

int		ft_printf(const char *format, ...);
int		ft_printc(int c, char **str);
int		ft_printi(int nb, char **str);
int		ft_printp(void *ptr, char **str);
int		ft_prints(char *s, char **str);
int		ft_printu(unsigned int nu, char **str);
int		ft_printx(long nb, bool up, char **str);
int		ft_printb(int ibool, char **str);


#endif
