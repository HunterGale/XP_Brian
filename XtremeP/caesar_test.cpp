#include "pch.h"

#include "caesarShift.h";


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
