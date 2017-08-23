#include "Organizer.h"


void hlp(){

  printf("\nThere are three modes to choose from:\n");
  printf("=====================================\n\n");
  printf("1) File Mode\n   ---------\n");
    printf(" ./mediaOrganizer /path/media.file /path/to/store/folder\n\n");

  printf("2) Folder Mode\n   -----------\n");
    printf(" ./mediaOrganizer /source/path/folder /path/to/store/folder\n\n");

  printf("3) Duplication Cleaning Mode\n   -------------------------\n");
    printf(" ./mediaOrganizer -dup /source/path/folder\n\n");

  printf("Flags:\n======\n\n");
  printf(" Category\n --------\n");
  printf(" -photos: for photo organization only.\n");
  printf(" -video:  for video organization only.\n\n");

  printf(" File type\n ---------\n");
  printf(" -jpg:    for jpg organization only.\n");
  printf(" -png:    for png organization only.\n");
  printf(" -avi:    for avi organization only.\n");
  printf(" -mov:    for mov organization only.\n");
  printf(" -wmv:    for wmv organization only.\n");
  printf(" -mp4:    for mp4 organization only.\n");
  printf(" -mts:    for mts organization only.\n\n");

  printf(" Informative\n -----------\n");
  printf(" -hlp:    for the Media Organizer User Guide.\n"); 
  printf(" -vrs:    for version information.\n"); 
  printf(" -det:    for a detailed list of executions in a\n");
  printf("           txt format ( detailedTransfer.txt ).\n\n");  

  printf(" Mode\n ----\n");
  printf(" -dup:    for deletion of duplicates with similar names. (fast)\n"); 
  printf(" -dux:    for deletion of duplicates with diffrent names. (slow)\n"); 
  printf(" -del:    for deletion of source files.\n\n"); 

  printf("( Using multiple flags will enhance your selection. \n");
  printf("  flags can be inserted anywhere, but the paths \n");
  printf("  to are always source and destination paths. ) \n\n" ACRE);

}

