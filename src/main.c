/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:40:23 by kwiessle          #+#    #+#             */
/*   Updated: 2017/12/20 14:21:45 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static void init_mlx(double *coefs) {
  t_env *env;

  env = init_env(coefs[2], coefs[1], coefs[0]);
  init_graph(env);
  mlx_put_image_to_window(env->mlx, env->window, env->img->img, 0, 0);
  mlx_string_put(env->mlx, env->window, 30, 30, _C_TXT, env->equation);
  mlx_hook(env->window, 2, 3, key_events, env);
  mlx_loop(env->mlx);
  free(env);
}

int  main(int ac, char **av) {
  int exceptions;

  if (ac == 2 || (ac == 3 && ft_strcmp(av[2], "--grapher") == 0)) {
  if (check_format(av[1]) == _FAILURE) {
      display_error();
      return (0);
  } else {
    char *equation_trimed = super_trim(av[1]);
    if (equation_validator(equation_trimed) == -1) {
      display_error();
      return (0);
    }
    int max_pow = get_max_pow(equation_trimed);
    double *coefs = get_coeff(equation_trimed, max_pow);
    while (max_pow > 0 && coefs[max_pow] == 0) {
      max_pow--;
    }
    print_reduced_form(max_pow, coefs);
    if ( (exceptions = print_exceptions(max_pow, coefs)) <= _FAILURE ) {
      switch(exceptions) {
        case -5:
          return (0);
          break;
        case -4:
          return (0);
          break;
        case -3:
          return (0);
          break;
        case -2:
          if (av[2] && av[2] && ft_strcmp(av[2], "--grapher") == 0) {
            init_mlx(coefs);
          }
      }
    }
    print_solutions(coefs);
    if (av[2] && av[2] && ft_strcmp(av[2], "--grapher") == 0) {
      init_mlx(coefs);
    }
   exit(0);
    free_tab((void **)coefs);
    free(equation_trimed);
  }
 }
  return (0);
}
