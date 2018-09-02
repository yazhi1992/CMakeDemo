#include <jni.h>
#include <android/bitmap.h>

extern "C"

JNIEXPORT void JNICALL
Java_com_yazhidev_ndkdemo_BitmapUtil_processBitmap(JNIEnv *env, jobject /* this */, jobject bitmap) {
    //构造 AndroidBitmapInfo
    AndroidBitmapInfo info = {0};
    //将 bitmp 的信息填充给 info
    AndroidBitmap_getInfo(env, bitmap, &info);
    int *buf=NULL;
    //对 bitmap 解码并获取解码后的像素保存在内存中的地址指针赋值给 srcBuf
    AndroidBitmap_lockPixels(env, bitmap, (void **) &buf);
    int w = info.width;
    int h = info.height;
    int32_t *srcPixs = (int32_t *) buf;
    int alpha = 0xFF << 24;
    int i, j;
    int color;
    int red;
    int green;
    int blue;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            // get the color of per pixel
            color = srcPixs[w * i + j];
            red = ((color & 0x00FF0000) >> 16);
            green = ((color & 0x0000FF00) >> 8);
            blue = color & 0x000000FF;
            color = (red + green + blue) / 3;
            color = alpha | (color << 16) | (color << 8) | color;
            srcPixs[w * i + j] = color;
        }
    }
    //释放锁定，显示出被修改的像素数据
    AndroidBitmap_unlockPixels(env, bitmap);
}