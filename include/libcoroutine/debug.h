#pragma once

#include "declare.h"


namespace libcoroutine {

    class Test {
       public:
        Test() {};
        explicit Test(std::string info) : info_(info) {}
        ~Test() {};

        void printInfo();

       private:
        std::string info_;
    };

}  // namespace libcoroutine