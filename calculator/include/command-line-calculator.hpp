#pragma once
#include <math/math.hpp>
#include <parser/parser.hpp>
#include <unordered_map>
#include <string>

namespace zachariahs_world::simple_calculator
{
	using std::unordered_map;
	using std::size_t;

	constexpr size_t operator ""_size(const unsigned long long value) noexcept
	{
		return static_cast<size_t>(value);
	}

	using parser::string;
	using parser::invalid_argument;
	using parser::bad_variant_access;
	using parser::number;
	using parser::parse;
	using parser::get;
	using parser::get_if;
	using parsed_input = parser::input;

	class command_line_calculator
	{
	public:
		command_line_calculator() = default;

		number run(const string& command_string);

	private:
		static string previous_variable;

		number get_variable(const string& variable_name) const;
		number get_number(const parsed_input& number_input) const;

		number last_calculation_ = number {};
		unordered_map<string, number> variables_ = unordered_map<string, number> {};
	};
}
