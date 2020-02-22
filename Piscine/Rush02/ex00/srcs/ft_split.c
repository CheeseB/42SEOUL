/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinlee <jinlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:56:44 by jinlee            #+#    #+#             */
/*   Updated: 2020/02/09 23:23:30 by jinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

int		is_seperator(char c, char *sep)
{
	int	i;

	i = -1;
	while (sep[++i])
	{
		if (c == sep[i])
			return (1);
	}
	return (0);
}

int		chk_word_cnt(char *str, char *sep)
{
	int	i;
	int	cnt;
	int	len;

	i = -1;
	cnt = 1;
	len = 0;
	while (str[++i])
	{
		if (is_seperator(str[i], sep) && len > 0)
		{
			cnt++;
			len = 0;
		}
		else if (!is_seperator(str[i], sep))
			len++;
	}
	if (len > 0)
		cnt++;
	return (cnt);
}

int		chk_word_len(char *str, char *sep, int idx)
{
	int	i;
	int	cnt;
	int	len;

	i = -1;
	cnt = 1;
	len = 0;
	while (str[++i])
	{
		if (is_seperator(str[i], sep) && len > 0)
		{
			if (cnt == idx)
				return (len);
			cnt++;
			len = 0;
		}
		else if (!is_seperator(str[i], sep))
			len++;
	}
	return (len);
}

void	insert_word(char *str, char *sep, char *result, int idx)
{
	int	i;
	int	cnt;
	int	len;
	int	start;

	i = -1;
	cnt = 1;
	len = 0;
	while (str[++i])
	{
		if (is_seperator(str[i], sep) && len > 0)
		{
			if (cnt == idx)
				break ;
			cnt++;
			len = 0;
		}
		else if (!is_seperator(str[i], sep))
			len++;
	}
	start = (i - len) - 1;
	i = -1;
	while (++i < len)
		result[i] = str[++start];
	result[i] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		word_cnt;
	int		word_len;
	int		i;

	word_cnt = chk_word_cnt(str, charset);
	result = (char **)malloc(sizeof(char *) * word_cnt);
	result[word_cnt - 1] = 0;
	if (word_cnt == 1)
		return (result);
	i = -1;
	while (++i < word_cnt - 1)
	{
		word_len = chk_word_len(str, charset, i + 1);
		result[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		insert_word(str, charset, result[i], i + 1);
	}
	return (result);
}
