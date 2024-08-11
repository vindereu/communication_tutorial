#ifndef __INPUT_PROCESS_HPP__
#define __INPUT_PROCESS_HPP__
#include <iostream>
#include <limits>

void clean_input_buffer(std::istream &src)
{
    src.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool reset_input_error(std::istream &src)
{
    if (src.good())
        return false;
        
    src.clear();
    clean_input_buffer(src);
    return true;
}

bool input_valid_process()
{
    // reset cin error flag
    if (std::cin.eof())
        exit(0);
        
    if (reset_input_error(std::cin)) {
        std::cout << "[Error]Wrong input\n";
        return false;
    }

    clean_input_buffer(std::cin);
    return true;
}

#endif /* __INPUT_PROCESS_HPP__ */