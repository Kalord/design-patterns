### Компоновщик

План урока
1. Понятие
2. Цели
3. Пример

### 1)Понятие
**Компоновщик** - структурный паттерн проектирования, который выстраивает объекты в виде древовидной структуры, предосталвяет иерархию от частного к целому. 

### 2)Цели
Паттерн определяет иерархию классов, которые одновременно могут состоять из примитивных и сложных объектов, упрощает архитектуру клиента, делает процесс добавления новых видов объекта более простым.

### 3)Пример
```С++
#include <iostream>
#include <vector>

class Share
{
public:
    virtual void draw() = 0;
};

class Square : public Share
{
public:
    void draw() override
    {
        std::cout << "Square" << std::endl;
    }
};

class Triangle : public Share
{
public:
    void draw() override
    {
        std::cout << "Triangle" << std::endl;
    }
};

class Circle : public Share
{
public:
    void draw() override
    {
        std::cout << "Circle" << std::endl;
    }
};

class Composite : public Share
{
private:
    std::vector<Share*> shares;
public:
    ~Composite()
    {
        for(const auto& share : this->shares)
        {
            delete share;
        }
    }

    void addComponent(Share* shares)
    {
        this->shares.push_back(shares);
    }

    void removeComponent(Share* share)
    {
        for(int i = 0; i < this->shares.size(); i++)
        {
            if(this->shares[i] == share)
            {
                this->shares.erase(this->shares.begin() + i);
                break;
            }
        }
    }

    void draw() override
    {
        for(const auto& share : this->shares)
        {
            share->draw();
        }
    }
};

int main()
{
    Share* square = new Square();
    Share* triangle = new Triangle();
    Share* circle = new Circle();
    
    Composite composite;

    composite.addComponent(square);
    composite.addComponent(triangle);
    composite.addComponent(circle);

    composite.draw();

    return 0;
}
```