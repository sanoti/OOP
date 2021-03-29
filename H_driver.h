//
//  H_driver.h
//  ob
//
//  Created by Даниил on 12.11.2020.
//
#pragma once
#include <iostream>
#include <string>

using namespace std;

class driver{
private:
    int id;
    string name;
    string surename;
    int xp;
public:
    driver(int id = 0, string name = "pusto", string surename = "pusto", int xp = 0){
        this->set_id(id);
        this->set_name(name);
        this->set_surename(surename);
        this->set_xp(xp);

    }
    
    //  set'ы  //
    void set_id(int id) {
        if (id < 0)
            throw;
        else
            this->id = id;
    }
    
    void set_name(string name){
        this->name = name;
    }
    
    void set_surename(string surename){
        this->surename = surename;
    }
    
    void set_xp(int xp){
        if (xp < 0)
            throw;
        else
            this->xp = xp;
    }
    //  set'ы  //
    
    //  get'ы  //
    int get_id(){
        return id;
    }
    string get_name(){
        return name;
    }
    
    string get_surename(){
        return surename;
    }
    
    double get_xp(){
            return xp;
    }
    //  get'ы  //
    
    string out_driver(){
//        if (id == 0)
//            return "";
//        else
            return get_name() + " "s + get_surename() + " with "s + to_string(get_xp()) + " years of xp.\n"s;
    }
};
