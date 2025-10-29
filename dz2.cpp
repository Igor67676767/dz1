#include <iostream>
using namespace std;

//1
class Point {
    int x, y;
public:
    Point(int x, int y) { this->x = x; this->y = y; }
    void print() { cout << x << " " << y << "\n"; }
};

//2
class Point2 {
    int x, y;
public:
    Point2(int x = 0, int y = 0) { this->x = x; this->y = y; }
    Point2& setX(int v) { this->x = v; return *this; }
    Point2& setY(int v) { this->y = v; return *this; }
    void print() { cout << x << " " << y << "\n"; }
};

//3
class Counter {
    int value;
public:
    Counter(int v = 0) :value(v) {}
    Counter& increment(int d) { value += d; return *this; }
    void print() { cout << value << "\n"; }
};

//4
class Point3 {
    int x, y;
public:
    Point3(int x, int y) { this->x = x; this->y = y; }
    bool isSame(const Point3& other)const { return x == other.x && y == other.y; }
};

//5
class MyClass {
    int* data;
public:
    MyClass(int v = 0) { data = new int(v); }
    MyClass& assign(const MyClass& other) {
        if (this != &other) { *data = *other.data; }
        return *this;
    }
    ~MyClass() { delete data; }
};

//6
class SimpleString {
    char* data;
public:
    SimpleString(const char* s) {
        int n = 0; while (s[n])n++;
        data = new char[n + 1];
        for (int i = 0; i <= n; i++)data[i] = s[i];
    }
    SimpleString(const SimpleString& o) {
        int n = 0; while (o.data[n])n++;
        data = new char[n + 1];
        for (int i = 0; i <= n; i++)data[i] = o.data[i];
    }
    ~SimpleString() { delete[] data; }
};

//7
struct point { int x, y; };
class Vector2D {
    point* data;
public:
    Vector2D() { data = new point[3]; }
    Vector2D(const Vector2D& o) {
        data = new point[3];
        for (int i = 0; i < 3; i++)data[i] = o.data[i];
    }
    ~Vector2D() { delete[] data; }
};

//8
class Book {
    char* title;
public:
    Book(const char* t) {
        int n = 0; while (t[n])n++;
        title = new char[n + 1];
        for (int i = 0; i <= n; i++)title[i] = t[i];
    }
    Book(const Book& o) {
        int n = 0; while (o.title[n])n++;
        title = new char[n + 1];
        for (int i = 0; i <= n; i++)title[i] = o.title[i];
    }
    ~Book() { delete[] title; }
};

//9
class Array {
    int* data; size_t size;
public:
    Array(size_t s) :size(s) { data = new int[s]; }
    Array(const Array& o) :size(o.size) {
        data = new int[size];
        for (size_t i = 0; i < size; i++)data[i] = o.data[i];
    }
    ~Array() { delete[] data; }
};

//10
class DoublePtr {
    char** buf; int n;
public:
    DoublePtr(int n) :n(n) {
        buf = new char* [n];
        for (int i = 0; i < n; i++) { buf[i] = new char[2]; buf[i][0] = 'a' + i; buf[i][1] = 0; }
    }
    DoublePtr(const DoublePtr& o) :n(o.n) {
        buf = new char* [n];
        for (int i = 0; i < n; i++) {
            int len = 0; while (o.buf[i][len])len++;
            buf[i] = new char[len + 1];
            for (int j = 0; j <= len; j++)buf[i][j] = o.buf[i][j];
        }
    }
    ~DoublePtr() { for (int i = 0; i < n; i++)delete[] buf[i]; delete[] buf; }
};

//11
class BadString {
    char* data;
public:
    BadString(const char* s) {
        int n = 0; while (s[n])n++;
        data = new char[n + 1];
        for (int i = 0; i <= n; i++)data[i] = s[i];
    }
    ~BadString() { delete[] data; }
    BadString(const BadString& o) {
        int n = 0; while (o.data[n])n++;
        data = new char[n + 1];
        for (int i = 0; i <= n; i++)data[i] = o.data[i];
    }
};

//12
class DoubleDelete {
    int* p;
public:
    DoubleDelete() { p = new int[1]; }
    ~DoubleDelete() { delete[] p; }
    DoubleDelete(const DoubleDelete& o) { p = new int[1]; *p = *o.p; }
};

//13
class ClassName {
    int x;
public:
    ClassName(int v = 0) :x(v) {}
    ClassName(const ClassName& o) { x = o.x; }
};

//14
class Dyn {
    int* p;
public:
    Dyn(int v = 0) { p = new int(v); }
    Dyn(const Dyn& o) { p = new int(*o.p); }
    Dyn& operator=(const Dyn& o) {
        if (this != &o) { *p = *o.p; }
        return *this;
    }
    ~Dyn() { delete p; }
};

//15
class BookVal {
    int id;
public:
    BookVal(int i = 0) :id(i) {}
};

//16
class BookLoc {
    int id;
public:
    BookLoc(int i = 0) :id(i) {}
};

//17
class Number {
    int value;
public:
    Number(int v = 0) :value(v) {}
    Number& add(int v) { value += v; return *this; }
    Number& sub(int v) { value -= v; return *this; }
    bool isGreater(const Number& o)const { return value > o.value; }
};

//18
class Symbol {
    char c;
public:
    Symbol(char c) :c(c) {}
    bool equals(const Symbol& s)const { return c == s.c; }
};

//19
class Robot {
    int x, y;
public:
    Robot(int x = 0, int y = 0) :x(x), y(y) {}
    void moveX(int dx) { x += dx; }
    void moveY(int dy) { y += dy; }
};
