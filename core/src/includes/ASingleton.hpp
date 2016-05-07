#ifndef CDT_CORE_ASINGLETON_HPP#define CDT_CORE_ASINGLETON_HPP#include <cstddef>#include "libexport.h"
#define SINGLETON(__className) friend class cdt::ASingleton<__className>namespace cdt {template<class T>class ASingleton {	public:		static T& instance();		static void destroy();	protected:		ASingleton() {};		virtual ~ASingleton() = 0;	private:		static T* p_inst;		ASingleton(const ASingleton& other);		ASingleton& operator=(const ASingleton& other);};} // cdt
#include "ASingleton.impl.hpp"
#endif // CDT_CORE_ASINGLETON_HPP