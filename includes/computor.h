/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:39:06 by kwiessle          #+#    #+#             */
/*   Updated: 2017/11/25 18:25:16 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H

# include "define.h"
# include "libft.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

/* ERROR */

void    display_error(short e_type);
short   allowed_degree(char degree);
short   allowed_format(char c);
short   check_argument(char *equation);
short   check_format(char *equation);

/* MATH */

double ft_sqrt(double n);
double  get_discriminent(double a, double b, double c);
double  natural_sqrt_root_1(double a, double b, double delta);
double  natural_sqrt_root_2(double a, double b, double delta);
double  natural_sqrt_root_3(double a, double b);
char    *complex_sqrt_root_1(double a, double b, double delta);
char    *complex_sqrt_root_2(double a, double b, double delta);
double  ft_double_abs(double n);
/* PARSER */

char  *super_trim(char *str);
char  *fix(char *str);
double   get_coeff(char *equation_trimed, char degree);

#endif
