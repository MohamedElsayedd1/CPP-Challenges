#include <iostream>
#include <list>
#include <algorithm>
#include <limits> // For using std::numeric_limits to clear input buffer
#include <iomanip>
using namespace std;

class Song
{
private:
    string name;
    string artist;
    int rating;

public:
    Song(string n, string ar, int r) : name{n}, artist{ar}, rating{r} {}
    ~Song() = default;
    bool operator<(const Song &obj)
    {
        return this->rating < obj.rating;
    }
    bool operator==(const Song &obj)
    {
        return (this->name == obj.name && this->artist == obj.artist && this->rating == obj.rating);
    }
    friend ostream &operator<<(ostream &os, const Song &obj);
};

ostream &operator<<(ostream &os, const Song &obj)
{
    os << setw(30) << left << obj.name
       << setw(20) << left << obj.artist
       << setw(15) << left << obj.rating;
    return os;
}

void display_current_song(const list<Song> &songs, list<Song>::const_iterator it)
{
    cout << endl;
    if (it != songs.end())
    {
        cout << "Currently playing: " << endl
             << *it << endl;
    }
    else
    {
        cout << "Playlist is empty or iterator is at the end." << endl;
    }
}

void display_playlist(const list<Song> &songs)
{
    cout << setw(30) << left << "Name"
         << setw(20) << left << "Singer"
         << setw(15) << left << "Rating[5]" << endl;
    cout << setw(60) << right << setfill('-') << " " << endl;
    cout << setfill(' ');
    for (auto const &song : songs)
    {
        cout << song << endl;
    }
}

void add_new_song(list<Song> &songs, auto &it)
{
    string name;
    string artist;
    int rating;
    cout << "Adding new song .. \n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    cout << "Enter name of the song : ";
    getline(cin, name);
    cout << "Enter name of the singer : ";
    getline(cin, artist);
    cout << "Enter rating : ";
    cin >> rating;
    songs.insert(it, Song(name, artist, rating));
    it--;
    display_current_song(songs, it);
}

void display_menu(void)
{
    cout << "\nF - Play first song" << endl;
    cout << "\nN - Play next song" << endl;
    cout << "\nP - Play previous song" << endl;
    cout << "\nA - Add a new song at current location " << endl;
    cout << "\nL - List the current playlist" << endl;
    cout << "=================================================\n";
}

int main()
{
    // Initializing a list of Song objects
    list<Song> my_playlist{{"Born to die", "Lana Del Rey", 5},
                           {"Sway", "Michael Buble", 4},
                           {"My Way", "Frank Sinatra", 4},
                           {"Brother Louie", "Modern Talking", 3},
                           {"Cinderella", "Future", 4},
                           {"Shape of You", "Ed Sheeran", 5},
                           {"Blinding Lights", "The Weeknd", 5},
                           {"Levitating", "Dua Lipa", 4},
                           {"Rolling in the Deep", "Adele", 4},
                           {"Bohemian Rhapsody", "Queen", 5},
                           {"Hotel California", "Eagles", 5},
                           {"Hey Jude", "The Beatles", 5},
                           {"Smells Like Teen Spirit", "Nirvana", 4}};

    display_playlist(my_playlist);
    auto current_song = my_playlist.begin();
    display_current_song(my_playlist, current_song);

    char select = 'L';

    while (select != 'Q')
    {
        display_menu();
        cout << "Enter a selection (Q to Quit) : ";
        cin >> select;
        select = toupper(select);
        switch (select)
        {
        case 'F':
            current_song = my_playlist.begin();
            display_current_song(my_playlist, current_song);
            break;
        case 'N':
            current_song++;
            if (current_song == my_playlist.end())
                current_song = my_playlist.begin();
            display_current_song(my_playlist, current_song);
            break;
        case 'P':
            if (current_song == my_playlist.begin())
                current_song = my_playlist.end();
            current_song--;
            display_current_song(my_playlist, current_song);
            break;
        case 'A':
            add_new_song(my_playlist, current_song);
            break;
        case 'L':
            display_playlist(my_playlist);
        default:
            cout << "Wrong output! please try again.\n";
            break;
        }
    }

    return 0;
}