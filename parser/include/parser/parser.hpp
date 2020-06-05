#pragma once
#include <variant>
#include <string>
#include <vector>
#include <stdexcept>

namespace zachariahs_world::parser
{
	using number = long double;
	using std::string;
	using std::vector;
	using std::size_t;
	using std::invalid_argument;
	using std::bad_variant_access;
	using std::get;
	using std::get_if;
	using input = std::variant<string, number>;

	constexpr size_t operator ""_size(const unsigned long long value) noexcept
	{
		return static_cast<size_t>(value);
	}
	struct parsed_command
	{
		parsed_command() = default;
		parsed_command(string name, vector<input> inputs);

		string name;
		vector<input> inputs;
	};

	parsed_command parse(const string& input_string);
}
