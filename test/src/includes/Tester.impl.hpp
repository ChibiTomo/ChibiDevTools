#ifndef CDT_TEST_TESTER_IMPL_H
#define CDT_TEST_TESTER_IMPL_H

#include <exception>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "test.hpp"
#include "TestException.hpp"

#define TEST_ERROR_THROW(STR)		cdt::test::makeString("Should throw %s", STR)
#define TEST_ERROR_THROW_NOT(STR)	cdt::test::makeString("Should not throw %s", STR)
#define TEST_ERROR_BE(STR)			cdt::test::makeString("Values are not the same: %s", STR)
#define TEST_ERROR_BE_NOT(STR)		cdt::test::makeString("Values are the same: %s", STR)
#define TEST_ERROR_BE_NULL(STR)		cdt::test::makeString("Pointer is not null: %s", STR)
#define TEST_ERROR_BE_NULL_NOT(STR)	cdt::test::makeString("Pointer is null: %s", STR)

#define TEST(CONDITION, MSG, MSG_NOT) \
	if (m_inverted) { \
		ASSERT_MSG(!(CONDITION), MSG_NOT); \
	} else { \
		ASSERT_MSG(CONDITION, MSG); \
	}

namespace cdt {

template<typename T> const T* Tester<T>::mp_toTest = NULL;
template<typename T> bool Tester<T>::m_inverted = false;
template<typename T> const std::string* Tester<T>::mp_file = NULL;
template<typename T> int Tester<T>::m_line = 0;
template<typename T> std::string Tester<T>::m_resultStr = "";

template<class T> Tester<T>* Tester<T>::mp_inst = NULL;

template<class T>
Tester<T>& Tester<T>::instance() {
	if (!mp_inst) {
		mp_inst = new Tester<T>;
	}
	return *mp_inst;
}

template<typename T>
inline Tester<T>::~Tester<T>() {
	reset();
};

template<typename T>
inline Tester<T>& Tester<T>::init(const std::string& file, int line) {
	reset();
	mp_file = &file;
	m_line = line;
	return Tester<T>::instance();
};

template<typename T>
inline Tester<T>& Tester<T>::toTest(const T& var) {
	mp_toTest = &var;
	return Tester<T>::instance();
};
template<typename T>
inline Tester<T>& Tester<T>::toTest(const T* var) {
	mp_toTest = var;
	return Tester<T>::instance();
};

template<typename T>
inline Tester<T>& Tester<T>::not_() {
	m_inverted = true;
	return Tester<T>::instance();
};

template<typename T>
inline Tester<T>& Tester<T>::be(const T value) {
	_buildResultStr(&value);
	TEST(*mp_toTest == value, TEST_ERROR_BE(m_resultStr.c_str()), TEST_ERROR_BE_NOT(m_resultStr.c_str()));
	return Tester<T>::instance();
};
template<typename T>
inline Tester<T>& Tester<T>::be(const T* value) {
	std::cout<<"passed pointer";
	_buildResultStr(value);
	TEST(mp_toTest == value, TEST_ERROR_BE(m_resultStr.c_str()), TEST_ERROR_BE_NOT(m_resultStr.c_str()));
	return Tester<T>::instance();
};
template<typename T>
inline Tester<T>& Tester<T>::beNull() {
	_buildResultStr();
	TEST(mp_toTest == nullptr, TEST_ERROR_BE_NULL(m_resultStr.c_str()), TEST_ERROR_BE_NULL_NOT(m_resultStr.c_str()));
	return Tester<T>::instance();
};

template<typename T>
Tester<T>& Tester<T>::_throw(const testFxn_t& fxn) {
	_buildThrowResultStr();
	bool catched = false;
	try {
		fxn();
	} catch (T e) {
		catched = true;
		if (m_inverted) {
			throw cdt::TestException(*mp_file, m_line, TEST_ERROR_THROW_NOT(m_resultStr.c_str()));
		}
	}
	if (!catched && !m_inverted) {
		throw cdt::TestException(*mp_file, m_line, TEST_ERROR_THROW(m_resultStr.c_str()));
	}
	return Tester<T>::instance();
};

template<typename T>
inline void Tester<T>::reset() {
	m_inverted = false;
	mp_toTest = nullptr;
	m_resultStr = "";
};

template<typename T>
inline void Tester<T>::_buildResultStr(const T* value) {
	std::stringstream ss;
	ss	<< std::endl
		<< "\tTested: " << *mp_toTest << std::endl
		<< "\tExpected: " << *value << std::endl;
	m_resultStr = ss.str();
};
template<>
inline void Tester<bool>::_buildResultStr(const bool* value) {
	std::stringstream ss;
	ss	<< std::endl
		<< "\tTested: " << (*mp_toTest? "true" : "false") << std::endl
		<< "\tExpected: " << (*value? "true" : "false") << std::endl;
	m_resultStr = ss.str();
};
template<typename T>
inline void Tester<T>::_buildResultStr() {
	std::stringstream ss;
	ss	<< std::endl
		<< "\tTested: ";
	if (mp_toTest == nullptr) {
		ss << "nullptr";
	} else {
		ss 	<< mp_toTest;
	}
	ss	<< std::endl
		<< "\tExpected: " << (m_inverted? "not nullptr" : "nullptr") << std::endl;
	m_resultStr = ss.str();
};

template<typename T>
inline void Tester<T>::_buildThrowResultStr() {
};

} // namespace cdt

#endif // CDT_TEST_TESTER_IMPL_H

