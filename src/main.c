/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:40:23 by kwiessle          #+#    #+#             */
/*   Updated: 2017/12/04 16:30:02 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int  main(int ac, char **av) {
  t_env *env;
  (void)ac;
  int exceptions;
  if (check_format(av[1]) == _FAILURE) {
      display_error(3);
      return (0);
  } else {
    char *equation_trimed = super_trim(av[1]);
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
          env = init_env(0, coefs[1], coefs[0]);
          init_graph(env);
          mlx_hook(env->window, 2, 3, key_events, env);
          mlx_loop(env->mlx);
          free(env);
      }
    }
    print_solutions(coefs);
    if (av[2] && av[2] && ft_strcmp(av[2], "--grapher") == 0) {
      env = init_env(coefs[2], coefs[1], coefs[0]);
      init_graph(env);
      mlx_hook(env->window, 2, 3, key_events, env);
      mlx_loop(env->mlx);
      free(env);
    } else {
      display_error(4);
      exit(0);
    }
    free_tab((void **)coefs);
    free(equation_trimed);
  }

  return (0);
}
