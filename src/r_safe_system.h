#include <R.h>
#include <R_ext/Error.h>

#ifdef __cplusplus
extern "C" {
#endif
  
  // Redefine abort to use R's error handler
  inline void abort(void) { 
    Rf_error("Library error: abort() called. Terminating safely via R."); 
  }
  
  // Redefine exit to use R's error handler
  inline void exit(int status) { 
    Rf_error("Library error: exit(%d) called. Terminating safely via R.", status); 
  }
  
#ifdef __cplusplus
}
#endif
