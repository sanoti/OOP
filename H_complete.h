//
//  H_complete.h
//  ob
//
//  Created by Даниил on 12.11.2020.
//
#pragma once
#include <iostream>
#include <string>

using namespace std;
class complete{
private:
    int id;
    trip* com_trip;
    driver* com_driver;
    string departure;
    string arrival;
    double premium;
public:
    complete(int id, trip* com_trip, driver* com_driver, string departure , string arrival, double premium){
        this->set_id(id);
        this->set_com_trip(com_trip);
        this->set_com_driver(com_driver);
        this->set_departure(departure);
        this->set_arrival(arrival);
        this->set_premium(premium);
    }
    //  set'ы  //
    void set_id(int id){
        if (id < 0)
            throw;
        else
            this->id = id;
    }
    
    void set_com_trip(trip* com_trip){
        this->com_trip = com_trip;
    }
    
    void set_com_driver(driver* com_driver){
        this->com_driver = com_driver;
        
    }
    
    void set_departure(string departure){
        this->departure = departure;
        
    }
    
    void set_arrival(string arrival){
        this->arrival = arrival;
    }
    
    void set_premium(double premium){
        if (premium < 0 )
            throw;
        else
            this->premium = premium;
    }
    //  set'ы  //
    
    //  get'ы  //
    int get_id(){
        return this->id;
    }
    
    trip* get_trip (){
        return com_trip;
    }
    
    int get_trip_id (){
        return com_trip->get_id();
    }
    
    driver* get_driver (){
        return com_driver;
    }
    
    int get_driver_id(){
        return com_driver->get_id();
    }
    
    string get_departure (){
        return departure;
    }
    
    string get_arrival(){
        return arrival;
    }
    
    double get_premium(){
        return premium;
    }
    //  get'ы  //
    
    string out_com(){
        return com_trip->out_trip() + "Driver: "s + com_driver->out_driver() + "depatrure date: "s + get_departure() + "\n"s + "arrival date: "s + get_arrival() + "\n"s + "trip premium: "s + to_string(get_premium()) + "$.\n";
    }

};
