#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
#include "Utility.h"
#include "ClsDate.h"
#include "ClsInputValidate.h"
using namespace std;
int main() {
if (clsInputValidate::IsNumberBetween("58","52","62")){
    cout<<"true";
}
else{
    cout<<"false";
}
    return 0;
    
}