//
//  data_xml.h
//  ob
//
//  Created by Даниил on 03.12.2020.
//

#pragma once
#include "pugi.hpp"
#include "H_lowboy.h"
#include <string>
#include <fstream>

using namespace std;

class data_xml{
private:
    lowboy llowboy;
public:
    lowboy read(string s){
        pugi::xml_document doc;
        ifstream stream(s);
        //pugi::xml_parse_result result =
        doc.load(stream);
        
        for (pugi::xml_node tool = doc.child("lowboy").child("trips").child("trip"); tool; tool = tool.next_sibling("trip")){
            trip* trip_ = new trip(tool.attribute("id").as_int(), tool.attribute("name_of_trip").as_string(), tool.attribute("distanse").as_double(), tool.attribute("duration").as_double(), tool.attribute("paiment").as_double());
            llowboy.add_trip(*trip_);
        }
        
        for (pugi::xml_node tool = doc.child("lowboy").child("drivers").child("driver"); tool; tool = tool.next_sibling("driver")){
            driver* driver_ = new driver(tool.attribute("id").as_int(), tool.attribute("name").as_string(), tool.attribute("surename").as_string(), tool.attribute("xp").as_double());
            llowboy.add_driver(*driver_);
        }
        
        for (pugi::xml_node tool = doc.child("lowboy").child("complete_s").child("complete"); tool; tool = tool.next_sibling("complete")){
            
            trip* obj_t;
            pugi::xml_attribute tool1 = tool.attribute("trip");
            obj_t = llowboy.get_trip(tool1.as_int());
            
            driver* obj_d;
            pugi::xml_attribute tool2 = tool.attribute("driver");
            obj_d = llowboy.get_driver(tool2.as_int());
            
            complete* complete_ = new complete(tool.attribute("id").as_int(), obj_t, obj_d, tool.attribute("departure").as_string(), tool.attribute("arrival").as_string(), tool.attribute("premium").as_double());
            llowboy.add_complete(*complete_);
        }
        return llowboy;
    }
    
    void write(lowboy lowboy, const char* out_file_name){
        pugi::xml_document doc;
        
        doc.append_child("lowboy");
        doc.child("lowboy").append_child("trips");
        doc.child("lowboy").append_child("drivers");
        doc.child("lowboy").append_child("complete_s");
        
        vector<trip*> obj_tl = lowboy.get_trip_list();
        for (vector <trip*>::iterator it = obj_tl.begin(); it != obj_tl.end(); it++){
            pugi::xml_node node = doc.child("lowboy").child("trips").append_child("trip");
            node.append_attribute("id") = (*it)->get_id();
            node.append_attribute("name_of_trip") = ((*it)->get_name_of_trip()).c_str();
            node.append_attribute("distanse") = (*it)->get_distanse();
            node.append_attribute("duration") = (*it)->get_duration();
            node.append_attribute("paiment") =  (*it)->get_paiment();
        }
        
        vector<driver*> obj_dl = lowboy.get_driver_list();
        for (vector <driver*>::iterator it = obj_dl.begin(); it != obj_dl.end(); it++){
            pugi::xml_node node = doc.child("lowboy").child("drivers").append_child("driver");
            node.append_attribute("id") = (*it)->get_id();
            node.append_attribute("name") = (*it)->get_name().c_str();
            node.append_attribute("surename") = (*it)->get_surename().c_str();
            node.append_attribute("xp") = (*it)->get_xp();
        }
        
        vector<complete*> obj_cl = lowboy.get_complete_list();
        for (vector <complete*>::iterator it = obj_cl.begin(); it != obj_cl.end(); it++){
            pugi::xml_node node = doc.child("lowboy").child("complete_s").append_child("complete");
            node.append_attribute("id") =(*it)->get_id();
            node.append_child("trip").append_attribute("id") = (*it)->get_trip()->get_id();
            node.append_child("trip").append_attribute("name_of_trip") = (*it)->get_trip()->get_name_of_trip().c_str();
            //node.append_attribute("trip^s id") = (*it)->get_trip()->get_id();
            node.append_child("driver").append_attribute("id") = (*it)->get_driver()->get_id();
            ///node.append_child("driver").append_attribute("name") = (*it)->get_driver()->get_name().c_str();
            //node.append_attribute("driver^s id") = (*it)->get_driver()->get_id();
            node.append_attribute("departure") = (*it)->get_departure().c_str();
            node.append_attribute("arrival") = (*it)->get_arrival().c_str();
            node.append_attribute("premium") = (*it)->get_premium();
        }
        doc.save_file(out_file_name);
    }
};
