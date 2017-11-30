/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:39:06 by kwiessle          #+#    #+#             */
/*   Updated: 2017/11/30 11:56:04 by vquesnel         ###   ########.fr       */
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

void      display_error(short e_type);
short     allowed_degree(char degree);
short     allowed_format(char c);
short     check_argument(char *equation);
short     check_format(char *equation);

/* MATH */

double    ft_sqrt(double n);
double    get_discriminent(double a, double b, double c);
char      *natural_sqrt_root(double a, double b, double delta, char sign);
char      *natural_sqrt_root_3(double a, double b);
char      *complex_sqrt_root(double a, double b, double delta, char sign);
double    ft_double_abs(double n);
double    pgcd(int nb1, int nb2);
/* PARSER */

char      *super_trim(char *str);
char      *fix(char *str);
double    get_coeff(char *equation_trimed, int degree);
int       get_max_pow(char *equation_trimed);
char      *minimize(char *str);
/* PRINT */

void      print_discriminent(double a, double b, double c);
void      print_natural_sqrt(double a, double b, double delta, char sign);
void      print_one_sqrt(double a, double b);
void      print_complex_sqrt(double a, double b, double delta, char sign);
void      print_reduced_form(int max_pow, double *coefs);
int       print_exceptions(int max_pow, double *coefs);
void      print_solutions(double *coefs);
#endif
