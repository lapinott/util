#include <util/split.h>
#include <sstream>
#include <iterator>

namespace util {

	std::vector<std::string> split(const std::string& s, char delim) {
		std::vector<std::string> elems;
		split(s, delim, std::back_inserter(elems));
		return elems;
	}
}