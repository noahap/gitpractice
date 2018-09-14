/*Noah Pittenger, Section 001, noahap@byu.edu

Freeing Memory occurs in line 302 of this code.

Test Case 1:
Input:
add
I Only Wanna Be with You
You and me, we come from different worlds
Africa
I hear the drums echoing tonight
We Didn't Start The Fire
Harry Truman, Doris Jay, Red China, Johnnie Ray
STOP
addp
My Favorite Playlist
listp
addsp
0
1
addsp
0
2
list
play
0
list
quit
Output:
Song Output before playing songs
I Only Wanna Be with You: "You and me, we come from different worlds", 0 play(s).
Africa: "I hear the drums echoing tonight", 0 play(s).
We Didn't Start The Fire: "Harry Truman, Doris Jay, Red China, Johnnie Ray", 0 play(s).
Song Output after playing songs
I Only Wanna Be with You: "You and me, we come from different worlds", 0 play(s).
Africa: "I hear the drums echoing tonight", 1 play(s).
We Didn't Start The Fire: "Harry Truman, Doris Jay, Red China, Johnnie Ray", 1 play(s).
Result: Passed

Test Case 2:
Input:
add
Nearer My God to Thee
Nearer, my God, to Thee, Nearer to Thee
Beethoven's Fifth Symphony
Allegro con brio
Hotline Bling
You used to call me on my, you used to, you used to
Sweet Home Alabama
Big wheels keep on turning
STOP
addp
Sweet Jams
addsp
0
1
addsp
0
3
delsp
0
0
delsl
0
2
play
0
list
quit
Output:
Final list output:
Beethoven's Fifth Symphony: "Allegro con brio", 0 play(s).
Hotline Bling: "You used to call me on my, you used to, you used to", 0 play(s).
Sweet Home Alabama: "Big wheels keep on turning", 1 play(s).
Result: Passed
Test Case 3:
Input:
options
beef
dog
cat
add
La Fiesta Del Mariachi
La fiesta va a comenzar
Non, je no regrette rien
Non, rien de rien, non, je ne regrette rien
Si nos dejan
Si nos dejan, nos vamos a querer toda la vida
STOP
addp
International Playlist
addp
Domestic Playlist
addsp
0
1
listp
0
play
0
list
delsl
1
play
0
list
quit
Output:
All menu outputs passed
Songs before deleting from list
La Fiesta Del Mariachi: "La fiesta va a comenzar", 0 play(s).
Non, je no regrette rien: "Non, rien de rien, non, je ne regrette rien", 1 play(s).
Si nos dejan: "Si nos dejan, nos vamos a querer toda la vida", 0 play(s).

Songs after deleting from list
La Fiesta Del Mariachi: "La fiesta va a comenzar", 0 play(s).
Si nos dejan: "Si nos dejan, nos vamos a querer toda la vida", 0 play(s).
Result: Passed
*/

#include <iostream>
#include <string>
#include <iomanip>
#include<vector>
#include <sstream>
#include "Song.h"
#include "Playlist.h"
using namespace std;

