# Фабричный метод
1. Понятие
2. Цели
3. Структура
4. Примеры

------------

### **1)Понятие**
**Фабричный метод** - порождающий шаблон проектирования, который определяет общий интерфейс для создания объектов в суперклассе, позволяя подклассам изменять тип создаваемого объекта.

### **2)Цели**
1. Классу заранее неизвестно, объекты каких подклассов ему нужно создавать.
2. Класс спроектирован так, чтобы объекты, которые он создаёт, специфицировались подклассами.
3. Когда требуется сложная инициализация объекта, которая также может меняться в зависимости от условий.

### **3)Структура**
![](https://upload.wikimedia.org/wikipedia/ru/f/f0/FactoryMethodPattern.png)

**Product** - определяет классы, которые будут созданы фабричным методом.
**ConcreteCreator** - конкертный класс, реализующий Product.
**Creator** - создатель
**ConcreteCreator** - конкретный создатель, реализует класс Creator.

### **3)Примеры**

**Абстрактная реализация на C++**
```cpp
#include <iostream>
#include <string>

class Product
{
public:
    virtual std::string getData() = 0;
    virtual ~Product() {}
};

class ConcreteProduct : public Product
{
public:
    std::string getData() override
    {
        return "Hello, from ContreteProduct";
    }
};

class ConcreteProductTwo : public Product
{
public:
    std::string getData() override
    {
        return "Hello, from ConcreteProductTwo";
    }
};

class Creator
{
public:
    virtual Product* factory() = 0;
};

class ConcreteCreator : public Creator
{
public:
    Product* factory() override
    {
        return new ConcreteProduct();
    }
};

class ConcreteCreatorTwo : public Creator
{
public:
    Product* factory() override
    {
        return new ConcreteProductTwo();
    }
};

int main()
{
    Product* one = (ConcreteCreator()).factory();
    Product* two = (ConcreteCreatorTwo()).factory();

    std::cout << one->getData() << std::endl;
    std::cout << two->getData() << std::endl;

    delete one;
    delete two;

    return 0;
}
```
### Абстрактный пример на PHP

```php
interface Product
{
    public function getData();
}

class OneProduct implements Product
{
    public function getData()
    {
        return "Hello from OneProduct";
    }
}

class TwoProduct implements Product
{
    public function getData()
    {
        return "Hello from TwoProduct";
    }
}

interface FactoryProduct
{
    public function factory() : Product;
}

class OneFactory implements FactoryProduct
{
    public function factory() : Product
    {
        return new OneProduct();
    }
}

class TwoFactory implements FactoryProduct
{
    public function factory() : Product
    {
        return new TwoProduct();
    }
}

$one = (new OneFactory())->factory();
$two = (new TwoFactory())->factory();

echo $one->getData() . PHP_EOL; //Hello from OneProduct
echo $two->getData() . PHP_EOL; //Hello from TwoProduct
```