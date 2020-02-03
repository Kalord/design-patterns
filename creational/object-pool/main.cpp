#include <vector>
#include <iostream>

/**
 * Интерфейс, указывающий на то, что объект должен находится в объектном пуле
 */
class IPool
{
public:
	virtual void refresh() = 0;
};

class Object : public IPool
{
private:
	int data;
public:
	Object()
	{
		this->data = 5;
	}

	int getData()
	{
		return this->data;
	}

	void setData(int value)
	{
		this->data = value;
	}

	void refresh() override
	{
		this->data = 5;
	}
};

/**
 * Элемент объектного пула
 */
class ObjectItem
{
public:
	/**
	 * Указывает на то, находится ли объект в использовании
	 */
	bool in_use = false;
	/**
	 * Объект
	 */
	IPool* object;
};

/**
 * Объектный пул
 */
class ObjectPool
{
private:
	std::vector<ObjectItem> pool;
public:
	ObjectPool()
	{
		//В конструкторе инициализация пула объектов производить нельзя,
		//но для упрощения примера она будет происходит здесь,
		//для того, чтобы инициализировать объектный пул, необходимо использовать
		//фабричный метод
		//this->pool = ObjectPoolFactory::factory();

		for (int i = 0; i < 3; i++)
		{
			ObjectItem item;
			item.object = new Object();
			this->pool.push_back(item);
		}
	}

	~ObjectPool()
	{
		for (int i = 0; i < pool.size(); i++) delete pool[i].object;
	}

	/**
	 * Получение объекта
	 * Если объект не находится в использовании, то возвращается объект
	 * Иначе возвращается nullptr
	 */
	IPool* getObject(int index)
	{
		return !this->pool[index].in_use ? this->pool[index].object : nullptr;
	}

	/**
	 * Освобождение объекта из пула объектов
	 */
	void free(int index)
	{
		this->pool[index].in_use = false;
		this->pool[index].object->refresh();
	}
};

int main()
{
	return 0;
}