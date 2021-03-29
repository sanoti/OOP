//
//  H_lowboy.h
//  ob
//
//  Created by Даниил on 29.11.2020.
//
#pragma once
#include "H_trip_list.h"
#include "H_driver_list.h"
#include "H_complete_list.h"

using namespace std;

class lowboy {
private:
    trip_list list_of_trip;
    driver_list list_of_driver;
    complete_list list_of_complete;
public:
      //  trip  //
    void set_trip_list (trip_list list){
        list_of_trip = list;
    }
    
    void add_trip(trip& trip){
        list_of_trip.add_trip(trip);
    }
    
    void del_trip(int id){
        vector <complete*> list = list_of_complete.get_list();
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_trip()->get_id() == id){
                cout << "this trip is complete and can't be deleted";
                return;
            }
        }
        list_of_trip.del_trip_by_id(id);
    }
    
    string out_trip_list(){
        return list_of_trip.out_list();
    }
      //  trip  //
    
      //  driver  //
    void set_driver_list (driver_list list){
        list_of_driver = list;
    }
    
    void add_driver(driver& driver){
        list_of_driver.add_driver(driver);
    }
    
    void del_driver(int id){
        vector <complete*> list = list_of_complete.get_list();
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_trip()->get_id() == id){
                cout << "this driver is complete trip and can't be deleted";
                return;
            }
        }
        list_of_driver.del_driver_by_id(id);
    }
    
    string out_driver_list(){
        return list_of_driver.out_list();
    }
      //  driver  //
    
      //  complete  //
    void set_complete_list (complete_list list){
        list_of_complete = list;
    }
    
    void add_complete(complete& complete){
        list_of_complete.add_complete(complete);
    }
    
    void del_complete(int id){
        list_of_complete.del_complete_by_id(id);
    }
    
    string out_complete_list(){
        return list_of_complete.out_list();
    }
      //  complete  //
    
      //  clear  //
    void clear_trip_list(){
        list_of_trip.clear_list();
    }
    
    void clear_driver_list(){
        list_of_driver.clear_list();
    }
    
    void clear_complete_list(){
        list_of_complete.clear_list();
    }
    
    void clear_all_lists(){
        clear_trip_list();
        clear_driver_list();
        clear_complete_list();
    }
      //  clear  //
    
    //--  set'ы  --//
      //  trip  //
    void set_trip_name(int id, string name){
        list_of_trip.set_name_of_trip_by_id(id, name);
        vector <complete*> list = get_complete_list();
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_trip()->get_id() == id)
                (*it)->get_trip()->set_name_of_trip(name);
        }
    }
    
    void set_trip_distanse(int id, double distanse){
        list_of_trip.set_distanse_by_id(id, distanse);
        vector <complete*> list = get_complete_list();
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_trip()->get_id() == id)
                (*it)->get_trip()->set_distanse(distanse);
        }
    }
    
    void set_trip_duration(int id, double duration){
        list_of_trip.set_duration_by_id(id, duration);
        vector <complete*> list = get_complete_list();
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_trip()->get_id() == id)
                (*it)->get_trip()->set_duration(duration);
        }
    }
    
    void set_trip_paiment(int id, double paiment){
        list_of_trip.set_paiment_by_id(id, paiment);
        vector <complete*> list = get_complete_list();
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_trip()->get_id() == id)
                (*it)->get_trip()->set_paiment(paiment);
        }
    }
      //  trip  //
      //  driver  //
    void set_driver_name(int id, string name){
        list_of_driver.set_name_by_id(id, name);
        vector <complete*> list = get_complete_list();
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_driver()->get_id() == id)
                (*it)->get_driver()->set_name(name);
        }
    }
    
    void set_driver_surename(int id, string surename){
        list_of_driver.set_surename_by_id(id, surename);
        vector <complete*> list = get_complete_list();
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_driver()->get_id() == id)
                (*it)->get_driver()->set_surename(surename);
        }
    }
    
    void set_driver_xp(int id, double xp){
        list_of_driver.set_xp_by_id(id, xp);
        vector <complete*> list = get_complete_list();
        for (vector <complete*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_driver()->get_id() == id)
                (*it)->get_driver()->set_xp(xp);
        }
    }
      //  driver  //
      //  complete  //
    void set_com_trip(int id, trip* com_trip){
        list_of_complete.set_com_trip_by_id(id, com_trip);
    }
    
    void set_com_trip(int id, driver* com_driver){
        list_of_complete.set_com_driver_by_id(id, com_driver);
    }
    
    void set_com_departure(int id, string departure){
        list_of_complete.set_departure_by_id(id, departure);
    }
    
    void set_com_arrival(int id, string arrival){
        list_of_complete.set_arrival_by_id(id, arrival);
    }
    
    void set_com_premium(int id, double premium){
        list_of_complete.set_premium_by_id(id, premium);
    }
      //  complete  //
    //--  set'ы  --//
    
    //--  get'ы  --//
      //  trip  //
    string get_trip_name(int id){
        return list_of_trip.get_name_of_trip_by_id(id);
    }
    
    double get_trip_distanse(int id){
        return list_of_trip.get_distanse_by_id(id);
    }
    
    double get_trip_duration(int id){
        return list_of_trip.get_duration_by_id(id);
    }
    
    double get_trip_paiment(int id){
        return list_of_trip.get_paiment_by_id(id);
    }
    
    string out_trip(int id){
        return list_of_trip.get_out_trip(id);
    }
    
    string out_all_trip(){
        return list_of_trip.out_list();
    }
    
    trip* get_trip(int id){
        return list_of_trip.get_trip_by_id(id);
    }
    
    vector<trip*> get_trip_list(){
        return list_of_trip.get_list();
    }
      //  trip  //
      //  driver  //
    string get_driver_name(int id){
        return list_of_driver.get_name_by_id(id);
    }
    
    string get_driver_surename(int id){
        return list_of_driver.get_surename_by_id(id);
    }
    
    int get_driver_xp(int id){
        return list_of_driver.get_xp_by_id(id);
    }
    
    string out_driver(int id){
        return list_of_driver.get_out_driver(id);
    }
    
    driver* get_driver(int id){
        return list_of_driver.get_driver_by_id(id);
    }
    
    vector<driver*> get_driver_list(){
        return list_of_driver.get_list();
    }
    
    string out_all_driver(){
        return list_of_driver.out_list();
    }
      //  driver  //
      //  complete  //
    trip* get_com_trip(int id){
        return list_of_complete.get_com_trip_by_id(id);
    }
    
    driver* get_com_driver(int id){
        return list_of_complete.get_com_driver_by_id(id);
    }
    
    string get_com_departure(int id){
        return list_of_complete.get_departure_by_id(id);
    }
    
    string get_com_arrival(int id){
        return list_of_complete.get_arrival_by_id(id);
    }
    
    double get_com_premium(int id){
        return list_of_complete.get_premium_by_id(id);
    }
    
    vector <complete*> get_complete_list(){
        return list_of_complete.get_list();
    }
    
    string out_all_complete(){
        return list_of_complete.out_list();
    }
      //  complete  //
    vector<int> get_id_trip_list(){
        return list_of_trip.get_id_trip_list();
    }
    
    vector<int> get_id_driver_list(){
        return list_of_driver.get_id_trip_list();
    }
    
    vector<int> get_id_complete_list(){
        return list_of_complete.get_id_complete_list();
    }
    //--  get'ы  --//
    


};

