/*Noah Pittenger, Section 001, noahap@byu.edu*/
#include <iostream>
#include <iomanip>
#include<string>
#include "Song.h"

Song::Song() {
	numPlays = 0;
	songInput = "none";
	songLine = "none";
	songTag = "none";
}
Song::Song(string song, string line, string tags) {
	songInput = song;
	songLine = line;
	//addSongTag = tag;
	songTag = tags;
}

void Song::SetNewTag(string tag) {
	addSongTag.push_back(tag);
}
/*
void Song::OutputTags() {
	for (int i = 0; i < addSongTag.size(); ++i) {
		cout << addSongTag.at(i) << " ";
	}
	cout << endl;
}
*/
string Song::GetLine() {
	return songLine;
}
string Song::GetSong() {
	return songInput;
}
void Song::PrintSongsAndLines() {
	cout << songInput << ": \"" << songLine << "\", " << numPlays << " play(s)." << endl;
	cout << "Tags: " << songTag << endl;
	
	cout << endl;
	
}
void Song::PrintSongs() {
	cout << ": " << songInput << endl;
}
void Song::IncrementSong() {
	++numPlays;
}