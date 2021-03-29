//
//  H_driver_list.h
//  ob
//
//  Created by Даниил on 16.11.2020.
//
#pragma once
#include "H_driver.h"


using namespace std;

//string name;
//string surename;
//int xp;

class driver_list{
private:
    vector <driver*> list;
public:
    void add_driver(driver& ddriver){ //  добавляем водителя в лист
        for (vector <driver*>::iterator it = list.begin(); it != list.end(); it++){
            if (ddriver.get_id() == (*it)->get_id()){
                cout << "driver is already on the list"s;
                return;
            }
        }
        list.push_back(&ddriver);
    }
    
    void del_driver(driver& ddriver){ //   удаляем водителя из листа
        for (vector <driver*>::iterator it = list.begin(); it != list.end(); it++){
            if (ddriver.get_id() == (*it)->get_id()){
                list.erase(it);
                return;
            }
        }
    }
    
    void del_driver_by_id(int id){ //   удаляем водителя из листа
        for (vector <driver*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                list.erase(it);
                return;
            }
        }
    }
    
    void clear_list(){ //   очищаем весь лист
        list.clear();
    }
    
    //  set'ы  //
    void set_name_by_id(int id, string name){ //    добавляем name по id
        for (vector <driver*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                (*it)->set_name(name);
            }
        }
    }
    
    void set_surename_by_id(int id, string surename){ //    добавляем surename по id
        for (vector <driver*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                (*it)->set_surename(surename);
            }
        }
    }
    
    void set_xp_by_id(int id, int xp){ //    добавляем paiment по id
        for (vector <driver*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                (*it)->set_xp(xp);
            }
        }
    }
    //  set'ы  //
    
    
    //  get'ы  //
    vector <driver*> get_list(){ //   возвращаем весь list
        return list;
    }
    
    driver* get_driver_by_id(int id){ //     возвращаем водителя по id
        for (vector <driver*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                return (*it);
            }
        }
        driver x = driver();
        driver* u = &x;
        return u;
    }
    
    string get_out_driver(int id){ //     возвращаем конкретный driver по id в виде строки
        for (vector <driver*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id)
                return (*it)->out_driver();
        }
        return "driver isn't on the list\n";
    }
    
    string get_name_by_id(int id){ //     возвращаем name по id
        for (vector <driver*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                return (*it)->get_name();
            }
        }
        return "driver(and his 'name') isn't on the list\n";
    }
    
    string get_surename_by_id(int id){ //     возвращаем surename по id
        for (vector <driver*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                return (*it)->get_surename();
            }
        }
        return "driver(and his 'surename') isn't on the list\n";
    }
    
    double get_xp_by_id(int id){ //     возвращаем xp по id
        for (vector <driver*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id){
                return (*it)->get_xp();
            }
        }
        return -1;
    }
    
    vector <int>  get_id_trip_list(){ //     возвращаем вектор со всеми id
        vector <int> result;
        for (vector <driver*>::iterator it = list.begin(); it != list.end(); it++){
            result.push_back((*it)->get_id());
        }
        return result;
    }
    //  get'ы  //

    
    bool check_driver_by_id(int id){ //     проверка на наличие водителя в списке
        for (vector <driver*>::iterator it = list.begin(); it != list.end(); it++){
            if ((*it)->get_id() == id)
                return true;
        }
        return false;
    }
    
    
    string out_list(){ //     вывод всех водителей из списка
        if (list.size() == 0){
            return "list is empty"s;
        }
        string result = "all drivres:\n";
        for (vector <driver*>::iterator it = list.begin(); it != list.end(); it++){
            result += (*it)->out_driver() + "\n";
        }
        return result;
    }
    
    
};

