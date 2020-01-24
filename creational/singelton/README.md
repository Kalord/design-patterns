# Одиночка
1. Понятие
2. Задачи
3. Примеры

### 1)Понятие
**Одиночка** - порождающий шаблон проектирования, гарантирующий, что в приложение будет единственный экземпляр некоторого класса.

### 2)Задачи
У класса есть только один экземпляр, и он предоставляет к нему глобальную точку доступа. При попытке создания данного объекта он создаётся только в том случае, если ещё не существует, в противном случае возвращается ссылка на уже существующий экземпляр и нового выделения памяти не происходит.
Данные паттерн проектирования является уместным, когда:
1. Если, исходя из задачи класса, экземпляр данного класса должен существовать только в единственном экземпляре, а повторное его создание приведет к нарушению логике.
2. Предоставление глобальной точки доступа.

### 3)Примеры
#### Абстрактная реализация C++
```cpp
#include <iostream>

class Singelton
{
protected:
    //Экземпляр класса
    static Singelton* singelton;
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
```