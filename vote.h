//
// Created by Azhar Gaffar on 19/11/2019.
//

#ifndef ALTERNATIVEVOTINGSYSTEM_VOTE_H
#define ALTERNATIVEVOTINGSYSTEM_VOTE_H

#include <vector>

typedef unsigned int candidate;

class vote {

private:
    std::vector<candidate> prefs;

public:
    vote(const std::vector<candidate> &prefs);

    bool spent() const;

    candidate first_preference() const;

    void discard(candidate c);
};


#endif //ALTERNATIVEVOTINGSYSTEM_VOTE_H
