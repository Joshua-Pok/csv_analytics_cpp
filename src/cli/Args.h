#pragma once // tells compiler to only include this header file once
#include <string>
#include <variant>
#include <vector>

//"using namespace std" makes all the names in std available without qualification in the current scope

namespace CLI{
	struct Args {
	bool help = false;
	std::vector<std::string> inputs; //std::vector is basically an array
	std::string json_out;
	};

        std::variant<CLI::Args, std::string> ParseArguments(int argc, char* argv[]);
	std::string Usage();

}





