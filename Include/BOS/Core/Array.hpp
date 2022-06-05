#pragma once

#include "BOS/Core/Memory.hpp"
#include "BOS/Core/Status.hpp"


namespace BOS
{
  template <class DataType, class IndexType, IndexType kCount>
  class Array final
  {
    DataType fElements[kCount];

    Array(const Array&) = delete;
    Array(const Array&&) = delete;
    Array& operator = (const Array&) = delete;
    Array& operator = (const Array&&) = delete;

    void checkIndex(Status& status, IndexType index) const noexcept
    {
      if (Passed(status) && index < 0)
        status = Status::LowerBound;

      if (Passed(status) && index >= kCount)
        status = Status::UpperBound;
    }

  public:

    Array() = default;
    ~Array() = default;

    void erase(Status& status) noexcept
    {
      Memory::erase<DataType, IndexType>(status, fElements, kCount);
    }

    void set(Status& status, IndexType index, const DataType& data) noexcept
    {
      checkIndex(status, index);

      Memory::copy<DataType, IndexType>(status, &fElements[index], &data);
    }

    void get(Status& status, IndexType index, DataType& data) const noexcept
    {
      checkIndex(status, index);
      Memory::copy<DataType, IndexType>(status, &data, &fElements[index]);
    }
  };
}