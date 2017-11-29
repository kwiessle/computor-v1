/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:55:13 by vquesnel          #+#    #+#             */
/*   Updated: 2017/11/29 14:26:21 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"
void      print_discriminent(double a, double b, double c) {
  printf("To calculate the discriminent you need to resolve\n\n");
  printf("\e[1;38;5;130mΔ = b^2 - 4 * a * c\e[0m\n\n");
  printf("Where a, b, c are respectively the coefficent of the degree 2, 1, 0 so:\n\n");
  printf("Δ = %g^2 - 4 * %g * %g\n", b, a, c);
  printf("Δ = %g^2 - %g\n", b, 4 * a * c);
  printf("Δ = %g - %g\n", b * b, 4 * a * c);
  printf("\e[1;38;5;82;4mΔ = %g\e[0m\n\n", b * b - 4 * (a * c));
}
void      print_natural_sqrt(double a, double b, double delta, char sign) {
  double dividend = sign == '+' ? -b + ft_sqrt(delta) : -b - ft_sqrt(delta);
  double divisor = 2 * a;

  printf("\e[1;38;5;130mX%c = (-b %c √Δ) / (2 * a)\e[0m\n", sign == '+' ? '1' : '2', sign);
  printf("X%c = (-(%g) %c √%g) / (2 * (%g))\n", sign == '+' ? '1' : '2', b, sign, delta, a);
  printf("X%c = (-(%g) %c %g) / %g\n", sign == '+' ? '1' : '2', b, sign, ft_sqrt(delta), divisor);
  printf("X%c =  %g / %g\n\n", sign == '+' ? '1' : '2',dividend, divisor);
}
void      print_one_sqrt(double a, double b){
  printf("\e[1;38;5;130mX1 = -b / (2 * a)\e[0m\n");
  printf("X1 = -(%g) / (2 * (%g))\n", b, a);
  printf("X1 = %g / %g\n", -b, 2 * a);
}
void      print_complex_sqrt(double a, double b, double delta, char sign){
  printf("\e[1;38;5;130mX%c = (-b %c i√(-Δ)) / (2 * a)\e[0m\n", sign == '+' ? '1' : '2', sign);
  printf("X%c = (-(%g) %c i√-(%g)) / (2 * (%g))\n", sign == '+' ? '1' : '2', b, sign, delta, a);
  printf("X%c = (-(%g) %c %gi) / %g\n", sign == '+' ? '1' : '2', b, sign, ft_sqrt(-delta), 2 * a);
  printf("X%c =  %g / %g %c %g/%gi\n\n", sign == '+' ? '1' : '2', -b, 2 * a, sign,  ft_sqrt(-delta), 2 * a);
}

void      print_reduced_form(int max_pow, double *coefs) {
  int i = 0;
  int tmp_pow = max_pow;

  printf("Reduced form: ");
  while ( tmp_pow >= 0 ) {
    switch (tmp_pow) {
      case 0:
        printf("\e[1;38;5;124;4m%c%c", i == 0 ? coefs[i] < 0 ? 45 : 0 : coefs[i] <= 0 ? 45 : 43 , i == 0 ? 0 : ' ');
        printf("%g\e[0m ", ft_double_abs(coefs[i]));
        break;
      case 1:
        printf("\e[1;38;5;124;4m%c%c", i == 0 ? coefs[i] < 0 ? 45 : 0 : coefs[i] <= 0 ? 45 : 43 , i == 0 ? 0 : ' ');
        printf("%g\e[0m * X ", ft_double_abs(coefs[i]));
        break;
      case 2:
        printf("\e[1;38;5;124;4m%c%c", i == 0 ? coefs[i] < 0 ? 45 : 0 : coefs[i] <= 0 ? 45 : 43 , i == 0 ? 0 : ' ');
        printf("%g\e[0m * X^%d ", ft_double_abs(coefs[i]), tmp_pow);
        break;
      default:
        printf("%c%c", i == 0 ? coefs[i] < 0 ? 45 : 0 : coefs[i] <= 0 ? 45 : 43 , i == 0 ? 0 : ' ');
        printf("%g * X^%d ", ft_double_abs(coefs[i]), tmp_pow);
    }
    i++;
    tmp_pow--;
  }
  printf("= 0\n");
  printf("Polynomial degree: %d\n", max_pow);
}

int      print_exceptions(int max_pow, double *coefs) {
  if (max_pow >= 3) {
    printf("\e[1;38;5;160;4mThe polynomial degree is stricly greater than 2, I can't solve.\e[0m\n");
    return _FAILURE;
  }
  if (max_pow == 0 ) {
    printf("\e[1;38;5;160;4mThis isn't a valid equation\e[0m\n");
    return _FAILURE;
  }
  if (max_pow == 1) {
    if (coefs[1] == 0 && coefs[0] == 0) {
      printf("\e[1;38;5;82;4mAll numbers are solution\e[0m\n");
      return _FAILURE;
    }
    printf("a = 0, The unique solution is:\n\n");
    printf("\e[1;38;5;130mX1 = -c / b\e[0m\n");
    printf("X1 = - (%g) / %g\n\n", coefs[max_pow], coefs[max_pow - 1]);
    printf("\e[1;38;5;82;4mX1= %g\e[0m\n", -coefs[max_pow] / coefs[max_pow - 1]);
    return _FAILURE;
  }
  if (coefs[0] == 0 && coefs[1] == 0  && coefs[2] == 0) {
    printf("\e[1;38;5;82;4mAll numbers are solution\e[0m\n");
    return _FAILURE;
  }
  return _SUCCESS;
}