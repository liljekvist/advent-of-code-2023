#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

auto main() -> int
{
	std::string buffer;

	std::vector<char> arr_buffer;

	std::ifstream file("../../advent-of-code-2023/advent-of-code-2023/resources/day1-data.txt");

	if (!file.is_open())
		return -1;

	int32_t result_value = 0;

	while (std::getline(file, buffer)) {
		std::cout << buffer << std::endl;
		std::ranges::copy(buffer.begin(), buffer.end(), std::back_inserter(arr_buffer));

		auto result = std::ranges::find_if(arr_buffer.begin(), arr_buffer.end(), [](char c) { return std::isdigit(c); });

		auto result_2 = std::ranges::find_if(arr_buffer.rbegin(), arr_buffer.rend(), [](char c) { return std::isdigit(c); });

		if(result != arr_buffer.end() && result_2 != arr_buffer.rend())
		{
			std::string value_as_string = std::format("{}{}", *result, *result_2);

			result_value += std::stoi(value_as_string);
		}

		arr_buffer.clear();

	}

	std::cout << result_value;

	file.close();
	return 0;

}