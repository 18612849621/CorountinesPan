#pragma once

#include "declare.h"

namespace libcoroutine {
    struct Generator {  // 协程任务
        struct promise_type {

            std::suspend_always initial_suspend() {
                return {};
            };

            std::suspend_never final_suspend() noexcept {
                return {};
            }

            void unhandled_exception() {}

            Generator get_return_object() {
                return Generator {std::coroutine_handle<promise_type>::from_promise(*this)};
            }

            std::suspend_always await_transform(int value) {
                value_ = value;
                return {};
            }

            void return_void() {}

            int value_;
        };

        std::coroutine_handle<promise_type> handle_;

        int next() {
            handle_.resume();
            return handle_.promise().value_;
        }

        void resume() {
            handle_.resume();
        }
    };

}  // namespace libcoroutine