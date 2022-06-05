#include "BOS/Core/Status.hpp"

bool BOS::Passed(Status status)
{
  return (status == Status::Passed);
}