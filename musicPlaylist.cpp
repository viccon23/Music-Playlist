#include <iostream>
#include <limits>
#include <vector>
#include <string>
using namespace std;

#include "code.h"

void displayMenu() {
  cout << "Welcome to C++ Playlist! Choose an Option Below:" << endl;
  cout << "======================================" << endl;
  cout << "     1.  Create Playlist" << endl;
  cout << "     2.  Add track to playlist" << endl;
  cout << "     3.  Remove the first track of playlist" << endl;
  cout << "     4.  Remove track by song title" << endl;
  cout << "     5.  Toggle a track as favorited" << endl;
  cout << "     6.  Insert track at a specific position" << endl;
  cout << "     7.  Display Playlist" << endl;
  cout << "     8.  Search Playlist by genre" << endl;
  cout << "     9.  Exit" << endl;
  cout << "======================================" << endl;
  cout << "Enter your choice: ";
}
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
      cout << "Choose Playlist Name" << endl;
      string Title;
      getline(cin, Title);
      // Assign the Playlist object to the declared variable
      playlist = Playlist(Title);
      break;
    }

    case 2: {
      // Create the new song object
      cout << "Let's Add a track to our playlist!" << endl;
      cout << "Input the name of the track: " << endl;
      string t, al, len;
      vector<string> a;
      vector<string> g;
      getline(cin, t);
      cout << "Input artist names (Enter 'done' to finish):" << endl;
      string artist;
      while (getline(cin, artist) && artist != "done") {
        a.push_back(artist);
      }
      cout << "Input Genres of the song (enter 'done' to finish):" << endl;
      string genre;
      while (getline(cin, genre) && genre != "done") {
        g.push_back(genre);
      }
      cout << "Input name of Album where the song is included. If it's not in "
              "an album, type N/A: "
           << endl;
      getline(cin, al);
      cout << "Type the length of the song in minute:second format:" << endl;
      getline(cin, len);
      Song *song = new Song(t, a, g, al, len);
      // Finally, add song object to the playlist
      playlist.addTrack(song, {g}, {a});
      break;
    }

    case 3: {
      cout << "Removing first track in playlist" << endl;
      playlist.removeFirstTrack();
      break;
    }
    case 4: {
      cout << "Enter the name of the track you want to remove from your "
              "playlist: "
           << endl;
      string title;
      getline(cin, title);
      playlist.removeTrack(title);
      cout << "\n\n Track Removed!" << endl;
      break;
    }
    case 5: {
      cout << "Enter the name of the track you want to playlist" << endl;
      string title;
      getline(cin, title);
      playlist.toggleFavorite(title);
      cout << "\n\n Track Favorited!" << endl;
      break;
    }
    case 6: {
      cout << "Let's Add a track to our playlist!" << endl;
      cout << "Input the name of the track: " << endl;
      string t, al, len;
      vector<string> a;
      vector<string> g;
      getline(cin, t);
      cout << "Input artist names (Enter 'done' to finish):" << endl;
      string artist;
      while (getline(cin, artist) && artist != "done") {
        a.push_back(artist);
      }
      cout << "Input Genres of the song (enter 'done' to finish):" << endl;
      string genre;
      while (getline(cin, genre) && genre != "done") {
        g.push_back(genre);
      }
      cout << "Input name of Album where the song is included. If it's not in "
              "an album, type N/A: "
           << endl;
      getline(cin, al);
      cout << "Type the length of the song in minute:second format:" << endl;
      getline(cin, len);
      Song *song = new Song(t, a, g, al, len);
      cout << "What position do you want to insert your track at?\nNote: If "
              "you input a number larger than the playlist, then the track "
              "will be placed at the end. If the number is 0, the track will "
              "be placed in the beginning. No negative values are allowed."
           << endl;
      int position;
      cin >> position;
      // Finally, add song object to the playlist
      playlist.insertTrackAt(song, {g}, {a}, position);
      break;
    }
    case 7: {
      cout << "Here are all the songs in the playlist" << endl;
      playlist.displayPlaylist();
      break;
    }
    case 8: {
      cout << "What genre would you like to filter the playlist by?: " << endl;
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

/* Display the playlist
myPlaylist.displayPlaylist();

// Toggle a track as a favorite
myPlaylist.toggleFavorite("Bohemian Rhapsody");
myPlaylist.toggleFavorite("Ghosts 'n' Stuff");
myPlaylist.toggleFavorite("Your Mind");

// Display the playlist again to show the favorite track
myPlaylist.displayPlaylist();

// Search for songs by genre
myPlaylist.searchByGenre("Rock");

// Remove a track from the playlist
myPlaylist.removeTrack("I Will Always Love You");

// Display the playlist again to show the removed track
myPlaylist.displayPlaylist();

// Insert a track at a specific position in the playlist
myPlaylist.insertTrackAt(s3, {"Pop", "R&B"}, {"Whitney Houston"}, 2);

// Display the playlist again to show the inserted track
myPlaylist.displayPlaylist();

cout << endl << endl;
myPlaylist.searchByGenre("Techno");

return 0;
} */