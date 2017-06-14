#ifndef CDT_APPLICATION_AMODULE_HPP
#define CDT_APPLICATION_AMODULE_HPP

#include "includes/IModule.hpp"

namespace cdt {

class AModule : public virtual IModule {
	public:
		virtual ~AModule() {};
		
		// virtual void init  () = 0;
		// virtual void clean () = 0;
		// virtual int  load  () = 0;
		// virtual int  unload() = 0;
		
		void* getFxn(char* fxnName) override;

		char* getVersion  () override;
		int   getMajorVers() override;
		int   getMinorVers() override;
		int   getPatchVers() override;
		char* getSpecVers () override;
};

} // namespace cdt

#endif // CDT_APPLICATION_AMODULE_HPP
