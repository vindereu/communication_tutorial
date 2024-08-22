#ifndef __MY_QUEUE_HPP__
#define __MY_QUEUE_HPP__
#include <vector>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <iostream>

template<typename T>
class SimpleQueue
{
public:
    SimpleQueue() = delete;

    SimpleQueue(size_t queue_size)
        : maxSize{queue_size}
    {
        assert(queue_size > 0);
        buffer.reserve(queue_size);
    }

    void enqueue(const T &data)
    {
        if (is_full()) {
            buffer[maxSize-1] = data;
            return;
        }

        buffer.push_back(data);
    }

    bool dequeue(T &data)
    {
        if (is_empty())
            return false;

        data = buffer[0];
        buffer.erase(buffer.begin());  // Takes time
        return true;
    }

    const T* peek()
    {
        return buffer.size() ? buffer.data() : nullptr;
    }

    void clear()
    {
        buffer.clear();  // capacity isn't change
    }

    bool is_empty()
    {
        return buffer.size() == 0;
    }

    bool is_full()
    {
        return buffer.size() == maxSize;
    }

    void print_content()
    {
        if (!is_empty())
            print_data(0, buffer.size());

        std::cout << '\n';
    }

    void print_real_layout()
    {
        if (!is_empty()) {
            print_data(0, buffer.size());
        }

        print_empty(maxSize-buffer.size());
        std::cout << '\n';
    }

private:
    const size_t maxSize;
    std::vector<T> buffer;

private:
    void print_empty(size_t amount)
    {
        assert(amount >= 0);
        assert(amount <= maxSize);
        for (size_t i=0; i<amount; i++)
            std::cout << "? ";
    }

    void print_data(size_t start, size_t end)
    {
        assert(start >= 0);
        assert(start < end);
        assert (end <= buffer.size());
        for (size_t i=start; i<end; i++)
            std::cout << buffer[i] << ' ';
    }
};


template<typename T>
class RingQueue_Array
{
public:
    RingQueue_Array() = delete;

    RingQueue_Array(size_t queue_size)
        : maxSize{queue_size}, count{0}, writeIdx{0}, readIdx{0}
    {
        assert(queue_size > 0);
        buffer.reserve(queue_size);
    }

    void enqueue(const T &data)
    {
        buffer[writeIdx] = data;
        if (is_full())
            return;

        count++;
        next_write_idx();
    }

    bool dequeue(T &data)
    {
        if (is_empty())
            return false;
            
        data = buffer[readIdx];
        if (is_full()) {
            count--;
            next_write_idx();
        }
        else
            count--;

        next_read_idx();
        return true;
    }

    const T* peek()
    {
        return count ? &buffer[readIdx] : nullptr;
    }

    void clear()
    {
        buffer.clear();  // capacity isn't change
        count = 0;
        writeIdx = 0;
        readIdx = 0;
    }

    bool is_empty()
    {
        return count == 0;
    }

    bool is_full()
    {
        return count == maxSize;
    }

    void print_content()
    {
        if (!is_empty())
            print_data(0, count);
        
        std::cout << '\n';
    }

    void print_real_layout()
    {
        if (is_empty()) {
            print_empty(maxSize);
            std::cout << '\n';

            print_pointer();
            std::cout << '\n';
            return;
        }

        // Contents display
        if ((readIdx + count - 1) >= maxSize) {
            print_data(maxSize-readIdx, count);
            print_empty(maxSize-count);
            print_data(0, maxSize-readIdx);
        }
        else {
            print_empty(readIdx);
            print_data(0, count);
            print_empty(maxSize - (readIdx+count));
        }
        std::cout << '\n';

        print_pointer();
        std::cout << '\n';
    }
    
private:
    const size_t maxSize;
    size_t count;
    size_t writeIdx, readIdx;
    std::vector<T> buffer;

private:
    void next_write_idx()
    {
        if (is_full())
            return;

        writeIdx = ((writeIdx+1) == maxSize)
                    ? 0
                    : writeIdx + 1;
    }

    void next_read_idx()
    {
        if (is_empty()) {
            readIdx = writeIdx;
            return;
        }

        readIdx = ((readIdx+1) == maxSize)
                    ? 0
                    : readIdx + 1;
    }

