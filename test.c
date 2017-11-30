/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:14:46 by vquesnel          #+#    #+#             */
/*   Updated: 2017/11/30 15:14:41 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int main (){
  char *test[] = {
    "42 = 42",
    "42 * X = 42",
    "-2 * X^2 = 0",
    "0 = X^2 + X^3",
    NULL
  };
  int j = 0;
  while (test[j]) { j++; }
  double **result = NULL;
  int i = 0;
  if ( !(result = (double **)malloc(j * sizeof(double *))) ) {
    return (_FAILURE);
  }
  while (test[i] != NULL) {
    char *equation_trimed = super_trim(test[i]);
    int max_pow = get_max_pow(equation_trimed);
    int tmp_pow = max_pow;
    double *coefs;
    if ( !(coefs = (double *)malloc(max_pow * sizeof(double))) ) {
      return (_FAILURE);
    }
    if ( !(result[i] = (double *)malloc(max_pow * sizeof(double) + 1)) ) {
      return (_FAILURE);
    }
    while ( tmp_pow >= 0 ) {
      result[i][tmp_pow + 1] = get_coeff(equation_trimed, tmp_pow);

      tmp_pow--;
    }
    while (max_pow > 0 && result[i][max_pow + 1] == 0) {
      max_pow--;
    }
    result[i][0] = max_pow;
    i++;
  }
  if (result[0][0] != 0 || result[0][1] != 0) {
    printf("ERREUR PREMIERE EQUATION\n");
  }
  else if (result[1][0] != 1 || result[1][1] != -42 || result[1][2] != 42 ) {
    printf("ERREUR DEUXIEME EQUATION\n");
  }
  else if (result[2][0] != 2 || result[2][1] != 0 || result[2][2] != 0 || result[2][3] != -2 ) {
    printf("ERREUR TROISIEME EQUATION\n");
  }
  else if (result[3][0] != 3 || result[3][1] != 0 || result[3][2] != 0 || result[3][3] != -1 || result[3][4] != -1) {
    printf("ERREUR QUATRIEME EQUATION\n");
  }
  else
   printf("ALL IS OK\n");
  return (0);
}