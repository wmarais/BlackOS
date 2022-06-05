#pragma once

namespace BOS
{
  class Kernel
  {
    static Kernel fInstance;
  public:
    static Kernel& ref();

    void main();
  };
}
