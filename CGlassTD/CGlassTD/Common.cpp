#include "Common.h"

std::vector<std::string> mysplit( std::string str )
{
	using namespace std;
	std::vector<std::string> outArr;

	istringstream iss(str);
	copy(istream_iterator<string>(iss),
		istream_iterator<string>(),
		 back_inserter<vector<string> >(outArr));

	return outArr;
}

std::string convertToString( double num )
{
	std::ostringstream stream;
	stream << num;

	return stream.str();
}
