#include "pch.h"

#include "../XtremeP/caesarShift.h";
#include "../XtremeP/secret_cipher.h"
// #include (path to random cipher goes here)

// Tests for Caesar Shift (Written by Jake)
TEST(CaesarShift, FunctionExists) {
	EXPECT_NO_THROW({
		caesarShift("Hello");
		});
}

TEST(CaesarShift, MessageLengthIsSame) {
	EXPECT_EQ(static_cast<int>(caesarShift("Hello world").size()), 11);
	EXPECT_EQ(static_cast<int>(caesarShift("Text").size()), 4);
}

TEST(CaesarShift, CaseInsensitive) {
	EXPECT_EQ(caesarShift("HELLO WORLD"), "KHOOR ZRUOG");
	EXPECT_EQ(caesarShift("MY TEXT"), "PB WHAW");
}

TEST(CaesarShift, CaseSensitive) {
	EXPECT_EQ(caesarShift("hello world"), "KHOOR ZRUOG");
	EXPECT_EQ(caesarShift("my text"), "PB WHAW");
}

// Tests for Caesar Shift Secret Feature (Written by Jake)
TEST(JakeSecretTest, ReturnIsCorrect) {
	EXPECT_EQ(caesarShift("Veni Vidi Vici"), "SPQR");
	EXPECT_EQ(caesarShift("veni vidi vici"), "SPQR");
	EXPECT_EQ(caesarShift("VENI VIDI VICI"), "SPQR");
}

TEST(JakeSecretTest, DoesntAlwaysReturnSecret) {
	EXPECT_NE(caesarShift("This"), "SPQR");
	EXPECT_NE(caesarShift("Hello World"), "SPQR");
}


// Tests for Rail Fence Cipher (Other secret feature, written by Hunter)
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

// Tests for random Cipher feature (Written by Hunter)
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