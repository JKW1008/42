/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjung <kjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:09:06 by kjung             #+#    #+#             */
/*   Updated: 2024/10/25 19:20:57 by kjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int    ft_atoi(const char *str)
{
    long    result;
    int     sign;
    
    result = 0;
    sign = 1;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-')
        sign = -1;
    if (*str == '-' || *str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        if (result > INT_MAX && sign == 1)
            return (-1);
        if (result > ((long)INT_MAX + 1) && sign == -1)
            return (-1);
        str++;
    }
    return (sign * result);
}