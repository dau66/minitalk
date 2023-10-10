/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:37:29 by ksho              #+#    #+#             */
/*   Updated: 2023/10/10 16:10:18 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h> /* signal.hをインクルード */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	dec_to_binary(int decimal)
{
	int	binary;
	int	base;
	int	remainder;

	binary = 0;
	base = 1;
	if (decimal == 0)
		return (0);
	while (decimal > 0)
	{
		remainder = decimal % 2;
		binary += remainder * base;
		decimal /= 2;
		base *= 10;
	}
	return (binary);
}

int	main(int ac, char **av)
{
	int	i;
	int	k;
	int	ascii_binary;

	if (ac != 3)
		exit(EXIT_FAILURE);
	i = 0;
	while (av[2][i] != '\0')
	{
		k = 0;
		ascii_binary = dec_to_binary(av[2][i]);
		while (k < 8)
		{
			if (ascii_binary % 10 == 1)
				kill((pid_t)ft_atoi(av[ac - 2]), SIGUSR1);
			else if (ascii_binary % 10 == 0)
				kill((pid_t)ft_atoi(av[ac - 2]), SIGUSR2);
			ascii_binary /= 10;
			k++;
			// 1 us = 1/1000 ms
			// 1 ms = 1/1000 s
			usleep(1000);
		}
		i++;
	}
	// exit(EXIT_SUCCESS);
}
// int	convert_adjustment(int decimal, int count)
// {
// 	while (count)
// 	{
// 		decimal /= 10;
// 		count--;
// 	}
// 	return (decimal);
// }

/* シグナルハンドラとしたい関数の定義 */
// void signal_handler(int signum)
// {
//     /* シグナルをキャッチしたときに実行したい内容 */
//     puts("\n中断します");
//     exit(1);
// }

// int main(void){

//     /* シグナルハンドラの登録 */
//     signal(SIGINT, signal_handler);

//     /* Ctl+Cで強制終了されるまで無限ループ */
//     while(1)
// 		pause();

//     return (0);
// }