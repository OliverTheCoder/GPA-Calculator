/**
 * @author Oliver Boamah
 * GPA CALCULATOR
 *
 */
#include <iostream>
using namespace std;
double getGPA(double marks);
double getTotalGPA(int n, int credit_hrs[], double course_grade[]);
string getClass(double totalGPA);
void displayResults(int n, string course_name[], int credit_hrs[], double marks[], double course_grade[], double totalGPA, string theClass);

/**
 * GPA CALCULATOR
 *
 */

int main()
{
    cout << "----------------------------------------------------" << endl;
    cout << "\t\t GPA CALCULATOR  " << endl;
    cout << "----------------------------------------------------" << endl;

    // how many subjects ?
    int n;
    cout << "Enter the number of subjects " << endl;
    cin >> n;

    // array to hold the names of courses
    string course_name[n];

    // array to hold the marks of courses
    double course_marks[n];

    // array to hold the gpa of courses
    double course_grade[n];

    // array to hold the number of credit hrs
    int credit_hrs[n];

    double grade;

    // Accept inputs
    for(int i = 0; i < n; i++)
    {
        // accept course name
        cout << "Enter the name for course "<< (i+1) << endl;
        cin.ignore();
        getline(cin, course_name[i]);

        // accept the number of credit hrs
        cout << "How many Credit Hrs ? " << endl;
        cin >> credit_hrs[i];

        // accept mark and compute corresponding gpa
        cout << "What did you score for " << course_name[i] << endl;
        cin >> grade;
        course_marks[i] = grade;

        grade = getGPA(grade);
        course_grade[i] = grade;
    }

    // compute total GPA
    double totalGPA = getTotalGPA(n, credit_hrs, course_grade);

    // Get corresponding class
    string theClass = getClass(totalGPA);

    // Print results
    displayResults(n, course_name, credit_hrs,course_marks, course_grade, totalGPA, theClass);


    return 0;
}

/* This function displays the results in a neatly */
void displayResults(int n, string course_name[], int credit_hrs[], double course_marks[], double course_grade[], double totalGPA, string theClass)
{

    cout << endl << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "MARK \t GPA \t NUM CREDIT HRS \t COURSE NAME" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << course_marks[i] << "\t  " << course_grade[i] << "\t\t" << credit_hrs[i] << "\t\t  " << course_name[i] << endl;
    }
    cout << "TOTAL GPA = " << totalGPA << endl;
    cout << "You are a " << theClass << " student" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
}



 /* Compute the GPA for a given mark */
double getGPA(double marks)
{
    double grade = 0.0;
    if(marks >= 80){
        grade = 4.0;
    }else if(marks >= 75){
        grade = 3.5;
    }else if(marks >= 70){
        grade = 3.0;
    }else if(marks >= 65){
        grade = 2.5;
    }else if(marks >= 60){
        grade = 2.0;
    }else if(marks >= 55){
        grade = 1.5;
    }else if(marks >= 50){
        grade = 1.0;
    }else if(marks >= 45){
        grade = 0.5;
    }
    else{
        grade = 0.0;
    }

    return grade;
}

/* This function computes the total GPA */
double getTotalGPA(int n, int credit_hrs[], double course_grade[])
{

    double totalGPA = 0.0;
    int totalCreditHrs = 0;
    for(int i = 0; i < n; i++)
    {
        totalGPA += credit_hrs[i] * course_grade[i];
        totalCreditHrs += credit_hrs[i];
    }

    return totalGPA/totalCreditHrs;
}

/* This function computes the class per the given GPA */
string getClass(double totalGPA)
{
    string theClass;
    if(totalGPA >= 3.6){
        theClass = "First Class";
    }else if(totalGPA >= 3.0){
        theClass = "Second Class Upper";
    }
    else if(totalGPA >= 2.0){
        theClass = "Second Class Lower";
    }
    else if(totalGPA >= 1.5 ){
        theClass = "Third Class";
    }
    else if (totalGPA >= 1.0){
        theClass = "Pass";
    }
    else{
        theClass = "Failed!, You can't graduate";
    }

    return theClass;
}

























