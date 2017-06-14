#include <boost/smart_ptr/shared_ptr.hpp>

#include "MyModule.hpp"
#include "MyModule.hpp"

namespace cdt {

MyModule::MyModule() {
}

MyModule::~MyModule() {
}

void MyModule::init() {
}

void MyModule::clean() {
}

int MyModule::load() {
	return MY_MODULE_SUCCESS;
}

int MyModule::unload() {
	return MY_MODULE_SUCCESS;
}

boost::shared_ptr<MyModule> createMyModule() {
	boost::shared_ptr<MyModule> ptr(new MyModule());
	return ptr;
}

} // namespace cdt
