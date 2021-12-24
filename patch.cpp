
#include "test_mgr.h"

__attribute__((noinline)) static void func()
{
    TestMgr::instance()->inline_func();
    TestMgr::instance()->noinline_func();
}

extern"C" void patch_main()
{
    printf("call patch_main()\n");
    func();
}