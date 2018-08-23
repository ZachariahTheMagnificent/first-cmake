#pragma once
#include <parser/parser.hpp>

namespace zachariahs_world::parser
{
	vector<string> tokenize(const string& input_string);
	input parse_input(const string& input_string);
}
