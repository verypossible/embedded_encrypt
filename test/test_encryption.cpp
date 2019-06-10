#ifdef UNIT_TEST
#include "Encryption.h"
#include "unity.h"

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_function_should_doBlahAndBlah(void) {

  unsigned long long int initVector = 36753562;
  Encryption enc((unsigned char *)"0123456789010123", initVector);

  unsigned char encryptedBuffer[20] = {};

  unsigned char toEncrypt[20] = "foobar";
  enc.encrypt(toEncrypt, encryptedBuffer, 20);

  TEST_ASSERT_FALSE(
      strcmp((const char *)encryptedBuffer, (const char *)toEncrypt) == 0);

  unsigned char decryptedBuffer[20] = {};
  enc.decrypt(encryptedBuffer, decryptedBuffer, 20);

  TEST_ASSERT_EQUAL_STRING((const char *)decryptedBuffer,
                           (const char *)"foobar");
}

void loop(void) {}
#endif
