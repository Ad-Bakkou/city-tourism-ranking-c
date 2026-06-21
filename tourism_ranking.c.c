#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char city_name[100];
    char country_name[100];
    double N_tourist;
    char most_visited[100];
    char line[100];
}city_info;


void menu1(); 
void menu2();
int display(FILE *fptr);
void load_file_data(FILE*fptr,city_info*arr,int N_cities);
void comment();
void dataload();
void dataload2();
int city_ranking(city_info*arr,int N_cities,char *city);
void notfound();
void success();
int  get_city_info(city_info*arr,int N_cities, char *cityName);
void updateTourist_N(city_info *arr, int N_cities, char *cityName, double New_tourist);
void sort(city_info *arr, int N_cities);
int  country_info(city_info *arr, int N_cities, const char *country);
int remove_city(city_info *arr, int N_cities, char *cityName);



int main() {
    FILE *fptr;
    city_info arr[100];
    int N_cities,flak = 0,choice;
    int  t,c_info,remove,rank,len,flag = 0;
    char cityName[100];
    char country[100];
    double New_tourist;

    fptr = fopen("data.txt","r+");
    if(fptr==NULL) {
        printf("Failed to open data.txt");
        return 0;
    }
    else {
      menu1();
      do {
          menu2();
          scanf("%d",&choice);

          switch(choice) {
            case 1 :
                    N_cities = display(fptr);
                    flak = 1;
                    printf("\n\t++++++++++++++++++++++++++++++++++++++++++++++\n");
                    printf("\n\t\tthere are %d cities in this file \n",N_cities);
                    printf("\n\t+++++++++++++++++++++++++++++++++++++++++++++++\n");
                    printf("\n\n\n");
                    break;
            case 2:
                  if(flak == 0){
                     printf("\n\n\n");
                     printf("\n\t\t___________________________________________________________\n");
                     printf("\n\t\t'Please review the file to determine the number of cities.'\n");
                     printf("\n\t\t____________________________________________________________\n");
                     printf("\n\n\n");
                  }
                  else{
                  if(flag == 0) {
                    load_file_data(fptr,arr,N_cities);
                    flag = 1;
                    dataload();
                    }else {
                      dataload2();
                    }  
                  }                
                  break;

            case 3:
                  getchar();
                  if(flag == 0) {
                    comment();
                  }else {
                    printf("\n enter the city name :");
                    fgets(cityName,sizeof(cityName),stdin);
                    //remove the new line from string
                    len = strlen(cityName);

                    if (cityName[len - 1] == '\n') {
                      cityName[len - 1] = '\0';
                    }
                    rank = city_ranking(arr,N_cities,cityName);
                    if(rank == -1) {
                      notfound();
                    }else {
                      printf("\n\n\n");
                      printf("\n\t\t____________________________________\n");
                      printf("\n\t\t %s is ranked number %d. \n",cityName,rank);
                      printf("\n\t\t____________________________________\n");
                      printf("\n\n\n");
                    }
                  }
                  break;
            case 4:
                  getchar();
                  if(flag == 0) {
                    comment();
                      }else {
                            printf("\n enter the city name :");
                              fgets(cityName,sizeof(cityName),stdin);
                                int len = strlen(cityName);
                                    //remive new line from the string
                                    if (cityName[len - 1] == '\n') {
                                      cityName[len - 1] = '\0';}               
                                        t = get_city_info(arr, N_cities,cityName);
                                          if(t == -1) {
                                            notfound();
                                          }else {
                                        printf("\n\n\n");
                                      printf("----------------------------------------------------------------------------------------------------------------\n");
                                  printf("-%s is ranked number #%d.\n", cityName, t + 1);
                                printf("-Located in %s.\n", arr[t].country_name);
                              printf("-Receiving %.3lf tourists yearly.\n", arr[t].N_tourist);
                            printf("-The most visited place is %s.\n", arr[t].most_visited);
                          printf("-----------------------------------------------------------------------------------------------------------------\n");
                        printf("\n\n\n");
                        }
                      }
                  break;
            case 5:
                  getchar();
                  if(flag == 0){
                    comment();
                  }else{
                    printf("\n enter the city name :");
                    fgets(cityName,sizeof(cityName),stdin);
                    //remove new line from the string
                    len = strlen(cityName);
                    if (cityName[len - 1] == '\n') {
                      cityName[len - 1] = '\0';
                    }
                    printf("\nEnter the new number of yearly  tourist for %s :",cityName);
                    scanf("%lf",&New_tourist);
                    updateTourist_N(arr, N_cities,cityName,New_tourist);
                    sort(arr,N_cities);
                    success();
                  }
                  break;
      
            case 6:
                  getchar();
                  if(flag == 0) {
                    comment();
                  }else{
                  printf("\n enter the country name :");
                  fgets(country,sizeof(country),stdin);
                  //remive new line from string
                  len = strlen(country);

                  if (country[len - 1] == '\n') {
                    country[len - 1] = '\0';
                  }
                  c_info =  country_info(arr, N_cities,country);
                  if(c_info == 0) {
                    printf("Error in creating file %s\n",country);
                  }
                  else if (c_info == 1) {
                    dataload();
                  }
                  else{
                    notfound();
                  }
                  }
                  break;

            case 7:          
                  getchar();
                  if(flag == 0) {
                    comment();

                  }else {
                    printf("\n enter the city name :");
                    fgets(cityName,sizeof(cityName),stdin);
                    //remove new line from string
                    len = strlen(cityName);

                    if (cityName[len - 1] == '\n') {
                      cityName[len - 1] = '\0';}
                      remove = remove_city(arr, N_cities,cityName);
                      if(remove == 1) {
                        success();
                      }
                      else if(remove == -1) {
                        notfound();
                      }
                  }
                  break;

            case 8 :
            
                  printf("\n\n\n");
                  printf("\n\t\t___________________________________________________________\n");
                  printf("\n\t\t\t\tExiting the program...\n");
                  printf("\n\t\t____________________________________________________________\n");
                  printf("\n\n\n");
                   break;

                }    
      } while(choice < 8);
    }
}





