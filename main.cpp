#include <iostream>
#include <ctime>
#include <iomanip>
#include <unistd.h>

int main() {
    const time_t t = time(nullptr);
    tm userTime = *localtime(&t);
    std::cin >> std::get_time(&userTime, "%M:%S");
    system("cls"); // IDE or other consoles work strangely with this, external console work correctly
    const auto timer = userTime.tm_min * 60 + userTime.tm_sec;
    int min = userTime.tm_min;
    int sec = userTime.tm_sec;
    for (int i = timer; i != 0; --i) {
        std::cout << std::setw(2) << std::setfill('0') << min << ":" <<
            std::setw(2) << std::setfill('0') << sec << std::endl;
        sleep(1);
        if (sec == 0) { sec = 60; --min; }
        --sec;
        system("cls");
    }
    std::cout << "Time's up!" << std::endl;
    return 0;
}
