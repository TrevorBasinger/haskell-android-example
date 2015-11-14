#include <map>
#include <jni.h>
#include <pthread.h>
#include "wqueue.h"
#include "rqueue.h"

#ifdef __cplusplus
extern "C" {
#endif

  void* haskell_runtime( void* d );
  void* reader_runtime( void* d );
  void* writer_runtime( void* d );
  void* choreo_runtime( void* d );  

  void hs_android_main( void );
  
  void write_message( char* cmsg, int n );
  void write_coord( int x, int y );

  void register_callback_fptr( void(*v)(char*,int,char*, int) );
  void register_choreo_fptr( void(*v)( uint64_t ) );


  void Java_com_uphere_vchatter_Bridge_registerJRef( JNIEnv* env, jobject obj, jint k, jobject v );

  void Java_com_uphere_vchatter_Bridge_onFrameHS( JNIEnv* env, jlong frameTimeNanos );
  
  extern std::map<int,jobject> ref_objs;
  extern void (*fptr_callback)(char*, int, char*, int);
  extern void (*fptr_calljava)( JNIEnv*, message* );
  extern void (*fptr_flushjava)( JNIEnv* );
  extern JavaVM* jvm; 
  extern jmethodID ref_mid1;
  extern jmethodID ref_mid2;
  extern jmethodID ref_mid3;
  extern jmethodID ref_mid4;
  extern jclass cls1;
  extern jclass cls2;

  extern pthread_t thr_haskell;
  extern pthread_t thr_msgread; 
  extern pthread_t thr_msgwrite;
  extern pthread_t thr_msgchoreo;  

  extern pthread_mutex_t lock;
  extern pthread_cond_t  cond;

  extern int size_nickbox;
  extern char nickbox[4096];

  extern int size_messagebox;
  extern char messagebox[4096]; 


#ifdef __cplusplus
}
#endif

extern wqueue* wq;
extern rqueue* rq;
