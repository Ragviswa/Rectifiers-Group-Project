#include "component.hpp"
#ifndef current_matrix_hpp
#define current_matrix_hpp
using namespace std;


vector<float> find_current(vector<base_class*> all_components, int matrix_base_size, int voltage_count, int capacitor_count, float t){
    //Creates current matrix filled with 0s
    vector<float> current_matrix;
    for (int i=0; i<matrix_base_size+voltage_count+capacitor_count; i++){
        current_matrix.push_back(0);
    }
    //Scans through every component looking for sources
    for (int i=0; i<all_components.size(); i++){
        //Add values to the current matrix
        if (all_components[i]->return_type() == 'I' || all_components[i]->return_type() == 'L'){
            if (all_components[i]->return_nodes()[1]->return_ID() != 0){
                current_matrix[ all_components[i]->return_nodes()[1]->return_ID()-1 ] += all_components[i]->return_value(t);
            }
        }
        //Add voltage values to the matrix
        else if (all_components[i]->return_type() == 'V'){
            if (all_components[i]->return_nodes()[0]->return_ID() != 0){
                current_matrix[ stoi(all_components[i]->return_name().substr(1)) + matrix_base_size -1] = all_components[i]->return_value(t);
            }
        }
        //Add capacitor values to the matrix
        else if(all_components[i]->return_type() == 'C'){
            if (all_components[i]->return_nodes()[0]->return_ID() != 0){
                current_matrix[ stoi(all_components[i]->return_name().substr(1)) + matrix_base_size+voltage_count -1] = all_components[i]->return_value(t);
            }
        }
    }
    return current_matrix;
}
#endif