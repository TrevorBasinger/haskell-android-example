#include <jni.h>
#include <HsFFI.h>

extern void hs_set_java_vm(HsPtr a1);
extern void __stginit_HaskellActivity(void);


JNIEXPORT jint JNICALL JNI_OnLoad( JavaVM *vm, void *pvt ) {
    static char *argv[] = { "libhaskell.so", 0 }, **argv_ = argv;
    static int argc = 1;

    hs_init(&argc, &argv_);
    //hs_init( 0, 0);
    hs_add_root(__stginit_HaskellActivity);
    hs_set_java_vm(vm);
    return JNI_VERSION_1_2;
}

JNIEXPORT void JNICALL JNI_OnUnload( JavaVM *vm, void *pvt ) {
    hs_exit();
}



jstring
Java_blah_com_example_hellojni_HelloJni_stringFromJNI(JNIEnv *env, jobject this)
{
  int a = 300; // secretfunction();
  
  char* str;

  if( a > 300) { str = "hello haskell"; }
  else { str = "there haskell"; } 
  
  return (*env)->NewStringUTF(env, str); 
}

