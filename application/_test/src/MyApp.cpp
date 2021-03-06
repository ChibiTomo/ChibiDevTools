#include <iostream>

#include "MyApp.hpp"
#include "MyModule.hpp"

namespace cdt {

MyApp::MyApp() {
	std::cout << "CTR" << std::endl;
}

MyApp::~MyApp() {
	std::cout << "DTR" << std::endl;
}

void MyApp::load() {
	std::cout << "Loading app..." << std::endl;
	
	this->addModule("TEST", cdt::createMyModule());
	this->addModule("TEST", cdt::createMyModule());
	ModulePtr mod = this->replaceModule("TEST", cdt::createMyModule());
}

void MyApp::run() {
	std::cout << "run" << std::endl;
}

void MyApp::clean() {
	std::cout << "clean" << std::endl;
}

} // namespace cdt
