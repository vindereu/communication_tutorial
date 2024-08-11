#ifndef __QUEUE_PROCESS_HPP__
#define __QUEUE_PROCESS_HPP__
#include <iostream>
#include "my_queue.hpp"
#include "input_process.hpp"

void hints_for_menu()
{
    std::cout << "[Info]Hint:\n"
              << "0: quit\n"
              << "1: simple queue(single type)\n"
              << "2: ring queue array(single type)\n"
              << "3: ring queue array(multi type)\n"
              << "4: ring queue array keep buffer(multi type)\n\n";
}

void hints_for_queue()
{
    std::cout << "[Info]Hint:\n"
              << "-2: which queue type\n"
              << "-1: hint\n"
              << "0: quit\n"
              << "1: enqueue\n"
              << "2: dequeue\n"
              << "3: peek\n"
              << "4: clear\n"
              << "5: is_full\n"
              << "6: is_empty\n"
              << "7: content(debug)\n\n";
}

void simple_queue_process()
{
    static SimpleQueue<int> queue(10);

    hints_for_queue();
    
    int option;
    int data;
    const int* dataPtr;
    bool isSuccess;
    while (1) {
        std::cout << "[In]Option:";
        std::cin >> option;
        if (!input_valid_process())
            continue;
    
        switch (option)
        {
        case -2:
            std::cout << "[Out]simple queue(array, single type)\n";
            break;
        
        case -1:
            hints_for_queue();
            break;
        
        case 0:
            queue.clear();
            return;
            break;
        
        case 1:
            data = random() % 10;  // 0~9
            queue.enqueue(data);
            std::cout << "[Out]Enqueue data: " << data << '\n';
            break;
        
        case 2:
            isSuccess = queue.dequeue(data);
            if (isSuccess)
                std::cout << "[Out]Dequeue data: " << data << '\n';
            else
                std::cout << "[Out]Buffer is empty\n";
            break;
        
        case 3:
            dataPtr = queue.peek();
            if (dataPtr == nullptr)
                std::cout << "[Out]Buffer is empty\n";
            else
                std::cout << "[Out]Peeked data: " << *dataPtr  << '\n';
            break;

        case 4:
            queue.clear();
            break;
        
        case 5:
            std::cout << "[Out]Is full?: ";
            if (queue.is_full())
                std::cout << "True\n";
            else
                std::cout << "False\n";
            break;
        
        case 6:
            std::cout << "[Out]Is empty?: ";
            if (queue.is_empty())
                std::cout << "True\n";
            else
                std::cout << "False\n";
            break;

        case 7:
            std::cout << "[Out]Buffer content:\n";
            std::cout << "User perspective:\n";
            queue.print_content();
            std::cout << "Real layout:\n";
            queue.print_real_layout();
            break;

        default:
            std::cout << "[Error]Wrong command\n";
            break;
        }

        std::cout << '\n';
    }
}

void ring_queue_array_process()
{
    static RingQueue_Array<int> queue(10);

    hints_for_queue();
    
    int option;
    int data;
    const int* dataPtr;
    bool isSuccess;
    while (1) {
        std::cout << "[In]Option:";
        std::cin >> option;
        if (!input_valid_process())
            continue;
    
        switch (option)
        {
        case -2:
            std::cout << "[Out]ring queue(array, single type)\n";
            break;
        
        case -1:
            hints_for_queue();
            break;
        
        case 0:
            queue.clear();
            return;
            break;
        
        case 1:
            data = random() % 10;  // 0~9
            queue.enqueue(data);
            std::cout << "[Out]Enqueue data: " << data << '\n';
            break;
        
        case 2:
            isSuccess = queue.dequeue(data);
            if (isSuccess)
                std::cout << "[Out]Dequeue data: " << data << '\n';
            else
                std::cout << "[Out]Buffer is empty\n";
            break;
        
        case 3:
            dataPtr = queue.peek();
            if (dataPtr == nullptr)
                std::cout << "[Out]Buffer is empty\n";
            else
                std::cout << "[Out]Peeked data: " << *dataPtr  << '\n';
            break;

        case 4:
            queue.clear();
            break;
        
        case 5:
            std::cout << "[Out]Is full?: ";
            if (queue.is_full())
                std::cout << "True\n";
            else
                std::cout << "False\n";
            break;
        
        case 6:
            std::cout << "[Out]Is empty?: ";
            if (queue.is_empty())
                std::cout << "True\n";
            else
                std::cout << "False\n";
            break;

        case 7:
            std::cout << "[Out]Buffer content:\n";
            std::cout << "User perspective:\n";
            queue.print_content();
            std::cout << "Real layout:\n";
            queue.print_real_layout();
            break;

        default:
            std::cout << "[Error]Wrong command\n";
            break;
        }

        std::cout << '\n';
    }
}

