#ifndef CDT_TEST_TESTER_HPP
#define CDT_TEST_TESTER_HPP

#include <string>
#include <vector>

typedef void (*testFxn_t)();

namespace cdt {
	
namespace test {
	std::string makeString(const std::string& format, ...);
}

struct Dummy {
	static void doNothing() {};
};

struct Test {
	std::string desc;
	testFxn_t test;
};

struct TestCase {
	testFxn_t beforeEach;
	testFxn_t afterEach;
	std::string desc;
	std::vector<Test> testList;
};

template<typename T>
class Tester {
public:
	static Tester<T>& instance();
	virtual ~Tester<T> ();

	static Tester<T>& init(const std::string& file, int line);

	static Tester<T>& toTest(const T& var);
	static Tester<T>& toTest(const T* var);

	static Tester<T>& not_();

	static Tester<T>& be(const T value);
	static Tester<T>& be(const T* value);
	static Tester<T>& beNull();

	static Tester<T>& _throw(const testFxn_t& fxn);

	static void reset();

private:
	static const T* mp_toTest;
	static bool m_inverted;
	static const std::string* mp_file;
	static std::string m_resultStr;
	static int m_line;
	static Tester<T>* mp_inst;
	
	Tester<T>() {};
	Tester<T>(const Tester<T>& other);
	Tester<T>& operator=(const Tester<T>& other);

	static void _buildResultStr(const T* value);
	static void _buildResultStr();
	static void _buildThrowResultStr();
};

} // namespace cdt

#include "Tester.impl.hpp"

#endif // CDT_TEST_TESTER_HPP

