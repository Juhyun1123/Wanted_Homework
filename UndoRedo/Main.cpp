#include <iostream>
#include "UndoRedoEventSystem.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main(void)
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    UndoRedoEventSystem sys;
    sys.Run();

	return 0;
}