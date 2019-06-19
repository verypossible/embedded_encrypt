#include <AES.h>

#ifndef VERY_ENCRYPT_H
#define VERY_ENCRYPT_H

class VeryEncrypt {

public:
  VeryEncrypt(unsigned char *key, unsigned long long int initVector) {
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
