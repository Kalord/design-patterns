#include <iostream>
#include <string>

/**
 * Иерархия классов отвечающая за тип кузова у автомобиля
 **/
class TypeCar
{
public:
    virtual std::string getType() = 0;
};

class Coupe : public TypeCar
{
public:
    std::string getType() override
    {
        return "Coupe";
    }
};

class Sedan : public TypeCar
{
public:
    std::string getType() override
    {
        return "Sedan";
    }
};

/**
 * Иерархия классов отвечающих за марку автомобиля
 **/
class Make
{
private:
    TypeCar* typeCar;
public:
    Make(TypeCar* typeCar)
    {
        this->typeCar = typeCar;
    }

    virtual ~Make() {}

    virtual std::string getMake() = 0;
};

class Kia : public Make
{
public:
    Kia(TypeCar* typeCar) : Make(typeCar)
    {
    }

    std::string getMake() override
    {
        return "Kia";
    }
};

class BMW : public Make
{
public:
    BMW(TypeCar* typeCar) : Make(typeCar)
    {
    }

    std::string getMake() override
    {
        return "BMW";
    }
};

int main()
{
    TypeCar* typeCar = new Coupe();
    BMW bwm(typeCar);
    
    return 0;
}