#pragma once

#include "BOS/Core/Status.hpp"

namespace BOS
{
  class Memory final
  {
  public:
    /***************************************************************************
     * Perform a byte level erase of the array of items. 
     **************************************************************************/
    template <class DataType, class IndexType>
    static void erase(Status& status, DataType * items, 
                      IndexType itemCount) noexcept
    {
      if (Passed(status))
      {
        unsigned char* bytes = reinterpret_cast<unsigned char*>(items);
        for (IndexType i = 0; i < byteCount<DataType, IndexType>(itemCount); i++)
          bytes[i] = 0;
      }
    }

    /***************************************************************************
     * Calculate the number bytes consumed by the array of items.
     **************************************************************************/
    template <class DataType, class IndexType>
    static IndexType byteCount(IndexType itemCount) noexcept
    {
      return sizeof(IndexType) * itemCount;
    }

    /***************************************************************************
     * Perform a byte level copy of the object.
     **************************************************************************/
    template <class DataType, class IndexType>
    static void copy(Status& status, DataType* destination, 
                     const DataType* source) noexcept
    {
      if (Passed(status))
      {
        unsigned char* dst = reinterpret_cast<unsigned char*>(destination);
        const unsigned char* src = reinterpret_cast<const unsigned char*>(source);

        for (IndexType i = 0; i < byteCount<DataType, IndexType>(1); i++)
          dst[i] = src[i];
      }
    }
  };
}