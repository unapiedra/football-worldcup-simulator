#include "stdafx.h"
#include "json.h"

#include "Simulation.h"

void debug_terminate()
{
	std::cerr << "Uncaught exception." << std::endl;
	assert(false);
}

int main(int argc, char* argv[])
{
	// options can either be passed as a filename in the command line or as input to stdin
	std::string inputFilename = "";
	for (int i = 1; i < argc; ++i)
	{
		std::string option = argv[i];

		if (option == "-f" && (i < argc - 1))
		{
			inputFilename = argv[i + 1];
		}
	}

	json_spirit::Value jsonData;
	bool jsonResult = false;

	if (!inputFilename.empty())
	{
		std::ifstream input(inputFilename, std::ifstream::in);
		jsonResult = json_spirit::read((std::istream&)input, jsonData);
	}
	else
	{
		jsonResult = json_spirit::read((std::istream&)std::cin, jsonData);
	}

	if (!jsonResult)
	{
		exit(1);
	}

	std::set_terminate(debug_terminate);

#ifdef NDEBUG
	try
#endif
	{

		sim::Simulation simulation(jsonData);
		simulation.execute();

		json_spirit::Object results = simulation.getJSONResults();
		std::string json = json_spirit::write(results, json_spirit::remove_trailing_zeros);
		std::cout << json << std::endl;
	}
#ifdef NDEBUG
	catch(const std::runtime_error& re)
	{
		std::cerr << "Runtime error: " << re.what() << std::endl;
		assert (false);
		exit(1);
	}
	catch(const std::exception& ex)
	{
		std::cerr << "Error occurred: " << ex.what() << std::endl;
		assert (false);
		exit(1);
	}
	catch (const char *s)
	{
		std::cerr << s << std::endl;
		assert(false);
		exit(1);
	}
	catch (std::string &s)
	{
		std::cerr << s << std::endl;
		assert(false);
		exit(1);
	}
	catch(...)
	{
		std::cerr << "An unexpected error occurred." << std::endl;
		assert (false);
		exit(1);
	}
#endif
	

	return 0;
}

