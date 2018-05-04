#ifndef _Pack_h
#define _Pack_h

#include "ParamsHandler.h"
#include <stdio.h>

template <typename Header>
class Pack
{
    public:
    
    Pack()
    {
        this->buffer = new byte[PACK_SIZE];
        
        for (int i = 0; i < PACK_SIZE; i++) 
            buffer[i] = 0;
        
        this->header = (Header*)buffer;
    
        this->readPosition = sizeof(Header);
        this->writePosition = sizeof(Header);
        
        printf("%d\n", (int)sizeof(Header));
    }
    
    Pack(byte* buffer)
    {
        this->buffer = buffer;
        this->header = (Header*)buffer;
        
        this->readPosition = sizeof(Header);
        this->writePosition = sizeof(Header);
        
        printf("%d\n", (int)sizeof(Header));
    }
    
    inline const Header& MyHeader() const
    {
        return (*header);
    }
    
    inline Header& MyHeader()
    {
        return (*header);
    }
    
    inline const byte* Buffer()
    {
        return this->buffer;
    }
    
    inline byte& operator[](int index)
    {
        index += sizeof(Header);
        
        if(index < PACK_SIZE && index > 0)
        {
            return buffer[index];
        }
    }
    
    inline const byte& operator[](int index) const
    {
        index += sizeof(Header);
        
        if(index < PACK_SIZE && index > 0)
        {
            return buffer[index];
        }
    }
    
    void Write(byte* buffer, int offset, int count)
    {
        for (int i = 0; i < count; i++) 
        {
            this->buffer[writePosition + i] = buffer[i + offset];
        }
        
        this->writePosition += count;
    }
    
    void Read(byte* buffer, int offset, int count)
    {
        for (int i = 0; i < count; i++) 
        {
            buffer[i + offset] = this->buffer[readPosition + i];
        }
        
        this->readPosition += count;
    }
    
    /* void encrypt() */
    
    protected:
    Header* header;
    byte* buffer;
    int readPosition;
    int writePosition;
};

#endif