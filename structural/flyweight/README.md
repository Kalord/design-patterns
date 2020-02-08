# Приспособленец
План урока
1. Понятие
2. Цели
3. Пример

### 1)Понятие
**Приспособленец** -  структурный шаблон проектирования, при котором объект, представляющий себя как уникальный экземпляр в разных местах программы, по факту не является таковым.

### 2)Цели
Оптимизация работы с памятью путём предотвращения создания экземпляров элементов, имеющих общую сущность.

### 3)Пример
#### Абстрактный пример на C++
```c++
#include <iostream>
#include <vector>

class IShape
{
public:
    virtual void draw(int x, int y) = 0;
};

class Point : public IShape
{
public:
    void draw(int x, int y) override
    {
        std::cout << "Draw point (x: " << x << "y: " << y << std::endl;
    }
};

class FactoryShape
{
private:
    static inline IShape* shapes[3] = {nullptr};
public:
    static inline const int POINT = 0;

    static IShape* factory(int index)
    {
        IShape* shape = FactoryShape::shapes[index];

        if(shape == nullptr)
        {
            if(index == FactoryShape::POINT)
            {
                shape = new Point();
                std::cout << "Create object" << std::endl; 
                FactoryShape::shapes[index] = shape;
            }
        }

        return shape;
    }

    static void free()
    {
        for(int i = 0; i < 3; i++)
        {
            delete shapes[i];
        }
    }
};

int main()
{
	std::vector<IShape*> shapes;

	for (int i = 0; i < 1000; i++)
	{
		shapes.push_back(FactoryShape::factory(FactoryShape::POINT));
	}

	for (int i = 0; i < shapes.size(); i++)
	{
		shapes[i]->draw(1, 1);
	}

	FactoryShape::free();

    return 0;
}
```