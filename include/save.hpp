#pragma once
#include <filesystem>

class Save
{
public:
        Save(const char* p);
private:
        std::filesystem::path path;

};
