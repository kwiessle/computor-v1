/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:04:44 by kwiessle          #+#    #+#             */
/*   Updated: 2017/11/28 17:44:43 by vquesnel         ###   ########.fr       */
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

int   get_max_pow(char *equation_trimed) {
  char *tmp = equation_trimed;
  int i = 0;
  int max_pow = 0;
  char *tmp2;
  while((tmp = ft_strchr(tmp, '^')) != NULL) {
    tmp++;
    tmp2 = ft_strdup(tmp);
    while(tmp2[i] && (tmp2[i] != '-' && tmp2[i] != '+' && tmp2[i] != '=')) {
      i++;
    }
    tmp2[i] = '\0';
    max_pow = max_pow < ft_atoi(tmp2) ? ft_atoi(tmp2) : max_pow;
  }
  return(max_pow);
}

double   get_coeff(char *equation_trimed, int degree) {
  char    **left;
  char    **right;
  int     i = 0;
  int     j = 0;
  double  a = 0.0;
  char    *_pow;
  (void)degree;
  left = ft_strsplit(ft_strsplit(equation_trimed, '=')[0],'*');
  right = ft_strsplit(ft_strsplit(equation_trimed, '=')[1], '*');
  while (left[i]) {
    if (left[i][1] == '^') {
      _pow = ft_strsub(left[i], 2, ft_strlen(left[i]));
      while(_pow[j] && (_pow[j] != '-' && _pow[j] != '+' && _pow[j] != '=')) {
        j++;
      }
      _pow[j] = '\0';
      if (ft_atoi(_pow) == degree) {
        a = a + atof(fix(left[i - 1]));
      }
    }
    i++;
  }
  i = 0;
  while (right[i]) {
    if (right[i][1]== '^') {
      _pow = ft_strsub(right[i], 2, ft_strlen(right[i]));
      while(_pow[j] && (_pow[j] != '-' && _pow[j] != '+' && _pow[j] != '=')) {
        j++;
      }
      _pow[j] = '\0';
      if (ft_atoi(_pow) == degree) {
        a = a + (-1 * atof(fix(right[i - 1])));
      }
    }
    i++;
  }
  return (a);
}

