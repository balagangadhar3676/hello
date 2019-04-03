#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <json-c/json.h> 

int main (int argc, char** argv) 
{

   

	 FILE* file = NULL;
  int filesize;
  const int blocksize = 1;
  size_t readsize;
  char *str;

  // Open the file
  file = fopen(argv[1], "r");
  if (NULL == file)
  {
    printf("file not created");
    exit(EXIT_FAILURE);
  }

  // Determine the file size
  fseek(file, 0, SEEK_END);
  filesize = ftell(file);
  rewind (file);

   str= (char*) malloc(sizeof(char) * filesize);



  printf("file size=%d\n",filesize);

  while(fgets(str,80,file)!=NULL)
	 puts(str);
                   
     char *ptr=str;
      json_object * jobj = json_tokener_parse(ptr);
     printf ("The json object created: %s\n",json_object_to_json_string(jobj));


  // Clean exit
  fclose(file);
  return EXIT_SUCCESS;
}
