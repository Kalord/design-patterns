#include <iostream>

class Singelton
{
protected:
    //Экземпляр класса
    static inline Singelton* singelton = nullptr;
    //Блокировка доступа к конструктору
    Singelton() {}
public:
    int x = 5;
    /**
     * Получение доступа к объекту
     **/
    static Singelton* instanse()
    {
        if(!singelton) singelton = new Singelton();
        return singelton;
    }
    /**
     * Удаление объекта
     **/
    static bool deleteInstance()
    {
        if(singelton)
        {
            delete singelton;
            singelton = nullptr;
            return true;
        }
        return false;
    }
};

int main()
{
    //Создание объекта
    Singelton* singeltonOne = Singelton::instanse();

    Singelton::instanse();

    //5
    std::cout << singeltonOne->x << std::endl;

    //Измненение данных
    singeltonOne->x = 10;

    //Получение объекта
    Singelton* singeltonTwo = Singelton::instanse();

    //10
    std::cout << singeltonTwo->x << std::endl;

    //Освобождение памяти
    singeltonOne->deleteInstance();

    return 0;
}