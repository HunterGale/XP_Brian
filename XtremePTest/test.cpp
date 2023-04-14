#include "pch.h"

#include <gtest/gtest.h>
#include <string>
#include "secret_cipher.h" // include the header file with the function declaration

TEST(SecretCipherTest, Test1) {
	std::string input = "HELLO WORLD";
	std::string expected_output = "HOLELWRDLO";
	int key = 3;
	std::string actual_output = secret_cipher(input, key);
	EXPECT_EQ(expected_output, actual_output);
}

TEST(SecretCipherTest, Test2) {
	std::string input = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
	std::string expected_output = "TBJRDHKRXUETYOECOOMVHZGQIWFPOEAUNSL";
	int key = 5;
	std::string actual_output = secret_cipher(input, key);
	EXPECT_EQ(expected_output, actual_output);
}

TEST(SecretCipherTest, Test3) {
	std::string input = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string expected_output = "ACEGIKMOQSUWYBDFHJLNPRTVXZ";
	int key = 2;
	std::string actual_output = secret_cipher(input, key);
	EXPECT_EQ(expected_output, actual_output);
}

TEST(SecretCipherTest, CaseTest) {
	std::string input = "hello world";
	std::string expected_output = "HOLELWRDLO";
	int key = 3;
	std::string actual_output = secret_cipher(input, key);
	EXPECT_EQ(expected_output, actual_output);
}