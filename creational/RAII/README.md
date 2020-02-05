# RAII

### План урока
1. Понятие
2. Цели
3. Пример

### 1)Понятие
RAII - (Resource Acquisition Is Initialization) получение ресурса есть инициализация. Суть данного паттерна заключается в том, что при инициализации объекта происходит получение ресурса, а при уничтожении объекта происходит освобождение ресурса.

### 2)Цели
1. При выделении памяти
2. При открытии файла
3. При работе с мьютексом

### 3)Пример
```C++
/**
 * Умный указатель
 */
template<typename T>
class unique_ptr
{
private:
	T* pointer;
	/**
     * Запрет на копирование
     **/
	unique_ptr<T>(unique_ptr<T> const&) = delete;
	unique_ptr<T>& operator=(unique_ptr<T> const&) = delete;
public:
    /**
     * Получения указателя на выделенную память, при создании конструктора
     **/
	unique_ptr(T* pointer) :
	pointer(pointer)
	{}
    /**
     * Освобождение памяти при вызове деструктора
     **/
	~unique_ptr()
	{
		if(this->pointer != nullptr) delete this->pointer;
	}
    /**
     * Получение доступа к указателю
     **/
	T* operator->()
	{
		return this->pointer;
	}
};
```