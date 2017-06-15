#include <iostream>
#include <cstdarg>
#include <cstdio>

#include "includes/test.hpp"
#include "includes/Tester.hpp"

namespace cdt {

namespace test {
	
std::string makeString(const std::string& format, ...) {
	char buff[1024];
	va_list arguments;
	va_start(arguments, format);
	vsnprintf(buff, 1024, format.c_str(), arguments);
	va_end(arguments);
	return std::string(buff);
}
	
std::string getPadding(const std::string& str, const char c, size_t length) {
	if (str.size() >= length) {
		return "";
	}

	std::string result(1, c);

	for (size_t i = result.size() + str.size(); i < length; i++) {
		result += c;
	}

	return result;
};

std::string padLeft(const std::string& str, const char c, size_t length) {
	return getPadding(str, c, length) + str;
};

std::string padRight(const std::string& str, const char c, size_t length) {
	return str + getPadding(str, c, length);
};

std::string center(const std::string& str, const char c, size_t length) {
	size_t l = length / 2 + str.size() / 2 + length % 2;
	size_t r = length / 2 + str.size() / 2 + str.size() % 2;
	return getPadding(str, c, l) + str + getPadding(str, c, r);
};

} // test

void run_test(const std::vector<cdt::TestCase>* testcaseList) {
	int total = 0;
	int failCount = 0;
	int successCount = 0;
	for (const cdt::TestCase &testcase : *testcaseList) {
		total++;
		int totalRun = 0;
		int errorNbr = 0;
		int successNbr = 0;
		std::cout << cdt::test::center(" " + testcase.desc + " ", '=', 79) << std::endl;
		for (const cdt::Test &test : testcase.testList) {
			try {
				totalRun++;
				std::cout << cdt::test::padRight("   " + test.desc, '.', 64);
				testcase.beforeEach();
				test.test();
				testcase.afterEach();
				std::cout << cdt::test::padLeft("OK   ", '.', 15) << std::endl;
				successNbr++;
			} catch (const cdt::TestException& e) {
				std::cout << cdt::test::padLeft("Test Fail   ", '.', 15) << std::endl;
//				std::cout << e.getFile() << ":" << e.getLine() << std::endl;
				std::cout << "   " << e.what() << std::endl;
				errorNbr++;
			} catch (const std::exception& e) {
				std::cout << cdt::test::padLeft("Error   ", '.', 15) << std::endl;
				std::cout << "   " << e.what() << std::endl;
				errorNbr++;
			} catch (...) {
				std::cout << cdt::test::padLeft("Error   ", '.', 15) << std::endl;
				std::cout << "   " << "Unknown exception" << std::endl;
				errorNbr++;
			}
		}
		if (errorNbr == 0) {
			successCount++;
		} else {
			failCount++;
		}
		std::stringstream ss;
		ss << "Run: " << totalRun << ", Success: " << successNbr << ", Errors: " << errorNbr;
		std::cout << cdt::test::center(" " + ss.str() + " ", '=', 79) << std::endl;
		std::cout << std::endl;
	}
	std::cout << cdt::test::center(" Tests results ", '=', 79) << std::endl;
	std::cout << cdt::test::padLeft("Total tests:   ", ' ', 20) << total << std::endl;
	std::cout << cdt::test::padLeft("Total success: ", ' ', 20) << successCount << std::endl;
	std::cout << cdt::test::padLeft("Total fail:    ", ' ', 20) << failCount << std::endl;
}

} // namespace cdt

