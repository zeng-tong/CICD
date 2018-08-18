// 
// Created by zengtong on 2018/8/18 10:13 AM.
//

#include "commonHeader"
/*
 * 1. 按照ANSI(American National Standards Institute)标准，不能对 void 指针进行算法操作，
 * 即不能对void指针进行如p++的操作,所以需要转换为具体的类型指针来操作,例如char *;
 *
 * 2. memcpy是对内存进行操作，可能遇到内存重叠的情况，同样的问题存在于memmove中， 但是源代码
 * 中这两个函数的处理方式不一样：memcpy中dst和src中的区域不能重叠，否则会出现未知结果。
 * 函数没做任何内存的处理，内存是否重叠由程序员自己控制。memmove里面则判断了内存重叠的情况，
 * 当内存重叠时从后往前复制，以确保复制正常处理。
 * */

void* Memcpy(void* dst, const void* src, size_t n) {
    if (dst == nullptr || src == nullptr) // 按照ANSI(American National Standards Institute)标准，不能对 void 指针进行算法操作。
        return nullptr;
    int sz = static_cast<int>(n);
    char* destnation = static_cast<char*>(dst);
    const char* source = static_cast<const char*>(src);
    for (int i = sz - 1; i >= 0; --i) {// 避免内存重叠，从后面开始拷贝。
        *(destnation + i) = *(source + i);
    }
    return dst;
}

int main(){
    char dst[30] = "HELLO";
    Memcpy(dst + 15, dst, 6);
    cout << dst + 15 << endl;
    return 0;
}