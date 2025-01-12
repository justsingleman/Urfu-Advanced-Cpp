#include "circular_queue.hpp"
#include <iostream>

int main() {
    CircularQueue queue(5);

    // Добавляем элементы
    queue.Push(1);
    queue.Push(2);
    queue.Push(3);
    queue.Push(4);
    queue.Push(5);

    std::cout << "Front: " << queue.Front() << std::endl; 
    std::cout << "Back: " << queue.Back() << std::endl;   

    // Попробуем добавить еще один элемент (должно вернуть false)
    if (!queue.Push(6)) {
        std::cout << "Queue is full!" << std::endl; 
    }

    // Удаляем элементы
    queue.Pop();
    queue.Pop();

    std::cout << "Front: " << queue.Front() << std::endl; 
    std::cout << "Back: " << queue.Back() << std::endl;  

    // Добавляем новый элемент
    queue.Push(6); 
    std::cout << "Back after adding 6: " << queue.Back() << std::endl; 

    return 0;
}
