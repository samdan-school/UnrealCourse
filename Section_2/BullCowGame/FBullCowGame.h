#pragma once
#include <string>

using FText = std::string;
using int32 = int;

struct BullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	OK,
	Not_Isogram,
	Wrong_Length,
	Now_Lowercase
};

enum class EResetStatus {
	OK,
	No_Hidden_Word,
};

class FBullCowGame {
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FText) const;

	void Reset();

	BullCowCount SubmitGuess(FText);
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FText MyHiddenWord;
	bool bGameIsWon;
};