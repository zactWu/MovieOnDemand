// dllmain.h: 模块类的声明。

class CRoundModule : public ATL::CAtlDllModuleT< CRoundModule >
{
public :
	DECLARE_LIBID(LIBID_RoundLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ROUND, "{971ba990-6ff5-4db9-9f59-1b61a2c3fe4b}")
};

extern class CRoundModule _AtlModule;
