#include<stdio.h>

void Minutes(int minutes[])
{
  int day;

  printf("\n Enter day number ->");
  scanf("%d", &day);

  if(day < 1 || day > 7)
  {
    printf("Invalid day number! \n ");
    return;
  }
  printf("Enter listening miuntes for day %d -> ",day);
  scanf("%d", &minutes[day - 1]);

  FILE *file = fopen("music_log.txt","w");
  if(file == NULL)
  {
    printf("Error opening file ! \n");
    return;

  }

  for(int i = 0; i < 7; i++)
  {
    fprintf(file, "%d\n",minutes[i]);
  }
  fclose(file);
  printf("Listening minutes saved successfully! \n");
}

void loadData(int minutes[])
{
   FILE *file = fopen("music_log.txt", "r");

   if(file == NULL)
   {
     return;
   }
   for(int i =0; i < 7; i++)
   {
     fscanf(file ,"%d" , &minutes[i]);
   }
   fclose(file);
}

void weeklyReport(int minutes[])
{
  int total=0;
  int highest = minutes[0];

  for(int i = 0; i < 7; i++)
  {
    total +=minutes[i];

    if(minutes[i] > highest)
    {
      highest = minutes[i];
    }
  }

  printf("\n----------WEEKLY REPORT----------\n");
  printf("Total Listening Minutes ->  %d\n", total);
  printf("Average Listening -> %.2f minutes\n" ,total/7.0);
  printf("Highest Listening -> %d minutes\n" , highest);
}

void resetData(int minutes[])
{
  char confirmation;

  printf("\n Are you sure you want to reset the weekly data?(yes/no) -> ");
  scanf("%c",&confirmation);

  if(confirmation != 'y' && confirmation != 'Y')
  {
    printf("Reset canelled. \n");
    return;
  }
   
  for(int i = 0; i < 7; i++)
  {
    minutes[i] =0;
  }
  FILE *file = fopen("music_log.txt" , "w");

  if( file != NULL)
  {
    fclose(file);
  }
  printf("Weekly data has been reset.\n");
  
}

int main()
{
  int minutes[7] = {0};
  int choice;

  loadData(minutes);
  do
  {
    printf("\n----------MUSIC LISTENING LOGGER----------\n");
    printf("1. Log Listening Minutes\n");
    printf("2. View Weekly Report\n");
    printf("3. Reset Weekly Data\n");
    printf("4. Exit\n");
    
    printf("Enter your choice -> ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      Minutes(minutes);
      break;

    case 2:
      weeklyReport(minutes);
      break;

    case 3:
      resetData(minutes);
      break;

    case 4:
      printf("Goodbye ! \n");
      break;
    
    default:
      printf("Invalid choice ! please try again.\n");
      break;
    }
  }while (choice != 4);
  return 0;
}