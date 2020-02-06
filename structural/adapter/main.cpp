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