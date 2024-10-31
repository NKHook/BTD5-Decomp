#include "DGAnalytics.hpp"

DGAnalytics* DGAnalytics::_pInstance = nullptr;
DGAnalytics* DGAnalytics::Instance() {
	if (!_pInstance) {
		_pInstance = new DGAnalytics();
	}
	return _pInstance;
}

void DGAnalytics::Log(std::string format, ...) {

}
