/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:40:23 by kwiessle          #+#    #+#             */
/*   Updated: 2017/12/04 11:11:17 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int  main(int ac, char **av) {
  t_env *env = new_env();
  if (ac != 2) {
    display_error(1);
    return (0);
  }
  // if (check_argument(av[1]) == _FAILURE) {
  //     display_error(2);
  //     return (0);
  // }

  printf("%lf\n", env->a);
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
      return (0);
    }
    print_solutions(max_pow, coefs);
  }
    mlx_loop(env->mlx);
    return (0);
}
