#include <iostream>

/**
 * Класс, отвечающий за питание какого-либо электронного механизма
 **/
class Power
{
public:
    void on()
    {
        std::cout << "On" << std::endl;
    }

    void off()
    {
        std::cout << "Off" << std::endl;
    }
};

/**
 * Внешний накопитель
 **/
class USB
{
private:
    int data = 5;
public:
    bool hasData()
    {
        return this->data;
    }

    int getData()
    {
        return this->data;
    }

    void setData(int data)
    {
        this->data = data;
    }
};

/**
 * Жесткий диск
 **/
class HDD
{
private:
    int data;
public:
    void loadFromUSD(USB usb)
    {
        if(usb.hasData())
        {
            this->data = usb.getData();
            std::cout << "Data loaded" << std::endl;
            return;
        }
        std::cout << "Data not found" << std::endl;
    }
};

/**
 * Фасад для работы с компонентами
 **/
class Computer
{
private:
    Power power;
    USB usb;
    HDD hdd;
public:
    Computer()
    {
        this->power.on();
    }

    void writeToHDDFromUSB()
    {
        this->hdd.loadFromUSD(this->usb);
    }
};

int main()
{
    Computer computer;
    
    computer.writeToHDDFromUSB();

    return 0;
}