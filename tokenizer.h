
#pragma once
#include <string>
#include <vector>

namespace
{
	template<typename String>
	decltype(auto) tokenize(const String& string, const String& delimiters)
	{
		if constexpr (std::is_same_v<String, std::string> || std::is_same_v<String, std::wstring> ||
			std::is_same_v<String, std::u16string> || std::is_same_v<String, std::u32string>)
		{
			std::vector<String> tokens{};

			// skip delimiters at begining
			auto last_pos = string.find_first_not_of(delimiters, 0);

			// find first non-delimiter
			auto pos = string.find_first_of(delimiters, last_pos);

			while (pos != String::npos || last_pos != String::npos)
			{
				// find a token, add it to the vector
				tokens.push_back(string.substr(last_pos, pos - last_pos));

				// skip delimiters
				last_pos = string.find_first_not_of(delimiters, pos);

				// find next non-delimiter
				pos = string.find_first_of(delimiters, last_pos);
			}

			return tokens;
		}		
	}
}
