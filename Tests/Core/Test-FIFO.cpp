#include "BOS/Core/FIFO.hpp"

#include <iostream>

using namespace BOS;

int main(int argc, char* argv[])
{
  Status status = Status::Passed;

  FIFO<float, int, 200> fifo;
  fifo.initialise(status);

  fifo.push(status, 100.0f);
  fifo.push(status, 200.0f);
  fifo.push(status, 300.0f);

  float data;
  fifo.pop(status, data);
  std::cout << data << ", ";
  fifo.pop(status, data);
  std::cout << data << ", ";
  fifo.pop(status, data);
  std::cout << data << std::endl;

  fifo.terminate(status); 
    
  return 0;
}