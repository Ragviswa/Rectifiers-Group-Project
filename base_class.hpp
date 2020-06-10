#ifndef base_class_hpp
#define base_class_hpp


#include <vector>
#include <string>
#include <cmath>
using namespace std;


class node;


//Base class just for inherited functionality so everything can use the same methods when iterating through arrays of components
class base_class
{
    protected:
        node* node1;
        node* node2;
        string name;       
        float value;
        float prev_cv = 0;
        char type;


    public:
        //Returns the nodes the component is connected to in a vector form
        virtual vector<node*> return_nodes(){
            vector<node*> temp{node1, node2};
            return temp;
        }


        //Returns type of component
        virtual char return_type(){
            return type;
        }


        //Returns name of the current component
        virtual string return_name(){
            return name;
        }


        //Sets the previous value of current/voltage
        virtual void set_prev_cv(float cv){
            prev_cv = cv;
        }
        

        //Returns value of the component
        virtual float return_value(float t);
        virtual float return_value(float t, bool final_loop_checker);
        

        //For global functionality
        virtual base_class* return_Req();
        virtual base_class* return_Ieq();
};


#endif