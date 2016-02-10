#ifndef CDT_TEST_TESTER_HPP#define CDT_TEST_TESTER_HPP
#include <string>
#include <vector>

#include <cdt/core/ASingleton.hpp>
typedef void (*testFxn_t)();namespace cdt {struct Dummy {	static void doNothing() {};};struct Test {	std::string desc;	testFxn_t test;};struct TestCase {	testFxn_t beforeEach;	testFxn_t afterEach;	std::string desc;	std::vector<Test> testList;};template<typename T>class Tester : public cdt::ASingleton<Tester<T>> {	SINGLETON(Tester);public:	virtual ~Tester ();	static Tester& init(const std::string& file, int line);	static Tester& toTest(const T& var);	static Tester& toTest(const T* var);	static Tester& not_();	static Tester<T>& be(const T value);	static Tester<T>& be(const T* value);	static Tester<T>& _throw(const testFxn_t& fxn);	static void reset();private:	static const T* mp_toTest;	static bool m_inverted;	static const std::string* mp_file;	static std::string m_resultStr;	static int m_line;	static void _buildResultStr(const T* value);	static void _buildThrowResultStr();};
} // namespace cdt

#include "Tester.impl.hpp"#endif // CDT_TEST_TESTER_HPP