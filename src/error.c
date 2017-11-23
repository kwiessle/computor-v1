/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:13:14 by kwiessle          #+#    #+#             */
/*   Updated: 2017/11/23 21:34:14 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void   display_error(short e_type) {
  switch (e_type) {
    case 1:
      printf("Only one equation needed to run computor.\n");
      break;
    case 2:
      printf("Too high degree. I can't solve\n");
      break;
    case 3:
      printf("Equation wrong format\n");
      break;
    default:
      printf("Unknonw ERROR_TYPE\n");
      break;
  }
}

short   allowed_degree(char degree) {
    switch (degree) {
      case '0':
        return (_SUCCESS);
      case '1':
        return (_SUCCESS);
      case '2':
        return (_SUCCESS);
      default:
        return (_FAILURE);
    }
}

short   allowed_format(char c) {
  short   i = 0;
  char    *set = "0123456789 .=+-*/\0";

  while (set[i]) {
    if (set[i] == c)
      return (_SUCCESS);
    i++;
  }
  return (_FAILURE);
}

short   check_argument(char *equation) {
  short   i = 0;

  while (equation[i]) {
    if (equation[i] == '^' && allowed_degree(equation[i + 1] == _FAILURE))
        return (_FAILURE);
    i++;
  }
  return (_SUCCESS);
}

short   check_format(char *equation) {
  short   i = 0;
  while (equation[i]) {
    if (allowed_format(equation[i]) == _FAILURE)
      return (_FAILURE);
      i++;
  }
  return (_SUCCESS);
}