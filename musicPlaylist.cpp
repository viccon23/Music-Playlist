#include <iostream>
#include <limits>
#include <vector>
#include <string>
using namespace std;

#include "code.h"

int main() {

  int choice = 0;
  bool exitMenu = false;
  Playlist playlist; // Declare and initialize the Playlist object outside the
                     // switch statement

  while (!exitMenu) {
    displayMenu();
    cin >> choice;

    // Add cin.ignore() to discard remaining characters
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    switch (choice) {
    case 1: {
      cout << "\nChoose Playlist Name: \n" << endl;
      string Title;
      getline(cin, Title);
      // Assign the Playlist object to the declared variable
      playlist = Playlist(Title);
      break;
    }

    case 2: {
      // Create the new song object
      cout << "\n\nLet's Add a track to our playlist!" << endl;
      cout << "Input the name of the track: \n" << endl;
      string t, al, len;
      vector<string> a;
      vector<string> g;
      getline(cin, t);
      cout << "\nInput artist names (Enter 'done' to finish):\n" << endl;
      string artist;
      while (getline(cin, artist) && artist != "done") {
        a.push_back(artist);
      }
      cout << "\nInput Genres of the song (enter 'done' to finish):\n" << endl;
      string genre;
      while (getline(cin, genre) && genre != "done") {
        g.push_back(genre);
      }
      cout << "\nInput name of Album where the song is included. If it's not in "
              "an album, type N/A: \n"
           << endl;
      getline(cin, al);
      cout << "\nType the length of the song in minute:second format:\n" << endl;
      getline(cin, len);
      Song *song = new Song(t, a, g, al, len);
      // Finally, add song object to the playlist
      playlist.addTrack(song, {g}, {a});
      break;
    }

    case 3: {
      cout << "\nRemoving first track in playlist....\n" << endl;
      playlist.removeFirstTrack();
      cout << "Track Removed!\n";
      break;
    }
    case 4: {
      cout << "\nEnter the name of the track you want to remove from your "
              "playlist: \n"
           << endl;
      string title;
      getline(cin, title);
      playlist.removeTrack(title);
      cout << "\n\n Track Removed!" << endl;
      break;
    }
    case 5: {
      cout << "\nEnter the name of the track you want to playlist\n" << endl;
      string title;
      getline(cin, title);
      playlist.toggleFavorite(title);
      cout << "\n\n Track Favorited!" << endl;
      break;
    }
    case 6: {
      cout << "\nLet's Add a track to our playlist!" << endl;
      cout << "Input the name of the track: \n" << endl;
      string t, al, len;
      vector<string> a;
      vector<string> g;
      getline(cin, t);
      cout << "\nInput artist names (Enter 'done' to finish):\n" << endl;
      string artist;
      while (getline(cin, artist) && artist != "done") {
        a.push_back(artist);
      }
      cout << "\nInput Genres of the song (enter 'done' to finish):\n" << endl;
      string genre;
      while (getline(cin, genre) && genre != "done") {
        g.push_back(genre);
      }
      cout << "\nInput name of Album where the song is included. If it's not in "
              "an album, type N/A: \n"
           << endl;
      getline(cin, al);
      cout << "\nType the length of the song in minute:second format:\n" << endl;
      getline(cin, len);
      Song *song = new Song(t, a, g, al, len);
      cout << "\nWhat position do you want to insert your track at?\nNote: If "
              "you input a number larger than the playlist, then the track "
              "will be placed at the end. If the number is 0, the track will "
              "be placed in the beginning. No negative values are allowed.\n"
           << endl;
      int position;
      cin >> position;
      // Finally, add song object to the playlist
      playlist.insertTrackAt(song, {g}, {a}, position);
      break;
    }
    case 7: {
      cout << "\nHere are all the songs in the playlist\n" << endl;
      playlist.displayPlaylist();
      break;
    }
    case 8: {
      cout << "\nWhat genre would you like to filter the playlist by?: \n" << endl;
      string genre;
      getline(cin, genre);
      playlist.searchByGenre(genre);
      break;
    }
    case 9: {
      return 0;
    }
    default: {
      exitMenu = true;
      break;
    }
    }
  }
  
}