//funtions
    

void menu1() {
    printf("\t\t\t------------------------------------------------\n");
    printf("\t\t\t\t\t   WELCOME \n");
    printf("\t\t\t------------------------------------------------\n");
    printf("\n\n");
}

void menu2() {
    printf("\t\t\t\t******** Menu ********\n");
    printf("\n\t\t\t1. View File Content\n");
    printf("\n\t\t\t2. Load File Data\n");
    printf("\n\t\t\t3. Get ranking of a city\n");
    printf("\n\t\t\t4. Get information about a city\n");
    printf("\n\t\t\t5. Update the number of yearly tourist of a city\n");
    printf("\n\t\t\t6. Find The Most Visited cities In a country\n");
    printf("\n\t\t\t7. Remove a city from the ranking\n");
    printf("\n\t\t\t8. Quit\n");
    printf("\n\t\t\t*****************************************************\n");
    printf("\n\t\t\t your choice please : ");
}

void comment() {
    printf("\n\n\n");
    printf("\n\t\t___________________________________________________________\n");
    printf("\n\t\tFirst, load the data and then access city_info.\n");
    printf("\n\t\t____________________________________________________________\n");
    printf("\n\n\n");
}

void dataload() {
    printf("\n\n\n");
    printf("\n\t\t____________________________________\n");
    printf("\n\t\t\t Data load successfully\n");
    printf("\n\t\t____________________________________\n");
    printf("\n\n\n");
}

void dataload2() {
     printf("\n\n\n");
     printf("\n\t\t____________________________________\n");
     printf("\n\t\t\t Data is already loaded.\n");
     printf("\n\t\t____________________________________\n");
     printf("\n\n\n");
}

void notfound() {
      printf("\n\n\n");
      printf("\n\t\t___________________________________________________\n");
      printf("\n\t\t  The name you are searching for does not exist . \n");
      printf("\n\t\t____________________________________________________\n");
      printf("\n\n\n");
}

