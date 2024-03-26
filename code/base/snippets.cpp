// Disable LeakSanitizer when working with pointers
extern "C" const char* __asan_default_options() { return "detect_leaks=0"; }

