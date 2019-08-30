
#include <string>
#include <vector>
//#include <sstream>

class CSVParser
{
private:
	std::string				 input;
	std::vector<std::string> record;

public:
	CSVParser(std::string);

	void parse(void);

	std::string operator [](int) const;
};

