#include <string>
#include "Args.h"
#include <variant>


namespace CLI{
//parses arguments
std::variant<CLI::Args, std::string> ParseArguments(int argc, char* argv[]){ //argc stands for argument count, argv stands for argument values
	
	CLI::Args args{};


	for(int i = 1; i < argc; i++){
		std::string arg = argv[i];
		if (arg == "--help"){
			args.help = true;
		}else if(arg == "--input"){
			if ((i + 1) >= argc){
				return "No file path specified";
			}
			char* file_path = argv[i + 1];
			args.inputs.push_back(file_path);
			i++;
		}else if(arg == "--json"){
			if ((i + 1) >= argc){
				return "No Json specified!";
			};

			std::string val = argv[i + 1];
			if (val.starts_with("--")){
				return "Missing name value after --json";
			}

			args.json_out = val;
			i++;

		}else{
			return "Unknown argument specified";
		};

	}


	if(!args.help && args.inputs.empty()){
		return "Error: At least one --input <file> is required";
	};

	return args;


}


std::string Usage(){
	// returns a string describing how to use the program
	return R"(

	csv_analytics
	Usage:

	csv_analytics --input <file.csv> [--input <file2.csv]

	csv analytics --help


	Options:
	--input <path>: CSV file to process(repeatable)
	--json <path>: Write JSON report to file
	--help: Show this help
)";

}
}
