#include<iostream>
#include<iomanip>
#include<string>
#include<list>


class Song
{
	friend std::ostream& operator<<(std::ostream& os, const Song& s);
	
	std::string name;
	std::string artist;
	int rating;
public:
	Song() = default;
	Song(std::string name, std::string artist, int rating)
		:name{ name }, artist{ artist }, rating{ rating }{}
	std::string getName() const
	{
		return name;
	}
	std::string getArtist() const
	{
		return artist;
	}
	int getRating() const
	{
		return rating;
	}

	bool operator<(const Song& rhs) const
	{
		return this->name < rhs.name;
	}
	bool operator==(const Song& rhs) const
	{
		return this->name == rhs.name;
	}

};

std::ostream& operator<<(std::ostream& os, const Song& s)
{
	os << std::setw(20) << std::left << s.name
		<< std::setw(30) << std::left << s.artist
		<< std::setw(2) << std::left << s.rating;
	return os;
}


void displayMenu()
{
	std::cout << "\nF - Play The First Song" << std::endl;
	std::cout << "N - Play The Next Song" << std::endl;
	std::cout << "P - Play The Previous Song" << std::endl;
	std::cout << "L - Display the Playlist" << std::endl;
	std::cout << "A - Add and play a song at current location" << std::endl;
	std::cout << "===================================================" << std::endl;
	std::cout << "Enter a selection (Q to Quit!)" << std::endl;
}

void playCurrentSong(const Song& currentSong)
{
	std::cout << "Playing: \n" <<currentSong << std::endl;
}

void displayPlaylist(const std::list<Song>& playlist, const Song& currentSong)
{

	for (const Song& song : playlist)
	{
		std::cout << song << std::endl;
	}

	playCurrentSong(currentSong);
	
}


int main()
{

	std::list<Song> playlist
	{
		{"Let It Go", "Demi Lovato",5},
		{"Paris", "Sabrina Carpenter",4},
		{"Murder", "AURORA",3},
		{"I need a hero", "Bonnie Tyler",4}
		
	};

	std::list<Song>::iterator currentSong = playlist.begin();
	displayPlaylist(playlist, *currentSong);
	
	char selection{};
	do {
		displayMenu();
		std::cin >> selection;
		selection = std::toupper(selection);
		switch (selection)
		{
		case 'F':
			std::cout << "Playing first song" << std::endl;
			currentSong = playlist.begin();
			playCurrentSong(*currentSong);
			break;

		case 'N':
			std::cout << "Playing next song" << std::endl;
			currentSong++;
			if (currentSong == playlist.end())
			{
				std::cout << "Wrapping to start of playlist" << std::endl;
				currentSong = playlist.begin();
			}
			playCurrentSong(*currentSong);
			break;

		case 'P':
			std::cout << "Playing previous song" << std::endl;
			if (currentSong == playlist.begin())
			{
				std::cout << "Wrapping to start of playlist" << std::endl;
				currentSong = playlist.end();
			}
			currentSong--;
			playCurrentSong(*currentSong);
			break;
		case 'A':
		{
			std::string name, artist;

			int rating;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Adding and playing new song" << std::endl;
			std::cout << "Enter song name ";
			getline(std::cin, name);
			std::cout << "Enter song artist ";
			getline(std::cin, artist);
			std::cout << "Enter song rating(1-5) ";
			std::cin >> rating;
			playlist.insert(currentSong, Song(name, artist, rating));
			currentSong--;
			playCurrentSong(*currentSong);
			break;
		}
		case 'L':
			std::cout << std::endl;
			displayPlaylist(playlist, *currentSong);
			break;

		case 'Q':
			std::cout <<"Quitting" <<std::endl;
			break;

		default:
			std::cout << "Not a Valid Choice!!" << std::endl;
			break;
		}
	
	
	} while (selection != 'Q');

	

	system("pause");
	return 0;
}