#pragma once

#include "BOS/Status.hpp"
#include "BOS/FIFO.hp"

namespace BOS
{
  class Terminal
  {
  public:

    void initialise(Status& status);

    void terminate(Status& status);

  };
}