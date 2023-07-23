//
// Created by Kagura on 2023/7/23.
//
#include <windows.h>

#include "JNI.h"
#include "../Reg.h"

JNIEXPORT
jlong JNICALL Java_xyz_slkagura_reg_wrapper_JNI_setUserPath(JNIEnv *jEnv, jclass jClass, jstring jValue) {
    LPBYTE lpData = (unsigned char *) jEnv->GetStringUTFChars(jValue, nullptr);
    LSTATUS result = setUserPath(lpData);
    return result;
}

JNIEXPORT
jstring JNICALL Java_xyz_slkagura_reg_wrapper_JNI_getUserPath(JNIEnv *jEnv, jclass jClass) {
    LPBYTE lpData = nullptr;
    LSTATUS result = getUserPath(lpData);
    if (result != ERROR_SUCCESS) {
        lpData = (unsigned char *) "";
    }
    return jEnv->NewStringUTF((char *) lpData);
}
