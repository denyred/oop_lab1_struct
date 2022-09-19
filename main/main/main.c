//
//  main.c
//  main
//
//  Created by Spataru Dionisie on 19.09.2022.
//

#include<stdio.h>



int main()
{
    printf("\n\n\t\tLinked List options\n\n\n");
    int choice;
    
    FILE * fpointer = fopen("data.txt", "w");

    while(1)
    {
        printf("1. Append\n");
        printf("2. Prepend\n");
        printf("3. Reverse\n");
        printf("4. Add a value to the specific index \n");
        printf("5. Remove a value the from index\n");
        printf("6. Sort the linked list\n");
        printf("7. Search for a value \n");
        printf("8. Join two linked lists \n");
        printf("9. Backwards traversal \n");
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
                
            case 8:
                printf("Enter number:\n");
                break;
                
            case 9:
                printf("Enter number:\n");
                break;
        
            case 0:
                fclose(fpointer);
                return(0);    // terminates the complete program execution
        }
    }
    return 0;
}
