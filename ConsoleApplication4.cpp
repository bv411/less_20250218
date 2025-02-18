#include <iostream>


/*
struct Имя_структуры {

поля структуры

};
*/

struct Subject {
	char name[200];
};

struct Student {

	char name[200];	
	Subject	subjs[3];
	const int SUBJ_COUNT = 3;

};
// Описываем пользовательский тип "Точка"
struct Point {
	int x = 0;
	int y = 0;
};

// Описываем пользовательский тип "Линия"
struct Line {
	Point p1;
	Point p2;
};

// Описываем пользовательский тип "Окружность"
struct Circle
{
	Point center;
	double r = 0;
};

void print_point(const Point& p) {
	std::cout << "(" << p.x << "; " << p.y << ")";
}

void change_point(Point& p) {
	std::cout << "Enter new x ";
	std::cin >> p.x;
	std::cout << "Enter new y ";
	std::cin >> p.y;
}

Point create_point() {

	Point p;
	std::cout << "Enter x ";
	std::cin >> p.x;
	std::cout << "Enter y ";
	std::cin >> p.y;

	return p;
}

void analiz(const Point& p) {

	if (p.x > 0 && p.y > 0) {
		std::cout << "Point in 1 chet!" << std::endl;
		return;
	}

	if (p.x < 0 && p.y > 0) {
		std::cout << "Point in 2 chet!" << std::endl;
		return;
	}

	if (p.x < 0 && p.y < 0) {
		std::cout << "Point in 3 chet!" << std::endl;
		return;
	}

	if (p.x > 0 && p.y < 0) {
		std::cout << "Point in 4 chet!" << std::endl;
		return;
	}

	if (p.x == 0 && p.y != 0) {
		std::cout << "Point in X os!" << std::endl;
		return;
	}
	if (p.x != 0 && p.y == 0) {
		std::cout << "Point in Y os!" << std::endl;
		return;
	}

	std::cout << "Point in center!" << std::endl;
}

void gen_points(Point* p, int size) {
	for (int i = 0; i < size; i++) {
		p[i].x = rand() % 101;
		p[i].y = rand() % 101;
	}
}

void print_points(Point* p, int size) {
	for (int i = 0; i < size; i++) {
		print_point(p[i]);
		std::cout << std::endl;
	}
}

void print_student(const Student& st) {

	std::cout << " Student " << st.name << std::endl;

	for (int i = 0; i < st.SUBJ_COUNT; i++) {
		std::cout <<"Subject " << (i+1) <<" " << st.subjs[i].name<< std::endl;
	}

}

int main()
{

	srand(time(NULL));

	Student st[2]{ { "Kostya",
			  {
				  {"C++"},
				  {"Python"},
				  {"Go"}
			  }
	}, { "Ivan",
			  {
				  {"C#"},
				  {"Rubi"},
				  {"Rust"}
			  }
	} };

	print_student(st[0]);
	print_student(st[1]);

	



	/*const int SIZE = 10;
	Point points[SIZE];

	gen_points(points, SIZE);
	print_points(points, SIZE);*/
	
	/*int size;

	std::cout << "Enter point count ";
	std::cin >> size;

	Point* points = new Point[size];

	gen_points(points, size);
	print_points(points, size);

	delete[] points;*/


	/*while (true) {
		Point mp = create_point();
		print_point(mp);
		std::cout << std::endl;
		analiz(mp);
	}*/

	/*Point my_point =  create_point(); 
	print_point(my_point);
	std::cout << std::endl;

	
	change_point(my_point);

	print_point(my_point);
	std::cout << std::endl;*/


	/*const Point center{ 0,0 };

	print_point(center);
	

	Point p;

	print_point(p);*/


	/*Point p{25,67};
	std::cout << &(p.x) << std::endl;
	std::cout << &(p.y) << std::endl;*/

	//Point p1{ 33,4 };

	//std::cout << "( " << p.x << ", " << p.y << " )" << std::endl;

	//p.x = 0;
	//p.y = 10;


	//std::cout << "( " << p.x << ", " << p.y << " )" << std::endl;
	////std::cout << "( " << p1.x << ", " << p1.y << " )" << std::endl;

	//Point p3;

	//std::cout << "( " << p3.x << ", " << p3.y << " )" << std::endl;


	/*Line l{ 
		{1},
		{3}
	};*/

	/*l.p1.x = 1;
	l.p1.y = 2;

	l.p2.x = 3;
	l.p2.y = 4;*/

	/*std::cout << "( " << l.p1.x << ", " << l.p1.y << " ) - "
			  << "( " << l.p2.x << ", " << l.p2.y << " )" << std::endl;*/

	/*Circle c{ {10,10}, 20};


	std::cout << "Circle center = (" << c.center.x << ", "
		<< c.center.y << ") , Radius = " << c.r << std::endl;*/

	
	return 0;
}














//struct Example1 {
//    char c;    // 1 байт
//    int i;     // 4 байта
//    char c1;    // 1 байт
//    double d;  // 8 байт
//};
//
//int main()
//{
//    Example1 e;
//    std::cout << sizeof(Example1);
//    std::cout << (int*)&(e.c) << std::endl;
//    std::cout << &(e.i) << std::endl;
//    std::cout << (int*) &(e.c1) << std::endl;
//    std::cout << &(e.d) << std::endl;
//
//}
