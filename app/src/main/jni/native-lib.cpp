#include <jni.h>
#include <string>

extern "C" {
//编码
#include "libavcodec/avcodec.h"
//封装格式处理
#include "libavformat/avformat.h"
//像素处理
#include "libswscale/swscale.h"
}

extern "C" JNIEXPORT jstring

JNICALL
Java_com_liuguoquan_study_ndk_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    char info[4000] = {0};
    av_register_all();
    AVCodec *c_temp = av_codec_next(NULL);
    while (c_temp != NULL) {
        c_temp = c_temp->next;
    }
    return env->NewStringUTF(hello.c_str());
}
