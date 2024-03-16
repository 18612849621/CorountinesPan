#include "generator.h"
#include "libcoroutine.h"

using namespace libcoroutine;

Generator generator() {
    int a = 0;
    std::cout << "await before" << std::endl;
    co_await a++;
    std::cout << "await after" << std::endl;
}

int main() {
    auto g = generator();
    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    int v = g.next();
    // g.resume(); 
    std::cout << "main:" << v << std::endl;
    return 0;
}