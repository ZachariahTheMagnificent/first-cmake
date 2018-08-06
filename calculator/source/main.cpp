#include <iostream>
#include <math/math.hpp>
#include <parser/parser.hpp>

int main() {
	using zachariahs_world::parser::parse;
	using std::cout;
	using std::string;
	using std::cin;
	using std::exception;
	using std::invalid_argument;

	cout << "Testing parser library.\n";
	cout << '\n';

	while(true) {
		cout << "Enter a command(Empty line to exit): ";
		const auto max_string_size = std::size_t {} + 1000;
		char command_string[max_string_size];
		std::cin.getline(command_string, max_string_size);

		if(std::strlen(command_string) == 0) {
			break;
		}

		try {
			auto parsed_command = parse(command_string);
			cout << "Command name: "<< parsed_command.name << '\n';
			for(auto& input : parsed_command.inputs) {
				if(auto float_input = std::get_if<float>(&input); float_input != nullptr) {
					cout << "Num input: " << *float_input << '\n';

				} else {
					auto string_input = std::get<string>(input);
					cout << "String input: " << string_input << '\n';
				}
			}
		} catch(const exception& parser_exception) {
			cout << "Error: " << parser_exception.what() << '\n';
		} catch(...) {
			cout << "Error: An error occured :shrug:\n";
		}
		
	}

	std::system("pause");
	return EXIT_SUCCESS;
}