#include <AES.h>

#ifndef ENCRYPTION_H
#define ENCRYPTION_H

class Encryption {

public:
  Encryption(unsigned char *key, unsigned long long int initVector) {
    _key = key;
    _initVector = initVector;
  }
  void encrypt(unsigned char plain[], unsigned char encryptedBuffer[],
               int size);
  void decrypt(unsigned char encrypted[], unsigned char decryptedBuffer[],
               int size);

private:
  byte *_key;
  unsigned long long int _initVector;
};

#endif
