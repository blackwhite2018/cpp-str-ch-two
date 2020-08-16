#include <iostream>

int ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return count;
}

char *str_rm_symbol(char *str, int pos)
{
	int iter;

	if (pos < 0 || ft_strlen(str) <= 1)
		return str;
	iter = 1;
	while (str[iter] != '\0')
	{
		if (iter >= pos)
		{
			iter++;
			str[iter - 1] = str[iter];
			continue;
		}
		iter++;
	}
	str[iter] = '\0';
	return str;
}

char *str_rm_all_symbol(char *str, char symbol)
{
	int iter;

	iter = 0;
	while (str[iter] != '\0')
	{
		if (str[iter] == symbol)
			str = str_rm_symbol(str, iter--);
		iter++;
	}
	return str;
}

char *str_insert_symbol(char *str, char symbol, int pos)
{
	char *pstr = new char[ft_strlen(str) + 1];
	int iter;
	int iterStr;

	if (pos >= 0 && ft_strlen(str) >= pos)
	{
		iter = 0;
		iterStr = 0;
		while (str[iter] != '\0')
		{
			if (iter == pos)
			{
				iterStr = iter++;
				pstr[iterStr++] = symbol;
				continue;
			}
			pstr[iterStr++] = str[iter++];
		}
	}
	std::cout << pstr << '\n';
	return pstr;
}

bool is_palindrome_str(char *str)
{
	int length;
	int iter;

	length = ft_strlen(str);
	iter = 0;
	while (iter < length / 2)
	{
		if (str[iter] != str[length - iter - 1])
			return false;
		iter++;
	}
	return true;
}

int count_word(char *str)
{
	int count;
	int iter;

	count = 0;
	iter = 0;
	while (str[iter] != '\0')
	{
		if (str[iter] == ' ')
			count++;
		iter++;
	}
	return count >= 1 ? count + 1 : 0;
}

int main(void)
{
	/*
	// 1
	char str[20] = "hello, lstring\0";
	std::cout << str_rm_symbol(str, 3);
	*/

	/*
	// 2
	char str[20] = "hello, lstring\0";
	std::cout << str_rm_all_symbol(str, 'l');
	*/

	/*
	// 3
	char str[20] = "hello, string\0";
	char *ptr = str_insert_symbol(str, 'P', 5);
	std::cout << ptr;
	delete[] ptr;
	*/

	/*
	// 4
	char str[20] = "ttr\0";
	std::cout << is_palindrome_str(str);
	*/

	/*
	// 5
	char str[20] = "hello, string\0";
	std::cout << count_word(str);
	*/
	return 0;
}
