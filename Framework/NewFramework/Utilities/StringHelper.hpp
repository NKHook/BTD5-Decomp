#pragma once

#include <string>
#include <vector>

class StringHelper {
public:
	static std::string Format(const std::string& format, ...);
	static void StringHelper::Explode(const std::string&, const std::string&, std::vector<std::string>*);
};
