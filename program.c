// This file is a part of Julia. License is MIT: http://julialang.org/license

// Standard headers
#include <string.h>
#include <stdint.h>

// Julia headers (for initialization and gc commands)
#include "uv.h"
#include "julia.h"

// Declare C prototype of a function defined in Julia
extern void julia_main();

int main(int argc, char *argv[])
{
    intptr_t v;

    // Initialize Julia
    uv_setup_args(argc, argv); // no-op on Windows
    libsupport_init();
    jl_options.image_file = "libhello";
    julia_init(JL_IMAGE_CWD);

    // Do some work
    julia_main();

    // Cleanup and graceful exit
    jl_atexit_hook(0);
    return 0;
}
