#ifndef CDT_CORE_ASINGLETON_IMPL_HPP
#define CDT_CORE_ASINGLETON_IMPL_HPP

#include <memory>

namespace cdt {

template<class T>
std::shared_ptr<T> ASingleton<T>::instance() {
	auto result = mp_inst.lock();
	if (!result) {
		result.reset(new T, deleteFxn);
		mp_inst = result;
	}
	return result;
}
	
template<class T>
void ASingleton<T>::deleteFxn(T* ptr) {
	delete ptr;
}

template<class T> std::weak_ptr<T> ASingleton<T>::mp_inst;
template<class T> ASingleton<T>::~ASingleton<T>() {};

} // cdt

#endif // CDT_CORE_ASINGLETON_HPP
