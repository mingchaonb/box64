#define _GNU_SOURCE
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "wrappedlibs.h"
#include "debug.h"
#include "wrapper.h"
#include "bridge.h"
#include "librarian/library_private.h"
#include "x64emu.h"
#include "emu/x64emu_private.h"
#include "callback.h"
#include "librarian.h"
#include "box64context.h"

const char* breakdowntestName = "libbreakdown_test.so.1";
#define ALTNAME "libbreakdown_test.so"

#define LIBNAME breakdowntest

#include "generated/wrappedbreakdowntesttypes.h"
#include "wrappercallback.h"

EXPORT void* my_breakdown_test_get_callback(x64emu_t* emu)
{
    (void)emu;
    void* callback = my->breakdown_test_get_callback();
    return (void*)AddBridge(my_lib->w.bridge, iFiii, callback, 0,
                            "breakdown_test_callback");
}

EXPORT int my_breakdown_test_accept_callback(x64emu_t* emu, void* callback)
{
    (void)emu;
    return my->breakdown_test_accept_callback(
        GetNativeFnc((uintptr_t)callback));
}

#include "wrappedlib_init.h"
