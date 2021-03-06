#include <sstream>
#include <string>

#include "includes/TestException.hpp"

namespace cdt {

TestException::TestException(const std::string& msg) : m_msg(msg) {};
TestException::~TestException() throw() {};

const char* TestException::what() const throw() {
	return m_msg.c_str();
}

} // namespace cdt