void ring_queue_multi_type_process()
{
    static RingQueue_SimpleMultiType queue(10);

    hints_for_queue();
    
    int option;
    int data;
    int id;
    bool isSuccess;
    while (1) {
        std::cout << "[In]Option:";
        std::cin >> option;
        if (!input_valid_process()) {
            std::cout << '\n';
            continue;
        }
    
        switch (option)
        {
        case -2:
            std::cout << "[Out]ring queue(array, multi-type)\n";
            break;
        
        case -1:
            hints_for_queue();
            break;
        
        case 0:
            queue.clear();
            return;
            break;
        
        case 1:
            data = random() % 10;  // 0~9
            queue.enqueue(1, data);
            std::cout << "[Out]Enqueue data: " << data << '\n';
            break;
        
        case 2:
            isSuccess = queue.dequeue(data);
            if (isSuccess)
                std::cout << "[Out]Dequeue data: " << data << '\n';
            else
                std::cout << "[Out]Buffer is empty\n";
            break;
        
        case 3:
            id = queue.peek();
            if (id == -1)
                std::cout << "[Out]Buffer is empty\n";
            else
                std::cout << "[Out]Peeked data: " << id  << '\n';
            break;

        case 4:
            queue.clear();
            break;
        
        case 5:
            std::cout << "[Out]Is full?: ";
            if (queue.is_full())
                std::cout << "True\n";
            else
                std::cout << "False\n";
            break;
        
        case 6:
            std::cout << "[Out]Is empty?: ";
            if (queue.is_empty())
                std::cout << "True\n";
            else
                std::cout << "False\n";
            break;

        case 7:
            std::cout << "[Out]Buffer content:\n";
            std::cout << "User perspective:\n";
            queue.print_content();
            std::cout << "Real layout:\n";
            queue.print_real_layout();
            break;

        default:
            std::cout << "[Error]Wrong command\n";
            break;
        }

        std::cout << '\n';
    }
}

void ring_queue_multi_type_keep_buffer_process()
{
    static RingQueue_MultiType_KeepBuffer queue(10);
    hints_for_queue();
    
    int option;
    int data;
    int id;
    bool isSuccess;
    while (1) {
        std::cout << "[In]Option:";
        std::cin >> option;
        if (!input_valid_process())
            continue;
    
        switch (option)
        {
        case -2:
            std::cout << "[Out]ring queue(array, multi-type, keep buffer)\n";
            break;
        
        case -1:
            hints_for_queue();
            break;
        
        case 0:
            queue.deep_clear();
            return;
            break;
        
        case 1:
            data = random() % 10;  // 0~9
            queue.enqueue(1, data);
            std::cout << "[Out]Enqueue data: " << data << '\n';
            break;
        
        case 2:
            isSuccess = queue.dequeue(data);
            if (isSuccess)
                std::cout << "[Out]Dequeue data: " << data << '\n';
            else
                std::cout << "[Out]Buffer is empty\n";
            break;
        
        case 3:
            id = queue.peek();
            if (id == -1)
                std::cout << "[Out]Buffer is empty\n";
            else
                std::cout << "[Out]Peeked data: " << id  << '\n';
            break;

        case 4:
            queue.clear();
            break;
        
        case 5:
            std::cout << "[Out]Is full?: ";
            if (queue.is_full())
                std::cout << "True\n";
            else
                std::cout << "False\n";
            break;
        
        case 6:
            std::cout << "[Out]Is empty?: ";
            if (queue.is_empty())
                std::cout << "True\n";
            else
                std::cout << "False\n";
            break;

        case 7:
            std::cout << "[Out]Buffer content:\n";
            std::cout << "User perspective:\n";
            queue.print_content();
            std::cout << "Real layout:\n";
            queue.print_real_layout();
            break;

        default:
            std::cout << "[Error]Wrong command\n";
            break;
        }

        std::cout << '\n';
    }
}



#endif /* __QUEUE_PROCESS_HPP__ */