/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:39:06 by kwiessle          #+#    #+#             */
/*   Updated: 2017/12/04 11:12:30 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H

/* LIBS */

# include "define.h"
# include "libft.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>

/* GRAPHER */

typedef struct      s_env
{
  void      *mlx;
  void      *window;
  double    a;
  double    b;
  double    c;
  double    delta;
  char      *equation;
}                   t_env;

t_env     *new_env(void);
int       key_events(int keycode, t_env *env);
void      init_graph(t_env *env);
int       polynomial(int x, double a, double b, double c);

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
