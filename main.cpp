#include <iostream>
#include <string>
#include <map>
#include <pthread.h>
 
void* producer_routine(void* arg) {
  // Wait for consumer to start
 
  // Read data, loop through each value and update the value, notify consumer, wait for consumer to process
  std::string inputNumber;
  char newChar;
  do
  {
    newChar = std::cin.get();
    if(newChar > '0' && newChar < '9')
      inputNumber += newChar;
    else if(!inputNumber.empty())
    {
      
      std::cout << std::stoi(inputNumber) << "\n";
      inputNumber.clear();
    }
  } while(newChar != '\n');
  
  return nullptr;
  pthread_exit(0);
}
 
void* consumer_routine(void* arg) {
  // notify about start
  // for every update issued by producer, read the value and add to sum
  // return pointer to result (for particular consumer)
  return nullptr;
  pthread_exit(0);
}
 
void* consumer_interruptor_routine(void* arg) {
  // wait for consumers to start
 
  // interrupt random consumer while producer is running                                          
  return nullptr;
  pthread_exit(0);
}
 
int run_threads() {
  // start N threads and wait until they're done
  // return aggregated sum of values
  int a = 0;
  producer_routine(&a);
  return 0;
}
 
int get_tid() {
  // 1 to 3+N thread ID
  static std::map<pthread_t, int> selfToTid;
  static int id = 1;
  if(!selfToTid.count(pthread_self()))
  {
    selfToTid[pthread_self()] = id;
    id++;
  }
  return selfToTid[pthread_self()];
}
 
int main() {
  std::atoi("20");
  std::cout << run_threads() << std::endl;
  return 0;
}
