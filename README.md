# EmbindTest
Embind Classes and Functions aren't available on higher Optimisation levels

When solution is built with Optimisation level -O2 or higher, Classes and Functions exported with Embind,
they can't be reached from Javascript.
When built with -O1 or lower, they can be used in Javascript.

Example .html files can be found in Emscripten/Debug and Emscripten/Release.
