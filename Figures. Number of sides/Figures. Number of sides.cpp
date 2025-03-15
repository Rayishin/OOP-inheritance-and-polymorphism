#include <iostream>
#include <string>

class Figure
{
protected:

	int sides_count;
	std::string name;

	Figure(int setSides_count, std::string setName) : sides_count(setSides_count), name(setName) {}

public:
	Figure() : sides_count(0), name("Figure") {}

	int  get_sides_count() const
	{
		return sides_count;
	}

	std::string get_name() const
	{
		return name;
	}
};

class Triangle : public Figure
{
public:
	Triangle() : Figure(3, "Triangle") {}
};

class Quadrangle : public Figure
{
public:
	Quadrangle() : Figure(4, "Quadrangle") {}
};

int main()
{
	Figure figure;
	Triangle triangle;
	Quadrangle quadrangle;

	std::cout << "Number of sides: " << std::endl;
	std::cout << figure.get_name() << ": " << figure.get_sides_count() << std::endl;
	std::cout << triangle.get_name() << ": " << triangle.get_sides_count() << std::endl;
	std::cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << std::endl;

	return EXIT_SUCCESS;
}