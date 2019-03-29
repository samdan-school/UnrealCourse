#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { this->Reset(); }

void FBullCowGame::Reset() {
	this->MyCurrentTry = 1;

	const FText HIDDEN_WORD = "plant";
	this->MyHiddenWord = HIDDEN_WORD;

	constexpr int32 MAX_TRIES = 5;
	this->MyMaxTries = MAX_TRIES;
}

bool FBullCowGame::CheckGuessValidity(FText) {
	return false;
}

BullCowCount FBullCowGame::SubmitGuess(FText Guess) {
	BullCowCount BullCowCount;
	int32 HiddenWordLength = this->MyHiddenWord.length();

	for (int32 i = 0; i < HiddenWordLength; i++) {
		for (int32 j = 0; j < HiddenWordLength; j++) {
			if (this->MyHiddenWord[i] == Guess[i]) {
				if (i == j)  BullCowCount.Bulls++;
				else  BullCowCount.Cows++;
			}
		}
	}
	return BullCowCount;
}

int FBullCowGame::GetMaxTries() const { return this->MyMaxTries; }

int FBullCowGame::GetCurrentTry() const { return this->MyCurrentTry; }

bool FBullCowGame::IsGameWon() const {
	return false;
}