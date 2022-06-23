#include<iostream>
class Shape {
public:
	virtual void draw() = 0;
};
class RoundedRectangle : public Shape {
public:
	void draw() {
		std::cout << "Inside RoundedRectangle::draw() method." << std::endl;
	}
};
class RoundedSquare : public Shape {
public:
	void draw() {
		std::cout << "Inside RoundedSquare::draw() method." << std::endl;
	}
};
class Rectangle : public Shape {
public:
	void draw() {
		std::cout << "Inside Rectangle::draw() method." << std::endl;
	}
};
class Sqaure : public Shape {
public:
	void draw() {
		std::cout << "Inside Sqaure::draw() method." << std::endl;
	}
};
class AbstractFactory {
public:
	virtual Shape* getShape(std::string shapeType) = 0;
};
class ShapeFactory : public AbstractFactory {
public:
	Shape* getShape(std::string shapeType) {
		if (shapeType.compare("RECTANGLE") == 0) {
			return new Rectangle();
		}
		else if (shapeType.compare("SQUARE") == 0) {
			return new Sqaure();
		}
		return NULL;
	}
};
class RoundedShapeFactory : public AbstractFactory {
public:
	Shape* getShape(std::string shapeType) {
		if (shapeType.compare("RECTANGLE") == 0) {
			return new RoundedRectangle();
		}
		else if (shapeType.compare("SQUARE") == 0) {
			return new RoundedSquare();
		}
		return NULL;
	}
};
class FactoryProducer abstract {
public:
	static AbstractFactory* getFactory(bool rounded) {
		if (rounded) {
			return new RoundedShapeFactory();
		}
		else {
			return new ShapeFactory();
		}
	}
};
int main() {
	//get shape factory
	FactoryProducer* factory = NULL;
	AbstractFactory* shapeFactory = factory->getFactory(false);
	//get an object of Shape Rectangle
	Shape* shape1 = shapeFactory->getShape("RECTANGLE");
	//call draw method of Shape Rectangle
	shape1->draw();
	//get an object of Shape Square 
	Shape* shape2 = shapeFactory->getShape("SQUARE");
	//call draw method of Shape Square
	shape2->draw();
	//get shape factory
	AbstractFactory* shapeFactory1 = factory->getFactory(true);
	//get an object of Shape Rectangle
	Shape* shape3 = shapeFactory1->getShape("RECTANGLE");
	//call draw method of Shape Rectangle
	shape3->draw();
	//get an object of Shape Square 
	Shape* shape4 = shapeFactory1->getShape("SQUARE");
	//call draw method of Shape Square
	shape4->draw();
	return 0;
}