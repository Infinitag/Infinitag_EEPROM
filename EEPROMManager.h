/*
* INFINITAG - open source laser tag
* Authors: Jani Taxidis, Tobias Stewen & Florian Kleene
* Website: www.infinitag.io
*
* All files are published under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International (CC BY-NC-SA 4.0)
* License: https://creativecommons.org/licenses/by-nc-sa/4.0/
*/

#ifndef INFINITAG_EEPROM_MANAGER_H
#define INFINITAG_EEPROM_MANAGER_H

#include <EEPROMEntry.h>

class EEPROMManager
{
public:
  template <typename T>
  EEPROMEntry<T> allocateEntry()
  {
    int size = sizeof(T);
    EEPROMEntry<T> entry(size, currentAddress);
    currentAddress += size;
    return(entry);
  }
  
  static EEPROMManager* the() 
  {
    if(!instance)
    {
      instance = new EEPROMManager();
    }      
    return instance;
  }
  
private:  
    static EEPROMManager* instance;
  
  EEPROMManager()
    : currentAddress(0)
  {
    
  }
  
  int currentAddress;
};

#endif //INFINITAG_EEPROM_MANAGER_H