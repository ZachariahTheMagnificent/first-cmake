#include <stdexcept>
#include <internal/internal.hpp>

namespace zachariahs_world
{
	namespace parser
	{
		parsed_command parse(const std::string& input_string)
		{
			auto return_value = parsed_command {};

			const auto tokens = tokenize(input_string);

			if(tokens.empty())
			{
				throw std::invalid_argument {"Input string contains no parsable tokens!"};
			}

			return_value.name = tokens[0];

			for(auto index = std::size_t {} +1, size = tokens.size(); index < size; ++index)
			{
				return_value.inputs.push_back(parse_input(tokens[index]));
			}

			return return_value;
		}
	}
}
