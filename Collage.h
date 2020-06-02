#pragma once
#include"PBM_image.h"
#include"PPM_image.h"
#include"PGM_image.h"
#include"Enum_types.h"
#include<algorithm> //max()

class Collage
{
public:
    static void make_collage(orientation_t, Image*, Image*, string in_outfilename);
};

