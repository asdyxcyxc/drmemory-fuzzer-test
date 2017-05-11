// DrFuzzTest.cpp: simple test of Dr. Memory Fuzzer
//
// Copied from https://github.com/google/fuzzer-test-suite
#include <stdio.h>

bool FuzzMe(unsigned char *data, size_t dataSize)
{
    printf("%s: dataSize=%u\n", __func__, dataSize);
    return dataSize > 0 &&
        data[0] == 'F' &&
        data[1] == 'U' &&
        data[2] == 'Z' &&
        data[3] == 'Z';  // :‑<
}

extern "C"
void DrMemoryFuzzerTest(unsigned char *data, size_t dataSize)
{
    FuzzMe(data, dataSize);
}

int main()
{
    unsigned char data[] = "FUZZ";
    DrMemoryFuzzerTest(data, 3);
    return 0;
}
