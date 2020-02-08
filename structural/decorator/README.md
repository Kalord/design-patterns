# Декторатор
План урока
1. Понятие
2. Цели
3. Структура
4. Пример

### 1)Понятие
**Декторатор** - структурный шаблон проектирования, предназначенный для динамического подключения дополнительного поведения к объекту.

### 2)Цели
Объект, который предполагается использовать, выполняет основные функции. Однако может потребоваться добавить к нему некоторую дополнительную функциональность, которая будет выполняться до, после или даже вместо основной функциональности объекта.

### 3)Структура
![](https://upload.wikimedia.org/wikipedia/ru/0/00/Decorator_template.png)

### 4)Пример
```c++
#include <iostream>
#include <memory>

class IComponent
{
public:
    virtual void action() = 0;
    virtual ~IComponent() {}
};

class Component : public IComponent
{
public:
    void action() override
    {
        std::cout << "World!";
    }
};

class DecoratorOne : public IComponent
{
private:
    std::shared_ptr<IComponent> component;
public:
    DecoratorOne(std::shared_ptr<IComponent> component)
    {
        this->component = component;
    }

    void action() override
    {
        this->component->action();
        std::cout << ", ";
    }
};

class DecoratorTwo : public IComponent
{
private:
    std::shared_ptr<IComponent> component;
public:
    DecoratorTwo(std::shared_ptr<IComponent> component)
    {
        this->component = component;
    }

    void action() override
    {
        this->component->action();
        std::cout << "Hello" << std::endl;
    }
};

int main()
{
    DecoratorTwo component(
        std::shared_ptr<IComponent>(new DecoratorOne(
            std::shared_ptr<IComponent>(new Component())
        ))
    );

    component.action();

    return 0;
}
```