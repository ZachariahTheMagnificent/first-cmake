#include <internal/internal.hpp>

namespace zachariahs_world
{
	namespace parser
	{
		std::vector<std::string> tokenize(const std::string& input_string)
		{
			std::vector<std::string> tokens;

			for(auto begin = input_string.find_first_not_of(' ', 0); begin != input_string.npos; begin = input_string.find_first_not_of(' ', begin + 1))
			{
				const auto end = input_string.find_first_of(' ', begin + 1);

				if(end == input_string.npos)
				{
					tokens.push_back(input_string.substr(begin, input_string.npos));
					break;
				}
				else
				{
					tokens.push_back(input_string.substr(begin, end - begin));
					begin = end;
				}
			}

			return tokens;
		}
		input parse_input(const std::string& input_string)
		{
			try
			{
				return input {std::stold(input_string)};
			}
			catch(...)
			{
				return input {input_string};
			}
		}
	}
}
