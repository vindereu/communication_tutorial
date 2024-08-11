#include <iostream>
#include <limits>
#include <random>
#include <ctime>
#include "queue_test/queue_process.hpp"

int main()
{
    srand(time(0));  // set random seed by current time

    int option = 0;
    while (true) {
        hints_for_menu();
        std::cout << "[In]Option:";
        std::cin >> option;

        if (!input_valid_process())
            continue;

        switch (option)
        {
        case 0:
            exit(0);
            break;
        case 1:
            simple_queue_process();
            break;
        case 2:
            ring_queue_array_process();
            break;
        case 3:
            ring_queue_multi_type_process();
            break;
        case 4:
            ring_queue_multi_type_keep_buffer_process();
            break;
        default:
            std::cout << "[Error]Wrong command\n";
            break;
        }

        std::cout << '\n';
    }

    std::cout << "\r[Info]Done\n";
}
