#ifndef CONFIG_HPP_INCLUDED
#define CONFIG_HPP_INCLUDED
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

#include "vulkan_include.hpp"

struct vec3f{
  float r;
  float g;
  float b;
};

namespace vkBasalt
{
    class Config
    {
    public:
        Config();
        Config(const Config& other);

        template<typename T>
        T getOption(const std::string& option, const T& defaultValue = {})
        {
            T result = defaultValue;
            parseOption(option, result);
            return result;
        }
        float parseOption(const std::string& option,uint32_t offset);

    private:
        std::unordered_map<std::string, std::string> options;

        void readConfigLine(std::string line);
        void readConfigFile(std::ifstream& stream);

        void parseOption(const std::string& option, int32_t& result);
        void parseOption(const std::string& option, float& result);
        void parseOption(const std::string& option, bool& result);
        void parseOption(const std::string& option, std::string& result);
        void parseOption(const std::string& option, std::vector<std::string>& result);
    };
} // namespace vkBasalt

#endif // CONFIG_HPP_INCLUDED
