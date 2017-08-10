/*
* INFINITAG - open source laser tag
* Authors: Jani Taxidis, Tobias Stewen & Florian Kleene
* Website: www.infinitag.io
*
* All files are published under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International (CC BY-NC-SA 4.0)
* License: https://creativecommons.org/licenses/by-nc-sa/4.0/
*/

#include <EEPROM.h>

template <typename T>
class EEPROMEntry
{
public:
  EEPROMEntry()
    : size(0)
    , baseAddress(0)
    , data(0)
  {    
  }
  
  EEPROMEntry(int _size, int _baseAddress)
    : size(_size)
    , baseAddress(_baseAddress)
    , data(0)
  {    
  }
  
  ~EEPROMEntry()
  {
    if(data)
    {
      store(*data);
    }
  }
  
  
  void setData(T* _data)
  {
    data = _data;
  }
  
  T load(void) const
  {
    T entry;
    char* entryPtr = (char*)&entry;
    for(int address = baseAddress; address < baseAddress + size; ++address)
    {
      *entryPtr++ = EEPROM.read(address);
    }
    return entry;
  }
  
  void store(const T& entry) const
  {
    const char* entryPtr = (const char*)&entry;
    for(int address = baseAddress; address < baseAddress + size; ++address)
    {
      EEPROM.write(address, *entryPtr++);
    }
  }
private:  
  int size;
  int baseAddress;
  T* data;
};