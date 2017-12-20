/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:13:14 by kwiessle          #+#    #+#             */
/*   Updated: 2017/12/19 22:01:37 by kwiessle         ###   ########.fr       */
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
    case 4:
      printf("Unknown option flag. (Must be --flagname)\n");
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
  char    *set = "0123456789 .=+-*X^\0";
  while (set[i]) {
    if (set[i] == c)
      return (_SUCCESS);
    i++;
  }
  return (_FAILURE);
}

short   check_argument(char *equation) {
  short   i = 0;
  short   tmp = 0;
  while (equation[i]) {
    tmp = allowed_degree(equation[i + 1]);
    if (equation[i] == '^' && tmp == _FAILURE) {
      return (_FAILURE);
    }
    i++;
  }
  return (_SUCCESS);
}

short   check_format(char *equation) {
  short   i = 0, tmp = 0;
  int     verif = 0;

  if (ft_strlen(equation) < 3) {
     return _FAILURE;
  }
  while (equation[i]) {
    tmp = allowed_format(equation[i]);
    if (tmp == _FAILURE)
      return (_FAILURE);
    if (equation[i] == '=')
      verif++;
      i++;
  }
  if (verif != 1)
    return (_FAILURE);
  else
    return (_SUCCESS);
}

static char    *equation_clear(char *dirty){
  short i = 0;
  while (dirty[i]) {
    if (dirty[i] == '#') {
      dirty[i] = ' ';
    }
    i++;
  }
  return (dirty);
}

short   equation_validator(char *equation) {
  char *clean = equation_clear(equation);
  int i = 1;
  if (clean[0] != '+' && clean[0] != '-' && (clean[0] >= 0 && clean[0] < '0') && clean[0] > '9')
    return (-1);
  while (clean[i]) {
    if (clean[i] >= '0' && clean[i] <= '9') {
      if (clean[i -1] != '+' && clean[i -1] != '-' && clean[i -1] != '.' && clean[i -1] != '=' && (clean[0] >= 0 && clean[0] < '0') && clean[0] > '9')
        return (-1);
      if (clean[i +1] != '+' && clean[i +1] != '-' && clean[i +1] != '*' && clean[i +1] != '.' && clean[i +1] != '=' && (clean[0] >= 0 && clean[0] < '0') && clean[0] > '9')
        return (-1);
    }
    // if (clean[i] == 'X') {
    //   if (clean[i -1] != '+' || clean[i -1] != '-' || clean[i -1] != '*')
    //     printf("%c -> %c -> %c\n",clean[i -1], clean[i], clean[i +1]);
    //   if (clean[i +1] != '+' || clean[i +1] != '-' || clean[i +1] != '=' || clean[i +1] != '^')
    //     printf("%c -> %c -> %c\n",clean[i -1], clean[i], clean[i +1]);
    // }
    // if (clean[i] == '+' || clean[i] == '-') {
    //   if (clean[i -1] != 'X' || !(clean[i -1] >= '0' && clean[i -1] <= '9'))
    //     printf("%c -> %c -> %c\n",clean[i -1], clean[i], clean[i +1]);
    //   if (clean[i +1] != 'X' || !(clean[i +1] >= '0' && clean[i +1] <= '9'))
    //     printf("%c -> %c -> %c\n",clean[i -1], clean[i], clean[i +1]);
    // }
    // if (clean[i] == '*') {
    //   if (!(clean[i -1] >= '0' && clean[i -1] <= '9'))
    //     printf("%c -> %c -> %c\n",clean[i -1], clean[i], clean[i +1]);
    //   if (clean[i +1] != 'X')
    //     printf("%c -> %c -> %c\n",clean[i -1], clean[i], clean[i +1]);
    // }
    // if (clean[i] == '^') {
    //   if (clean[i -1] != 'X')
    //     printf("%c -> %c -> %c\n",clean[i -1], clean[i], clean[i +1]);
    //   if (!(clean[i +1] <= '0' && clean[i +1] <= '9'))
    //     printf("%c -> %c -> %c\n",clean[i -1], clean[i], clean[i +1]);
    // }
    // if (clean[i] == '=') {
    //   if (clean[i -1] != 'X' || !(clean[i -1] >= '0' && clean[i -1] <= '9'))
    //     printf("%c -> %c -> %c\n",clean[i -1], clean[i], clean[i +1]);
    //   if (clean[i +1] != '+' || clean[i +1] != '-' || clean[i +1] != 'X' || !(clean[i +1] >= '0' && clean[i +1] <= '9'))
    //     printf("%c -> %c -> %c\n",clean[i -1], clean[i], clean[i +1]);
    // }
    // if (clean[i] == '.') {
    //   if (!(clean[i -1] >= '0' && clean[i -1] <= '9'))
    //     printf("%c -> %c -> %c\n",clean[i -1], clean[i], clean[i +1]);
    //   if (!(clean[i +1] >= '0' && clean[i +1] <= '9'))
    //     printf("%c -> %c -> %c\n",clean[i -1], clean[i], clean[i +1]);
    // }
    i++;
  }
  return (0);
}
