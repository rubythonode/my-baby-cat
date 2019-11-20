#pragma once

#ifndef _RESOURCES_
#define _RESOURCES_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESOURCE_CAT_LEN 8
#define RESOURCE_FISH_LEN 1
#define RESOURCE_BACKGROUND_LEN 1

char** RESOURCE_CAT[RESOURCE_CAT_LEN];
char** RESOURCE_FISH[RESOURCE_FISH_LEN];
char** RESOURCE_BACKGROUND[RESOURCE_BACKGROUND_LEN];

char **loadResources(int resourceLength, char* formatString) {
  int **resourceList = malloc(resourceLength * sizeof(char *));
  for (int idx = 1; idx <= resourceLength; idx++) {
    char filename[100];
    sprintf(filename, formatString, idx);
    int len = strlen(filename) + 1;
    (*resourceList)[idx - 1] = (char*)malloc(sizeof(char) * len);
    strcpy((*resourceList)[idx - 1], filename);
  }
}

inline void updateResources() {
  // TODO: Abstraction needed!!!

  // export cat resources to array automatically
  // for (int idx = 1; idx <= RESOURCE_CAT_LEN; idx++) {
  //   char filename[100];
  //   sprintf(filename, "resources/cat/cat-p%d.bmp", idx);
  //   int len = strlen(filename) + 1;
  //   RESOURCE_CAT[idx - 1] = (char*)malloc(sizeof(char) * len);
  //   strcpy(RESOURCE_CAT[idx - 1], filename);
  // }
  // loadResources(&RESOURCE_CAT, RESOURCE_CAT_LEN, "resources/cat/cat-p%d.bmp");

  // export fish resources to array automatically
  // for (int idx = 1; idx <= RESOURCE_FISH_LEN; idx++) {
  //   char filename[100];
  //   sprintf(filename, "resources/fish/fish-lv%d.bmp", idx);
  //   int len = strlen(filename) + 1;
  //   RESOURCE_FISH[idx - 1] = (char*)malloc(sizeof(char) * len);
  //   strcpy(RESOURCE_FISH[idx - 1], filename);
  // }

  // // export background stages
  // for (int idx = 1; idx <= RESOURCE_BACKGROUND_LEN; idx++) {
  //   char filename[100];
  //   sprintf(filename, "resources/background/background-st%d.bmp", idx);
  //   int len = strlen(filename) + 1;
  //   RESOURCE_BACKGROUND[idx - 1] = (char*)malloc(sizeof(char) * len);
  //   strcpy(RESOURCE_BACKGROUND[idx - 1], filename);
  // }
  **RESOURCE_CAT = loadResources(RESOURCE_CAT_LEN, "resources/cat/cat-p%d.bmp");
  // char **RESOURCE_FISH[RESOURCE_FISH_LEN];
  // char **RESOURCE_BACKGROUND[RESOURCE_BACKGROUND_LEN];
}

#endif