int main() {

	int numPlays = 0;
	int playlistIndex = 0;
	int songIndex = 0;
	int numTags = 0;
	const int IGNORE_ALL = 9999;
	string userSelection = "";
	string songName = "";
	string firstLine = "";
	string playlistName = "";
	string songTag = "";
	istringstream inSS(songTag);
	vector<Song*> songs;
	vector<Playlist> playlists;
	vector<string> tags;
	Song *addTagPtr = nullptr;
	//string newTag = "";
	Song *addSongPtr = nullptr;
	Playlist newPlaylist;


	cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl;

	do {
		cout << "Enter your selection now:" << endl << endl;
		cin >> userSelection;
		cin.ignore(IGNORE_ALL, '\n');

		if (userSelection == "add") {
			cout << "Read in Song names, first lines, and tags (type \"STOP\" when done):" << endl;
			do {
				numTags = 0;
				cout << "Song Name:";
				getline(cin, songName);
				if (songName == "STOP") {
					break;
				}
				cout << endl;

				cout << "Song's first line:";
				getline(cin, firstLine);
				cout << endl;

				cout << "Tags:";
				getline(cin, songTag);
				/*
				if (songTag != "") {
					for (int i = 0; i < songTag.size(); ++i) {
						char nextChar = songTag[i];
						if (isspace(nextChar)) {
							++numTags;
						}
					}
					for (int i = 0; i < numTags; ++i) {
						inSS.clear();
						string tag;
						inSS >> tag;
						addSongPtr->SetNewTag(tag);
						inSS.clear();
					}
				}
				/*
				while (!inSS.eof()) {
					vector<string> tags;
					string tag;
					inSS >> tag;
					tags.push_back(tag);
				}
				*/
				cout << endl;

				addSongPtr = new Song(songName, firstLine, songTag);
				songs.push_back(addSongPtr);
				
			} while (songName != "STOP");
		}
		
		else if (userSelection == "list") {
			for (int i = 0; i < songs.size(); ++i) {
				songs.at(i)->PrintSongsAndLines();
			}
		}
		else if (userSelection == "addp") {
			cout << "Playlist name:";
			getline(cin, playlistName);
			cout << endl;
			newPlaylist.SetName(playlistName);
			playlists.push_back(newPlaylist);
		}

		else if (userSelection == "addsp") {
			int j = 0;
			int k = 0;
			for (int i = 0; i < playlists.size(); ++i) {
				cout << j;
				playlists.at(i).PrintPlaylists();
				++j;
			}
			cout << "Pick a playlist index number:" << endl;
			cin >> playlistIndex;
			cout << endl;
			for (int i = 0; i < songs.size(); ++i) {
				cout << k;
				songs.at(i)->PrintSongs();
				++k;
			}
cout << "Pick a song index number:";
cin >> songIndex;
playlists.at(playlistIndex).AddSong(songs.at(songIndex));
cout << endl;
		}

		else if (userSelection == "listp") {
			int j = 0;
			for (int i = 0; i < playlists.size(); ++i) {
				cout << j;
				playlists.at(i).PrintPlaylists();
				++j;
			}
		}

		else if (userSelection == "play") {
			int j = 0;
			for (int i = 0; i < playlists.size(); ++i) {
				cout << j;
				playlists.at(i).PrintPlaylists();
				++j;
			}
			cout << "Pick a playlist index number:" << endl;
			cin >> playlistIndex;
			cout << endl << endl;
			cout << "Playing first lines of playlist";
			playlists.at(playlistIndex).PrintPlaylists();
			cout << endl;
			playlists.at(playlistIndex).PlaySongs();
		}

		else if (userSelection == "delp") {
			int j = 0;
			for (int i = 0; i < playlists.size(); ++i) {
				cout << j;
				playlists.at(i).PrintPlaylists();
				++j;
			}
			cout << "Pick a playlist index number to delete:";
			cin >> playlistIndex;
			cout << endl;
			playlists.erase(playlists.begin() + playlistIndex);
		}

		else if (userSelection == "delsp") {
			int j = 0;
			int k = 0;
			for (int i = 0; i < playlists.size(); ++i) {
				cout << j;
				playlists.at(i).PrintPlaylists();
				++j;
			}
			cout << "Pick a playlist index number:" << endl;
			cin >> playlistIndex;
			cout << endl;
			playlists.at(playlistIndex).PrintSongsInPlaylist();

			cout << "Pick a song index number to delete:";
			cin >> songIndex;
			playlists.at(playlistIndex).DeletePlaylistSong(songIndex);
			cout << endl;
		}

		else if (userSelection == "delsl") {
			for (int i = 0; i < songs.size(); ++i) {
				cout << i;
				songs.at(i)->PrintSongs();
			}
			cout << "Pick a song index number:";
			cin >> songIndex;
			for (int i = 0; i < playlists.size(); ++i) {
				if (playlists.at(i).FindPlaylistWithSong(songs.at(songIndex)) != -1) {
					playlists.at(i).FindAndEraseSong(songs.at(songIndex));
				}
			}
			delete songs.at(songIndex);
			songs.erase(songs.begin() + songIndex);
		}

		else if (userSelection == "options") {
			cout << "add      Adds a list of songs to the library" << endl;
			cout << "list     Lists all the songs in the library" << endl;
			cout << "addp     Adds a new playlist" << endl;
			cout << "addsp    Adds a song to a playlist" << endl;
			cout << "listp    Lists all the playlists" << endl;
			cout << "play     Plays a playlist" << endl;
			cout << "delp     Deletes a playlist" << endl;
			cout << "delsp    Deletes a song from a playlist" << endl;
			cout << "delsl    Deletes a song from the library(and all playlists)" << endl;
			cout << "options  Prints this options menu" << endl;
			cout << "quit     Quits the program" << endl;
			cout << endl;
		}

		else if (userSelection == "quit") {
			// I am Freeing Memory below.
			for (int i = 0; i < songs.size(); ++i) {
				delete songs.at(i);
				songs.erase(songs.begin() + i);
			}
			for (int i = 0; i < playlists.size(); ++i) {
				playlists.erase(playlists.begin() + i);
			}
			break;
		}

		else {
			cout << "add      Adds a list of songs to the library" << endl;
			cout << "list     Lists all the songs in the library" << endl;
			cout << "addp     Adds a new playlist" << endl;
			cout << "addsp    Adds a song to a playlist" << endl;
			cout << "listp    Lists all the playlists" << endl;
			cout << "play     Plays a playlist" << endl;
			cout << "delp     Deletes a playlist" << endl;
			cout << "delsp    Deletes a song from a playlist" << endl;
			cout << "delsl    Deletes a song from the library(and all playlists)" << endl;
			cout << "options  Prints this options menu" << endl;
			cout << "quit     Quits the program" << endl;
			cout << endl;
		}
		cout << endl;
		
	} while (userSelection != "quit");
	
	cout << "Goodbye!" << endl;
	//system("pause");
	return 0;
}