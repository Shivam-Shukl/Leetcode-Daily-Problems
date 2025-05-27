#include <mutex>
#include <condition_variable>
#include <functional>

class Semaphore {
public:
    Semaphore() : count(0) {}

    Semaphore(int c) : count(c) {}

    void setCount(int a) {
        count = a;
    }

    inline void signal() {
        std::unique_lock<std::mutex> lock(mtx);
        count++;
        if (count <= 0) {
            cv.notify_one();
        }
    }

    inline void wait() {
        std::unique_lock<std::mutex> lock(mtx);
        count--;
        while (count < 0) {
            cv.wait(lock);
        }
    }

private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;
};

class DiningPhilosophers {
    Semaphore fork[5];
    std::mutex m;
public:
    DiningPhilosophers() {
        for (int i = 0; i < 5; ++i) {
            fork[i].setCount(1);
        }
    }

    void wantsToEat(int philosopher,
                    std::function<void()> pickLeftFork,
                    std::function<void()> pickRightFork,
                    std::function<void()> eat,
                    std::function<void()> putLeftFork,
                    std::function<void()> putRightFork) {

        std::lock_guard<std::mutex> lock(m);  // to avoid deadlock
        fork[philosopher].wait();             // pick left fork
        fork[(philosopher + 1) % 5].wait();   // pick right fork

        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        fork[philosopher].signal();

        putRightFork();
        fork[(philosopher + 1) % 5].signal();
    }
};
