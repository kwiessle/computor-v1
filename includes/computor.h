/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:39:06 by kwiessle          #+#    #+#             */
/*   Updated: 2017/12/20 14:08:00 by vquesnel         ###   ########.fr       */
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

typedef struct		 s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
}        					t_img;

typedef struct      s_env
{
  void      *mlx;
  void      *window;
  double    a;
  double    b;
  double    c;
  double    delta;
  char      *equation;
  t_img     *img;
}                   t_env;

t_env     *init_env(double a, double b, double c);
int       key_events(int keycode, t_env *env);
void      init_graph(t_env *env);
float     polynomial(double x, double a, double b, double c);
void      draw_curve(t_env *env);
void      draw_roots(t_env *env);
void		  mlx_put_pixel_to_img(t_env *env, double x, double y, int color);
/* ERROR */

void      display_error(short e_type);
short     allowed_format(char c);
short     check_format(char *equation);
short     equation_validator(char *equation);

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
double    *get_coeff(char *equation_trimed, int degree);
int       get_max_pow(char *equation_trimed);
char      *minimize(char *str);
void free_tab(void **tab);
/* PRINT */

void      print_discriminent(double a, double b, double c);
void      print_natural_sqrt(double a, double b, double delta, char sign);
void      print_one_sqrt(double a, double b);
void      print_complex_sqrt(double a, double b, double delta, char sign);
void      print_reduced_form(int max_pow, double *coefs);
int       print_exceptions(int max_pow, double *coefs);
void      print_solutions(double *coefs);
#endif