    void print_empty(size_t amount)
    {
        assert(amount >= 0 && amount <= maxSize);
        for (size_t i=0; i<amount; i++)
            std::cout << "? ";
    }

    void print_data(size_t start, size_t end)
    {
        assert(start >= 0);
        assert(start < end);
        assert(end <= count);
        for (size_t i=start; i<end; i++) {
            size_t actualIdx = readIdx + i;
            if (actualIdx >= maxSize)
                actualIdx -= maxSize;
            std::cout << buffer[actualIdx] << ' ';
        }
    }

    void print_pointer()
    {
        if (is_empty()) {
            size_t width = writeIdx*2 + 1;
            std::cout.width(width);
            std::cout << '^' << '\n';
            std::cout.width(width);
            std::cout << "(w,r)" << '\n';
            return;
        }

        size_t width[2] = {std::min(readIdx,writeIdx)*2 + 1,
                           (abs((long long)(readIdx-writeIdx))-1)*2 + 1};

        char name[2];
        if (readIdx < writeIdx) {
            name[0] = 'r';
            name[1] = 'w';
        }
        else {
            name[0] = 'w';
            name[1] = 'r';
        }

        for (size_t i=0; i<2; i++) {
            std::cout.width(width[i]);
            std::cout << '^' << ' ';
        }
        std::cout << '\n';

        for (size_t i=0; i<2; i++) {
            std::cout.width(width[i]);
            std::cout << name[i] << ' ';
        }
        std::cout << '\n';
    }
};


// TODO: redesign print framework
class RingQueue_SimpleMultiType
{
public:
    RingQueue_SimpleMultiType() = delete;
    RingQueue_SimpleMultiType(size_t queue_size)
        : maxSize{queue_size}, count{0}, writeIdx{0}, readIdx{0}
    {
        assert(queue_size > 0);
        buffer = new DataDescriptor[queue_size];
    }

    ~RingQueue_SimpleMultiType()
    {
        clear();
        delete[] buffer;
    }

    template<typename T>
    bool enqueue(int64_t id, const T &data)
    {
        DataDescriptor* const pointer = buffer+writeIdx;
        if (is_full())
            delete[] pointer->ptr;

        // Try to allocate memory
        pointer->ptr = new uint8_t[sizeof(T)];
        if (pointer->ptr == nullptr)
            return false;

        // Assign data
        memcpy(pointer->ptr, &data, sizeof(T));
        pointer->userId = id;
        pointer->bytes = sizeof(T);

        // The index remain same if the buffer is full
        if (is_full())
            return true;

        count++;
        next_write_idx();
        return true;
    }

    template<typename T>
    bool dequeue(T &data)
    {
        if (is_empty())
            return false;
        
        DataDescriptor* const pointer = buffer+readIdx;
        if (sizeof(T) != pointer->bytes)
            return false;

        memcpy(&data, pointer->ptr, pointer->bytes);
        delete[] pointer->ptr;
        pointer->ptr = nullptr;
        pointer->userId = -1;
        pointer->bytes = 0;

        if (is_full()) {
            count--;
            next_write_idx();
        }
        else
            count--;
    
        next_read_idx();
        return true;
    }

    int64_t peek()
    {
        return count ? (buffer+readIdx)->userId : -1;
    }

    void clear()
    {
        for (size_t i=0; i<maxSize; i++) {
            delete[] (buffer+i)->ptr;
            (buffer+i)->ptr = nullptr;
        }

        count = 0;
        readIdx = 0;
        writeIdx = 0;
    }

    bool is_empty()
    {
        return count == 0;
    }

    bool is_full()
    {
        return count == maxSize;
    }

    void print_content()
    {
        if (!is_empty())
            print_descriptor(0, count);

        std::cout << '\n';
    }

    void print_real_layout()
    {
        if (is_empty()) {
            // Empty contents
            size_t splitPos = writeIdx + 1;
            print_empty(splitPos, 0, " < (w,r)\n");
            print_empty(maxSize - splitPos, splitPos);
            return;
        }

        if (readIdx < writeIdx) {
            // empty -> data -> empty
            // data -> empty
            // data
            print_empty(readIdx);
            print_read_pointer_data();
            print_descriptor(1, count, readIdx+1, "");
            print_write_pointer_data();
            print_empty(maxSize-writeIdx-1, writeIdx+1);
            std::cout << '\n';
        }
        else {
            // empty -> data
            // data(end) -> empty -> data(start)
            // data(end) -> data(start)
            size_t splitPos = maxSize - readIdx;
            print_descriptor(splitPos, count, 0, "");
            print_write_pointer_data();
            print_empty(readIdx-writeIdx-1, writeIdx+1);
            print_read_pointer_data();
            print_descriptor(1, splitPos, readIdx+1);
        }
    }

private:
    struct DataDescriptor
    {
        int64_t userId;
        size_t bytes;
        uint8_t *ptr;
    };
    
