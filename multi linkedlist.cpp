#include <iostream>
using namespace std;

//  STUDENT NODE 
struct sNode {
    string data;      // student ka naam ya ID
    sNode* next;      // next student ka address
};

//  COURSE NODE 
struct cNode {
    string data;          // course ka naam
    cNode* next;          // next course ka address
    sNode* studentList;   // is course ki student list ka head
};

// Global head pointer for course list
cNode* cList = NULL;


// INSERT COURSE
void insertCourse(string courseNo) {

    // naya course node create karo
    cNode* node = new cNode;
    node->data = courseNo;
    node->next = NULL;
    node->studentList = NULL;

    // agar list empty hai
    if (cList == NULL) {
        cList = node;   // head bana do
        return;
    }

    // warna end tak traverse karo
    cNode* temp = cList;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = node;  // end me attach kar do
}

// SEARCH COURSE
cNode* searchCourse(string courseNo) {

    if (cList == NULL) {
        cout << "Course List is empty\n";
        return NULL;
    }

    cNode* temp = cList;

    while (temp != NULL) {

        if (temp->data == courseNo) {
            cout << "Course Found\n";
            return temp;  // course ka address return
        }

        temp = temp->next;  // next course pe move
    }

    cout << "Course Not Found\n";
    return NULL;
}


// ADD STUDENT IN COURSE
void addStudentInCourse(string courseNo, string studentNo) {

    // pehle course find karo
    cNode* course = searchCourse(courseNo);

    if (course == NULL)
        return;

    // naya student node create karo
    sNode* node = new sNode;
    node->data = studentNo;
    node->next = NULL;

    // agar student list empty hai
    if (course->studentList == NULL) {
        course->studentList = node;
        return;
    }

    // warna student list ke end tak jao
    sNode* temp = course->studentList;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = node;
}

// SEARCH STUDENT IN ALL COURSES
sNode* searchStudent(string studentNo) {

    if (cList == NULL) {
        cout << "Course list empty\n";
        return NULL;
    }

    cNode* coursePtr = cList;

    // outer loop -> courses
    while (coursePtr != NULL) {

        sNode* studentPtr = coursePtr->studentList;

        // inner loop -> students
        while (studentPtr != NULL) {

            if (studentPtr->data == studentNo) {
                cout << "Student Found in Course: "
                     << coursePtr->data << endl;

                return studentPtr;
            }

            studentPtr = studentPtr->next;  // next student
        }

        coursePtr = coursePtr->next;  // next course
    }

    cout << "Student not found in any course\n";
    return NULL;
}

// SEARCH STUDENT IN SPECIFIC COURSE

sNode* searchStudentInCourse(string courseNo, string studentNo) {

    cNode* course = searchCourse(courseNo);

    if (course == NULL)
        return NULL;

    sNode* studentPtr = course->studentList;

    while (studentPtr != NULL) {

        if (studentPtr->data == studentNo) {
            cout << "Student Found in Course: "
                 << courseNo << endl;

            return studentPtr;
        }

        studentPtr = studentPtr->next;
    }

    cout << "Student not found in this course\n";
    return NULL;
}


// DELETE COURSE
void deleteCourse(string courseNo) {

    if (cList == NULL) {
        cout << "Course List empty\n";
        return;
    }

    cNode* curr = cList;
    cNode* prev = NULL;

    // course search karo
    while (curr != NULL && curr->data != courseNo) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Course not found\n";
        return;
    }

    // pehle us course ke students delete karo
    sNode* sTemp = curr->studentList;
    while (sTemp != NULL) {
        sNode* del = sTemp;
        sTemp = sTemp->next;
        delete del;
    }

    // course delete karo
    if (prev == NULL)
        cList = curr->next;
    else
        prev->next = curr->next;

    delete curr;

    cout << "Course deleted successfully\n";
}

// DISPLAY ALL DATA
void displayAll() {

    if (cList == NULL) {
        cout << "No courses available\n";
        return;
    }

    cNode* temp = cList;

    while (temp != NULL) {

        cout << "Course: " << temp->data << " -> ";

        sNode* stdTemp = temp->studentList;

        if (stdTemp == NULL) {
            cout << "No Students";
        }
        else {
            while (stdTemp != NULL) {
                cout << stdTemp->data;

                if (stdTemp->next != NULL)
                    cout << " -> ";

                stdTemp = stdTemp->next;
            }
        }

        cout << endl;
        temp = temp->next;
    }
}


// =================================================
// MAIN
// =================================================
int main() {

    insertCourse("Course1");
    insertCourse("Course2");
    insertCourse("Course3");

    addStudentInCourse("Course1", "Syeda");
    addStudentInCourse("Course2", "Bareeha");
    addStudentInCourse("Course2", "Fatimaa");

    cout << "\nSearching Student:\n";
    searchStudent("fatimaa");

    cout << "\nAll Data:\n";
    displayAll();

    cout << "\nDeleting Course2:\n";
    deleteCourse("Course2");

    cout << "\nAfter Deletion:\n";
    displayAll();

    return 0;
}
