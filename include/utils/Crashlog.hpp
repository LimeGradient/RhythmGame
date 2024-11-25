#pragma once

#include <filesystem>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

#include <fmt/format.h>
#include <cpptrace/cpptrace.hpp>

namespace fs = std::filesystem;

class Crashlog {
public:
    static std::string getCurrentDate() {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);

        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
        return ss.str();
    }

    static void generateCrashlog(int signum) {  
        auto crashlogPath = fmt::format("{}/crashlogs", fs::current_path().string());

        if (!fs::exists(crashlogPath))
            fs::create_directory(crashlogPath);
        
        std::ofstream crashlogFile(fmt::format("{}/{}.log", crashlogPath, getCurrentDate()));
        crashlogFile << cpptrace::generate_trace().to_string();
        crashlogFile.close();

        exit(signum);
    }
};