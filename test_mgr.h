
#pragma once

#include "singleton.h"
#include <stdio.h>

struct TestMgr : public Singleton<TestMgr>
{
    TestMgr()
    {
        printf("call TestMgr::TestMgr(). this=%p\n", this);
    }

    void inline_func()
    {
        printf("call TestMgr::inline_func(). this=%p\n", this);
        cnt_ += 1;
    }

    void noinline_func();

    int cnt_ = 0;
};