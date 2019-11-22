#pragma once

#ifndef _OBJ_OBSTACLE_
#define _OBJ_OBSTACLE_

#include "Resources.h"
#include "Objects/Obstacle/ObstacleIntf.h"
#include "Objects/Obstacle/ObstacleImpl.h"

const Obstacle DEFAULT_OBSTACLE = {
  POSITION_BOTTOM,
  0, 0,
  NULL,
  NULL,

  _Obstacle_init,
  _Obstacle_update,
  _Obstacle_move,
};

Obstacle createObstacleByPos(int pos, ImageLayer* imageLayer) {
  Obstacle testObstacle = DEFAULT_OBSTACLE;
  imageLayer->imageCount++;
  Image *images = imageLayer->images;
  int imageIndex = imageLayer->imageCount - 1;

  char *fileName = (!pos) ?
    RESOURCE_OBST_BOTTOM[randrange(RESOURCE_OBST_BOTTOM_LEN)] :
    RESOURCE_OBST_TOP[randrange(RESOURCE_OBST_TOP_LEN)];

  images[imageIndex] = (Image) {
    .fileName = fileName,
    .x = 0,
    .y = 0,
    .scale = 1,
    .isShown = false
  };
  // imageLayer.imageCount++;

  testObstacle.image = &images[imageIndex];
  testObstacle.imageLayer = imageLayer;
  testObstacle.init(&testObstacle, pos);
  return testObstacle;
}

#endif