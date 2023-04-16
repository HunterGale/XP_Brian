#include "pch.h"

#include <gtest/gtest.h>
#include <string>
#include "secret_cipher.h" 
#include "random_cipher.h"

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

TEST(RandomCipherTest, DifferentCharacters) {
	// Test that the output has different characters than the input
	std::string input = "hello";
	std::string output = random_cipher(input);
	ASSERT_EQ(input.size(), output.size());

	// This is nessessary to eliminate the possible of the random string being the same
	// as the input string, by chance
	for (int i = 0; i < input.size(); i++) {
		ASSERT_NE(input[i], output[i]);
	}
}

TEST(RandomCipherTest, SameLength) {
	// Test that the output has the same length as the input
	std::string input = "teststring";
	std::string output = random_cipher(input);
	ASSERT_EQ(input.size(), output.size());
}

TEST(RandomCipherTest, Random) {
	// Test that the output is truly random
	std::string input = "randominputstring";
	std::string output1 = random_cipher(input);
	std::string output2 = random_cipher(input);
	ASSERT_EQ(input.size(), output1.size());
	ASSERT_EQ(input.size(), output2.size());
	ASSERT_NE(output1, output2); // outputs should be different (although there is a possibility they could be the same by chance)
}