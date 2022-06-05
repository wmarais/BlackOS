#pragma once

#include "BOS/Events/EventSink.hpp"
#include "BOS/Status.hpp"
#include "BOS/FIFO.hpp"

namespace BOS
{
  class Terminal : public EventSink
  {
  public:

    void initialise(Status& status);

    void terminate(Status& status);

    void update(Status& status);

  };
}