#include <iostream>
#include <vector>
#include <fstream> // read txt files
#include <algorithm> // sort
#include <tuple> // tuples

using namespace std;

/* define variables for all set sizes and parameter values */
// Input
unsigned int B;
unsigned int L;
unsigned int D;
vector<unsigned int> scores;
struct lib {
    unsigned int book_number;
    unsigned int signup_time;
    unsigned int scans;
};
vector<lib> libraries;
vector<vector<unsigned int>> book_ids;

// Output
vector<pair<unsigned int, unsigned int>> library_signup_order;
vector<vector<unsigned int>> scanned_book_ids;

void loadData(string filename)
{
    /* Loads data from txt file */

    ifstream File; // read from file
    File.open(filename);

    // string for the lines in the txt file
    string text;

    // Line 1: 
    // Number of books B
    // Nomber of libs L
    // Number of days D
    File >> B >> L >> D;
    
    // Line 2:
    // array of scores
    unsigned int score;
    for (int i=0; i<B; i++)
    {
        File >> score;
        scores.push_back(score);
    }

    // Library specific lines
    lib current_lib;
    for (int i=0; i<L; i++)
    {
        // Line 1:
        // Number of books in lib l
        // Signup time in lib l
        // Scans per day in lib l
        File 
            >> current_lib.book_number
            >> current_lib.signup_time
            >> current_lib.scans;
        libraries.push_back(current_lib);
 
        // Line 2:
        // array of book_ids
        unsigned int id;
        unsigned int b = current_lib.book_number;
        vector<unsigned int> current_book_ids;
        for (int i=0; i<b; i++)
        {
            File >> id;
            current_book_ids.push_back(id);
        }
        book_ids.push_back(current_book_ids);
    }
  
    File.close();
}

void optimize(void)
{
    /* 
    Determine the library order by taking the library with the highest score sum first.
    Calculate score sum for respective order. 
    */

    // Optimization criterium: Maximum score sum per library
    vector<pair<unsigned long int, int>> score_sum; // vector of the score sum with the index of the respective library, pair(score, library index)
    unsigned int current_book_number; // number of books in the current library
    for (int l=0; l<L; l++)
    {
        current_book_number = libraries[l].book_number;
        unsigned long int temp_score = 0;
        for (int i=0; i<current_book_number; i++)
        {
            temp_score += scores[book_ids[l][i]]; // Get book id of respective library and book and look up the score for scanning
        }
        score_sum.push_back(make_pair(temp_score, l));
    }
    // Sort in descending order to scan from librarier with the highest books scores first
    sort(score_sum.rbegin(), score_sum.rend()); // Sort score sums in descending order while keeping original indices 

    // Signup queue
    int signup_time = 1;
    bool signup_free = true; // If true, then the signup pipeline is free for a new library
    int signup_lib_counter = 0; // increments when a library finished the signup
    
    // Scanning queue
    vector<tuple<int, int, bool>> scan_lib_id; // libraries that passed the signup process and are ready to be scanned, tuple(library id, book start index for scanning in library, scanning still active)
    vector<unsigned int> current_book_ids; // all ids of books in current library
    unsigned int book_id; // single id of the respective book in a library
    vector<vector<pair<unsigned int, unsigned int>>> lib_scores_sorted; // scores of books sorted in descending order for all libraries that have been added to the scanning queue
    vector<pair<unsigned int, unsigned int>> current_book_scores; // all scores together with their book id in current library
    unsigned int scan_number; // number of scans per day of a library
    unsigned int scan_start_index; // index of book vector where the scan should start from
    vector<bool> scanned(B, false); // false if book with respective id has been scanned else true

    // Score calculation
    unsigned int total_score;

    // Iterate over number of available days for scanning process
    int day = 0; 
    while (day < D)
    {
        // Check signup status
        if (signup_time == 0) // if signup process is finished, unblock signup and enable library for scanning
        {
            cout << "signup finished lib" << signup_lib_counter << " day" << day-1 << endl;
            signup_free = true; // unblock signup
            scan_lib_id.push_back(make_tuple(score_sum[signup_lib_counter].second, 0, true)); // add library id to scanning queue and set the index to start scanning from to 0
            current_book_ids = book_ids[score_sum[signup_lib_counter].second];
            for (int i=0; i<current_book_ids.size(); i++) // get scored of books in curren library
            {
                book_id = current_book_ids[i];
                current_book_scores.push_back(make_pair(scores[book_id], book_id));
            }
            sort(current_book_scores.rbegin(), current_book_scores.rend()); // sort the scores in descending order
            lib_scores_sorted.push_back(current_book_scores);
            signup_lib_counter++; // increment for next library
            scanned_book_ids.push_back(vector<unsigned int>()); // add new vector which will collect the ids of the scanned books of the respective library
        }

        // If signup of library is finished update the signup time for the next library
        if (signup_free == true)
        {
            if (signup_lib_counter < L) // If there are libraries left for signup
            {
                cout << "signup start lib" << signup_lib_counter << " day" << day << endl;
                signup_time = libraries[score_sum[signup_lib_counter].second].signup_time; // Gets the signup time from the struct of the respective library
                signup_free = false; // block signup
            }
        }
        
        // Iterate over libraries that are signed up
        for (int i=0; i<scan_lib_id.size(); i++)
        {
            cout << "scan lib" << i << " day" << day << endl;
            if (get<2>(scan_lib_id[i]) == true) // if library still has books that are unscanned
            {
                scan_number = libraries[get<0>(scan_lib_id[i])].scans; // get number of possible scans per day
                scan_start_index = get<1>(scan_lib_id[i]); // get index to start scanning from
                
                // Iterate over number of scans that are allowed per day
                int c = 0;
                while (c < scan_number)
                {
                    if (scan_start_index == libraries[get<0>(scan_lib_id[i])].book_number) // if current index exceeds the list size break
                    {
                        get<2>(scan_lib_id[i]) = false; // block library for scanning
                        break;
                    }
                    if (scanned[lib_scores_sorted[i][scan_start_index].second] == false)
                    {
                        total_score += lib_scores_sorted[i][scan_start_index].first; // add score of current scanned book to total score
                        scanned_book_ids[i].push_back(lib_scores_sorted[i][scan_start_index].second); // add book id
                    }
                    scan_start_index++; // increment for next iteration
                }
                get<1>(scan_lib_id[i]) = scan_start_index; // update start index for next day
            }
        }
    signup_time--;
    day++;
    }
    // Gather necessary values for submission
    for (int i=0; i<scan_lib_id.size(); i++) 
    {
        library_signup_order.push_back(make_pair(get<0>(scan_lib_id[i]), scanned_book_ids[i].size())); // add library id and number of scanned books
        cout << get<0>(scan_lib_id[i]) << " " << scanned_book_ids[i].size() << endl;
    }

}

int main(void)
{
    loadData("a_example.txt");
    optimize();
    return 0;
}