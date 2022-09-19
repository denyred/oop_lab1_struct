//
//  main.c
//  main
//
//  Created by Spataru Dionisie on 19.09.2022.
//

#include<stdio.h>



int main()
{
    printf("\n\n\t\tQueue options\n\n\n");
    int choice;

    while(1)
    {
        printf("1. Queue \n");
        printf("2. Dequeue\n");
        printf("3. Search\n");
        printf("4. Sort\n");
        printf("5. Reverse\n");
        printf("6. Priority queue\n");
        printf("7. Circular queue\n");
        printf("0. Exit\n\n\n");
        printf("Enter your choice :  ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter number:\n");
                break;
        
            case 2:
                printf("Enter number:\n");
                break;
        
            case 3:
                printf("Enter number:\n");
                break;
            
            case 4:
                printf("Enter number:\n");
                break;
                
            case 5:
                printf("Enter number:\n");
                break;
            
            case 6:
                printf("Enter number:\n");
                break;
                
            case 7:
                printf("Enter number:\n");
                break;
        
            case 0:
                return(0);    // terminates the complete program execution
        }
    }
    return 0;
}
