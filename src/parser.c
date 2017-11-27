/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:04:44 by kwiessle          #+#    #+#             */
/*   Updated: 2017/11/27 17:57:27 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"


char  *super_trim(char *str) {
  int     i = 0, j = 0, spaces = 0;
  char    *super;
  while (str[i]) {
    if (str[i] ==  ' ')
      spaces++;
    i++;
  }
  if (!(super = malloc(sizeof(char*) * (strlen(str) - spaces))))
    return (NULL);
  i = 0;
  while (str[i]) {
    if (str[i] != ' ') {
      super[j] = str[i];
      j++;
    }
    i++;
  }
  super[j] = '\0';
  return (super);
}

char  *fix(char *str) {
  int   i = 0, verif = 0;
  while (str[i]) {
    if (str[i] == '+' || str[i] == '-') {
      verif++;
      break;
    }

    i++;
  }
  while (verif ==1 && i > 0) {
    ++str;
    i--;
  }
  return (str);
}



void  print_tab(char *name, char **tab) {
  int   i = 0;
  printf("\n\n%s\n\n", name);
  while (tab[i]) {
    printf("%s\n", tab[i]);
    i++;
  }
}

double   get_coeff(char *equation_trimed, char degree) {
  char    **sides;
  char    **left;
  char    **right;
  int     i = 0;
  double  a = 0.0;
  sides = ft_strsplit(equation_trimed, '=');
  left = ft_strsplit(sides[0],'*');
  right = ft_strsplit(sides[1], '*');
  print_tab("LEFT  ->", left);
  print_tab("RIGHT  ->", right);
  while (left[i]) {
    if (left[i][2] == degree || left[i][3] == degree)
      a = a + atof(fix(left[i -1]));
    i++;
  }
  i = 0;
  while (right[i]) {
    if (right[i][2] == degree || right[i][3] == degree)
      a = a + (-1 * atof(fix(right[i -1])));
    i++;
  }
  return (a);
}

// int   main(int ac, char **av) {
//   printf("FINAL  -> %lf\n", get_coeff(super_trim(av[1]), '2'));
//   // printf("%s\n", fix(av[1]));
//   return (0);
// }
