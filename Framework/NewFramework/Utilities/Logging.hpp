#pragma once

#include <mutex>
#include <vector>

class ILoggingComponent {
public:
	virtual ~ILoggingComponent() = 0;
	virtual void Unknown() = 0;
	virtual void Error(const char* message) = 0;
	virtual void Warning(const char* message) = 0;
};
class CLogging {
	std::vector<ILoggingComponent*> mComponents{};
	std::mutex mMutex{};
	static CLogging* m_pInstance;
public:
	CLogging() = default;
	static CLogging* GetSingletonPtr();

	void PrintError(const char* file, const char* func, int line, const char* message, ...);
	void VPrintError(const char* file, const char* func, int line, const char* message, va_list args);

	void PrintWarning(const char* file, const char* func, int line, const char* message, ...);
	void VPrintWarning(const char* file, const char* func, int line, const char* message, va_list args);
};
#define LOG_ERROR(msg, ...) CLogging::GetSingletonPtr()->PrintError(__FILE__, __FUNCTION__, __LINE__, msg, __VA_ARGS__);