    const size_t maxSize;
    size_t count;
    size_t writeIdx, readIdx;
    DataDescriptor *buffer;
    
private:
    void next_write_idx()
    {
        if (is_full())
            return;

        writeIdx = ((writeIdx+1) == maxSize)
                    ? 0
                    : writeIdx + 1;
    }

    void next_read_idx()
    {
        if (is_empty()) {
            readIdx = writeIdx;
            return;
        }
        readIdx = ((readIdx+1) == maxSize)
                    ? 0
                    : readIdx + 1;
    }

    void print_empty(size_t amount=1, size_t startLine=0, std::string endStr="\n")
    {
        for (size_t i=0; i<amount; i++) {
            std::cout << i+startLine << ". ?";
            if (i < amount-1)
                std::cout << '\n';
            else
                std::cout << endStr;
        }
    }

    void print_descriptor(DataDescriptor *ptr)
    {
        assert(ptr != nullptr);
        std::cout << "Id: " << ptr->userId << ' '
                  << "Bytes: " << ptr->bytes << ' '
                  << "Addr: " << (void*)(ptr->ptr);
    }

    void print_descriptor(size_t start, size_t end, size_t startLine=0, std::string endStr="\n")
    {
        assert(start >= 0);
        assert(end <= count);

        for (size_t i=start; i<end; i++) {
            std::cout << (i-start)+startLine << ". ";
            size_t actualIdx = readIdx+i;
            if (actualIdx >= maxSize)
                actualIdx -= maxSize;
            print_descriptor(buffer+actualIdx);
            
            if (i < end-1)
                std::cout << '\n';
            else
                std::cout << endStr;
        }
    }

    void print_read_pointer_data()
    {
        print_descriptor(0, 1, readIdx, " < r\n");
    }

    void print_write_pointer_data()
    {
        if (is_full()) {
            std::cout << " < w\n";
            return;
        }

        if (count != 1)
            std::cout << '\n';
        
        print_empty(1, writeIdx, " < w\n");
    }
};


// TODO: roughly same as the RingQueue_SimpleMultiType
class RingQueue_MultiType_KeepBuffer
{
public:
    RingQueue_MultiType_KeepBuffer() = delete;
    RingQueue_MultiType_KeepBuffer(size_t queue_size)
        : maxSize{queue_size}, count{0}, writeIdx{0}, readIdx{0}
    {
        assert(queue_size > 0);
        buffer = new DataDescriptor[queue_size];
    }

    ~RingQueue_MultiType_KeepBuffer()
    {
        deep_clear();
        delete[] buffer;
    }

    template<typename T>
    bool enqueue(int64_t id, const T &data)
    {
        DataDescriptor* pointer = buffer+writeIdx;
        // Is size > capacity
        if (sizeof(T) > pointer->capacity) {
            delete[] pointer->ptr;
            pointer->ptr = new uint8_t[sizeof(T)];
            
            if (pointer->ptr == nullptr) {
                pointer->capacity = 0;
                pointer->size = 0;
                pointer->userId = -1;
                return false;
            }

            pointer->capacity = sizeof(T);
        }

        // Assign data
        memcpy(pointer->ptr, &data, sizeof(T));
        pointer->userId = id;
        pointer->size = sizeof(T);

        // The index remain same if the buffer is full
        if (is_full()) {
            return true;
        }

        count++;
        next_write_idx();
        return true;
    }

    template<typename T>
    bool dequeue(T &data)
    {
        if (is_empty())
            return false;

        DataDescriptor* pointer = buffer+readIdx;
        if(sizeof(T) != pointer->size)
            return false;

        // Assign data
        memcpy(&data, pointer->ptr, pointer->size);
        
        // Note the space is not used
        pointer->size = 0;
        pointer->userId = -1;

        // Move pointer
        if (is_full()) {
            count--;
            next_write_idx();
        }
        else
            count--;

        next_read_idx();
        return true;
    }

