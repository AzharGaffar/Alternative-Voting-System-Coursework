//
// Created by Azhar Gaffar on 19/11/2019.
//

#ifndef ALTERNATIVEVOTINGSYSTEM_ELECTION_H
#define ALTERNATIVEVOTINGSYSTEM_ELECTION_H


#include "vote.h"
#include <istream>

class election {

private:
    std::vector<vote> votes;

public:
    void add_vote(const vote &v);

    int vote_count() const;

    void eliminate(candidate c);

    std::vector<std::pair<candidate, int>> ranked_candidates() const;

};

election read_votes(std::istream &in);

#endif //ALTERNATIVEVOTINGSYSTEM_ELECTION_H

