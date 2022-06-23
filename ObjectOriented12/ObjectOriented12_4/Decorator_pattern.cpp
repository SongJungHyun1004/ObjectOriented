#include<iostream>
using namespace std;
class Shape {
public:
	virtual void draw() = 0;
};

class Rectangle : public Shape {
public:
	void draw() {
		cout << "Shape: Rectangle" << endl;
	}
};

class Circle : public Shape {
public:
	void draw() {
		cout << "Shape: Circle" << endl;
	}
};

class ShapeDecorator abstract : public Shape {
protected:
	Shape* decoratedShape;

public:
	ShapeDecorator(Shape* decoratedShape) {
		this->decoratedShape = decoratedShape;
	}

public:
	void draw() {
		decoratedShape->draw();
	}
};

class RedShapeDecorator : public ShapeDecorator {

public:
	RedShapeDecorator(Shape* decoratedShape) : ShapeDecorator(decoratedShape){

	}
public:
	void draw() {
		decoratedShape->draw();
		setRedBorder(decoratedShape);
	}

private:
	void setRedBorder(Shape* decoratedShape) {
		cout << "Border Color: Red" << endl;
	}
};


int main() {

	Shape* circle = new Circle();

	Shape* redCircle = new RedShapeDecorator(new Circle());

	Shape* redRectangle = new RedShapeDecorator(new Rectangle());
	cout << "Circle with normal border" << endl;
	circle->draw();

	cout << "\nCircle of red border" << endl;
	redCircle->draw();

	cout << "\nRectangle of red border" << endl;
	redRectangle->draw();
	return 0;
}
