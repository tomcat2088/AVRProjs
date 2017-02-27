//
// Created by wangyang on 17/2/27.
//

#include "Graphics.h"

bool Graphics::pointOnLine(Point point, Line line) {
    float xScale = (line.end.x - point.x) / (point.x - line.start.x);
    float yScale = (line.end.y - point.y) / (point.y - line.start.y);
    float delta = yScale - xScale;
    if (xScale >= 0 && yScale >= 0 && delta < 0.0001 && delta > -0.0001) {
        return true;
    }
    return false;
}