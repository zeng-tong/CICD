#include <atomic>
#include <mutex>
using namespace std;

class Singleton{
private:
    Singleton() {};
    Singleton(const Singleton& singleton){};
    Singleton& operator = (const Singleton& singleton) {};

private:
    static Singleton* instance;
    //static Lock lock;
    static std::atomic<Singleton*> safe_instance;
    static std::mutex m_mutex;
public:
/*    static Singleton* getInstance() {
        if (instance == nullptr) {
            Lock lock;
            if (instance == nullptr)
                instance = new Singleton();
        }
        return instance;
    }*/

    static Singleton* getInstance() {
        Singleton* tmp = safe_instance.load(std::memory_order_relaxed);
        std::atomic_thread_fence(std::memory_order_acquire);
        if (tmp == nullptr) {
            std::lock_guard<std::mutex> lock(m_mutex);
            tmp = safe_instance.load(std::memory_order_relaxed);
            tmp = new Singleton();
            std::atomic_thread_fence(std::memory_order_release);
            safe_instance.store(tmp);
        }
        return tmp;
    }
};