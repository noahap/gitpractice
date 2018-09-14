/*Noah Pittenger, Section 001, noahap@byu.edu*/
#include <iostream>
#include <iomanip>
#include<string>
#include<vector>
#include "Playlist.h"
#include "Song.h"

Playlist::Playlist() {
	playlistInput = "none";
	songsInPlaylist;
}
Playlist::Playlist(string playlist) {
	playlistInput = playlist;
}
int Playlist::FindPlaylistWithSong(Song* songs) {
	for (int i = 0; i < songsInPlaylist.size(); ++i) {
		if (songsInPlaylist.at(i)->GetSong() == songs->GetSong()) {
			return i;
		}
	}
}
string Playlist::SetName(string playlist) {
	playlistInput = playlist;
	return playlistInput;
}
void Playlist::PrintPlaylists() {
	cout << ": " << playlistInput << endl;
}
void Playlist::AddSong(Song* song) {
	songsInPlaylist.push_back(song);
}
void Playlist::PlaySongs() {
	for (int i = 0; i < songsInPlaylist.size(); ++i) {
		cout << songsInPlaylist.at(i)->GetLine() << endl;
		songsInPlaylist.at(i)->IncrementSong();
	}
}
void Playlist::DeletePlaylistSong(int userIndex) {
	songsInPlaylist.erase(songsInPlaylist.begin() + userIndex);
}
void Playlist::PrintSongsInPlaylist() {
	for (int i = 0; i < songsInPlaylist.size(); ++i) {
		cout << i << ": " << songsInPlaylist.at(i)->GetSong() << endl;
	}
}
void Playlist::FindAndEraseSong(Song* song) {
	for (int i = 0; i < songsInPlaylist.size(); ++i) {
		if (songsInPlaylist.at(i) == song) {
			songsInPlaylist.erase(songsInPlaylist.begin() + i);
		}
	}
}


