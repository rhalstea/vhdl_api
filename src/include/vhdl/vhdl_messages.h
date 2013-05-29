#define LEVEL_0   0  // output
#define LEVEL_1   1  // error
#define LEVEL_2   2  // warning
#define LEVEL_3   3  // info


#define OUTPUT_LEVEL    LEVEL_3
#define STREAM          std::cerr
#define END_LINE        std::endl
#define PREFIX          << __FILE__ << "(" << __LINE__ << "): "

// always print output messages
#define OUTPUT(m)    STREAM << m << END_LINE
#define OUTPUT2(m)   STREAM << m

// print info messages
#if OUTPUT_LEVEL > LEVEL_0
   #define ERROR(m)     STREAM PREFIX << "ERROR: " << m << END_LINE
#else
   #define ERROR(m)
#endif

// print warning messages
#if OUTPUT_LEVEL > LEVEL_1
   #define WARNING(m)   STREAM PREFIX << "WARNING: " << m << END_LINE
#else
   #define WARNING(m)
#endif

// print error messages
#if OUTPUT_LEVEL > LEVEL_2
   #define INFO(m)      STREAM PREFIX << "INFO: " << m << END_LINE
#else
   #define INFO(m)
#endif
