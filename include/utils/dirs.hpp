#pragma once

#include <string>
#include <filesystem>

#include <fmt/format.h>

namespace fs = std::filesystem;

class Dirs {
public:
    static std::string getResourcesDir() {
        auto basePath = fs::current_path();
        std::string::size_type pos = basePath.string().find_last_of("/");
        auto workingPath = basePath.string().substr(0, pos);
        return fmt::format("{}/resources", basePath.string());
    }
};