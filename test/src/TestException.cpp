#include <sstream>
#include <string>

#include "includes/TestException.hpp"

namespace cdt {

TestException::TestException(const std::string& msg) : m_msg(msg) {}
TestException::TestException(const std::string& file, const int& line, const std::string& msg) : m_msg(msg), m_file(file), m_line(line) {}
TestException::~TestException() throw() {}

const char* TestException::what() const throw() {
	return m_msg.c_str();
}

const std::string& TestException::getFile() const {
	return m_file;
}

const int TestException::getLine() const {
	return m_line;
}

} // namespace cdt