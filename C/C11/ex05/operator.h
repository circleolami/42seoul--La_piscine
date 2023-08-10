/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 01:30:02 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/11 02:19:59 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H
# define OPERATOR_H
# include <unistd.h>

int		ft_atoi(char *str);
void	ft_putnbr(int nbr);
void	ft_add(int a, int b);
void	ft_multi(int a, int b);
void	ft_minus(int a, int b);
void	ft_div(int a, int b);
void	ft_mod(int a, int b);
#endif
