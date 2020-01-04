#include <iostream>
#include <fstream>
#include "election.h"
#include "vote.h"
#include <algorithm>

int main() {
    bool start = true;
    std::fstream in("votes.txt");
    election election;
    int round_number = 1;
    if (in.is_open()) {
        election = read_votes(in);
        while (start == true) {
            std::vector<std::pair<candidate, int>> candidates_list = election.ranked_candidates();
            int selected;
            bool selection = false;
            std::cout << "Round " << round_number << ": " << election.vote_count() << " votes\n";
            std::cout << "First preferences:\n";
            for (int i = 0; i < candidates_list.size(); i++) {
                std::cout << "  Candidate " << candidates_list[i].first << ": " << candidates_list[i].second << "\n";
            }
            int half_of_vote = (election.vote_count()) / 2;
            for (int z = 0; z < candidates_list.size(); z++) {
                if (candidates_list[z].second > half_of_vote) {
                    selected = z;
                    selection = true;
                }
            }
            if (selection == true) {
                std::cout << "Candidate " << candidates_list[selected].first << " is selected.\n";
                start = false;
            } else {
                std::cout << "Candidate " << candidates_list.back().first << " is eliminated.\n\n";
                election.eliminate(candidates_list.back().first);
                round_number++;
            }
        }
    } else {
        std::cout << "File couldn't be opened.\n";
    }
}