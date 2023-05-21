#include <Windows.h>
#include <iostream>

#include "Nacitavac.h"

#include <fstream>
#include <string.h>
#include "Algoritmus.h"
#include "MemoryLeak.h"
#include <libds/amt/explicit_hierarchy.h>
#include <libds/adt/table.h>
#include "uroven1a2.h"
#include "uroven3.h"
#include "uroven4.h"
#include "uroven1.h"



auto main() -> int
{
    {
        initHeapMonitor();
         SetConsoleOutputCP(1250);
        SetConsoleCP(1250);
        //uroven1a2 uroven;
        //uroven.main();
        uroven3 uroven;
        uroven.main();
}
_CrtDumpMemoryLeaks();

    return 0;


}


