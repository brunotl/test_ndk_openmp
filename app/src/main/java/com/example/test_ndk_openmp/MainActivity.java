package com.example.test_ndk_openmp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.example.test_ndk_openmp.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'test_ndk_openmp' library on application startup.
    static {
        System.loadLibrary("test_ndk_openmp");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI(10000));
    }

    /**
     * A native method that is implemented by the 'test_ndk_openmp' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI(long count);
}