/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:23:18 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/16 22:01:17 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

struct Data
{
	std::string s1;
	int			n;
	std::string s2;
};

void	*serialize(void)
{
	static const char alphaNum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char	*data = new char[20];
	int		*intPortion = reinterpret_cast<int*>(data + 8);

	for (int i = 0; i < 8; ++i)
	{
		data[i] = alphaNum[rand() % (sizeof(alphaNum) - 1)];
		data[12 + i] = alphaNum[rand() % (sizeof(alphaNum) - 1)];
		std::cout << " c1 = " << data[i] << " c2 = " << data[12 + i] << std::endl;
	}
	*intPortion = rand();
	std::cout << "n = " << *intPortion << std::endl;
	return reinterpret_cast<void*>(data);
}

Data	*deserialize(void *raw)
{
	Data	*data = new Data;
	char	*s1 = reinterpret_cast<char*>(raw);
	int		*n = reinterpret_cast<int*>(s1 + 8);

	for (int i = 0; i < 8; ++i)
	{
		data->s1.push_back(s1[i]);
		data->s2.push_back(s1[i + 12]);
	}
	data->n = *n;
	return data;
}

int main(void)
{
	srand(std::time(NULL));
	void	*test = serialize();
	Data	*data = deserialize(test);

	std::cout << "Deserialized data:" << std::endl
		<< "s1 = " << data->s1 << std::endl
		<< "n = " << data->n << std::endl
		<< "s2 = " << data->s2 << std::endl;
	delete reinterpret_cast<char*>(test);
	delete data;
}