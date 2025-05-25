#include <stdio.h>

int main()
{
    int subjectCount = 0;
    scanf("%d", &subjectCount);
    
    // 기존 점수
    int scoreArray[subjectCount] = {0};
    int max = 0;
    for (int index = 0; index < subjectCount; index++)
    {
        int score = 0;
        scanf("%d", &score);
        
        scoreArray[index] = score;
        if (max < score)
        {
            max = score;
        }
    }
    
    // 조작 점수
    double manipulateScoreArray[subjectCount] = {0.0};
    double manipulateTotalScore = 0.0;
    for (int index = 0; index < subjectCount; index++)
    {
        if (0 < scoreArray[index])
        {
            manipulateScoreArray[index] = double(scoreArray[index]) / max * 100;
        }
        else
        {
            manipulateScoreArray[index] = 0.0;
        }
        
        manipulateTotalScore += manipulateScoreArray[index];
    }
    
    // 조작 점수 평균
    float manipulateAverage = manipulateTotalScore / subjectCount;
    printf("%.14lf\n", manipulateAverage);
    
}