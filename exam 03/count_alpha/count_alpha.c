#include <stdio.h>

int get_index(char c)
{
	return (c - 'a');
}

int check_double(char *str, char c, int index)
{
	int i = 0;
	while(i < index)
	{
		if(str[i] == c)
			return 0;
		i++;
	}
	return 1;
}

char ft_last(char *str)
{
	int i = 0;
	char last;
	while(str[i])
	{
		if(((str[i] >= 'a' && str[i] <= 'z') 
			|| (str[i] >= 'A' && str[i] <= 'Z')) 
			&& (check_double(str, str[i], i)))
			last = str[i];
		i++;
	}
	return last;
}

void ft_count(char *str)
{
	int i = 0;
	int tab[26];
	int len;
	char last;

	/// set the tab to 0
	while(i < 26)
	{
		tab[i] = 0;
		i++;
	}
	/// minimize the string
	i = 0;
	while(str[i])
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	len = i;
	last = ft_last(str);
	i = 0;
	/// inc
	while(str[i])
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			tab[get_index(str[i])]++;
		}
		i++;
	}
	/// printing
	i = 0;
	while(str[i])
	{
		if( check_double(str, str[i], i) 
				&& (str[i] >= 'a' 
				&& str[i] <= 'z')) 
		{
			printf("%d%c", tab[get_index(str[i])], str[i]);
			if(str[i] != last)
				printf(", ");
		}
		i++;
	}

}

int main(int c, char **v)
{
	if(c == 2)
		ft_count(v[1]);
	printf("\n");
	return 0;
}
