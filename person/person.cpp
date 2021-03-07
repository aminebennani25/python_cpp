#include <pybind11/pybind11.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>



struct Person {
	Person(const std::string &name, int age) : name(name), age(age) { }
	void setName(const std::string &name_) { name = name_; }
	const std::string &getName() const { return name; }
	void setAge(int  age_) { age = age_; }
	int &getAge() {return age;}
	std::string name;
	int age;
};


namespace py = pybind11;


PYBIND11_MODULE(person, m) {
	py::class_<Person>(m, "Person")
	.def(py::init<const std::string &, int>())
	.def("setName", &Person::setName)
	.def("getName", &Person::getName)
	.def("setAge", &Person::setAge)
	.def("getAge", &Person::getAge)
	.def("__repr__", [](const Person &p) {
		std::string var = "The person who's name  " + p.name + " has ";
		std::stringstream ss;
		ss << p.age;
		std::string s;
		ss>>s;
		var += s;
		return var;
	} );
}
