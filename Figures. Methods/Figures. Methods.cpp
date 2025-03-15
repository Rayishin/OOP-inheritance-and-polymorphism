#include <iostream>
#include <string>

class Figure
{
protected:
    std::string name;
    int sides_count;

public:
    Figure(std::string setName, int setSides) : name(setName), sides_count(setSides) {}

    virtual void print_info() const
    {
        std::cout << name << ":\n";
        std::cout << (check() ? "Correct\n" : "Incorrect\n");
        std::cout << "Number of sides: " << sides_count << std::endl;
    }

    virtual bool check() const
    {
        return sides_count == 0;
    }

    virtual ~Figure() = default;
};

class Triangle : public Figure
{
protected:
    int a, b, c;
    int A, B, C;

public:
    Triangle(int seta, int setb, int setc, int setA, int setB, int setC) :
        Figure("Triangle", 3), a(seta), b(setb), c(setc), A(setA), B(setB), C(setC) {
    }

    void print_info() const override
    {
        Figure::print_info();
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Angel: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }

    bool check() const override
    {
        return (A + B + C == 180) && (a + b > c) && (a + c > b) && (b + c > a);
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

    bool check() const override
    {
        return Triangle::check() && (C == 90);
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

    bool check() const override
    {
        return Triangle::check() && (a == c) && (A == C);
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

    bool check() const override
    {
        return Triangle::check() && (a == b && b == c) && (A == 60 && B == 60 && C == 60);
    }
};

class Quadrangle : public Figure
{
protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    Quadrangle(int seta, int setb, int setc, int setd, int setA, int setB, int setC, int setD)
        : Figure("Quadrangle", 4), a(seta), b(setb), c(setc), d(setd), A(setA), B(setB), C(setC), D(setD) {
    }

    void print_info() const override
    {
        Figure::print_info();
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Angle: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }

    bool check() const override
    {
        return (A + B + C + D == 360);
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

    bool check() const override
    {
        return Quadrangle::check() && (a == c && b == d);
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

    bool check() const override
    {
        return Rectangle::check() && (a == b);
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

    bool check() const override
    {
        return Quadrangle::check() && (a == c && b == d && A == C && B == D);
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

    bool check() const override
    {
        return Parallelogram::check() && (a == b);
    }
};

int main()
{
    Figure* figures[] =
    {
        new Triangle(10, 20, 30, 50, 60, 70),
        new RectangularTriangle(10, 20, 30, 50, 40),
        new IsoscelesTriangle(10, 20, 50, 60),
        new EquilateralTriangle(30),
        new Quadrangle(10, 20, 30, 40, 50, 60, 70, 80),
        new Rectangle(10, 20),
        new Square(20),
        new Parallelogram(20, 30, 30, 40),
        new Rhombus(30, 30, 40)
    };

    for (const auto& fig : figures)
    {
        fig->print_info();
        delete fig;
    }

    return EXIT_SUCCESS;
}