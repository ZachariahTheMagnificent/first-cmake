#include <command-line-calculator.hpp>

namespace zachariahs_world
{
	command_line_calculator::string command_line_calculator::previous_variable = string {"previous"};

	command_line_calculator::number command_line_calculator::run(const string & command_string)
	{
		using parser::parse;
		using std::get;
		using std::invalid_argument;

		auto parsed_command = parse(command_string);

		if(parsed_command.name == "abs")
		{
			if(parsed_command.inputs.size() != 1)
			{
				throw std::invalid_argument {"abs only accepts 1 argument!"};
			}

			using math::abs;

			const auto value = get_number(parsed_command.inputs[0]);
			const auto result = abs(value);

			last_calculation_ = result;
			variables_[previous_variable] = result;
			return result;
		}
		else if(parsed_command.name == "floor")
		{
			if(parsed_command.inputs.size() != 1)
			{
				throw std::invalid_argument {"floor only accepts 1 argument!"};
			}

			using math::floor;

			const auto value = get_number(parsed_command.inputs[0]);
			const auto result = floor(value);

			last_calculation_ = result;
			variables_[previous_variable] = result;
			return result;
		}
		else if(parsed_command.name == "ceil")
		{
			if(parsed_command.inputs.size() != 1)
			{
				throw std::invalid_argument {"ciel only accepts 1 argument!"};
			}

			using math::ceil;

			const auto value = get_number(parsed_command.inputs[0]);
			const auto result = ceil(value);

			last_calculation_ = result;
			variables_[previous_variable] = result;
			return result;
		}
		else if(parsed_command.name == "clamp")
		{
			if(parsed_command.inputs.size() != 3)
			{
				throw std::invalid_argument {"clamp only accepts 3 arguments!"};
			}

			using math::clamp;

			const auto value = get_number(parsed_command.inputs[0]);
			const auto min = get_number(parsed_command.inputs[1]);
			const auto max = get_number(parsed_command.inputs[2]);
			const auto result = clamp(value, min, max);

			last_calculation_ = result;
			variables_[previous_variable] = result;
			return result;
		}
		else if(parsed_command.name == "wrap")
		{
			if(parsed_command.inputs.size() != 3)
			{
				throw std::invalid_argument {"wrap only accepts 3 arguments!"};
			}

			using math::wrap;

			const auto value = get_number(parsed_command.inputs[0]);
			const auto min = get_number(parsed_command.inputs[1]);
			const auto max = get_number(parsed_command.inputs[2]);
			const auto result = wrap(value, min, max);

			last_calculation_ = result;
			variables_[previous_variable] = result;
			return result;
		}
		else if(parsed_command.name == "degrees-to-radians")
		{
			if(parsed_command.inputs.size() != 1)
			{
				throw std::invalid_argument {"degrees-to-radians only accepts 1 argument!"};
			}

			using math::degrees_to_radians;

			const auto value = get_number(parsed_command.inputs[0]);
			const auto result = degrees_to_radians(value);

			last_calculation_ = result;
			variables_[previous_variable] = result;
			return result;
		}
		else if(parsed_command.name == "radians-to-degrees")
		{
			if(parsed_command.inputs.size() != 1)
			{
				throw std::invalid_argument {"radians-to-degrees only accepts 1 argument!"};
			}
			using math::radians_to_degrees;

			const auto value = get_number(parsed_command.inputs[0]);
			const auto result = radians_to_degrees(value);

			last_calculation_ = result;
			variables_[previous_variable] = result;
			return result;
		}
		else if(parsed_command.name == "sqrt")
		{
			if(parsed_command.inputs.size() != 1)
			{
				throw std::invalid_argument {"sqrt only accepts 1 argument!"};
			}
			using math::sqrt;

			const auto value = get_number(parsed_command.inputs[0]);
			const auto result = sqrt(value);

			last_calculation_ = result;
			variables_[previous_variable] = result;
			return result;
		}
		else if(parsed_command.name == "plus")
		{
			if(parsed_command.inputs.size() < 2)
			{
				throw std::invalid_argument {"plus needs at least 2 arguments!"};
			}

			auto result = number {};

			for(const auto& input : parsed_command.inputs)
			{
				result += get_number(input);
			}

			last_calculation_ = result;
			variables_[previous_variable] = result;
			return result;
		}
		else if(parsed_command.name == "minus")
		{
			if(parsed_command.inputs.size() < 2)
			{
				throw std::invalid_argument {"minus needs at least 2 arguments!"};
			}

			auto result = get_number(parsed_command.inputs[0]);

			for(auto index = std::size_t {} +1, size = parsed_command.inputs.size(); index < size; ++index)
			{
				result -= get_number(parsed_command.inputs[index]);
			}

			last_calculation_ = result;
			variables_[previous_variable] = result;
			return result;
		}
		else if(parsed_command.name == "multiply")
		{
			if(parsed_command.inputs.size() < 2)
			{
				throw std::invalid_argument {"multiply needs at least 2 arguments!"};
			}

			auto result = number {} + 1;

			for(const auto& input : parsed_command.inputs)
			{
				result *= get_number(input);
			}

			last_calculation_ = result;
			variables_[previous_variable] = result;
			return result;
		}
		else if(parsed_command.name == "divide")
		{
			if(parsed_command.inputs.size() < 2)
			{
				throw std::invalid_argument {"divide needs at least 2 arguments!"};
			}

			auto result = get_number(parsed_command.inputs[0]);

			for(auto index = std::size_t {} +1, size = parsed_command.inputs.size(); index < size; ++index)
			{
				result /= get_number(parsed_command.inputs[index]);
			}

			last_calculation_ = result;
			variables_[previous_variable] = result;
			return result;
		}
		else if(parsed_command.name == "store")
		{
			if(parsed_command.inputs.size() > 1)
			{
				throw std::invalid_argument {"store only accepts 1 string!"};
			}
			try
			{
				auto string_input = get<string>(parsed_command.inputs[0]);
				variables_[string_input] = last_calculation_;
				return last_calculation_;
			}
			catch(...)
			{
				throw std::invalid_argument {"store only accepts a string!"};
			}
		}
		else if(parsed_command.name == "print")
		{
			if(parsed_command.inputs.size() > 1)
			{
				throw std::invalid_argument {"print only accepts 1 string!"};
			}
			try
			{
				auto string_input = get<string>(parsed_command.inputs[0]);
				return get_variable(string_input);
			}
			catch(const std::bad_variant_access&)
			{
				throw std::invalid_argument {"print only accepts a string!"};
			}
			catch(...)
			{
				throw;
			}
		}

		throw invalid_argument {"Invalid command!"};
	}

	command_line_calculator::number command_line_calculator::get_variable(const string& variable_name) const
	{
		auto it = variables_.find(variable_name);
		if(it == variables_.end())
		{
			throw std::invalid_argument {"That variable doesn't exist!"};
		}
		return it->second;
	}

	command_line_calculator::number command_line_calculator::get_number(const parsed_input& number_input) const
	{
		using std::get;
		using std::get_if;

		if(auto num = get_if<number>(&number_input); num != nullptr)
		{
			return *num;
		}
		else
		{
			return get_variable(get<string>(number_input));
		}
	}
}
