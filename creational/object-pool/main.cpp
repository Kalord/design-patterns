#include <iostream>
#include <vector>
#include <utility>

class Object
{
    
};

class Record
{
public:
    Object* instance;
    bool use;
};

class ObjectPool
{
private:
    std::vector<Record> pool;
};

int main()
{
    return 0;
}