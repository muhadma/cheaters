#include <iostream>
#include <string>
#include "student.h"

using namespace std;

class Course {
    Student** students;
    string topic;
    int size;
    int capacity;
    int yearlvl;
    string program;
    
    public: 
        Course(string topic) : topic(topic), size(0), yearlvl(0), program("") {
            capacity = 5;
            students = (Student**)malloc(capacity * sizeof(Student*));  
        }
        

        int addStudent(Student* s) {
            if (size == capacity) {
                int newCapacity = capacity + (capacity / 2);
                students = (Student**)realloc(students, newCapacity * sizeof(Student*));
                capacity = newCapacity;
            }
            if (s->year_level == yearlvl && s->program == program) {
                return 0;
            } else {
                students[size++] = s;
            }
            return 1;  
        }

        int removeCheaters(string name) {
            int index = -1;
            int count = 0;
            for (int i = 0; i < size; i++) {
                if (students[i]->name == name) {
                    program = students[i]->program;
                    yearlvl = students[i]->year_level;
                    delete students[i];  
                    index = i;
                    count++;
                    for (int j = i; j < size - 1; j++) {
                        students[j] = students[j + 1];  
                    }
                    size--;
                    break;
                }
            }

            if (index == -1) {
                return 0;  
            }

            for (int i = 0; i < size; i++) {
                if (students[i]->program == program && students[i]->year_level == yearlvl) {
                    delete students[i];  
                    for (int j = i; j < size - 1; j++) {
                        students[j] = students[j + 1];  
                    }
                    size--;
                    count++;
                    i--;  
                }
            }

            return count;  
        }
        
        void print() {
            cout << "Student size: " << size << "/" << capacity << endl;
            for (int i = 0; i < capacity; i++) {
                if (i >= size) {
                    cout << i + 1 << " (none) " << endl;
                } else {
                    cout << i + 1 << ": " << students[i]->name << " " 
                         << students[i]->program << " " 
                         << students[i]->year_level << endl;
                }
            }
        }
};
