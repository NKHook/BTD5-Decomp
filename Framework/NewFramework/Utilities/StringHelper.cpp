#include "StringHelper.hpp"

#include <cstdarg>

std::string StringHelper::Format(const std::string& format, ...) {
	static std::string sEncodingError = "Encoding error when calling StringHelper::Format()";
	static std::string sEmptyFormatStringError = "Empty format string passed to StringHelper::Format()";

	if (format.empty()) {
		return sEmptyFormatStringError;
	}

	std::string result;
	va_list lst;
	va_start(lst, format);
	auto len = vsnprintf(nullptr, 0, format.c_str(), lst);
	if (len >= 0) {
		result.resize(len);
		auto resLen = vsnprintf(result.data(), len + 1, format.c_str(), lst);
		if (resLen >= 0) {
			return result;
		}
	}
	return sEncodingError;
	va_end(lst);
}
void StringHelper::Explode(const std::string& s, const std::string& delimiter, std::vector<std::string>* result) {
	auto temp = s;
	while(temp.find_first_of(delimiter) != std::string::npos) {
		result->push_back(temp.substr(0, temp.find_first_of(delimiter)));
		temp.erase(0, temp.find_first_of(delimiter) + 1);
	}
}
