#include <iostream>
#include <string>
using namespace std;

class Point {
    int x, y;
public:
    Point(int x, int y) { this->x = x; this->y = y; }
    Point& setX(int v) { this->x = v; return *this; }
    Point& setY(int v) { this->y = v; return *this; }
    bool isSame(const Point& o)const { return this->x == o.x && this->y == o.y; }
    void print()const { cout << "(" << x << "," << y << ")\n"; }
};

class Counter {
    int value;
public:
    Counter(int v = 0) :value(v) {}
    Counter& increment(int v) { this->value += v; return *this; }
    void print()const { cout << value << "\n"; }
};

class MyClass {
    int* data;
public:
    MyClass(int v = 0) { data = new int(v); }
    MyClass(const MyClass& o) { data = new int(*o.data); }
    MyClass& assign(const MyClass& o) {
        if (this == &o)return *this;
        delete data;
        data = new int(*o.data);
        return *this;
    }
    ~MyClass() { delete data; }
    void print()const { cout << *data << "\n"; }
};

class SimpleString {
    char* data;
public:
    SimpleString(const char* s = "") { data = new char[strlen(s) + 1]; strcpy(data, s); }
    SimpleString(const SimpleString& o) { data = new char[strlen(o.data) + 1]; strcpy(data, o.data); }
    ~SimpleString() { delete[] data; }
    void print()const { cout << data << "\n"; }
};

class Vector2D {
public:
    double x, y;
    Vector2D(double x = 0, double y = 0) :x(x), y(y) {}
    Vector2D(const Vector2D& o) :x(o.x), y(o.y) {}
};

class Book {
    string title;
public:
    Book(string t = "") :title(t) {}
    Book(const Book& o) :title(o.title) {}
    Book& setTitle(string t) { this->title = t; return *this; }
    Book& setAuthor(string a) { author = a; return *this; }
    void print()const { cout << title << " by " << author << "\n"; }
private:
    string author;
};

class Array {
    int* data; size_t size;
public:
    Array(size_t n = 0) :size(n) { data = new int[n]; for (size_t i = 0; i < n; i++)data[i] = 0; }
    Array(const Array& o) :size(o.size) { data = new int[size]; for (size_t i = 0; i < size; i++)data[i] = o.data[i]; }
    ~Array() { delete[] data; }
    void set(size_t i, int v) { if (i < size)data[i] = v; }
    void print()const { for (size_t i = 0; i < size; i++)cout << data[i] << " "; cout << "\n"; }
};

class DynStr {
    char* buf;
public:
    DynStr(const char* s = "") { buf = new char[strlen(s) + 1]; strcpy(buf, s); }
    DynStr(const DynStr& o) { buf = new char[strlen(o.buf) + 1]; strcpy(buf, o.buf); }
    ~DynStr() { delete[] buf; }
    void print()const { cout << buf << "\n"; }
};

class BadString {
    char* data;
public:
    BadString(const char* s = "") { data = new char[strlen(s) + 1]; strcpy(data, s); }
    ~BadString() { delete[] data; }
};

class RawHolder {
public:
    int* p;
    RawHolder() { p = new int[1]; }
    ~RawHolder() { delete[] p; }
};

class FixedHolder {
    int* p;
public:
    FixedHolder(int v = 0) { p = new int(v); }
    FixedHolder(const FixedHolder& o) { p = new int(*o.p); }
    ~FixedHolder() { delete p; }
};

void printBook(Book b) { b.print(); }

Book createBook() { Book b("Created"); return b; }