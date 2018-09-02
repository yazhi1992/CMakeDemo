package com.yazhidev.cmakedemo

import android.graphics.Bitmap
import android.graphics.BitmapFactory
import android.graphics.drawable.AdaptiveIconDrawable
import android.graphics.drawable.BitmapDrawable
import android.graphics.drawable.LayerDrawable
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import com.yazhidev.ndkdemo.BitmapUtil
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val drawable = resources.getDrawable(R.mipmap.google) as BitmapDrawable
        val bitmap = drawable.bitmap
        BitmapUtil.processBitmap(bitmap)
        image.setImageBitmap(bitmap)
    }

}
