#pragma once
#include <variant>
#include <string>
#include <vector>

namespace zachariahs_world {
	namespace parser {
		using input = std::variant<std::string, float>;

		struct parsed_command {
			parsed_command() = default;
			parsed_command(std::string name, std::vector<input> inputs) :
				name {std::move(name)},
				inputs {std::move(inputs)} {}

			std::string name;
			std::vector<input> inputs;
		};

		parsed_command parse(const std::string& input_string);
	}
}
