#include <iostream>

int main()
{
    srand(time(NULL));

    int random_array [1000000];
    int counter_array [42] = {0};

    //  fills random_array with numbers between 1 and 42
    for (int i = 0; i < 1000001; i++)
    {
        random_array[i] = (rand() % 42 + 1);
    }
    //

    // every time a number j appears in array, 1 is added to the counter_array on index of j-1 
    for (int i = 0; i < 1000001; i++)
    {   
        for (int j = 1; j < 43; j++ )
        {
            if(random_array[i] == j)
            {
                counter_array[j-1] += 1;
            }
        }
    }
    //
    std::cout<<"After one milion draws: "<<std::endl;
    //
    for (int i = 0; i < 42; i++) 
    {
        std::cout<<"Number "<<i+1<<" has appeared "<<counter_array[i]<<" times."<<std::endl;
    }
    //


        
    return 0;
}