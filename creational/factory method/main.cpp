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