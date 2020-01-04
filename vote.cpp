//
// Created by Azhar Gaffar on 19/11/2019.
//

#include "vote.h"
#include <algorithm>

vote::vote(const std::vector<candidate> &prefs) : prefs(prefs) {
}

bool vote::spent() const {
    if (prefs.empty()) {
        return true;
    } else {
        return false;
    }
}

candidate vote::first_preference() const {
    return prefs[0];
}

void vote::discard(candidate c) {
    prefs.erase(remove(prefs.begin(), prefs.end(), c), prefs.end());
}

