#include "VectorDataStructures.hpp"

#include <Utilities/Logging.hpp>
#include <Utilities/StringHelper.hpp>

CVec2::CVec2(const CVec2i& vec) : mX(static_cast<float>(vec.mX)), mY(static_cast<float>(vec.mY)) {}
CVec2::CVec2(const std::string& s) {
	set(s);
}

void CVec2::set(const std::string& s) {
	std::vector<std::string> tokens;
	StringHelper::Explode(s, ",", &tokens);
	if (tokens.size() != 2) {
		LOG_ERROR("Incorrect number of components (%d) in string \'%s\'.", tokens.size(), s);
	}
}

std::string CVec2::ToString() const {
	return StringHelper::Format("%f,%f", mX, mY);
}
