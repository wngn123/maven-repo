#ifdef BUILD_DLL  
#define EXPORT __declspec(dllexport) 
#else  
#define EXPORT __declspec(dllimport) 
#endif 
EXPORT void hello(void);