int main(int argc, char *argv[]) {

int arg[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int *argp = arg;
char *sourcePath = NULL, *destPath = NULL, *filePath = NULL;  

if(argc == 2 && !strcmp(argv[1], "-hlp")){
  hlp();
  return 1;

}else if(argc == 2 && !strcmp(argv[1], "-vrs")){
  printf("Media Organiser Version: 1.7.0\n");;
  printf("A project by Keybraker (https://github.com/keybraker)\n");
  printf("GNU License: https://www.gnu.org/philosophy/free-sw.html\n\n");;
  printf("Copyrights © Keybraker 2017, All rights reserved\n");;
  return 1;

}else if(argc > 2){

  for(int i = 1; i < argc; i++){
    
    if(!strcmp(argv[i], "-jpg")){ 
      arg[0] = 1; 

    }else if(!strcmp(argv[i], "-png")){ 
      arg[1] = 1;

    }else if(!strcmp(argv[i], "-avi")){
     arg[2] = 1;

    }else if(!strcmp(argv[i], "-mov")){ 
      arg[3] = 1;

    }else if(!strcmp(argv[i], "-wmv")){ 
      arg[4] = 1;

    }else if(!strcmp(argv[i], "-mp4")){ 
      arg[5] = 1;

    }else if(!strcmp(argv[i], "-mts")){
      arg[6] = 1;

    }else if(!strcmp(argv[i], "-det")){ 
      arg[7] = 1;

    }else if(!strcmp(argv[i], "-photo")){ 
      arg[8] = 1;

    }else if(!strcmp(argv[i], "-video")){ 
      arg[9] = 1;

    }else if(!strcmp(argv[i], "-dup")){ 
      arg[10] = 1;

    }else if(!strcmp(argv[i], "-dux")){ 
      arg[12] = 1;

    }else if(!strcmp(argv[i], "-hlp")){
      hlp();
      return -1;

    }else if(!strcmp(argv[i], "-del")){
      arg[11] = 1;

    }else if(!strcmp(argv[i], "-vrs")){
      printf("Media Organiser Version: 1.7.0\n");;
      printf("A project by Keybraker (https://github.com/keybraker)\n");
      printf("GNU License: https://www.gnu.org/philosophy/free-sw.html\n\n");;
      printf("Copyrights © Keybraker 2017, All rights reserved\n");;
      return 1;

    }else if(argv[i][0] == '-'){
      printf(ACR "%s: is an unrecognizable argument.\n", argv[i]);
      printf("Please consider using one of the following:\n\n");
      printf(" Category\n --------\n");
      printf(" -photos: for photo organization only.\n");
      printf(" -video:  for video organization only.\n\n");

      printf(" File type\n ---------\n");
      printf(" -jpg:    for jpg organization only.\n");
      printf(" -png:    for png organization only.\n");
      printf(" -avi:    for avi organization only.\n");
      printf(" -mov:    for mov organization only.\n");
      printf(" -wmv:    for wmv organization only.\n");
      printf(" -mp4:    for mp4 organization only.\n");
      printf(" -mts:    for mts organization only.\n\n");

      printf(" Informative\n -----------\n"); 
      printf(" -hlp:    for the Media Organizer User Guide.\n"); 
      printf(" -vrs:    for version information.\n"); 
      printf(" -det:    for a detailed list of executions in a\n");
      printf("           txt format ( detailedTransfer.txt ).\n\n"); 

      printf(" Mode\n ----\n");
      printf(" -dup:    for deletion of duplicates with diffrent names.\n");   
      printf(" -dux:    for deletion of duplicates with diffrent names. (slow)\n"); 
      printf(" -del:    for deletion of source files.\n\n"); 

      printf("( Using multiple flags will enhance your selection.\n");
      printf("  flags can be inserted anywhere, but the paths\n");
      printf("  to are always source and destination paths. )\n" ACRE);

    }else{

      if(isFile(argv[i])){ 

        if(sourcePath == NULL && filePath == NULL){
          filePath = (char *) malloc (32768 * sizeof(char));
          filePath = argv[i];

        }else{
          printf(ACR "Media Organizer Usage Guide:\n");
          printf(" ./mediaOrganizer /path/media.file /path/to/store/folder\n");
          printf(" ./mediaOrganizer /source/path/folder /path/to/store/folder\n");
          printf(" for more information use -hlp\n" ACRE);
          return -1;

        }

      }else if(!isFile(argv[i])){ 

        if(sourcePath == NULL && filePath == NULL){ 
          sourcePath = (char *) malloc (32768 * sizeof(char));
          sourcePath = argv[i];

        }else if(sourcePath != NULL || filePath != NULL ){ 
          destPath = (char *) malloc (32768 * sizeof(char));
          destPath = argv[i];

        }else{
          printf(ACR "Media Organizer Usage Guide:\n");
          printf(" ./mediaOrganizer /path/media.file /path/to/store/folder\n");
          printf(" ./mediaOrganizer /source/path/folder /path/to/store/folder\n");
          printf(" for more information use -hlp\n" ACRE);
          return -1;

        }

      }

    }

  }

}else {
  printf(ACR "Media Organizer Usage Guide:\n");
  printf(" ./mediaOrganizer /path/media.file /path/to/store/folder\n");
  printf(" ./mediaOrganizer /source/path/folder /path/to/store/folder\n");
  printf(" for more information use -hlp\n" ACRE);
  return -1;

}
  
int sum = 0;
for(int i = 0; i < 11; i++){ if(arg[i] == 1)   sum += arg[i]; }
  if(arg[10] == 1 && sum != arg[10]){
  printf(ACR "-dup can only be used solely, with a directory not file.\n" ACRE);
  return -1;

}

if(filePath != NULL && sourcePath == NULL && destPath != NULL ){ // file version initiation
  if(isFile(filePath) == 1){
    if(isDir(destPath) == 1){
      clock_t t1 = clock(); 
      fileVersion(filePath, destPath);
      clock_t t2 = clock(); 
      float diff = ((float)(t2 - t1) / 1000000.0F ) * 1000; 
      printf(ACY "\r[%-5f%-9s]\n" ACRE, diff, " millisecs");

    }else{
      printf(ACR "%s is not a path to a folder.\n\n", destPath);
      printf("Media Organizer Usage Guide:\n");
      printf(" ./mediaOrganizer /path/media.file /path/to/store/folder\n");
      printf(" ./mediaOrganizer /source/path/folder /path/to/store/folder\n");
      printf(" for more information use -hlp\n" ACRE);
      return -1;

    }

  }else{
    printf(ACR "%s is not a path to a file.\n\n", filePath);
    printf("Media Organizer Usage Guide:\n");
    printf(" ./mediaOrganizer /path/media.file /path/to/store/folder\n");
    printf(" ./mediaOrganizer /source/path/folder /path/to/store/folder\n");
    printf(" for more information use -hlp\n" ACRE);
    return -1;

  }

}else if(filePath == NULL && sourcePath != NULL && destPath != NULL){ // folder version initiation
  if(isDir(sourcePath) == 1){
    if(isDir(destPath) == 1){
      clock_t t1 = clock(); 
      folderVersion(sourcePath, destPath, argp); 
      clock_t t2 = clock(); 
      float diff = ((float)(t2 - t1) / 1000000.0F ) * 1000; 
      printf(ACY "\r[%-5f%-9s]\n" ACRE, diff, " millisecs");

    }else{
      printf(ACR "%s is not a path to a folder.\n\n", destPath);
      printf("Media Organizer Usage Guide:\n");
      printf(" ./mediaOrganizer /path/media.file /path/to/store/folder\n");
      printf(" ./mediaOrganizer /source/path/folder /path/to/store/folder\n");
      printf(" for more information use -hlp\n" ACRE);
      return -1;

    }

  }else{
    printf(ACR "%s is not a path to a folder.\n\n", sourcePath);
    printf("Media Organizer Usage Guide:\n");
    printf(" ./mediaOrganizer /path/media.file /path/to/store/folder\n");
    printf(" ./mediaOrganizer /source/path/folder /path/to/store/folder\n");
    printf(" for more information use -hlp\n" ACRE);
    return -1;

  }

}else if(filePath == NULL && sourcePath != NULL && destPath == NULL && arg[10] == 1){ // duplicate version initiation
  printf(ACG "# DUPLICATE MODE NORMAL\n\n");
  printf(ACR "DISCLAIMER: USE WITH CAUTION! PLEASE BACKUP ALL YOUR FILES \n");
  printf("BEFORE PROCCEDING TO CLEANUP DUPLICATES\n");
  printf("=======================================\n");
  printf("THIS MODE LOOKS UP EVERY FILE IN A DIRECTORY\n");
  printf("AND COMPARES THE EXIF DATA TO ALL THE OTHERS.\n");
  printf("IF A FILE IS FOUND THAT HAS THE SAME EXIF AND\n");
  printf("THEIR NAME IS THE SAME EXCEPT FOR A SLIGHT\n");
  printf("VARIATION LIKE 'IMG.JPG' AND 'IMG (2).JPG', THE\n");
  printf("PHOTO WITH THE LONGER NAME WILL BE DELETED.\n");
  printf("THERE IS A SLIGHT CHANCE THAT THE ALGORITHM MAY,\n");
  printf("DELETE A WRONG FILE BUT THE CHANCES ARE MINIMAL TO NONE. \n\n" ACRE);

  string answer;
  cout << "Proceed on your own risk (y/n): ";
  cin  >> answer;

  if(answer.compare("y") == 0){
    duplicateVersion(sourcePath, 0);

  }

}else if(filePath == NULL && sourcePath != NULL && destPath == NULL && arg[12] == 1){ // duplicate Xtreme version initiation
  printf(ACG "# DUPLICATE MODE EXTREME\n\n");
  printf(ACR "DISCLAIMER: USE WITH CAUTION! PLEASE BACKUP ALL YOUR FILES \n");
  printf("BEFORE PROCCEDING TO CLEANUP DUPLICATES\n");
  printf("=======================================\n");
  
  printf("THIS MODE LOOKS UP EVERY FILE IN A DIRECTORY\n");
  printf("AND COMPARES THE EXIF DATA TO ALL THE OTHERS.\n");
  printf("IF A FILE IS FOUND THAT HAS THE SAME EXIF AND\n");
  printf("THEIR NAME IS THE SAME EXCEPT FOR A SLIGHT\n");
  printf("VARIATION LIKE 'IMG.JPG' AND 'IMG (2).JPG', THE\n");
  printf("PHOTO WITH THE LONGER NAME WILL BE DELETED.\n");
  printf("THERE IS A SLIGHT CHANCE THAT THE ALGORITHM MAY,\n");
  printf("DELETE A WRONG FILE BUT THE CHANCES ARE MINIMAL TO NONE. \n\n" ACRE);

  string answer;
  cout << "Proceed on your own risk (y/n): ";
  cin  >> answer;

  if(answer.compare("y") == 0){
    duplicateVersion(sourcePath, 1);
  }

}else{
  printf(ACR "Media Organizer Usage Guide:\n");
  printf(" ./mediaOrganizer /path/media.file /path/to/store/folder\n");
  printf(" ./mediaOrganizer /source/path/folder /path/to/store/folder\n");
  printf(" for more information use -hlp\n" ACRE);
  return -1;

}

return 1;

}
