<?php

/**
 * Трейт, реализующий данный паттерн
 */
trait Singelton
{
    private static $instance = null;

    /**
     * Защищаем от создания
     */
    private function __construct() { /* ... @return Singleton */ }
    /**
     * Защищаем от создания через клонирование
     */
    private function __clone() { /* ... @return Singleton */ }
    /**
     * Защищаем от создания через unserialize
     */
    private function __wakeup() { /* ... @return Singleton */ }

    /**
     * Получение экземпляра
     */
    public static function getInstance() {
        self::$instance = !self::$instance ? new static() : self::$instance;
        return self::$instance;
    }
}

/**
 * Класс, для которого должен применяться паттерн одиночка
 */
class Concrete
{
    use Singelton;

    private $data = 5;

    public function incData()
    {
        $this->data++;
    }

    public function getData()
    {
        return $this->data;
    }
}

//Создание объекта
$singeltonOne = Concrete::getInstance();

//5
echo $singeltonOne->getData() . PHP_EOL;

$singeltonOne->incData();

//Получение объекта
$singeltonTwo = Concrete::getInstance();

//6
echo $singeltonTwo->getData() . PHP_EOL;