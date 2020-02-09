#ifndef ACADEMICRECORD_H
#define ACADEMICRECORD_H

#include <string>



//const AcademicRecord &s1, 

class AcademicRecord {

public:
// default constructor
AcademicRecord();
AcademicRecord(int maths, int computers, int physics);
AcademicRecord(const AcademicRecord &s2);
AcademicRecord operator++(); //prefix increment
AcademicRecord operator++(int); //postfix increment
AcademicRecord operator--(); //prefix decrement
AcademicRecord operator--(int); //postfix decrement

int GetMaths() const { return maths_; };
int GetComputers() const { return computers_; };
int GetPhysics() const { return physics_; };
void SetMaths(int maths) { maths_ = maths; };
void SetComputers(int computers) { computers_ = computers; };
void SetPhysics(int physics) { physics_ = physics; };

bool operator==(const AcademicRecord& s2);
AcademicRecord operator+=(int rhs);
AcademicRecord operator-=(int rhs);

std::string Print();

~AcademicRecord() { } // destructor, cleans up


private:
int maths_;
int computers_;
int physics_;
};


#endif