/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:36:27 by ksho              #+#    #+#             */
/*   Updated: 2023/10/10 16:10:21 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>

int			g_character;

static int	degit_count(int decimal)
{
	int	i;

	i = 0;
	if (decimal == 0)
		return (1);
	while (decimal)
	{
		i++;
		decimal = decimal / 10;
	}
	return (i);
}

int	binary_to_decimal(int binary)
{
	int	count;
	int	value;
	int	power;
	int k = 0;

	value = 0;
	count = degit_count(binary);
	// power = bi_power_int(count - 1);
	while (binary)
	{
		power = 1 << (count - 1);
		if(binary % 10 == 2)
			value = value + (1 * power);
		else if(binary % 10 == 1)
			value = value + (0 * power);
		count--;
		// power = bi_power_int(count - 1);

		binary /= 10;
		k ++;
	}
	return (value);
}

static void	handle_1(int sig_num)
{
	// ft_printf("ok\n");
	g_character = g_character * 10 + 2;
	sig_num = 0;
}

static void	handle_2(int sig_num)
{
	// ft_printf("ok\n");
	g_character = g_character * 10 + 1;
	sig_num = 0;
}

int	main(void)
{
	int	count;
	int	char_num;

	count = 1;
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, handle_1);
	signal(SIGUSR2, handle_2);
	while (1)
	{
		if (count == 9)
		{
			char_num = binary_to_decimal(g_character);
			ft_printf("%c",char_num);
			g_character = 0;
			count = 1;
		}
		// ft_printf("\ncharacter :=%d\n",g_character);
		// ft_printf("count :=%d\n",count);
		count ++;
		// ft_printf("%d\n",g_character);
		// ft_printf("before pause\n");
		pause();
		// ft_printf("after pause\n");
	}
	return (0);
}
