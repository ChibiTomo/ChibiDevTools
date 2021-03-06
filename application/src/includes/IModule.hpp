#ifndef CDT_APPLICATION_IMODULE_HPP
#define CDT_APPLICATION_IMODULE_HPP

#define CDT_MODULE_API

namespace cdt {

struct IModule {
	virtual ~IModule() {};
	
	virtual void init  () = 0;
	virtual void clean () = 0;
	virtual int  load  () = 0;
	virtual int  unload() = 0;

	virtual void* getFxn(char* fxnName) = 0;

	virtual char* getVersion  () = 0;
	virtual int   getMajorVers() = 0;
	virtual int   getMinorVers() = 0;
	virtual int   getPatchVers() = 0;
	virtual char* getSpecVers () = 0;
};

} // namespace cdt

#endif // CDT_APPLICATION_IMODULE_HPP
