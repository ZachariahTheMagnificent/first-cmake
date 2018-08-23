#include <iostream>
#include <command-line-calculator.hpp>

int main()
{
	using zachariahs_world::simple_calculator::command_line_calculator;
	using std::cout;
	using std::cin;
	using std::exception;

	try
	{
		auto calculator = command_line_calculator {};
		cout << "Simple calculater.\n";
		cout << '\n';

		while(true)
		{
			cout << "Enter a command(\"help\" for help or empty line to exit): ";
			const auto max_string_size = std::size_t {} +1000;
			char command_string[max_string_size];
			std::cin.getline(command_string, max_string_size);

			if(std::strlen(command_string) == 0)
			{
				break;
			}
			else if(std::strcmp(command_string, "help") == 0)
			{
				std::cout << R"(
****************************************
HELP
****************************************
<param1> is a string while [param2] is a number(or variable name). "previous" is a special variable that always stores the last calculation made.

store <name>: Stores the last calculation in variable <name>.

print <name>: Prints out the variable <name>.

abs [real]: Returns the mathmatical absolute value of [real].

floor [decimal]: Rounds down [decimal] to the lowest whole number.

ceil [decimal]: Rounds up [decimal] to the highest whole number.

clamp [value] [min] [max]: Limits [value] to the range [min] and [max] if it exceeds that range.

wrap [value] [min] [max]: If [value] goes out of the range [min] and [max], it wraps the value over to the other side.

degrees-to-radians [degrees]: Converts [degrees] to radians.

radians-to-degrees [radians]: Converts [radians] to degrees.

sqrt [value]: Returns the square root of [value].

plus [value1] [value2]...: Adds [value1], [value2], ... together.

minus [value1] [value2]...: Minus [value2], ... from [value1]

multiply [value1] [value2]...: Multiplies value1, value2, ... together.

divide [value1] [values2]...: Divides value1 by value2. Then, it divides that by ....

)";
			}
			else if(strcmp(command_string, "quick-maths") == 0)
			{
				cout << "420 Blaze it!\n";
			}
			else
			{
				try
				{
					auto number = calculator.run(command_string);
					cout << "Result: " << number << '\n';
				}
				catch(const exception& parser_exception)
				{
					cout << "Error: " << parser_exception.what() << '\n';
				}
			}
		}
	}
	catch(const std::exception& application_exception)
	{
		cout << "Error: " << application_exception.what() << '\n';
	}
	catch(...)
	{
		cout << "Error: An error occured :shrug:\n";
	}

	std::system("pause");
	return EXIT_SUCCESS;
}
