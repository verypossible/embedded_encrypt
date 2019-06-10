#include "Encryption.h"

AES aes;

void Encryption::encrypt(unsigned char plain[], unsigned char encryptedBuffer[],
                         int size) {
  int bits = 128;
  aes.iv_inc();
  byte iv[N_BLOCK];

  aes.set_IV(_initVector);
  aes.get_IV(iv);
  aes.do_aes_encrypt(plain, size, encryptedBuffer, _key, bits, iv);
}

void Encryption::decrypt(unsigned char encrypted[],
                         unsigned char decryptedBuffer[], int size) {
  int bits = 128;
  byte iv[N_BLOCK];

  aes.set_IV(_initVector);
  aes.get_IV(iv);
  aes.do_aes_decrypt(encrypted, size, decryptedBuffer, _key, bits, iv);
}
