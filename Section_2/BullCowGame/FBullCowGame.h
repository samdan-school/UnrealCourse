#pragma once
#include <string>

using FText = std::string;
using int32 = int;

struct BullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGuessValidity(FText);

	BullCowCount SubmitGuess(FText);
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FText MyHiddenWord;
};