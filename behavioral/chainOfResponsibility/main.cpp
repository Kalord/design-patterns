#include <string>

/**
 * Интерфейс для обработчиков
 **/
class IHandler
{
public:
    virtual void setNext(IHandler next) = 0;
    virtual void execute(std::string data) = 0;
};

/**
 * Базовый обработчик
 **/
class BaseHandler : public IHandler
{
protected:
    IHandler next;
public:
    void setNext(IHandler next) override
    {
        this->next = next;
    }
};

/**
 * Первый обработчик
 **/
class OneHandler : public BaseHandler
{
public:
    void execute(std::string data) override
    {
        if(data == "Hello")
        {
            this->next.execute();
        }
    }
}

/**
 * Второй обработчик
 **/
class TwoHandler : public BaseHandler
{
public:
    void execute(std::string data) override
    {
        if(data == ", ")
        {
            this->next.execute();
        }
    }
};

/**
 * Третий обработчик
 **/
class ThreeHandler : public BaseHandler
{
public:
    void execute(std::string data) override
    {
        if(data == "World!")
        {
            this->next.execute();
        }
    }
};

int main()
{
    return 0;
}