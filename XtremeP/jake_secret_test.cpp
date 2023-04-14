#include "pch.h"

#include "caesarShift.h";

TEST(JakeSecretTest, ReturnIsCorrect) {
	EXPECT_EQ(caesarShift("Veni Vidi Vici"), "SPQR");
	EXPECT_EQ(caesarShift("veni vidi vici"), "SPQR");
	EXPECT_EQ(caesarShift("VENI VIDI VICI"), "SPQR");
}

TEST(JakeSecretTest, DoesntAlwaysReturnSecret) {
	EXPECT_NE(caesarShift("This"), "SPQR");
	EXPECT_NE(caesarShift("Hello World"), "SPQR");
}
