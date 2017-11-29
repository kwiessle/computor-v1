/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:40:23 by kwiessle          #+#    #+#             */
/*   Updated: 2017/11/28 17:40:44 by vquesnel         ###   ########.fr       */
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
    i = 0;
    tmp_pow = max_pow;
    printf("Reduced form: ");
    while ( tmp_pow >= 0 ) {
      printf("%c%c", i == 0 ? coefs[i] < 0 ? 45 : 0 : coefs[i] <= 0 ? 45 : 43 , i == 0 ? 0 : ' ');
      printf("%g * X^%d ", ft_double_abs(coefs[i]), tmp_pow);
      i++;
      tmp_pow--;
    }
    printf("= 0\n");
    printf("Polynomial degree: %d\n", max_pow);
    if (max_pow >= 3) {
      printf("\e[1;38;5;160;4mThe polynomial degree is stricly greater than 2, I can't solve.\e[0m\n");
      return (0);
    }
    if (max_pow == 0 ) {
      printf("\e[1;38;5;160;4mThis isn't a valid equation\e[0m\n");
      return (0);
    }
    if (max_pow == 1) {
      if (coefs[1] == 0 && coefs[0] == 0) {
        printf("\e[1;38;5;82;4mAll numbers are solution\e[0m\n");
        return (0);
      }
      printf("a = 0, The unique solution is:\n\n");
      printf("\e[1;38;5;130mX1 = -c / b\e[0m\n");
      printf("X1 = - (%g) / %g\n\n", coefs[max_pow], coefs[max_pow - 1]);
      printf("\e[1;38;5;82;4mX1= %g\e[0m\n", -coefs[max_pow] / coefs[max_pow - 1]);
      return (0);
    }
    if (coefs[0] == 0 && coefs[1] == 0  && coefs[2] == 0) {
      printf("\e[1;38;5;82;4mAll numbers are solution\e[0m\n");
      return (0);
    }
    double delta = get_discriminent(coefs[max_pow - 2],coefs[max_pow - 1],coefs[max_pow]);
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
