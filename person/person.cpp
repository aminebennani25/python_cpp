#include <pybind11/pybind11.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>


struct Person {
	Person(const std::string &name) : name(name) { }
	void setName(const std::string &name_) { name = name_; }
	const std::string &getName() const { return name; }
	std::string name;
};



namespace py = pybind11;

PYBIND11_MODULE(example, m) {
	py::class_<Person>(m, "Person")
	.def(py::init<const std::string &>())
	.def("setName", &Person::setName)
	.def("getName", &Person::getName);
}