void success() {
  printf("\n\n\n");
  printf("\n\t\t____________________________________\n");
  printf("\n\t\t Update successfully. \n");
  printf("\n\t\t____________________________________\n");
  printf("\n\n\n");
}

int display(FILE *fptr) {
  char str[100];
  int count = 0;

  fseek(fptr,0,0);
  getchar();
  while(fgets(str,sizeof(str),fptr)!=NULL) {
    printf("%s",str);
      count++;
      if((count % 25) == 0) {
        printf("\t\t\tpress enter to continue :");
        getchar();
        printf("\n");
      }
  }
  return (count/5);
}

void load_file_data(FILE*fptr,city_info*arr,int N_cities) { 
  int length,len,le;

  fseek(fptr,0,0);
  getchar();
  for(int i = 0; i < N_cities ; i++){

      //load data with \n
    fgets(arr[i].city_name,100,fptr);
    fgets(arr[i].country_name,100,fptr);
    fscanf(fptr,"%lf",&arr[i].N_tourist);
    fgetc(fptr);  //consume the new line
    fgets(arr[i].most_visited,100,fptr);
    fgets(arr[i].line, 100, fptr);

    //remove newline character from strings
    length = strlen(arr[i].city_name);
    if (arr[i].city_name[length - 1] == '\n') {
        arr[i].city_name[length - 1] = '\0';
    }

      len= strlen(arr[i].country_name);
    if (arr[i].country_name[len - 1] == '\n') {
        arr[i].country_name[len - 1] = '\0';
    }

      le = strlen(arr[i].most_visited);
    if (arr[i].most_visited[le - 1] == '\n') {
        arr[i].most_visited[le - 1] = '\0';
    }  
  }
}

int city_ranking(city_info*arr, int N_cities, char *cityName) {
  int j = 0;
  for(j=0;j<N_cities;j++){
    if(strcmp(arr[j].city_name,cityName) == 0){
      return j+1;
    } //city found
  }

  return -1; // City not found
}

int  get_city_info(city_info*arr,int N_cities, char *cityName) {
  for(int j=0;j<N_cities;j++){
    if(strcmp(arr[j].city_name,cityName)==0){
      return j;
    } //city found
  }

  return -1;//city not found
}

void updateTourist_N(city_info *arr, int N_cities, char *cityName, double New_tourist) {
  for(int j=0;j<N_cities;j++) {
    if(strcmp(arr[j].city_name,cityName)==0) {
      arr[j].N_tourist = New_tourist;
      break;
    }
  }
} 

void sort(city_info *arr, int N_cities) {
  for(int i=0; i<N_cities; i++) {
    for(int j=0;j<N_cities-i-1;j++) {
      if(arr[j].N_tourist < arr[j+1].N_tourist){
        city_info temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}


int country_info(city_info *arr, int N_cities, const char *country) {
  int found = 0;
  char filename[100];

  for(int i=0;i<N_cities;i++){
    if(strcmp(arr[i].country_name,country)==0){
      found = 1;
      break;
    }
  }
  if(found){    
    FILE *file;
    strcpy(filename,country);
    strcat(filename, ".txt");
    file = fopen(filename,"w");

    if(file==NULL){
      return 0;
    }
    else{
      for(int j = 0; j < N_cities; j++){
        if(strcmp(arr[j].country_name,country)==0){
          fprintf(file, "%s\n",arr[j].city_name);
          fprintf(file, "%s\n",arr[j].most_visited);
          fprintf(file, "%s",arr[j].line);
        }
      }
      fclose(file);
      return 1;
    }
  }else{
    return 2;
  }
}

int remove_city(city_info *arr, int N_cities, char *cityName) {
  int flag = 0;
  int i;

  //serach for city
  for( i = 0; i < N_cities; i++) {
    if(strcmp(arr[i].city_name,cityName)==0){
      flag = 1;
      break;
    }
  }

  if(flag) {
    //shift the array
    for(int j = i; j < N_cities - 1; j++){
      arr[j] = arr[j+1];
    }
    N_cities--;
    return 1;
  }
  else{
    return -1;
  }
}

        