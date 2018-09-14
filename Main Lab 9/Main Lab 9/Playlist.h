/*Noah Pittenger, Section 001, noahap@byu.edu*/
#pragma once
#pragma once
#ifndef Playlist_h
#define Playlist_h
using namespace std;
#include "Song.h"
class Playlist {
public:
	Playlist();
	Playlist(string playlist);
	int FindPlaylistWithSong(Song* song);
	string SetName(string playlist);
	void PrintPlaylists();
	void AddSong(Song* song);
	void PlaySongs();
	void DeletePlaylistSong(int userindex);
	void PrintSongsInPlaylist();
	void FindAndEraseSong(Song* song);
private:
	string playlistInput = "none";
	vector<Song*> songsInPlaylist;
};
#endif