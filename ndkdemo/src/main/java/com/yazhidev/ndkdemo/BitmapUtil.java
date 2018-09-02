package com.yazhidev.ndkdemo;

import android.graphics.Bitmap;

/**
 * Created by zengyazhi on 2018/9/1.
 */

public class BitmapUtil {

    static {
        System.loadLibrary("bitmap-util");
    }

    public static native void processBitmap(Bitmap bitmap);
}

