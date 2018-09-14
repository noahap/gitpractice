/*Noah Pittenger, Section 001, noahap@byu.edu*/
#pragma once
#include<vector>
#ifndef Song_h
#define Song_h
using namespace std;

class Song {
public:
	Song();
	Song(string song, string line, string tags);
	string GetLine();
	string GetSong();
	void PrintSongsAndLines();
	void PrintSongs();
	void IncrementSong();
	void SetNewTag(string tag);
	
private:
	int numPlays = 0;
	string songInput = "none";
	string songLine = "none";
	string songTag = "none";
	vector<string> addSongTag;
};
#endif
