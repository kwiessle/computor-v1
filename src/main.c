/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:40:23 by kwiessle          #+#    #+#             */
/*   Updated: 2017/12/04 11:13:49 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int  main(int ac, char **av) {
  t_env *env;
  // if (ac < 2  ac > 3) {
  //   display_error(1);
  //   return (0);
  // }
  // if (check_argument(av[1]) == _FAILURE) {
  //     display_error(2);
  //     return (0);
  // }
  (void)ac;
  if (check_format(av[1]) == _FAILURE) {
      display_error(3);
      return (0);
  } else {
    char *equation_trimed = super_trim(av[1]);
    int max_pow = get_max_pow(equation_trimed);
    int tmp_pow = max_pow;
    double *coefs;

    if ( !(coefs = (double *)malloc(max_pow * sizeof(double))) ) {
      return (_FAILURE);
    }
    while ( tmp_pow >= 0 ) {
      coefs[tmp_pow] = get_coeff(equation_trimed, tmp_pow);
      tmp_pow--;
    }
    while (max_pow > 0 && coefs[max_pow] == 0) {
      max_pow--;
    }
    print_reduced_form(max_pow, coefs);
    if ( print_exceptions(max_pow, coefs) == _FAILURE ) {
      // return (0);
    }
    print_solutions(max_pow, coefs);
    if ( av[2] && av[2] && ft_strcmp(av[2], "--grapher") == 0) {
      env = new_env(get_coeff(equation_trimed, 2), get_coeff(equation_trimed, 1), get_coeff(equation_trimed, 0));
      init_graph(env);
      mlx_hook(env->window, 2, 3, key_events, env);
      mlx_loop(env->mlx);
    } else {
      display_error(4);
      exit(0);
    }
  }

  return (0);
}
