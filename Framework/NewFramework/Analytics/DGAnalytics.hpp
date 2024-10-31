#pragma once

#include <string>

class DGAnalytics {
	static DGAnalytics* _pInstance;
	DGAnalytics() = default;
public:
	static DGAnalytics* Instance();
	void Log(std::string format, ...);
};