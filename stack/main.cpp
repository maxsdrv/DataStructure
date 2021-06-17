#include <iostream>
#include <cassert>

class Node {
public:
    int data;
    Node *next;
private:
};

class Stack {
public:
    Stack() = default;
    ~Stack() = default;

    void push(const int item) {
        Node *tmp = new Node;
        if (isFull()) {
            std::cout << "Stack is full" << std::endl;
            assert(size > MAX);
        }
        tmp->data = item;
        tmp->next = this->head;

        head = tmp;
        size++;

        tmp = nullptr;
        delete tmp;
    }

    void pop() {
        if (!isEmpty()) {
            Node *current = head;
            head = current->next;
            current = nullptr;
            --size;
        }
        else {
            std::cout << "Stack is empty" << std::endl;
        }
    }

     void print() {
        Node *current = head; //создаём временный указатель на Node и присваиваем текущую голову стека
        Node *tmp = head; //временный указатель чтобы сохранить исходное состояние головы стека
        if (current == nullptr) { //проверяем не пуст ли стек
            std::cout << "( )" << std::endl;
        }
        while (current != nullptr) { //пока текущий указатель на голову стека не указывает на null бежим по циклу
            std::cout << current->data << " "; // выводим содержимое верхушки стека
            current = head->next; //говорим что текущий указатель это следующий элемент головы стека
            head = current; //сдвигаем голову стека
        }
        head = tmp; //возвращаем исходное состояние головы стека

        std::cout << std::endl;
    }
    template <typename T>
    T getSize() {
        return size;
    }
private:
    Node *head{};
    int size{};
    const unsigned int MAX = 10;

    //checking stack for emptiness
     [[nodiscard]] bool isEmpty() const {
        if (size == 0) return true;
        else return false;
    }
    //checking stack for fullness
    [[nodiscard]] bool isFull() const {
         if (size == MAX) {
             return true;
         }
         else return false;
     }

};

int main() {

    auto *stack = new Stack;
    stack->push(10);
    stack->push(12);
    stack->push(21);

    stack->print();

    stack->pop();
    stack->print();

    int size = stack->getSize<int>();
    std::cout << "Stack size: " << size << std::endl;

    delete stack;

    return 0;
}
