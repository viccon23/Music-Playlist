#include <iostream>
#include <limits>
#include <vector>
#include <string>
using namespace std;

struct Song {
  string title;
  vector<string> artists;
  vector<string> genres;
  string album;
  string length;

  Song(string t, vector<string> a, vector<string> g, string al, string len) {
    title = t;
    artists = a;
    genres = g;
    album = al;
    length = len;
  }
};

struct Track {
  Song *song;
  vector<string> genres;
  vector<string> artists;
  Track *next;
  Track *prev;
  bool isFavorited;

  Track(Song *s, vector<string> g, vector<string> a, bool f) {
    song = s;
    genres = g;
    artists = a;
    next = nullptr;
    isFavorited = f;
  }
};

struct Playlist {
  string name;
  Track *head;

  Playlist(string n = "") {
    name = n;
    head = nullptr;
  }

  ~Playlist() {
    Track *curr = head;
    while (curr != nullptr) {
      Track *temp = curr;
      curr = curr->next;
      delete temp;
    }
  }
  // Add track to the beginning of the playlist, create new track object,
  // manipulate nodes.
  void addTrack(Song *s, vector<string> genres, vector<string> artists) {
    Track *newTrack = new Track(s, genres, artists, false);
    newTrack->next = head;
    head = newTrack;
  }
  // Remove only the first track in the playlist
  void removeFirstTrack() {
    if (head == nullptr) {
      return;
    }
    Track *oldHead = head;
    head = head->next;
    delete oldHead;
  }
  // Remove any track based on input parameter
  void removeTrack(string title) {
    if (head == nullptr) {
      cout << "Playlist is already empty!" << endl;
      return;
    }
    if (head->song->title == title) {
      removeFirstTrack();
      return;
    }
    // Reconnect nodes to exclude deleted track object
    Track *prev = head;
    Track *curr = head->next;
    while (curr != nullptr) {
      if (curr->song->title == title) {
        prev->next = curr->next;
        delete curr;
        return;
      }
      prev = curr;
      curr = curr->next;
    }
  }
  // Change bool value of favorite by string title as input parameter
  void toggleFavorite(string title) {
    if (head == nullptr) {
      return;
    }
    Track *curr = head;
    while (curr != nullptr) {
      if (curr->song->title == title) {
        // Change isFavorited
        curr->isFavorited = !curr->isFavorited;
        return;
      }
      curr = curr->next;
    }
    cout << "Could not find track name!";
  }

  void insertTrackAt(Song *s, vector<string> genres, vector<string> artists,
                     int position) {
    if (position <= 0) {
      addTrack(s, genres, artists);
    } else {
      Track *newTrack = new Track(s, genres, artists, false);
      Track *curr = head;
      Track *prev = nullptr;
      int i = 0;
      while (curr != nullptr && i < position) {
        prev = curr;
        curr = curr->next;
        i++;
      }
      prev->next = newTrack;
      newTrack->next = curr;
    }
  }

  void displayPlaylist() {
    if (head == nullptr) {
      cout << "The playlist " << name << " is empty." << endl;
      return;
    }
    cout << "Current Playlist: " << name << ":" << endl;
    Track *curr = head;
    int i = 1;
    while (curr != nullptr) {
      cout << i << ". " << curr->song->title << " by ";
      for (int j = 0; j < curr->song->artists.size(); j++) {
        if (j != 0) {
          cout << ", ";
        }
        cout << curr->song->artists[j];
      }
      cout << " (" << curr->song->album << ", " << curr->song->length
           << " seconds)";
      if (!curr->song->genres.empty()) {
        cout << " [";
        for (int j = 0; j < curr->song->genres.size(); j++) {
          if (j != 0) {
            cout << ", ";
          }
          cout << curr->song->genres[j];
        }
        cout << "]";
      }
      if (curr->isFavorited) {
        cout << " - FAVORITE";
      }
      cout << endl;
      curr = curr->next;
      i++;
    }
  }

  void searchByGenre(string genre) {
    bool found = false;
    cout << "Songs with the genre '" << genre << "' in playlist " << name << ":"
         << endl;
    Track *curr = head;
    int i = 1;
    while (curr != nullptr) {
      for (int j = 0; j < curr->genres.size(); j++) {
        if (curr->genres[j] == genre) {
          found = true;
          cout << i << ". " << curr->song->title << " by ";
          for (int k = 0; k < curr->song->artists.size(); k++) {
            if (k != 0) {
              cout << ", ";
            }
            cout << curr->song->artists[k];
          }
          cout << " (" << curr->song->album << ", " << curr->song->length
               << " seconds)";
          if (curr->isFavorited) {
            cout << " - FAVORITE";
          }
          cout << endl;
          i++;
          break;
        }
      }
      curr = curr->next;
    }
    if (!found) {
      cout << "No songs with the genre " << genre << " found in playlist "
           << name << "." << endl;
    }
  }
};
