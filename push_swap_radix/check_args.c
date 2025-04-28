/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoirier <mpoirier@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:09:50 by mpoirier          #+#    #+#             */
/*   Updated: 2025/04/28 15:59:48 by mpoirier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int ft_contains(int num, char **argv, int i)
{
    while (argv[++i])
    {
        if (ft_atoi(argv[i]) == num)
            return (1);
    }
    return (0);
}

void    ft_check_args(int argc, char **argv)
{
    int         i;
    char        **args;
    long long   tmp;

    i = -1;
    if (argc == 2)
        args = ft_split(argv[1], ' ');
    else
    {
        i += 1;
        args = argv;
    }
    while (args[++i])
    {
        tmp = ft_atoll(args[i]);
        if (!ft_str_is((const char *)(args[i]), ft_isdigit))
            ft_error("Error");
        if (ft_contains(tmp, args, i))
            ft_error("Error");
        if (tmp < INT_MIN || tmp > INT_MAX)
            ft_error("Error");
    }
    if (argc == 2)
        ft_free_split(args);
}