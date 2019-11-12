//
// Created by Jake Meegan on 11/11/2019.
//

#ifndef ASSIGNMENT_1_REFERENCECOUNT_H
#define ASSIGNMENT_1_REFERENCECOUNT_H


class ReferenceCount {
public:
    void add() {
        count++;
    }

    int release() {
        return --count;
    }

private:
    int count;
};


#endif //ASSIGNMENT_1_REFERENCECOUNT_H
