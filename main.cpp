
#include "test_mgr.h"
#include <dlfcn.h>
#include <stdio.h>
#include <assert.h>

typedef void (*PatchMainFuncType)();

int main()
{
    printf("call main()\n");
    TestMgr::instance()->inline_func();
    TestMgr::instance()->noinline_func();

    void* handle = dlopen("./libpatch.so", RTLD_NOW | RTLD_GLOBAL);
    assert(handle != NULL);

    PatchMainFuncType patch_main_fun = (PatchMainFuncType)dlsym(handle, "patch_main");
    patch_main_fun();

    printf("TestMgr::instance()->cnt_=%d\n", TestMgr::instance()->cnt_);

    return 0;
}