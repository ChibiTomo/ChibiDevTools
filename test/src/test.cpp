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

struct TestReport_str {
    int total;
    int success;
    int fail;
    int disabled;
};

bool run_test(const cdt::TestCase& testcase, const cdt::Test& test) {
    bool success = true;
    bool hasError = false;
    int disabledNbr = 0;

    std::cout << cdt::test::padRight("   " + test.desc, '.', 64);

    if (test.disabled) {
        std::cout << cdt::test::padLeft("DISABLED   ", '.', 15) << std::endl;
        return false;
    }

	std::stringstream resultStrStrm;
    try {
        testcase.beforeEach();
    } catch (const cdt::TestException& e) {
        resultStrStrm << "   Before each, test fail:" << std::endl;
        resultStrStrm << "   " << e.what() << std::endl;
        success = false;
    } catch (const std::exception& e) {
        resultStrStrm << "   The before each function caused an error:" << std::endl;
        resultStrStrm << "    " << e.what() << std::endl;
        success = false;
        hasError = true;
    } catch (...) {
        resultStrStrm << "   The before each function caused an error:" << std::endl;
        resultStrStrm << "   " << "Unknown exception" << std::endl;
        success = false;
        hasError = true;
    }

    try {
        disabledNbr += test.test();
    } catch (const cdt::TestException& e) {
        resultStrStrm << "   " << e.what() << std::endl;
        success = false;
    } catch (const std::exception& e) {
        resultStrStrm << "   " << e.what() << std::endl;
        success = false;
        hasError = true;
    } catch (...) {
        resultStrStrm << "   " << "Unknown exception" << std::endl;
        success = false;
        hasError = true;
    }

    try {
        testcase.afterEach();
    } catch (const cdt::TestException& e) {
        resultStrStrm << "   After each, test fail:" << std::endl;
        resultStrStrm << "   " << e.what() << std::endl;
        success = false;
    } catch (const std::exception& e) {
        resultStrStrm << "   The after each function caused an error:" << std::endl;
        resultStrStrm << "    " << e.what() << std::endl;
        success = false;
        hasError = true;
    } catch (...) {
        resultStrStrm << "   The after each function caused an error:" << std::endl;
        resultStrStrm << "   " << "Unknown exception" << std::endl;
        success = false;
        hasError = true;
    }
    
    if (success) {
        std::cout << cdt::test::padLeft("OK   ", '.', 15) << std::endl;
    }
    
    if (disabledNbr > 0) {
        std::cout << cdt::test::padLeft(cdt::test::makeString("%d test(s) were disabled   ", disabledNbr), ' ', 79) << std::endl;
    }
    
    if (!success) {
        if (hasError) {
            std::cout << cdt::test::padLeft("Error   ", '.', 15) << std::endl;
        } else {
            std::cout << cdt::test::padLeft("Test Fail   ", '.', 15) << std::endl;
        }
//        std::cout << e.getFile() << ":" << e.getLine() << std::endl;
        std::cout << resultStrStrm.str();
    }

    return success;
}

TestReport_str run_test_case(const cdt::TestCase& testcase) {
    int total = 0;
    int success = 0;
    int fail = 0;
    int disabled = 0;

    if (testcase.disabled) {        
        std::cout << cdt::test::center(" [DISABLED] " + testcase.desc + " [DISABLED] ", '=', 79) << std::endl;
    } else {
        std::cout << cdt::test::center(" " + testcase.desc + " ", '=', 79) << std::endl;
        for (const cdt::Test &test : testcase.testList) {
            total++;
            if (run_test(testcase, test)) {
                success++;
            } else if (test.disabled) {
                disabled++;
            } else {
                fail++;
            }
        }
        std::stringstream ss;
        ss << "Run: " << total << ", Success: " << success << ", Fail: " << fail << ", Disabled: " << disabled;
        std::cout << cdt::test::center(" " + ss.str() + " ", '=', 79) << std::endl;
    }
    std::cout << std::endl;
    
    TestReport_str report;
    report.total = total;
    report.success = success;
    report.fail = fail;
    report.disabled = disabled;
    return report;
}

void run_test_list(const std::vector<cdt::TestCase>* testcaseList) {
	int totalGrp = 0;
	int failGrp = 0;
	int successGrp = 0;
	int disabledGrp = 0;
	int totalUnit = 0;
	int failUnit = 0;
	int successUnit = 0;
	int disabledUnit = 0;
	for (const cdt::TestCase &testcase : *testcaseList) {
        try {
            TestReport_str report = run_test_case(testcase);
            if (testcase.disabled) {
                disabledGrp++;
            } else {
                totalGrp++;
                if (report.fail == 0) {
                    successGrp++;
                } else {
                    failGrp++;
                }
                totalUnit+=report.total;
                failUnit+=report.fail;
                successUnit+=report.success;
                disabledUnit+=report.disabled;
            }
            
        } catch (...) {
            failGrp++;
        }
	}
	std::cout << cdt::test::center(" Tests results ", '=', 79) << std::endl;
	std::cout << cdt::test::padRight(cdt::test::makeString("        Total group run:      %d", totalGrp), ' ', 40);
	std::cout << cdt::test::padRight(cdt::test::makeString("        Total unit run:       %d", totalUnit), ' ', 40) << std::endl;
	std::cout << cdt::test::padRight(cdt::test::makeString("        Total group success:  %d", successGrp), ' ', 40);
	std::cout << cdt::test::padRight(cdt::test::makeString("        Total unit success:   %d", successUnit), ' ', 40) << std::endl;
	std::cout << cdt::test::padRight(cdt::test::makeString("        Total group fail:     %d", failGrp), ' ', 40);
	std::cout << cdt::test::padRight(cdt::test::makeString("        Total unit fail:      %d", failUnit), ' ', 40) << std::endl;
	std::cout << cdt::test::padRight(cdt::test::makeString("        Total group disabled: %d", disabledGrp), ' ', 40);
	std::cout << cdt::test::padRight(cdt::test::makeString("        Total unit disabled:  %d", disabledUnit), ' ', 40) << std::endl;
}

} // namespace cdt

