#include <jni.h>
#include <string>
#include <random>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_test_1ndk_1openmp_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */, jlong count) {

    int min;

    int16_t _height_min = std::numeric_limits<int16_t>::max();
    int16_t _height_max = std::numeric_limits<int16_t>::min();

    #pragma omp parallel for reduction(max : _height_max) reduction(min : _height_min)
    for (size_t i = 0; i < count; ++i) {

        std::random_device rd;   // a seed source for the random number engine
        std::mt19937 gen(rd());  // mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<unsigned> distrib(0, std::numeric_limits<int16_t>::max());

        int16_t hDst = distrib(gen);

        _height_min = std::min(_height_min, hDst);
        _height_max = std::max(_height_max, hDst);
    }

    auto str = std::to_string(_height_min) + std::to_string(_height_max);
    return env->NewStringUTF(str.c_str());
}