#include "StringUtils.hpp"

#include <cstdio>
#include <cstdarg>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>


namespace cdt {
	
std::string StringUtils::getPadding(const std::string& str, const char c, size_t length) {
	if (str.size() >= length) {
		return "";
	}

	std::string result(1, c);

	for (size_t i = result.size() + str.size(); i < length; i++) {
		result += c;
	}

	return result;
};

std::string StringUtils::padLeft(const std::string& str, const char c, size_t length) {
	return getPadding(str, c, length) + str;
};

std::string StringUtils::padRight(const std::string& str, const char c, size_t length) {
	return str + getPadding(str, c, length);
};

std::string StringUtils::center(const std::string& str, const char c, size_t length) {
	size_t l = length / 2 + str.size() / 2 + length % 2;
	size_t r = length / 2 + str.size() / 2 + str.size() % 2;
	return getPadding(str, c, l) + str + getPadding(str, c, r);
};

bool StringUtils::startsWith(const std::string& str, const std::string& needle) {
	size_t pos = str.find(needle);
	return pos == 0;
}

bool StringUtils::endsWith(const std::string& str, const std::string& needle) {
	size_t pos = str.rfind(needle);
	return pos == (str.size() - needle.size());
}

bool StringUtils::contains(const std::string& str, const std::string& needle) {
	size_t pos = str.find(needle);
	return pos != std::string::npos;
}

std::vector<std::string> StringUtils::split(const std::string &str, const std::string& delim) {
	std::vector<std::string> strs;
	boost::split(strs, str, boost::is_any_of(delim));
	return strs;
}

std::string StringUtils::join(const std::vector<std::string> &list, const std::string& glue) {
	return std::string(boost::algorithm::join(list, glue));
}

std::string StringUtils::makeString(const std::string& format, ...) {
	char buff[1024];
	va_list arguments;
	va_start(arguments, format);
	vsnprintf(buff, 1024, format.c_str(), arguments);
	va_end(arguments);
	return std::string(buff);
}

} // cdt
