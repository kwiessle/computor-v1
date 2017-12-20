/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:13:14 by kwiessle          #+#    #+#             */
/*   Updated: 2017/12/20 12:53:54 by vquesnel         ###   ########.fr       */
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
  char *tmp = ft_strdup(dirty);
  short i = 0;
  while (tmp[i]) {
    if (tmp[i] == '#') {
      tmp[i] = ' ';
    }
    i++;
  }
  return (tmp);
}

static short check_number(char *clean, int i) {
  if (clean[i - 1] != '^' && clean[i - 1] != '+' && clean[i - 1] != '-' && clean[i - 1] != '.' && clean[i - 1] != '=' && (clean[i - 1] < '0' || clean[i - 1] > '9')) {
    return (-1);
  }
  if (clean[i + 1] != '+' && clean[i +1] != '-' && clean[i +1] != '*' && clean[i +1] != '.' && clean[i +1] != '=' && (clean[i + 1] < '0' || clean[i + 1] > '9')) {
    return (-1);
  }
  return(0);
}

static short check_X(char *clean, int i) {
  if (clean[i - 1] != '+' && clean[i - 1] != '-' && clean[i - 1] != '*'){
    return (-1);
  }
  if (clean[i + 1] != '+' && clean[i + 1] != '-' && clean[i + 1] != '=' && clean[i + 1] != '^'){
    return (-1);
  }
  return (0);
}

static short check_operator(char *clean, int i) {
  if (clean[i - 1] != '=' && clean[i - 1] != 'X' && (clean[i - 1] < '0' || clean[i - 1] > '9')) {
    return (-1);
  }
  if (clean[i + 1] != 'X' && (clean[i +1] < '0' || clean[i +1] > '9')) {
    return (-1);
  }
  return (0);
}

static short check_multiplicator(char *clean, int i){
  if ((clean[i - 1] < '0' || clean[i - 1] > '9')) {
    return (-1);
  }
  if (clean[i + 1] != 'X') {
    return (-1);
  }
  return (0);
}

static short check_pow(char *clean, int i) {
  if (clean[i - 1] != 'X'){
    return (-1);
  }
  if (clean[i + 2] == '.' || clean[i + 2] =='^' || (clean[i + 1] < '0' || clean[i + 1] > '9')) {
    return (-1);
  }
  return (0);
}

static short check_equality(char *clean, int i) {
  if (clean[i - 1] != 'X' && (clean[i -1] < '0' || clean[i -1] > '9')) {
    return (-1);
  }
  if (clean[i + 1] != '+' && clean[i + 1] != '-'){
    return (-1);
  }
  return (0);
}

static short check_dot(char *clean, int i) {
  if ((clean[i - 1] < '0' || clean[i -1] > '9')) {
    return (-1);
  }
  if (clean[i + 2] == '.' || (clean[i + 1] < '0' || clean[i + 1] > '9')){
    return (-1);
  }
  return (0);
}
short   equation_validator(char *equation) {
  char *clean = minimize(equation_clear(equation));
  int i = 1;
  if (clean[0] != 'X' && clean[0] != '+' && clean[0] != '-' && (clean[0] >= 0 && clean[0] < '0') && clean[0] > '9')
    return (-1);
  while (clean[i] && clean[i+1] !='\0') {
    if (clean[i] >= '0' && clean[i] <= '9' && check_number(clean, i) < 0)
      return(-1);
    if (clean[i] == 'X'&& check_X(clean, i) < 0)
      return(-1);
    if ((clean[i] == '+' || clean[i] == '-') && check_operator(clean, i) < 0)
      return(-1);
    if (clean[i] == '*' && check_multiplicator(clean, i) < 0)
      return(-1);
    if (clean[i] == '^' && check_pow(clean, i) < 0)
      return(-1);
    if (clean[i] == '=' && check_equality(clean, i) < 0)
      return(-1);
    if (clean[i] == '.' && check_dot(clean, i) < 0)
      return(-1);
    i++;
  }
  return (0);
}
