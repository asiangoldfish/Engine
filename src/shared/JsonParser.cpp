#include "JsonParser.h"

#include "nlohmann/json.hpp"

#include <fstream>

JsonParser::JsonParser()
{

}

bool JsonParser::load(std::string filepath)
{
    // Load file
    std::ifstream infile(filepath);

    if (infile)
    {
        infile >> jsonData;
        infile.close();
    }
    else
    {
        return false;
    }
}

int JsonParser::getInt(const std::string& key) const
{
    if (jsonData.contains(key) && jsonData.at(key).is_number_integer())
    {
        return jsonData[key].get<int>();
    }
    else
    {
        std::cerr 
            << "Error: Key \'" << key << "\' does not exist or is not an integer" 
            << std::endl;

    }
}

float JsonParser::getFloat(const std::string& key) const
{
    return 0.0f;
}

std::string JsonParser::getString(const std::string& key) const
{
    return std::string();
}

bool JsonParser::getBool(const std::string& key) const
{
    return false;
}
