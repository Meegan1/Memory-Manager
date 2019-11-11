//
// Created by Jake Meegan on 11/11/2019.
//

#ifndef ASSIGNMENT_1_REFERENCECOUNT_H
#define ASSIGNMENT_1_REFERENCECOUNT_H


class ReferenceCount {
private:
    int count;

public:
    void add() {
        count++;
    }

    int release() {
        return --count;
    }
};


#endif //ASSIGNMENT_1_REFERENCECOUNT_H
