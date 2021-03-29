//
//  Htrip.h
//  ob
//
//  Created by Даниил on 08.11.2020.
//
#pragma once
#include <iostream>
#include <string>

using namespace std;
class trip{
private:
    int id;
    string name_of_trip;
    double distanse;
    double duration;
    double paiment;

public:
    //  конcтруктор trip  //
    trip(int id = 0, string name_of_trip = "pusto", double distanse = 0, double duration = 0, double paiment = 0){
        this->set_id(id);
        this->set_name_of_trip(name_of_trip);
        this->set_distanse(distanse);
        this->set_duration(duration);
        this->set_paiment(paiment);
    }
    //  конcтруктор trip  //

    //  set'ы  //
    void set_id(int id) {
        if (id < 0)
            throw;
        else
            this->id = id;
    }
    
    void set_name_of_trip (string name){
        name_of_trip = name;
    }
    
    void set_distanse(double distanse){
        if (distanse < 0)
            throw;
        else
            this->distanse = distanse;
    }

    void set_duration (double duration){
        if (duration < 0)
            throw;
        else
            this->duration = duration;
    }

    void set_paiment (double paiment) {
        if (paiment < 0)
            throw;
        else
            this->paiment = paiment;
    }
    //  set'ы  //


    //  get'ы  //
    
    int get_id(){
        return id;
    }
    string get_name_of_trip(){
        return name_of_trip;
    }

    double get_distanse(){
        return distanse;
    }

    double get_duration(){
        return duration;
    }

    double get_paiment(){
        return paiment;
    }
    //  get'ы  //
    
    string out_trip(){
        if (id == 0)
            return "";
        else
            return get_name_of_trip() + ": "s + to_string(get_distanse()) + "km, "s + to_string(get_duration()) + "h, "s + to_string(get_paiment()) + "$.\n"s;
    }
};
