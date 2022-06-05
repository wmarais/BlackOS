#pragma once

#include "BOS/Array.hpp"
#include "BOS/Status.hpp"

namespace BOS
{
  template <class DataType, class IndexType, IndexType kMaxCount>
  class FIFO final
  {
    IndexType fHead, fTail, fCount;
    Array<DataType, IndexType, kMaxCount> fElements;

    FIFO(const FIFO&) = delete;
    FIFO(const FIFO&&) = delete;
    FIFO& operator = (const FIFO&) = delete;
    FIFO& operator = (const FIFO&&) = delete;

  public:

    FIFO() = default;
    ~FIFO() = default;

    void initialise(Status& status)
    {
      reset(status);
    }

    void terminate(Status& status)
    {
      reset(status);
    }

    void reset(Status& status)
    {
      if (Passed(status))
      {
        fHead = 0;
        fTail = 0;
        fCount = 0;
        fElements.erase(status);
      }
    }

    bool isEmpty() const noexcept
    {
      return fCount == 0;
    }

    bool isFull() const noexcept
    {
      return fCount >= kMaxCount;
    }

    void push(Status& status, const DataType & data) noexcept
    {
      if (Passed(status) && isFull())
        status = Status::Overflow;

      fElements.set(status, fHead, data);

      if (Passed(status))
      {
        ++fCount;
        ++fHead;
        if (fHead >= kMaxCount)
          fHead = 0;
      }
    }

    void pop(Status& status, DataType & data) noexcept
    {
      if (Passed(status) && isEmpty())
        status = Status::Underflow;

      fElements.get(status, fTail, data);

      if (Passed(status))
      {
        --fCount;
        ++fTail;
        if (fTail >= kMaxCount)
          fTail = 0;
      }
    }
  };
}