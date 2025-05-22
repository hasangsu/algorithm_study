#include <iostream>

int main()
{
    int totalStudentCount = 30;
    int unsubmintStudentCount = 2;
    int taskArray[totalStudentCount] = {0, };
    for (int studentIndex = 0; studentIndex < (totalStudentCount - unsubmintStudentCount); studentIndex++)
    {
        int student = 0;
        scanf("%d", &student);
        taskArray[student - 1] = student;
    }
    
    int unsubmitTaskArray[unsubmintStudentCount] = {0};
    int temp = 0;
    for (int studentIndex = 0; studentIndex < totalStudentCount; studentIndex++)
    {
        if (taskArray[studentIndex] <= 0)
        {
            unsubmitTaskArray[temp] = studentIndex + 1;
            temp++;
        }
    }
    
    int minStudent = (unsubmitTaskArray[0] < unsubmitTaskArray[1]) ? unsubmitTaskArray[0] : unsubmitTaskArray[1];
    int maxStudent = (unsubmitTaskArray[0] > unsubmitTaskArray[1]) ? unsubmitTaskArray[0] : unsubmitTaskArray[1];
    printf("%d\n", minStudent);
    printf("%d\n", maxStudent);
}