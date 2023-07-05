/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-enzo.daumalle
** File description:
** ProgressBar.cpp
*/

#include "Raytracer.hpp"

static std::string format_duration(std::chrono::seconds duration) {
    std::ostringstream oss;
    auto hours = std::chrono::duration_cast<std::chrono::hours>(duration);
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration % std::chrono::hours(1));
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration % std::chrono::minutes(1));
    oss << std::setfill('0') << std::setw(2) << hours.count() << "h"
        << std::setfill('0') << std::setw(2) << minutes.count() << "m"
        << std::setfill('0') << std::setw(2) << seconds.count() << "s";
    return oss.str();
}

void progress_bar(std::atomic<double>& progress, int image_width, int image_height, std::chrono::steady_clock::time_point start_time) {
    int bar_width = 50;

    while (progress < 1.0) {
        int filled_width = static_cast<int>(progress * bar_width);
        std::string bar(filled_width, '=');
        std::string empty_bar(bar_width - filled_width, ' ');

        // Compute the remaining time
        auto now = std::chrono::steady_clock::now();
        double elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(now - start_time).count() / 1000.0;
        double remaining_seconds = elapsed_seconds / progress - elapsed_seconds;
        std::string remaining_time = "  |  ETA: " + format_duration(std::chrono::seconds(static_cast<int>(remaining_seconds)));

        // Compute the pixels per second
        int num_pixels_processed = static_cast<int>(progress * image_width * image_height);
        double pixels_per_second = num_pixels_processed / elapsed_seconds;

        std::cerr << "\r" << std::string(120, ' ') << "\r";
        std::cerr << "\r[" << bar << empty_bar << "] " << std::fixed << std::setprecision(1) << (progress * 100.0) << "%" << remaining_time << "  |  " << pixels_per_second << " pixels/s" << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cerr << "\r" << std::string(120, ' ') << "\r";
}