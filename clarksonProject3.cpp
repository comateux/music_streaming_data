#include <iostream>
#include <iomanip>
#include <ctime>		// time functions
#include <cstdlib>	    // include the random number generator
using namespace std;

// function prototypes
void mainMenu();
void streamingServiceMenu();
void distributionLabelMenu();
double generateStreams(int);
double calculateEarnings(int, long);
double calculateLabelEarnings(int, double);

// global constants
const double TIDAL = 0.01250;
const double AMAZON = 0.00402;
const double APPLEMUSIC = 0.00735;
const double SPOTIFY = 0.00437;
const double YOUTUBE = 0.00069;
const double MAJOR_LABEL = 0.60;
const double INDIE_LABEL = 0.30;

// main function
int main()
{
    // seed random time at 0
	srand(time(0));

    // variables
    int uploadChoice, streamingService, distributionLabel;
    int numSongs;
    double earnings = 0.0, totalEarnings = 0.0, songEarnings = 0.0, distributionCharges, artistEarnings;
    long numStreams, totalStreams;
    string artistName, serviceName, songName;

    do
    {


        // display main menu
        while(uploadChoice < 1 or uploadChoice > 3)
        {
            // call function to get the main upload menu
            mainMenu();
            cin >> uploadChoice;

            if(uploadChoice == 3)
            {
                cout << "\nThank you for using the program. \n";
                cout << "The program will now close. \n";
                return 0;
            }

            if(uploadChoice < 1 or uploadChoice > 2)
            {
                cout << "\nERROR - NOT A VALID MENU CHOICE. PLEASE TRY AGAIN.\n";
            }
        }

        // display streaming service menu
        while(streamingService < 1 or streamingService > 5)
        {
            // call function to get the streaming service menu
            streamingServiceMenu();
            cin >> streamingService;

            if(streamingService < 1 or streamingService > 5)
            {
                cout << "\nERROR - NOT A VALID STREAMING SERVICE. Please choose from the services listed.\n";
            }
        }

        // set the value of the streaming service
        switch(streamingService)
        {
            case 1:
                serviceName = "TIDAL";
                    break;
            case 2:
                serviceName = "Amazon";
                break;
            case 3:
                serviceName = "Apple Music";
                break;
            case 4:
                serviceName = "Spotify";
                break;
            case 5:
                serviceName = "YouTube";
                break;
        }

        if (uploadChoice == 1)
        {
            // clear the buffer between integer and string inputs
            cin.ignore();

            // get the input of the name of the artist
            cout << "\nWhat is the artist's name? ";
            getline(cin, artistName);

            // get the input of the name of the song
            cout << "\nWhat is the name of the song? ";
            getline(cin, songName);

            // get the input of the number of streams
            cout << "\nHow many streams does " << songName << " have on " << serviceName << "? ";
            cin >> numStreams;

            // validate the number of streams
            while(numStreams < 0)
            {
                cout << endl;
                cout << "ERROR - NUMBER OF STREAMS CANNOT BE NEGATIVE.";
                cout << "\n\nHow many streams does " << songName << " have on " << serviceName << "? ";
                cin >> numStreams;
            }

            // calculate the earnings
            switch(streamingService)
            {
                case 1:
                    earnings = numStreams * TIDAL;
                    break;
                case 2:
                    earnings = numStreams * AMAZON;
                    break;
                case 3:
                    earnings = numStreams * APPLEMUSIC;
                    break;
                case 4:
                    earnings = numStreams * SPOTIFY;
                    break;
                case 5:
                    earnings = numStreams * YOUTUBE;
                    break;
            }

            // output
            cout << setprecision(2) << showpoint << fixed;
            cout << endl << endl;
            cout << "Song Name: \t\t" << songName;
            cout << "\nArtist Name: \t\t" << artistName;
            cout << "\nStreaming Service: \t" << serviceName;
            cout << "\nStreams: \t\t" << numStreams;
            cout << "\nEarnings: \t\t$" << earnings << endl<< endl;


        }
        else if (uploadChoice == 2)
        {
            // clear the buffer between integer and string inputs
            cin.ignore();

            // get the input of the number of songs to be distributed
            cout << "\nHow many songs will be uploaded on " << serviceName << "? ";
            cin >> numSongs;

            while(numSongs < 0)
            {
                cout << endl;
                cout << "ERROR - NUMBER OF SONGS CANNOT BE NEGATIVE." << endl;
                cout << "\nHow many songs will be uploaded on " << serviceName << "? ";
                cin >> numSongs;
                cout << "\n\n";
            }

            // display distribution label types
            while(distributionLabel < 1 or distributionLabel > 2)
            {
                distributionLabelMenu();
                cin >> distributionLabel;

                if(distributionLabel < 1 or distributionLabel > 2)
                {
                    cout << "\nERROR -  INVALID DISTRIBUTION CHOSEN. Please choose from one of the options listed.\n";
                }
            }

            // loop that will process information for each song uploaded
            for(int song = 1; song <= numSongs; song++)
            {
                // for each song, get the following:

                // the number of streams generated
                numStreams = generateStreams(song);

                // add to the total streams
                totalStreams += numStreams;

                // output the song number and the streams
                cout << "\t Song #" << song << ": \t" << numStreams << " streams" << endl;


                // the amount of money earned from the song
                songEarnings = calculateEarnings(streamingService, numStreams);

                // add the total earnings
                totalEarnings += songEarnings;

                // the amount of money earned by the distribution label
                distributionCharges = calculateLabelEarnings(distributionLabel, totalEarnings);

            }

            // calculate the artist earnings
            artistEarnings = totalEarnings - distributionCharges;

            cout << endl << endl;
            cout << "\nStreaming Service: \t" << serviceName;
            cout << "\nStreams: \t\t" << totalStreams;
            cout << "\nEarnings: \t\t$" << totalEarnings;
            cout << "\nArtist Earnings: \t$" << artistEarnings;
            cout << "\nLabel Earnings: \t$" << distributionCharges << endl << endl;

        }
        else
            cout << "\nERROR - NOT A VALID MENU CHOICE. PLEASE TRY AGAIN.\n";
    }while(uploadChoice != 3);
}


