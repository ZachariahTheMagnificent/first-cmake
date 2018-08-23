#pragma once
#include <math/math.hpp>
#include <parser/parser.hpp>
#include <unordered_map>
#include <string>

namespace zachariahs_world::simple_calculator
{
	class command_line_calculator
	{
	public:
		using string = std::string;
		using number = parser::number;
		using parsed_input = parser::input;

		command_line_calculator() = default;

		number run(const string& command_string);

	private:
		static string previous_variable;

		number get_variable(const string& variable_name) const;
		number get_number(const parsed_input& number_input) const;

		number last_calculation_ = number {};
		std::unordered_map<string, number> variables_ = std::unordered_map<string, number> {};
	};
}
