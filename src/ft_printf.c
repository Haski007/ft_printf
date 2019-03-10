/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 12:55:48 by pdemian           #+#    #+#             */
/*   Updated: 2019/03/10 12:55:51 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int      count_args(const char *format)
{
    char    *all_possible;
    int     i;

    i = 0;
    all_possible = "cspdiouxX";
    while (format[i])
    {
        if ((ft_strchr(all_possible, format[i])))
            return (i + 1);
        i++;
    }
    return (0);
}

int             ft_printf(const char *format, ...)
{
    va_list args;
    int     done;
    int     nargs;
    t_orgi  params;

    done = 0;
    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            ft_putchar(*format);
            done++;
        }
        else
        {
            format++;
            nargs = count_args(format);
            params = parse_this(format, nargs - 1);
            printf("Type - %c\n", params.type);
            format += nargs - 1;
        }
        format++;
    }
    printf("%d\n", nargs);
    return (done);
}