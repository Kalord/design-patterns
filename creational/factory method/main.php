interface Product
{
    public function getData();
}

class OneProduct implements Product
{
    public function getData()
    {
        return "Hello from OneProduct";
    }
}

class TwoProduct implements Product
{
    public function getData()
    {
        return "Hello from TwoProduct";
    }
}

interface FactoryProduct
{
    public function factory() : Product;
}

class OneFactory implements FactoryProduct
{
    public function factory() : Product
    {
        return new OneProduct();
    }
}

class TwoFactory implements FactoryProduct
{
    public function factory() : Product
    {
        return new TwoProduct();
    }
}

$one = (new OneFactory())->factory();
$two = (new TwoFactory())->factory();

echo $one->getData() . PHP_EOL; //Hello from OneProduct
echo $two->getData() . PHP_EOL; //Hello from TwoProduct