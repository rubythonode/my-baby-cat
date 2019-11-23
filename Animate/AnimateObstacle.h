﻿#pragma once

#ifndef _ANIMATE_OBST_
#define _ANIMATE_OBST_

#include <Windows.h>
#include "Animate/Animate.h"
#include "Objects/Cat/Cat.h"
#include "Objects/Obstacle/Obstacle.h"
#include "ImageLayer/ImageLayer.h"

Obstacle *(*ObstacleSegmentPointer)[] = NULL;
int _animateObstacleSegments_shown = 0;

void animateObstacleSegments(AnimateProps* animateProps) {
  Cat *cat = animateProps->cat;
  int obstacleLength = animateProps->objectLength;
  while (1) {
    for (int idx = 0; idx < obstacleLength; idx++) {
      Obstacle *currentObstacle = (*ObstacleSegmentPointer)[idx];

      if (currentObstacle->x <= 200) { // 플레이어와 만남
        Image *image = currentObstacle->image;
        if (image->isShown) {
          image->isShown = false;

          if (cat->y >= 450) { // 부딧힘
            MessageBox(NULL, "아야", "", MB_OK);
            exit(0);
          }
        }
      } else {
        currentObstacle->move(currentObstacle, 20);
        if (currentObstacle->x <= 1500) {
          _animateObstacleSegments_shown++;
        }
      }
      Sleep(SPEED.delay / 1.5);
    }
  }
}

#endif
