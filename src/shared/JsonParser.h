#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <iostream>
#include "nlohmann/json.hpp"

class JsonParser
{
private:
    nlohmann::json jsonData;

public:
    JsonParser();
    virtual ~JsonParser() = default;
    bool load(std::string filepath);

    int getInt(const std::string &key) const;
    float getFloat(const std::string &key) const;
    std::string getString(const std::string &key) const;
    bool getBool(const std::string &key) const;    
};

#endif