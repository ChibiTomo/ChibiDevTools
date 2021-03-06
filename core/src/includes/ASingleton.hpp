#ifndef CDT_CORE_ASINGLETON_HPP
#define CDT_CORE_ASINGLETON_HPP

#include <memory>

#include "libexport.h"

#define SINGLETON(__className) friend class cdt::ASingleton<__className>

namespace cdt {

template<class T>
class ASingleton {
	public:
		static std::shared_ptr<T> instance();
		
        ASingleton<T>(ASingleton<T> const&)           = delete;
        ASingleton<T> operator=(ASingleton<T> const&) = delete;

	protected:
		ASingleton<T>() {};
		virtual ~ASingleton<T>();

	private:
		static std::weak_ptr<T> mp_inst;
		
		static void deleteFxn(T* ptr);
};

} // cdt

#include "ASingleton.impl.hpp"

#endif // CDT_CORE_ASINGLETON_HPP
