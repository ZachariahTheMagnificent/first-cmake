#include <stdexcept>
#include <internal/internal.hpp>

namespace zachariahs_world::parser
{
	parsed_command::parsed_command(string name, vector<input> inputs) :
		name {std::move(name)},
		inputs {std::move(inputs)}
	{}

	parsed_command parse(const string& input_string)
	{
		auto return_value = parsed_command {};

		const auto tokens = tokenize(input_string);

		if(tokens.empty())
		{
			throw invalid_argument {"Input string contains no parsable tokens!"};
		}

		return_value.name = tokens[0];

		for(auto index = 1_size, size = tokens.size(); index < size; ++index)
		{
			return_value.inputs.push_back(parse_input(tokens[index]));
		}

		return return_value;
	}
}
