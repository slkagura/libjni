//
// Created by Kagura on 2023/7/23.
//
#ifndef _Included_xyz_slkagura_reg_wrapper_JNI
#define _Included_xyz_slkagura_reg_wrapper_JNI

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jlong JNICALL Java_xyz_slkagura_reg_wrapper_JNI_setUserPath(JNIEnv *jEnv, jclass jClass, jstring jValue);
JNIEXPORT jstring JNICALL Java_xyz_slkagura_reg_wrapper_JNI_getUserPath(JNIEnv *jEnv, jclass jClass);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //JNI_H
