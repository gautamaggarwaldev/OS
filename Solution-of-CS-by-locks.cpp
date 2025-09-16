# include <iostream>
# include <thread>
# include <mutex>
using namespace std;

mutex mtx; // mutex object
int count = 0; 

void TaskA() {
    for(int i=0;i<1000000;i++) {
        // Acquire the lock before accessing the shared variable
        lock_guard<mutex> lock(mtx); 
        count += 1;
        // The lock is automatically released here when 'lock' goes out of scope
    }
}


int main() {

    thread t1(TaskA);
    thread t2(TaskA);

    t1.join();
    t2.join();

    cout << "Count: " << count << endl;
   
}