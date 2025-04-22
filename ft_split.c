/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:40:11 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/04/18 14:29:45 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_count(char const *s, char c);
static int		ft_fill_words(char **words, const char *s, char c);
static void		*ft_free(char **strs, int count);
static char		*ft_word_dup(char const *s, int start, int end);

char	**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (ft_calloc(sizeof(char *), 1));
	words = ft_calloc(sizeof(char *), (ft_word_count(s, c) + 1));
	if (!words)
		return (NULL);
	if (!ft_fill_words(words, s, c))
		return (NULL);
	return (words);
}

static int	ft_word_count(char const *s, char c)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			cnt++;
		i++;
	}
	return (cnt);
}

static int	ft_fill_words(char **words, const char *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			words[j] = ft_word_dup(s, start, i);
			if (!words[j])
				return (ft_free(words, j), 0);
			j++;
		}
	}
	words[j] = NULL;
	return (1);
}

static char	*ft_word_dup(char const *s, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

/*#include <string.h>


static void print_result(char **arr)
{
    int i = 0;

    if (!arr)
    {
        printf("Result: NULL\n");
        return;
    }
    while (arr[i])
    {
        printf("Word[%d]: \"%s\"\n", i, arr[i]);
        i++;
    }
    printf("Total words: %d\n", i);
    printf("-----------\n");
}

static int compare_results(char **result, char **expected)
{
    int i = 0;

    // Compare each word in the result with the expected
    while (expected[i] || result[i])
    {
        if ((expected[i] && !result[i]) || (!expected[i] && result[i]))
            return 0; // One of the arrays is longer than expected

        if (expected[i] && result[i] && strcmp(expected[i], result[i]) != 0)
            return 0; // Words don't match

        i++;
    }
    return 1; // Arrays match
}

int main(void)
{
    char *test1 = "Hello world this is split";
    char *test2 = "   trim this   please ";
    char *test3 = "";
    char *test4 = "42";
    char *test5 = "------";
    char *test6 = "--start middle--end--";

    char *expected1[] = {"Hello", "world", "this", "is", "split", NULL};
    char *expected2[] = {"trim", "this", "please", NULL};
    char *expected3[] = {NULL};
    char *expected4[] = {"42", NULL};
    char *expected5[] = {NULL};  // Corrected expected result for Test 5
    char *expected6[] = {"start middle", "end", NULL};

    char **result;

    printf("Test 1:\n");
    result = ft_split(test1, ' ');
    print_result(result);

    printf("Test 2:\n");
    result = ft_split(test2, ' ');
    print_result(result);

    printf("Test 3 (empty string):\n");
    result = ft_split(test3, ' ');
    print_result(result);

    printf("Test 4 (single word):\n");
    result = ft_split(test4, ' ');
    print_result(result);

    printf("Test 5 (only delimiters):\n");
    result = ft_split(test5, '-');
    print_result(result);

    printf("Test 6 (delims at edges):\n");
    result = ft_split(test6, '-');
    print_result(result);

    return 0;
}*/