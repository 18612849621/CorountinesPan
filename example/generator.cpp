#include "generator.h"
#include "libcoroutine.h"

using namespace libcoroutine;

#define main_step 15
#define coroutine_step 10

Generator generator() {
    int i = 1;
    while (i < coroutine_step) {
        co_await i++;
    }
}

int main() {
    auto g = generator();
    for (int i = 0; i < main_step; ++i) {
        std::cout << "[" << i << "]value:" << g.next() << std::endl;
    }
    return 0;
}