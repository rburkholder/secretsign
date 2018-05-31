#include <jni.h>
#include <string>
#include <sodium.h>
#include <boost/date_time/gregorian/gregorian.hpp>

# http://androidkt.com/android-mqtt/
# https://www.hivemq.com/blog/mqtt-client-library-enyclopedia-paho-android-service
# Pahao Android Service
# <uses-permission android:name="android.permission.INTERNET" />
# <uses-permission android:name="android.permission.WAKE_LOCK" />
# <uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" />
# <uses-permission android:name="android.permission.READ_PHONE_STATE" />

# has mqtt, plus example of charting
# https://wildanmsyah.wordpress.com/2017/05/11/mqtt-android-client-tutorial/

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
  JNIEnv* env;
  if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
    return -1;
  }

  // Get jclass with env->FindClass.
  // Register methods with env->RegisterNatives.

  return JNI_VERSION_1_6;
}

JNIEXPORT jstring JNICALL
Java_net_oneunified_secretsign_ActivityMain_stringFromJNI( JNIEnv *env, jobject /* this */) {
  std::string hello = "Hello from C++";
  return env->NewStringUTF(hello.c_str());
}

JNIEXPORT bool JNICALL
Java_net_oneunified_secretsign_ActivityMain_TestLib( JNIEnv *env, jobject /* this */ ) {
  int i = sodium_init();
  boost::gregorian::date date(2018, 6, 23);
  std::string dest( boost::gregorian::to_simple_string(date));
  return 0 < i;
}


#ifdef __cplusplus
}
#endif
