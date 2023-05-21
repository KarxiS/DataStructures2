#pragma once
#ifdef _DEBUG
#include <crtdbg.h>
class MemoryLeak
{
public:
	~MemoryLeak() {
		_CrtDumpMemoryLeaks();
	}
};

const MemoryLeak ml;
#endif // _DEBUG