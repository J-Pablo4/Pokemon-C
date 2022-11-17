//
// Created by jplop on 14/11/2022.
//

#include "Type.h"

double* get_weakness(Type type1, Type type2) {
    double *weakness = malloc(sizeof(double) * 14);

    switch (type1)
    {
        case water:
        {
            if (type2 == none) {
                double weakness_array[] = {0.5, 1, 1, 2, 1, 0.5, 0.5, 1, 1, 2, 1, 1, 1, 1, 1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if ( type2 == fighting)
            {
                double weakness_array[] = {0.5,0.5,1,2,1,0.5,0.5,1,1,2,2,0.5,1,1,2};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == psychic)
            {
                double weakness_array[] = {0.5, 2, 1, 2, 2, 0.5, 0.5, 0.5, 1, 2, 0.5, 1, 1, 1, 1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == ice)
            {
                double weakness_array[] = {0.5,1,1,2,1,1,0.25,2,1,2,1,2,1,1,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == poison)
            {
                double weakness_array[] = {0.5,0.5,1,2,1,0.5,0.5,0.5,1,1,2,1,2,0.5,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == flying)
            {
                double weakness_array[] = {0.5,0.5,1,4,1,0.5,1,0.5,1,1,1,2,0,1,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case bug:
        {
            if (type2 == none)
            {
                double weakness_array[] = {1,1,1,1,1,2,1,0.5,1,0.5,1,2,0.5,1,2};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == flying)
            {
                double weakness_array[] = {1,0.5,1,2,1,2,2,0.25,1,0.25,1,4,0,1,2};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == poison)
            {
                double weakness_array[] = {1,0.5,1,1,1,2,1,0.25,1,0.25,2,2,1,0.5,2};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == grass)
            {
                double weakness_array[] = {0.5,2,1,0.5,1,4,0.5,1,1,0.25,1,2,0.25,2,4};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case dragon:
        {
            if (type2 == none)
            {
                double weakness_array[] = {0.5,1,2,0.5,1,0.5,2,1,1,0.5,1,1,1,1,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == flying)
            {
                double weakness_array[] = {0.5,0.5,2,1,1,0.5,4,0.5,1,0.25,1,2,0,1,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case electric:
        {
            if (type2 == none)
            {
                double weakness_array[] = {1,1,1,0.5,1,1,1,1,1,1,1,1,2,1,0.5};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == flying)
            {
                double weakness_array[] = {1,0.5,1,1,1,1,2,0.5,1,0.5,1,2,0,1,0.5};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case ghost:
        {
            if(type2 == poison)
            {
                double weakness_array[] = {1,0.25,1,1,2,1,1,0,0,0.5,2,1,2,0.25,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case fire:
        {
            if (type2 == none)
            {
                double weakness_array[] = {2,0.5,1,1,1,0.5,0.5,1,1,0.5,1,2,2,1,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == flying)
            {
                double weakness_array[] = {2,0.25,1,2,1,0.5,1,0.5,1,0.25,1,4,0,1,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case ice:
        {
            if (type2 == psychic)
            {
                double weakness_array[] = {1,2,1,1,2,2,0.5,1,1,1,0.5,2,1,1,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == flying)
            {
                double weakness_array[] = {1,0.5,1,2,1,2,1,1,1,0.5,1,4,0,1,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case fighting:
        {
            double weakness_array[] = {1,0.5,1,1,1,1,1,1,1,1,2,0.5,1,1,2};
            memcpy(weakness, weakness_array, sizeof (double)*15);

            return weakness;
        }
        case normal:
        {
            if (type2 == none)
            {
                double weakness_array[] = {1,1,1,1,0,1,1,2,1,1,1,1,1,1,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == flying)
            {
                double weakness_array[] = {1,0.5,1,2,0,1,2,1,1,0.5,1,2,0,1,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case grass:
        {
            if (type2 == none)
            {
                double weakness_array[] = {0.5,2,1,0.5,1,2,2,1,1,0.5,1,1,0.5,2,2};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == psychic)
            {
                double weakness_array[] = {0.5,4,1,0.5,2,2,2,0.5,1,0.5,0.5,1,0.5,2,2};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == poison)
            {
                double weakness_array[] = {0.5,1,1,0.5,1,2,2,0.5,1,0.25,2,1,1,1,2};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case psychic:
        {
            double weakness_array[] = {1,2,1,1,2,1,1,0.5,1,1,0.5,1,1,1,1};
            memcpy(weakness, weakness_array, sizeof (double)*15);

            return weakness;
        }
        case rock:
        {
            if (type2 == water)
            {
                double weakness_array[] = {1,1,1,2,1,0.25,0.5,2,0.5,4,1,1,2,0.5,0.5};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == ground)
            {
                double weakness_array[] = {4,1,1,0,1,0.5,2,2,0.5,4,1,0.5,2,0.25,0.5};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == flying)
            {
                double weakness_array[] = {2,0.5,1,2,1,0.5,2,1,0.5,1,1,2,0,0.5,0.5};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case ground:
        {
            if (type2 == none)
            {
                double weakness_array[] = {2,1,1,0,1,1,2,1,1,2,1,0.5,1,0.5,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == rock)
            {
                double weakness_array[] = {4,1,1,0,1,0.5,2,2,0.5,4,1,0.5,2,0.25,0.5};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case poison:
        {
            if (type2 == none)
            {
                double weakness_array[] = {1,0.5,1,1,1,1,1,0.5,1,0.5,2,1,2,0.5,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == ground)
            {
                double weakness_array[] = {2,0.5,1,0,1,1,2,0.5,1,1,2,0.5,2,0.25,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == flying)
            {
                double weakness_array[] = {1,0.25,1,2,1,1,2,0.25,1,0.25,2,2,0,0.5,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
            default:
                break;
    }
    return NULL;
}