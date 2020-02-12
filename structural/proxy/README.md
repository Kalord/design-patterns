# Заместитель

План урока
1. Понятие
2. Цель
3. Виды
4. Пример

### 1)Понятие
**Заместитель** - структурный шаблон проектирования, предоставляющий объект, который контролирует доступ к другому объекту, перехватывая все вызовы.

### 2)Цели
Необходимо иметь доступ к объекту так, чтобы не создавать реальные объекты непосредственно, а через другой объект, который может иметь дополнительную функциональность.

### 3)Пример
#### Абстрактный пример на C++
```c++
#include <iostream>

class IMath
{
public:
    virtual int add(int x, int y) = 0;
};

class Math : public IMath
{
public:
    int add(int x, int y) override
    {
        return x + y;
    }
};

class MathProxy : public IMath
{
private:
    IMath* math;
public:
    MathProxy()
    {
        this->math = new Math();
    }

    ~MathProxy()
    {
        delete this->math;
    }

    int add(int x, int y) override
    {
        return this->math->add(x, y);
    }
};

int main()
{
    IMath* proxy = new MathProxy();

    std::cout << proxy->add(8, 2) << std::endl; //10

    delete proxy;

    return 0;
}
```