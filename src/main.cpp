#include <iostream>
#include "cli/Args.h"

int main(int argc, char** argv){
	(void)argc;
	(void)argv;


	std::cout << "csv_analytics\n"
		  << "Usage: csv_analytics [--help]\n"
		  << "Step1 placeholder: build + test scaffolding";


	std::variant<CLI::Args, std::string> res = CLI::ParseArguments(argc, argv);

	if(std::holds_alternative<std::string>(res)){
		std::cerr << std::get<std::string>(res)<< std::endl;
		//we need to use std::get to get the value of the variant and specify which type it is
		std::cerr << CLI::Usage() << std::endl; //string can just directly printk
		return 2;
	}else if(std::holds_alternative<CLI::Args>(res)){
		CLI::Args args = std::get<CLI::Args>(res);

		if (args.help == true){
			std::cout << CLI::Usage() << std::endl;
			return 0;

		}else{
			std::cout << "Parsed <N> input file(s)";
			return 0;

		}

	}



	


	return 0;
}
