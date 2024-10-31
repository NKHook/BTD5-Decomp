#include "Logging.hpp"

#include <Analytics/DGAnalytics.hpp>
#include <cstdarg>
#include <cstring>

CLogging* CLogging::m_pInstance = nullptr;
CLogging *CLogging::GetSingletonPtr() {
	if (!m_pInstance) {
		m_pInstance = new CLogging();
	}
	return m_pInstance;
}

void CLogging::PrintError(const char* file, const char* func, int line, const char* message, ...) {
	if (message != nullptr) {
		va_list lst;
		va_start(lst, message);
		VPrintError(file, func, line, message, lst);
		va_end(lst);
	}
}

#define MAX_TEXT_BUFFER 0x5000
void CLogging::VPrintError(const char* file, const char* func, int line, const char* message, va_list args) {
	std::unique_lock guard(mMutex);
	static char text[MAX_TEXT_BUFFER];
	vsnprintf(text, MAX_TEXT_BUFFER - 1, message, args);
	static char final[MAX_TEXT_BUFFER];
	sprintf(final, ">> %s:%d %s %s", file, line, func, text);
	for (auto& component : mComponents) {
		component->Error(final);
	}
	DGAnalytics::Instance()->Log(final);
}

void CLogging::PrintWarning(const char* file, const char* func, int line, const char* message, ...) {
	if (message != nullptr) {
		va_list lst;
		va_start(lst, message);
		VPrintError(file, func, line, message, lst);
		va_end(lst);
	}
}

#define LEN_TIMESTAMP 0x20
void CLogging::VPrintWarning(const char* file, const char* func, int line, const char* message, va_list args) {
	std::unique_lock guard(mMutex);
	static char timestamp[LEN_TIMESTAMP];
	static time_t t = 0;
	auto now = time(nullptr);
	static size_t result = 0;
	if (t != now) {
		result = strftime(timestamp, LEN_TIMESTAMP, "%d/%m/%y %H:%M:%S > ", localtime(&now));
		t = now;
	}
	auto len = result;
	static char text[MAX_TEXT_BUFFER];
	if (result == 0) {
		len = MAX_TEXT_BUFFER;
	} else {
		memcpy(text, timestamp, result);
		if (len - MAX_TEXT_BUFFER == 0) {
			return;
		}
		len = -(len - MAX_TEXT_BUFFER);
	}
	vsnprintf(text, len, message, args);
	for (auto& component : mComponents) {
		component->Warning(message);
	}
}


