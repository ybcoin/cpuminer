#ifndef __COMPAT_H__
#define __COMPAT_H__

#ifdef WIN32
#ifndef __MINGW64__

#include <windows.h>
static inline void sleep(int secs)
{
	Sleep(secs * 1000);
}
#endif

enum {
	PRIO_PROCESS		= 0,
};

static inline int setpriority(int which, int who, int prio)
{
	return -!SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_IDLE);
}



#endif /* WIN32 */

#endif /* __COMPAT_H__ */
