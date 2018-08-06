#pragma once
#include <parser/parser.hpp>

namespace zachariahs_world
{
	namespace parser
	{
		std::vector<std::string> tokenize(const std::string& input_string);
		input parse_input(const std::string& input_string);
	}
}
