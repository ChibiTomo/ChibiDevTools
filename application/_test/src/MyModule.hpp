#ifndef CDT_APPLICATION_TEST_MYMODULE_HPP
#define CDT_APPLICATION_TEST_MYMODULE_HPP

#include <boost/smart_ptr/shared_ptr.hpp>

#include <cdt/core/libexport.h>

#include "../../src/AModule.hpp"

#define MY_MODULE_SUCCESS 0
#define MY_MODULE_ERROR 1

namespace cdt {

class MyModule : public AModule {
	public:
		MyModule ();
		~MyModule();

		void init  () override;
		void clean () override;
		int  load  () override;
		int  unload() override;
};

extern "C" CDT_API boost::shared_ptr<MyModule> createMyModule();

} // namespace cdt

#endif // CDT_APPLICATION_TEST_MYMODULE_HPP
