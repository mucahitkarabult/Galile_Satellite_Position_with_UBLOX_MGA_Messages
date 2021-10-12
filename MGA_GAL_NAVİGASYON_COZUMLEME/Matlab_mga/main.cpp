#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <math.h>
#include <unordered_map>
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <ctime>
using namespace std;
string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}
void Local_CreateFile(std::string filename) {
    if (!std::filesystem::is_directory(filename) || !std::filesystem::exists(filename)) { // Check if src folder exists
        std::filesystem::create_directory(filename); // create src folder
    }
}

struct ephemeris {   // Declare PERSON struct type
    uint8_t type;
    uint8_t version;
    uint8_t svId;             // printf("%u %d %d %u %u %d %d %d %d %d %d %d %d %d  %d %d %u %d %d %d")
    uint8_t reserved0;
    uint16_t iodNav;
    int16_t deltaN;
    int32_t m0;
    uint32_t e;
    uint32_t sqrtA;
    int32_t omega0;
    int32_t i0;
    int32_t omega;
    int32_t omegaDot;
    int16_t iDot;
    int16_t cuc;
    int16_t cus;
    int16_t crc;
    int16_t crs;
    int16_t cic;
    int16_t cis;
    uint16_t toe;
    int32_t af0;
    int32_t af1;
    int8_t af2;
};
int main(){
stringstream ss;
int flag=0;

uint8_t head1;
uint8_t head2;
uint8_t class_id;
uint8_t class_id2;
int16_t numberofword;
uint8_t tmp;

int8_t i1;
int16_t i2;
int32_t i4;

uint8_t u1;
uint16_t u2;
uint32_t u4;

time_t tt;
time(&tt);
tm TM = *localtime( &tt );

//Must add 1 to month and 1900 to the year
int month=TM.tm_mon+1;
int day=TM.tm_mday;
int year=TM.tm_year+1900;

int hour=TM.tm_hour;

string filename="gal_"+to_string(year%2000)+"_"+to_string(month)+"_"+to_string(day)+"."+to_string(hour)+".ubx";


struct ephemeris gal_ep[50];
ifstream file (filename, ios::in | ios::binary);
if (file.is_open())
{


    while(!file.eof()){
        file.read(reinterpret_cast<char *>(&head1),sizeof(head1));
        if(head1==0xb5){

            file.read(reinterpret_cast<char *>(&head2),sizeof(head1));

            if(head2==0x62){

                file.read(reinterpret_cast<char *>(&class_id),sizeof(head1));
                if(class_id==0x13){
                    file.read(reinterpret_cast<char *>(&class_id2),sizeof(head1));

                    if(class_id2==0x02){

                        file.read(reinterpret_cast<char *>(&numberofword), sizeof(numberofword));

                        file.read(reinterpret_cast<char *>(&u1), sizeof(u1));
                        gal_ep[flag].type=u1;

                        file.read(reinterpret_cast<char *>(&u1), sizeof(u1));
                        gal_ep[flag].version=u1;

                        file.read(reinterpret_cast<char *>(&u1), sizeof(u1));
                        gal_ep[flag].svId=u1;
                        file.read(reinterpret_cast<char *>(&u1), sizeof(u1));
                        gal_ep[flag].reserved0=u1;
                        file.read(reinterpret_cast<char *>(&u2), sizeof(u2));
                        gal_ep[flag].iodNav=u2;

                        file.read(reinterpret_cast<char *>(&i2), sizeof(i2));
                        gal_ep[flag].deltaN=i2;

                        file.read(reinterpret_cast<char *>(&i4), sizeof(i4));
                        gal_ep[flag].m0=i4;

                        file.read(reinterpret_cast<char *>(&u4), sizeof(u4));
                        gal_ep[flag].e=u4;

                        file.read(reinterpret_cast<char *>(&u4), sizeof(u4));
                        gal_ep[flag].sqrtA=u4;

                        file.read(reinterpret_cast<char *>(&i4), sizeof(i4));
                        gal_ep[flag].omega0=i4;

                        file.read(reinterpret_cast<char *>(&i4), sizeof(i4));
                        gal_ep[flag].i0=i4;

                        file.read(reinterpret_cast<char *>(&i4), sizeof(i4));
                        gal_ep[flag].omega=i4;

                        file.read(reinterpret_cast<char *>(&i4), sizeof(i4));
                        gal_ep[flag].omegaDot=i4;

                        file.read(reinterpret_cast<char *>(&i2), sizeof(i2));
                        gal_ep[flag].iDot=i2;

                        file.read(reinterpret_cast<char *>(&i2), sizeof(i2));
                        gal_ep[flag].cuc=i2;

                        file.read(reinterpret_cast<char *>(&i2), sizeof(i2));
                        gal_ep[flag].cus=i2;

                        file.read(reinterpret_cast<char *>(&i2), sizeof(i2));
                        gal_ep[flag].crc=i2;

                        file.read(reinterpret_cast<char *>(&i2), sizeof(i2));
                        gal_ep[flag].crs=i2;

                        file.read(reinterpret_cast<char *>(&i2), sizeof(i2));
                        gal_ep[flag].cic=i2;

                        file.read(reinterpret_cast<char *>(&i2), sizeof(i2));
                        gal_ep[flag].cis=i2;

                        file.read(reinterpret_cast<char *>(&u2), sizeof(u2));
                        gal_ep[flag].toe=u2;

                        file.read(reinterpret_cast<char *>(&i4), sizeof(i4));
                        gal_ep[flag].af0=i4;

                        file.read(reinterpret_cast<char *>(&i4), sizeof(i4));
                        gal_ep[flag].af1=i4;

                        file.read(reinterpret_cast<char *>(&i1), sizeof(i1));
                        gal_ep[flag].af2=i1;

                        flag++;
                    }
                }
            }
        }

    }

}	file.close();

Local_CreateFile("Data_gal");
filename="Data_gal\\result_"+filename;

struct {
    int width;
    std::string header;
} columns[] = { { 10, "svId" },{ 10, "year" },{ 10, "month" },{ 10, "day" },{ 10, "hour" },
                { 15, "min" }, { 15, "sec" },{ 15, "af0" } , { 15, "af1" },
                { 15, "af2" },{ 15, "iodNav" }   ,{ 15, "crs" }, { 15, "delta_n" } ,
                { 15, "m0" } ,{ 15, "cuc" } , { 15, "e" } , { 20, "cus" } ,
                { 20, "sqrt_a" } , { 20, "toe" },{ 20, "cic" } ,{ 15, "omega0" } ,
                { 15, "cis" } ,{ 15, "i0" } , { 15, "crc" } , { 15, "omega" } , { 15, "omega_dot" } ,
                { 15, "idot" }};
ofstream out1(filename);

for (auto& col : columns) out1 << std::setw(col.width) << col.header << " | ";
out1 << "\n" << std::setfill('-');
for (auto& col : columns) out1 << std::setw(col.width) << "" << "-+-";
out1 << "\n" << std::setfill(' ');
out1 << "BEGINNING OF DATA\n" << std::setfill(' ');
for(int i=0;i<flag;i++){


    int gal_i_toe_hour,gal_i_toe_min,gal_i_toe;
    gal_i_toe=gal_ep[i].toe *60;
    while(gal_i_toe>86400){
        gal_i_toe-=86400;
    }
    gal_i_toe_hour=gal_i_toe/3600;
    gal_i_toe_min=(gal_i_toe%3600)/60;

    out1 <<(int)gal_ep[i].svId
    << "\t"<<(float)year
    <<"\t"<<(float)month
    <<"\t"<<(float)day
    <<"\t"<<gal_i_toe_hour
    <<"\t"<<gal_i_toe_min
    <<"\t"<<00
    <<"\t"<<(float)gal_ep[i].af0 *pow(2,-34)
    <<"\t"<<(float)gal_ep[i].af1 *pow(2,-46)
    <<"\t"<<(float)gal_ep[i].af2*pow(2,-59)
    <<"\t"<<(float)gal_ep[i].iodNav
    << "\t"<<(float)gal_ep[i].crs *pow(2,-5)
    << "\t"<<(float)gal_ep[i].deltaN*pow(2,-43)*M_PI
    << "\t"<<(float)gal_ep[i].m0*pow(2,-31)*M_PI
    <<"\t"<<(float)gal_ep[i].cuc*pow(2,-29)
    <<"\t"<<(float)gal_ep[i].e *pow(2,-33)
    <<"\t"<<(float)gal_ep[i].cus *pow(2,-29)
    <<"\t"<<(float)gal_ep[i].sqrtA *pow(2,-19)
    <<"\t"<<(float)gal_ep[i].toe *60
    <<"\t"<<(float)gal_ep[i].cic *pow(2,-29)
    <<"\t"<<(float)gal_ep[i].omega0 *pow(2,-31)*M_PI
    << "\t"<<(float)gal_ep[i].cis *pow(2,-29)
    << "\t"<<(float)gal_ep[i].i0 *pow(2,-31)*M_PI
    <<"\t"<<(float)gal_ep[i].crc *pow(2,-5)
    << "\t"<<(float)gal_ep[i].omega*pow(2,-31)*M_PI
    << "\t"<<(float)gal_ep[i].omegaDot *pow(2,-43)*M_PI
    <<"\t"<<(float)gal_ep[i].iDot*pow(2,-43)*M_PI << "\n";

}




return 0;
}

