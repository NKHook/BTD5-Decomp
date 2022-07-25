#pragma once

#include <string>
#include <stdint.h>

class CFlagStringConverter {
public:
    CategoryStruct* GetCategory(uint32_t categoryId);
    std::string* FlagToString(std::string* result, uint32_t category, uint64_t flag);
    uint64_t StringToFlag(uint32_t category, std::string* result);
}