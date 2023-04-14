#include <iostream>
#include <command-line-calculator.hpp>

using zachariahs_world::simple_calculator::command_line_calculator;
using std::cout;
using std::cin;
using std::exception;
using std::size_t;
using std::system;
using std::strcmp;
using std::strlen;

constexpr size_t operator ""_size(const unsigned long long value) noexcept
{
	return static_cast<size_t>(value);
}

int main()
{
	try
	{
		auto calculator = command_line_calculator {};
		cout << "Simple calculater.\n";
		cout << '\n';

		while(true)
		{
			cout << "Enter a command(\"help\" for help or empty line to exit): ";
			constexpr auto max_string_size = 1000_size;
			char command_string[max_string_size];
			cin.getline(command_string, max_string_size);

			if(strlen(command_string) == 0)
			{
				break;
			}
			else if(strcmp(command_string, "help") == 0)
			{
				cout << R"(
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
	catch(const exception& application_exception)
	{
		cout << "Error: " << application_exception.what() << '\n';
	}
	catch(...)
	{
		cout << "Error: An error occured :shrug:\n";
	}

	return EXIT_SUCCESS;
}
