#include <iostream>
#include <string>

class Figure
{
protected:
    std::string name;

public:
    Figure(std::string setName) : name(setName) {}

    virtual std::string get_name() const
    {
        return name;
    }

    virtual std::string get_sides_info() const = 0;
    virtual std::string get_angles_info() const = 0;

    virtual ~Figure() = default;
};

class Triangle : public Figure
{
protected:
    int a, b, c;
    int A, B, C;

public:
    Triangle(int seta, int setb, int setc, int setA, int setB, int setC)
        : Figure("Triangle"), a(seta), b(setb), c(setc), A(setA), B(setB), C(setC) {
    }

    std::string get_sides_info() const override
    {
        return "Sides: a=" + std::to_string(a) +
            " b=" + std::to_string(b) +
            " c=" + std::to_string(c);
    }

    std::string get_angles_info() const override
    {
        return "Angles: A=" + std::to_string(A) +
            " B=" + std::to_string(B) +
            " C=" + std::to_string(C);
    }
};

class RectangularTriangle : public Triangle
{
public:
    RectangularTriangle(int seta, int setb, int setc, int setA, int setB)
        : Triangle(seta, setb, setc, setA, setB, 90)
    {
        name = "Rectangular Triangle";
    }
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(int seta, int setb, int setA, int setB)
        : Triangle(seta, setb, seta, setA, setB, setA)
    {
        name = "Isosceles Triangle";
    }
};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(int seta)
        : Triangle(seta, seta, seta, 60, 60, 60)
    {
        name = "Equilateral Triangle";
    }
};

class Quadrangle : public Figure
{
protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    Quadrangle(int seta, int setb, int setc, int setd, int setA, int setB, int setC, int setD)
        : Figure("Quadrangle"), a(seta), b(setb), c(setc), d(setd), A(setA), B(setB), C(setC), D(setD)
    {
    }

    std::string get_sides_info() const override
    {
        return "Sides: a=" + std::to_string(a) +
            " b=" + std::to_string(b) +
            " c=" + std::to_string(c) +
            " d=" + std::to_string(d);
    }

    std::string get_angles_info() const override
    {
        return "Angles: A=" + std::to_string(A) +
            " B=" + std::to_string(B) +
            " C=" + std::to_string(C) +
            " D=" + std::to_string(D);
    }
};

class Rectangle : public Quadrangle
{
public:
    Rectangle(int seta, int setb)
        : Quadrangle(seta, setb, seta, setb, 90, 90, 90, 90)
    {
        name = "Rectangle";
    }
};

class Square : public Rectangle
{
public:
    Square(int seta)
        : Rectangle(seta, seta)
    {
        name = "Square";
    }
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int seta, int setb, int setA, int setB)
        : Quadrangle(seta, setb, seta, setb, setA, setB, setA, setB)
    {
        name = "Parallelogram";
    }
};

class Rhombus : public Parallelogram
{
public:
    Rhombus(int seta, int setA, int setB)
        : Parallelogram(seta, seta, setA, setB)
    {
        name = "Rhombus";
    }
};

void print_info(const Figure* fig)
{
    std::cout << fig->get_name() << ":\n";
    std::cout << fig->get_sides_info() << "\n";
    std::cout << fig->get_angles_info() << "\n\n";
}

int main()
{
    Triangle t(10, 20, 30, 50, 60, 70);
    RectangularTriangle rt(10, 20, 30, 50, 60);
    IsoscelesTriangle it(10, 20, 50, 60);
    EquilateralTriangle et(30);

    Quadrangle q(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rect(10, 20);
    Square sq(20);
    Parallelogram para(20, 30, 30, 40);
    Rhombus rhomb(30, 30, 40);

    print_info(&t);
    print_info(&rt);
    print_info(&it);
    print_info(&et);
    print_info(&q);
    print_info(&rect);
    print_info(&sq);
    print_info(&para);
    print_info(&rhomb);

    return EXIT_SUCCESS;
}
