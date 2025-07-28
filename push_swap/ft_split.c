/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngungor <ngungor@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:11:23 by ngungor           #+#    #+#             */
/*   Updated: 2025/07/28 14:11:29 by ngungor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	word_check;

	word_check = 0;
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && !word_check)
		{
			word_check = 1;
			count++;
		}
		else if (s[i] == c)
			word_check = 0;
		i++;
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	free_all(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	*allocate_word(char const *s, char c)
{
	int		len;
	int		i;
	char	*word;

	len = word_len(s, c);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**newstrings;
	int		i;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	newstrings = (char **)malloc(sizeof(char *) * (words + 1));
	if (!newstrings)
		return (NULL);
	i = 0;
	while (*s && i < words)
	{
		while (*s == c)
			s++;
		newstrings[i] = allocate_word(s, c);
		if (!newstrings[i])
			return (free_all(newstrings, i), NULL);
		s += word_len(s, c);
		i++;
	}
	newstrings[i] = NULL;
	return (newstrings);
}
