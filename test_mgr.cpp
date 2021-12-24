
#include "test_mgr.h"

void TestMgr::noinline_func()
{
    printf("call TestMgr::noinline_func(). this=%p\n", this);
}