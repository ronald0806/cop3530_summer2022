#include <iostream>
#include <string>
#include <vector>


std::vector<int> BinaryK(int k)
{
	std::vector<int> K;
	int tmp = k;
	int i = 0;

	while (tmp > 0)
	{
		K.push_back(tmp % 2);
		tmp = (tmp - K[i]) / 2;
		i++;
	}

	return K;
}

//calculating Modular Exponentiation
int ModularExpo(int a, std::vector<int> K, int n, int k)
{
	int b;
	int i;
	int A;

	if (n == 1)
		return 0;
	b = 1;
	if (k == 0)
		return b;
	A = a;
	if (K[0] == 1)
		b = a;

	for (i = 1; i <= K.size() - 1; i++)
	{

		A = (A * A) % n;

		if (K[i] == 1)
			b = (A * b) % n;
	}

	return b;
}

//Main function
int main()
{
	std::vector<int> K;
	int a;
	int k;
	int n;
	int i;
	int result;
	

	std::cout << "value a: ";
	std::cin >> a;
	std::cout << "value k: ";
	std::cin >> k;
	std::cout << "value n: ";
	std::cin >> n;
	
	K = BinaryK(k);
	
	result = ModularExpo(a, K, n, k);
	
	std::cout << " \n\n Result: " << result << " \n\n";

	return 0;
}