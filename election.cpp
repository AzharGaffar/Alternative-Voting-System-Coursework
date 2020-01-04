//
// Created by Azhar Gaffar on 19/11/2019.
//

#include "election.h"
#include <algorithm>
#include <sstream>
#include <istream>


void election::add_vote(const vote &v) {
    votes.push_back(v);
}

int election::vote_count() const {
    return votes.size();
}

void election::eliminate(candidate c) {
    typedef std::vector<vote>::size_type vec_size;
    for (vec_size i = 0; i < votes.size(); i++) {
        votes[i].discard(c);
    }
    votes.erase(remove_if(votes.begin(), votes.end(), [](vote &v) { return v.spent(); }), votes.end());
}

std::vector<std::pair<candidate, int>> election::ranked_candidates() const {
    std::vector<std::pair<candidate, int>> candidates_list;
    std::vector<candidate> candidates;
    for (int i = 0; i < votes.size(); i++) {
        if (!votes[i].spent())candidates.push_back(votes[i].first_preference());
    }
    sort(candidates.begin(), candidates.end(), [](int a, int b) { return b < a; });
    int highest_loop = (candidates[0]) + 1;
    for (int z = 0; z < highest_loop; z++) {
        int candidate_votes = count(candidates.begin(), candidates.end(), z);
        if (candidate_votes > 0) {
            candidates_list.push_back(std::make_pair(z, candidate_votes));
        }
    }
    sort(candidates_list.begin(), candidates_list.end(),
         [](std::pair<candidate, int> first_pair, std::pair<candidate, int> second_pair) {
             return second_pair.second < first_pair.second;
         });
    return candidates_list;
}


election read_votes(std::istream &in) {
    election election_list;
    std::string line;
    int x = 0;
    while (getline(in, line)) {
        std::stringstream s(line);
        std::vector<candidate> candidate_vector;
        while (s >> x) {
            candidate_vector.push_back(x);
        }
        election_list.add_vote(candidate_vector);
    }
    return election_list;
}

