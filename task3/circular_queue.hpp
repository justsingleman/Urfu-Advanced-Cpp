#pragma once
#include <cstddef>
#include <vector>
class CircularQueue {
private:
    std::vector<int> buffer;
    size_t capacity;
    size_t size;
    size_t front;
    size_t rear;
public:
    CircularQueue(size_t size);
    bool Push(int value);
    bool Pop();
    int Front() const;
    int Back() const;
    bool Empty() const;
    bool Full() const;
    CircularQueue(size_t size);
    bool Push(int value);
    bool Pop();
    int Front() const;
    int Back() const;
    bool Empty() const;
    bool Full() const;
};
