# include <iostream>
# include <thread>
using namespace std;

int count = 0; 

void TaskA() {
    for(int i=0;i<1000000;i++) {
        count += 1;
    }
}


int main() {

    thread t1(TaskA);
    thread t2(TaskA);

    t1.join();
    t2.join();

    cout << "Count: " << count << endl;
   
}