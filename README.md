# Структуры

Структуры - это пользовательский тип данных, который позволяет объединять несколько переменных разных типов под одним именем.
Они используются для создания сложных данных, которые могут включать в себя различные атрибуты.

## Основные понятия о структурах:

Структура объявляется с помощью ключевого слова *struct*, за которым следует имя структуры и тело структуры, содержащее переменные (члены структуры).
```
struct Person {
    char name[255];
    int age;
    double height;
};
```

В этом примере создана структура Person, которая содержит три члена:
name (строка), age (целое число) и height (число с плавающей точкой).

## Создание объектов структуры:

После объявления структуры можно создавать её объекты.

```
Person person1;
Person person2;
```

## Доступ к членам структуры:

Доступ к членам структуры осуществляется с помощью оператора *.*

```
person1.name = "Alice";
person1.age = 25;
person1.height = 1.68;

std::cout << "Name: " << person1.name << ", Age: " << person1.age << ", Height: " << person1.height << std::endl;
```

## Инициализация структуры:

Структуры можно инициализировать при создании объекта.

```
Person person3 = {"Bob", 30, 1.75};
```

## Структуры и функции:

Структуры могут быть переданы в функции как аргументы и возвращены из функций.

```
void printPerson(const Person& p) {
    std::cout << "Name: " << p.name << ", Age: " << p.age << ", Height: " << p.height << std::endl;
}

Person createPerson(const std::string& name, int age, double height) {
    Person p = {name, age, height};
    return p;
}
```

## Вложенные структуры:

Структуры могут содержать другие структуры в качестве членов.

```
struct Address {
    std::string city;
    std::string street;
    int houseNumber;
};

struct Employee {
    Person person;
    Address address;
    std::string position;
};

Employee emp = {{"Alice", 25, 1.68}, {"New York", "5th Ave", 10}, "Developer"};
```

## Структуры и указатели:

Можно использовать указатели на структуры. Доступ к членам структуры через указатель осуществляется с помощью оператора **->**

```
Person* ptr = &person1;
std::cout << "Name: " << ptr->name << std::endl;
```

## Структуры и массивы:

Можно создавать массивы структур.

```
Person people[3] = {
    {"Alice", 25, 1.68},
    {"Bob", 30, 1.75},
    {"Charlie", 35, 1.80}
};

for (int i = 0; i < 3; ++i) {
    printPerson(people[i]);
}
```

## Пример использования структуры:

```
#include <iostream>
#include <string>

struct Point {
    int x;
    int y;
};

void printPoint(const Point& p) {
    std::cout << "Point(" << p.x << ", " << p.y << ")" << std::endl;
}

int main() {
    Point p1 = {10, 20};
    printPoint(p1);

    Point p2;
    p2.x = 5;
    p2.y = 15;
    printPoint(p2);

    return 0;
}
```

Этот пример демонстрирует создание структуры Point, её инициализацию и использование в функции.

Структуры — это мощный инструмент в C++, который помогает организовывать данные в удобные и логические группы.

## Динамические массивы структур

Динамические массивы структур  позволяют создавать массивы, размер которых определяется во время выполнения программы.
Это полезно, когда количество элементов заранее неизвестно или может изменяться.
Для работы с динамическими массивами используются указатели и операторы *new* и *delete*.

## Создание динамического массива структур:

Для создания динамического массива структур используется оператор new. 
Он выделяет память в куче (heap) и возвращает указатель на первый элемент массива.

```
struct Person {
    std::string name;
    int age;
};

int n;
std::cout << "Enter the number of people: ";
std::cin >> n;

// Создание динамического массива структур
Person* people = new Person[n];
```

Здесь people — это указатель на массив структур Person, а n — количество элементов в массиве.

## Доступ к элементам динамического массива:

Доступ к элементам динамического массива осуществляется через указатель и оператор [] или через арифметику указателей.

```
for (int i = 0; i < n; ++i) {
    std::cout << "Enter name and age for person " << i + 1 << ": ";
    std::cin >> people[i].name >> people[i].age;
}

// Вывод данных
for (int i = 0; i < n; ++i) {
    std::cout << "Person " << i + 1 << ": " << people[i].name << ", " << people[i].age << " years old." << std::endl;
}
```

## Освобождение памяти:

После использования динамического массива необходимо освободить выделенную память с помощью оператора delete[].

```
delete[] people;
```
Если этого не сделать, произойдет утечка памяти.

## Изменение размера динамического массива:

```
// Увеличение размера массива
int newSize = n + 1;
Person* newPeople = new Person[newSize];

// Копирование данных
for (int i = 0; i < n; ++i) {
    newPeople[i] = people[i];
}

// Добавление нового элемента
newPeople[n].name = "Charlie";
newPeople[n].age = 30;

// Удаление старого массива
delete[] people;

// Переназначение указателя
people = newPeople;
n = newSize;
```

