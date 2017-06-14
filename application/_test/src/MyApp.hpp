#ifndef CDT_APPLICATION_TEST_MYAPP_HPP
#define CDT_APPLICATION_TEST_MYAPP_HPP

#include "../../src/AApplication.hpp"

namespace cdt {

class MyApp : public AApplication {
	public: 
		MyApp ();
		~MyApp();
	
		void load () override;
		void run  () override;
		void clean() override;
};

} // namespace cdt

#endif // CDT_APPLICATION_TEST_MYAPP_HPP
