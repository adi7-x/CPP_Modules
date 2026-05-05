#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (int i = 0; i < 5; ++i)
	{
		Base* b = generate();
		std::cout << "Generated object type (identify pointer): ";
		identify(b);
		std::cout << "Generated object type (identify reference): ";
		identify(*b);
		delete b;
		std::cout << "---\n";
	}

	return 0;
}