    int64_t peek()
    {
        return count ? (buffer+readIdx)->userId : -1;
    }

    void clear()
    {
        for (size_t i=0; i<maxSize; i++)
            (buffer+i)->size = 0;

        count = 0;
        readIdx = 0;
        writeIdx = 0;
    }

    void deep_clear()
    {
        for (size_t i=0; i<maxSize; i++) {
            delete[] (buffer+i)->ptr;
            (buffer+i)->ptr = nullptr;
            (buffer+i)->size = 0;
            (buffer+i)->capacity = 0;
            (buffer+i)->userId = -1;
        }

        count = 0;
        readIdx = 0;
        writeIdx = 0;
    }

    bool is_empty()
    {
        return count == 0;
    }

    bool is_full()
    {
        return count == maxSize;
    }

    void print_content()
    {
        if (!is_empty())
            print_descriptor(0, count);

        std::cout << '\n';
    }

    void print_real_layout()
    {
        if (is_empty()) {
            // Empty contents
            size_t splitPos = writeIdx + 1;
            print_empty(splitPos, 0, " < (w,r)\n");
            print_empty(maxSize - splitPos, splitPos);
            return;
        }

        if (readIdx < writeIdx) {
            // empty -> data -> empty
            // data -> empty
            // data
            print_empty(readIdx);
            print_read_pointer_data();
            print_descriptor(1, count, readIdx+1, "");
            print_write_pointer_data();
            print_empty(maxSize-writeIdx-1, writeIdx+1);
            std::cout << '\n';
        }
        else {
            // empty -> data
            // data(end) -> empty -> data(start)
            // data(end) -> data(start)
            size_t splitPos = maxSize - readIdx;
            print_descriptor(splitPos, count, 0, "");
            print_write_pointer_data();
            print_empty(readIdx-writeIdx-1, writeIdx+1);
            print_read_pointer_data();
            print_descriptor(1, splitPos, readIdx+1);
        }
    }

private:
    struct DataDescriptor
    {
        int64_t userId;
        size_t capacity;
        size_t size;
        uint8_t *ptr;
    };
    
    const size_t maxSize;
    size_t count;
    size_t writeIdx, readIdx;
    DataDescriptor *buffer;

private:
    void next_write_idx()
    {
        if (is_full())
            return;

        writeIdx = ((writeIdx+1) == maxSize)
                    ? 0
                    : writeIdx + 1;
    }

    void next_read_idx()
    {
        if (is_empty()) {
            readIdx = writeIdx;
            return;
        }
        readIdx = ((readIdx+1) == maxSize)
                    ? 0
                    : readIdx + 1;
    }

    void print_empty(size_t amount=1, size_t startLine=0, std::string endStr="\n")
    {
        for (size_t i=0; i<amount; i++) {
            std::cout << i+startLine << ". ?";
            if (i < amount-1)
                std::cout << '\n';
            else
                std::cout << endStr;
        }
    }

    void print_descriptor(DataDescriptor *ptr)
    {
        std::cout << "Id: " << ptr->userId << ' '
                  << "Size: " << ptr->size << ' '
                  << "Capacity: " << ptr->capacity << ' '
                  << "Addr: " << (void*)(ptr->ptr);
    }

    void print_descriptor(size_t start, size_t end, size_t startLine=0, std::string endStr="\n")
    {
        assert(start >= 0);
        assert(end <= count);

        for (size_t i=start; i<end; i++) {
            std::cout << (i-start)+startLine << ". ";
            size_t actualIdx = readIdx+i;
            if (actualIdx >= maxSize)
                actualIdx -= maxSize;
            print_descriptor(buffer+actualIdx);
            
            if (i < end-1)
                std::cout << '\n';
            else
                std::cout << endStr;
        }
    }

    void print_read_pointer_data()
    {
        print_descriptor(0, 1, readIdx, " < r\n");
    }

    void print_write_pointer_data()
    {
        if (is_full()) {
            std::cout << " < w\n";
            return;
        }

        if (count != 1)
            std::cout << '\n';
        
        print_empty(1, writeIdx, " < w\n");
    }
};

#endif /* __MY_QUEUE_HPP__ */