/*
    mainMenu() function
    Use a menu to prompt the user for uploading a single or
    multiple songs.
*/

void mainMenu()
{
    // display the first menu (upload menu)
    cout << "\nChoose from the following menu options: \n";
    cout << "\n\t 1: Upload a single song to a single song to a streaming service";
    cout << "\n\t 2: Upload multiple songs to a streaming service";
    cout << "\n\t 3: Exit the program";
    cout << "\n\n";

    // get the input for main menu choice
    cout << "Enter your choice (1, 2, or 3): ";
}

/*
    streamingService() function
    Prompt the user for the streaming service using a menu.
*/

void streamingServiceMenu()
{
    cout << "\nWhich Streaming Service will you use to upload your song(s)?\n";
    cout << "\n\t 1: TIDAL";
    cout << "\n\t 2: Amazon";
    cout << "\n\t 3: Apple Music";
    cout << "\n\t 4: Spotify";
    cout << "\n\t 5: YouTube";
    cout << "\n\n";

    // prompt user to choose a streaming service
    cout << "Enter your choice (1-5): ";
}

/*
    distributionLabelMenu() function
    A void function that displays a menu for the distribution label types
    when called.
*/

void distributionLabelMenu()
{
    // song distribution label menu
    cout << "\nWhich type of distribution will you use to distribute your song(s)?";
    cout << "\n\t 1: Major Label";
    cout << "\n\t 2: Independent Label";
    cout << "\n\nEnter your choice (1 or 2): ";
}

/*
    generateStreams() funtion
    A function that accepts the distribution label type and
    returns the number of streams generated.
*/

double generateStreams(int distributionLabel)
{
    long genStreams;

    if(distributionLabel == 1)
    {
        // major labels generate between 100,000 and 50,000,000 streams per song
		genStreams = 100000 + rand() % 49900000;
    }
    else
    {
        // indie label generate between 10,000 and 1,000,000 streams
		genStreams = 10000 + rand() % 990000;
    }

    return genStreams;
}

/*
    calcualteEarnings() function
    A function that accepts streaming service type and the number of streams
    generated and returns the amount of money earned from the song(s).
    Use global constants for service reates.
*/

double calculateEarnings(int streamingService, long numStreams)
{
    double earnings;

    // calculate the earnings
    if (streamingService == 1)
        earnings = numStreams * TIDAL;
    else if (streamingService == 2)
        earnings = numStreams * AMAZON;
    else if (streamingService == 3)
        earnings = numStreams * APPLEMUSIC;
    else if (streamingService == 4)
        earnings = numStreams * SPOTIFY;
    else earnings = numStreams * YOUTUBE;

    return earnings;


}

/*
    calculateLabelEarnings() function
    A fucntion that accepts the distribution lavel type and the amount earned from
    the total songs streamed
    and then returns the amount the distribution label earned.

*/

double calculateLabelEarnings(int distributionLabel, double totalEarnings)
{
    double labelEarnings;

    if (distributionLabel == 1)
        labelEarnings = totalEarnings * MAJOR_LABEL;
    else
        labelEarnings = totalEarnings * INDIE_LABEL;

    return labelEarnings;


}
