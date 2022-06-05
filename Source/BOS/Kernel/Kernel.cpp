#include "BOS/Kernel/Kernel.hpp"

using namespace BOS;


Kernel Kernel::fInstance;

/******************************************************************************/
Kernel & Kernel::ref()
{
  return fInstance;
}

/******************************************************************************/
void Kernel::main()
{

}

/******************************************************************************/
extern "C"
{
  void KernelMain(void)
  {
    Kernel::ref().main();
  }
}