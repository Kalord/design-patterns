#include <iostream>

/**
 * Агрегируемые
 **/
class One
{
public:
    int x = 1;
};

class Two
{
public:
    int x = 2;
};

class Three
{
public:
    int x = 3;
};

/**
 * Представим, что у нас есть композиция из N объектов,
 * при этом некоторые объекты будут не нужны
 * В таком случае - инициализировать объекты нужно непосредственно
 * во время попытки получить к ним доступ
 **/
class Concrete
{
private:
    One* one = nullptr;
    Two* two = nullptr;
    Three* three = nullptr;
public:
    One* getOne()
    {
        if(!one) one = new One();
        return one;
    }

    Two* getTwo()
    {
        if(!two) two = new Two();
        return two;
    }

    Three* getThree()
    {
        if(!three) three = new Three();
        return three;
    }
};

int main()
{
    return 0;
}