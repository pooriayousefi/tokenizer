
#include "tokenizer.h"
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <stdexcept>

auto main()->int
{
	try
	{
		// tokenizer test
		std::wstring a{ L"jrsybhyn, ryjk.lvy;vtv'tv\"rtgrae9verf0)SFb (s\nherah\tshhdfzh!" };
		std::wstring adelimit{ L"! .,\"'~@#$%^&()\n`\t<}>{?];:[" };
		auto ta{ tokenize(a, adelimit) };
		std::wcout << L"\n\ttokens A: ";
		for (auto& e : ta)
			std::wcout << e << L" ";

		std::string b{ "Hello. ;;Stevie\nMahone!hee hhe heee?" };
		std::string bdelimit{ "! .,\"'~@#$%^&()\n`\t<}>{?];:[" };
		auto tb{ tokenize(b, bdelimit) };
		std::cout << "\n\n\ttokens B: ";
		for (auto& e : tb)
			std::cout << e << " ";
		
		return EXIT_SUCCESS;
	}
	catch (const std::exception & xxx)
	{
		std::cerr << xxx.what() << std::endl;
		return EXIT_FAILURE;
	}
}
