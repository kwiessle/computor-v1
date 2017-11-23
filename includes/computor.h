/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:39:06 by kwiessle          #+#    #+#             */
/*   Updated: 2017/11/23 23:38:52 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H

# include "define.h"
# include <math.h>
# include <stdio.h>

/* PARSING */

void    display_error(short e_type);
short   allowed_degree(char degree);
short   allowed_format(char c);
short   check_argument(char *equation);
short   check_format(char *equation);

/* MATH */

double  get_discriminent(double a, double b, double c);
char    *natural_sqrt_root_1(double a, double b, double delta);
char    *natural_sqrt_root_2(double a, double b, double delta);
char    *natural_sqrt_root_3(double a, double b);
char    *complex_sqrt_root_1(double a, double b, double delta);
char    *complex_sqrt_root_2(double a, double b, double delta);

#endif
