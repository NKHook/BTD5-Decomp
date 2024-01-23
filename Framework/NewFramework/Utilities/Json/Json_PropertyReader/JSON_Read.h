#pragma once

#include <map>
#include <string>

class JSON_PropertyReader
{
public:
    std::map<std::string, JsonValue>* mData{};
    std::map<std::string, JsonValue>* mOtherData{};
    char padding_0008[8]{};
    bool reading = false;
    float N000023D7 = 1.0f;
    float N000023D8 = 1.0f;

    void Read(uint32_t& flags, CFlagStringConvertor* convertor, int category, std::string& key)
    {
        ReadFromObject(flags, key)
    }

    template<typename type_t>
    void ReadFromObject(type_t& data, const std::string& key)
    {
        if(this->reading)
        {
            const auto& iter = this->mData->find(key);
            if(iter != this->mData->end())
            {
                //Throw JSON_PropertyException
            }
            auto success = GetValueFromObject(this->mData, key, data);
            if(!success)
                return;
        }
    }

    template<typename type_t>
    static bool GetValueFromObject(std::map<std::string, json_spirit::Value> const* objectData, type_t& value, const std::string& key)
    {
        if(objectData == nullptr)
            return false;

        const auto& iter = objectData->find(key);
        if(iter != objectData->end()) {
            value = *iter;
            return true;
        }

        return false;
    }
};