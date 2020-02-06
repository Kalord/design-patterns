# Адаптер

### План урока
1. Понятие
2. Цели
3. Пример

### 1)Адаптер
Адаптер - структурный паттерн проектирования, предназначенный для организации использования методов объекта, недоступного для модификации.

### 2)Цели
Имеется интерфейс A, который несовместим с интерфейсом B, в таком случае создается интерфейс C, который является адаптером интерфейса B, для интерефейса A.

### 3)Пример

С++```
#include <iostream>

class Component
{
public:
    /**
     * Метод с которым необходимо работать
     **/
    virtual void getConnect() = 0;
};

class ConcreteComponent
{
public:
    /**
     * Метод в котором реализован алгоритм работы
     * Данный метод несовместим с getConnect()
     **/
    void connect()
    {
        std::cout << "Connect" << std::endl;
    }
};

class Adapter : public Component
{
private:
    ConcreteComponent adaptee;
public:
    /**
     * Адаптер метода connect
     **/
    void getConnect() override
    {
        this->adaptee.connect();
    }
};

int main()
{
    Component* component = new Adapter();

    component->getConnect(); 

    delete component;

    return 0;
}
```