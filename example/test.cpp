#include "libcoroutine.h"

int main () {
    libcoroutine::Test test("Let's go");
    test.printInfo();
    std::cout << 123 << std::endl;
    return 0;
}