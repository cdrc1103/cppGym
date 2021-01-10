#include <iostream>
#include <vector>
#include <fstream> // read txt files
#include <algorithm> // sort
#include <numeric> // iota

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
vector<unsigned int> library_signup_order;
vector<unsigned int> scanned_book_number;
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

int optimize(void)
{
    /* 
    Determine the library order by taking the library with the highest score sum first.
    Calculate score sum for respective order. 
    */

    // Calculate score sum per library
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

    // Scan books
    int signup_time;
    bool signup_free = true; // If true, then the signup pipeline is free for a new library
    int signup_lib_counter = 0;
    vector<pair<int, int>> scan_lib_id; // libraries that passed the signup process and are ready to be scanned, pair(library id, book start index for scanning in library)
    vector<vector<unsigned int>> lib_scores_sorted;
    int scan_lib_counter = 0;
    unsigned int score;
    unsigned int max_score_index;
    int day = 0; 
    sort(score_sum.begin(), score_sum.end(), greater<int>()); // Sort in descending order while keeping original indices because of pairs
    while (day <= D)
    {
        if (signup_free == true)
        {
            signup_time = libraries[score_sum[signup_lib_counter].second].signup_time; // Gets the signup time from the struct of the respective library
            signup_free = false; // block signup
            signup_lib_counter++; // increment for next 
        }
       
        if (signup_time == 0) // if signup process is finished, unblock signup and enable library for scanning
        {
            signup_free = true;
            scores[book_ids[l][i]]
        }



        signup_time--;
        day++;
    }

    return 0;
}

int main(void)
{
    loadData("a_example.txt");
    optimize();
    return 0;
}