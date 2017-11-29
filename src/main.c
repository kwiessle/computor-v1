/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:40:23 by kwiessle          #+#    #+#             */
/*   Updated: 2017/11/29 14:36:22 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int  main(int ac, char **av) {

  if (ac != 2) {
    display_error(1);
    return (0);
  }
  // if (check_argument(av[1]) == _FAILURE) {
  //     display_error(2);
  //     return (0);
  // }
  // if (check_format(av[1]) == _FAILURE) {
  //     display_error(3);
  //     return (0);
  // } else {
    char *equation_trimed = super_trim(av[1]);
    int max_pow = get_max_pow(equation_trimed);
    int tmp_pow = max_pow;
    double *coefs;
    if ( !(coefs = (double *)malloc(max_pow * sizeof(double))) ) {
      return (_FAILURE);
    }
    int i = 0;
    while ( tmp_pow >= 0 ) {
      coefs[i] = get_coeff(equation_trimed, tmp_pow);
      tmp_pow--;
      i++;
    }
    print_reduced_form(max_pow, coefs);
    if ( print_exceptions(max_pow, coefs) == _FAILURE ) {
      return (0);
    }
    double delta = get_discriminent(coefs[max_pow - 2], coefs[max_pow - 1], coefs[max_pow]);
    if (delta > 0) {
      printf("Δ is strictly positive, the two solutions are:\n\n");
      printf("\e[1;38;5;82;4mX1 = %s\e[0m\n\n", natural_sqrt_root(coefs[max_pow - 2],coefs[max_pow - 1], delta, '+'));
      printf("\e[1;38;5;82;4mX2 = %s\e[0m\n", natural_sqrt_root(coefs[max_pow - 2],coefs[max_pow - 1], delta, '-'));
    }
    else if (delta == 0) {
      printf("Δ is equal to zero, the unique solution is:\n\n");
      printf("\e[1;38;5;82;4mX1 = %s\e[0m\n", natural_sqrt_root_3(coefs[max_pow - 2],coefs[max_pow - 1]));
    }
    else {
      printf("Δ is strictly negative, the two solutions are:\n\n");
      printf("\e[1;38;5;82;4mX1 = %s\e[0m\n\n", complex_sqrt_root(coefs[max_pow - 2],coefs[max_pow - 1], delta, '+'));
      printf("\e[1;38;5;82;4mX2 = %s\e[0m\n", complex_sqrt_root(coefs[max_pow - 2],coefs[max_pow - 1], delta, '-'));
    }
    return (0);
}
