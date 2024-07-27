#include <iostream>
#include <ctime>
#include <iomanip>
#include <unistd.h>

int main() {
    const time_t t = time(nullptr);
    tm userTime = *localtime(&t);
    std::cin >> std::get_time(&userTime, "%M:%S");

    const auto timer = userTime.tm_min * 60 + userTime.tm_sec;
    int min = 0;
    int sec = 0;
    for (int i = 0; i < timer; ++i) {
        ++sec;
        if (sec == 60) { sec = 0; ++min; }
        std::cout << std::setw(2) << std::setfill('0') << min << ":" <<
            std::setw(2) << std::setfill('0') << sec << std::endl;
        sleep(1);
    }
    std::cout << "Time's up!" << std::endl;
    return 0;
}
