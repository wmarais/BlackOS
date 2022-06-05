#pragma once

#include <cstdint>

namespace BOS
{
  enum class Status : int32_t
  {
    Passed = 0,
    Failed = 1,

    Overflow = 2,
    Underflow = 3,
    LowerBound = 4,
    UpperBound = 5
  };

  bool Passed(Status status);
}