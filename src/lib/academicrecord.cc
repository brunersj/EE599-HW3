#include "academicrecord.h"
#include <iostream>

using std::cout;
using std::endl;

//default constructor
AcademicRecord::AcademicRecord(){
    maths_ = 0;
    computers_ = 0;
    physics_ = 0;
}

//parameterized constructor

AcademicRecord::AcademicRecord(int maths, int computers, int physics) : maths_(maths), computers_(computers), physics_(physics){}

// Copy constructor
AcademicRecord::AcademicRecord(const AcademicRecord &s2) {
    maths_ = s2.GetMaths();
    computers_ = s2.GetComputers();
    physics_ = s2.GetPhysics();
}

 // Prefix overload increment
  // ++p;
AcademicRecord AcademicRecord::operator++() {
    if(maths_ <= 90){
        maths_ = maths_ + 10;
    }
    else{
        maths_ = 100;
    }
    if (computers_ <= 90){
        computers_ = computers_ + 10;
    }
    else{
        computers_ = 100;
    }
    if (physics_ <= 90){
        physics_ = physics_ + 10;
    }
    else{
        physics_ = 100;
    }
    return *this;
}

  // Postfix overload increment
  // p++;
AcademicRecord AcademicRecord::operator++(int) {
    AcademicRecord temp = *this;
    if(maths_ <= 90){
        maths_ = maths_ + 10;
    }
    else{
        maths_ = 100;
    }
    if (computers_ <= 90){
        computers_ = computers_ + 10;
    }
    else{
        computers_ = 100;
    }
    if (physics_ <= 90){
        physics_ = physics_ + 10;
    }
    else{
        physics_ = 100;
    }

    return temp;
}

  // Prefix overload decrement 
  // ++p;
AcademicRecord AcademicRecord::operator--() {
    if(maths_ >= 20){
        maths_ = maths_ - 20;
    }
    else{
        maths_ = 0;
    }
    if (computers_ >= 20){
        computers_ = computers_ - 20;
    }
    else{
        computers_ = 0;
    }
    if (physics_ >= 20){
        physics_ = physics_ - 20;
    }
    else{
        physics_ = 0;
    }
    return *this;
}

  // Postfix overload decrement
  // p++;
AcademicRecord AcademicRecord::operator--(int) {
    AcademicRecord temp = *this;
    if(maths_ >= 20){
        maths_ = maths_ - 20;
    }
    else{
        maths_ = 0;
    }
    if (computers_ >= 20){
        computers_ = computers_ - 20;
    }
    else{
        computers_ = 0;
    }
    if (physics_ >= 20){
        physics_ = physics_ - 20;
    }
    else{
        physics_ = 0;
    }

    return temp;
}

bool AcademicRecord::operator==(const AcademicRecord &s2){
    return(maths_ == s2.maths_ && computers_ == s2.computers_ && physics_ == s2.physics_);
}

//AcademicRecord AcademicRecord::operator+=(const AcademicRecord& rhs){
AcademicRecord AcademicRecord::operator+=(int rhs){
    // maths_ += rhs.maths_;
    // computers_ += rhs.computers_;
    // physics_ += rhs.physics_;
    maths_ += rhs;
    computers_ += rhs;
    physics_ += rhs;
    
    // check if grades are in valid range
    if(maths_ > 100){
        maths_ = 100;
    }
    if (computers_ > 100){
        computers_ = 100;
    }
    if (physics_ > 100){
        physics_ = 100;
    }

    return *this;
}

AcademicRecord AcademicRecord::operator-=(int rhs){
    maths_ -= rhs;
    computers_ -= rhs;
    physics_ -= rhs;
    
    // check if grades are in valid range
    if(maths_ < 0){
        maths_ = 0;
    }
    if (computers_ < 0){
        computers_ = 0;
    }
    if (physics_ < 0){
        physics_ = 0;
    }
    
    return *this;
}

std::string AcademicRecord::Print(){
        std::string output;
        output = "Maths: " + std::to_string(maths_) + '\n';
        output += "Computers: " + std::to_string(computers_) + '\n';
        output += "Physics: " + std::to_string(physics_) + '\n';
        return output;
    }