#include<iostream>
using namespace std;
class Student {
private:
	string rollNo;
	string name;
public:
	Student() {

	}
public:
	string getRollNo() {
		return rollNo;
	}
public:
	void setRollNo(string rollNo) {
		this->rollNo = rollNo;
	}
public:
	string getName() {
		return name;
	}
public:
	void setName(string name) {
		this->name = name;
	}
};

class StudentView {
public:
	void printStudentDetails(string studentName, string studentRollNo) {
		cout << "Student: " << endl;
		cout << "Name: " << studentName << endl;
		cout << "Roll No: " << studentRollNo << endl;
	}
};

class StudentController {
private:
	Student* model;
	StudentView* view;
public:
	StudentController(Student* model, StudentView* view) {
		this->model = model;
		this->view = view;
	}
public:
	void setStudentName(string name) {
		model->setName(name);
	}
public:
	string getStudentName() {
		return model->getName();
	}
public:
	void setStudentRollNo(string rollNo) {
		model->setRollNo(rollNo);
	}
public:
	string getStudentRollNo() {
		return model->getRollNo();
	}
public:
	void updateView() {
		view->printStudentDetails(model->getName(), model->getRollNo());
	}
};

static Student* retriveStudentFromDatabase() {
	Student* student = new Student();
	student->setName("Robert");
	student->setRollNo("10");
	return student;
}

int main() {
	//fetch student record based on his roll no from the database
	Student* model = retriveStudentFromDatabase();
	//Create a view : to write student details on console
	StudentView* view = new StudentView();
	StudentController* controller = new StudentController(model, view);
	controller->updateView();
	//update model data
	controller->setStudentName("John");
	controller->updateView();
	return 0;
}