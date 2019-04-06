#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { this->Reset(); }

int32 FBullCowGame::GetMaxTries() const { return this->MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return this->MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return this->MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

EGuessStatus FBullCowGame::CheckGuessValidity(FText guess) const {
	EGuessStatus status = EGuessStatus::OK;
	if (false) status = EGuessStatus::Not_Isogram;
	else if (false) status = EGuessStatus::Now_Lowercase;
	else if (guess.length() != this->GetHiddenWordLength()) status = EGuessStatus::Wrong_Length;
	return status;
}

void FBullCowGame::Reset() {
	this->bGameIsWon = false;

	this->MyCurrentTry = 1;

	const FText HIDDEN_WORD = "plant";
	this->MyHiddenWord = HIDDEN_WORD;

	constexpr int32 MAX_TRIES = 5;
	this->MyMaxTries = MAX_TRIES;
}

BullCowCount FBullCowGame::SubmitValidGuess(FText Guess) {
	this->MyCurrentTry++;
	BullCowCount BullCowCount;
	int32 WordLength = this->GetHiddenWordLength(); // assume same length as guess

	// loop throught all letes in the hidden word
	for (int32 i = 0; i < WordLength; i++) {
		for (int32 j = 0; j < WordLength; j++) {
			if (this->MyHiddenWord[i] == Guess[i]) {
				if (i == j)  BullCowCount.Bulls++;
				else  BullCowCount.Cows++;
			}
		}
	}
	if (BullCowCount.Bulls == this->GetHiddenWordLength()) bGameIsWon = true;
	else bGameIsWon == false;
	return BullCowCount;
}