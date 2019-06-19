#ifdef UNIT_TEST
#include "VeryEncrypt.h"
#include "unity.h"

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_encrypt_decrypt(void) {

  unsigned long long int initVector = 36753562;
  VeryEncrypt enc((unsigned char *)"0123456789010123", initVector);

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

// not needed when using generate_test_runner.rb
void setup(void) {
  UNITY_BEGIN();

  RUN_TEST(test_encrypt_decrypt);

  UNITY_END();
}

void loop(void) {}
#endif
