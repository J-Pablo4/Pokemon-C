//
// Created by jplop on 14/11/2022.
//

#include "Type.h"

/*Esta función identifica el tipo de pokemon y les asigna un arreglo de
 * sus debilidades correspondientes, esto debido a que cada tipo pokemon tiene diferente
 * suceptibilidad contra otros tipos, una vez hecho esto copiamos el arreglo y se lo asignamos con memcpy.
 * Para lograr lo anterior introdujimos una serie de estructuras selectivas dentro de un switch que revisa el tipo de pokemon*/
double* get_weakness(Type type1, Type type2) {
    double *weakness = malloc(sizeof(double) * 14);

    switch (type1)
    {
        case water_type:
        {
            if (type2 == none) {
                double weakness_array[] = {0.5, 1, 1, 2, 1, 0.5, 0.5, 1, 1, 2, 1, 1, 1, 1, 1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if ( type2 == fighting_type)
            {
                double weakness_array[] = {0.5,0.5,1,2,1,0.5,0.5,1,1,2,2,0.5,1,1,2};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == psychic_type)
            {
                double weakness_array[] = {0.5, 2, 1, 2, 2, 0.5, 0.5, 0.5, 1, 2, 0.5, 1, 1, 1, 1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == ice_type)
            {
                double weakness_array[] = {0.5,1,1,2,1,1,0.25,2,1,2,1,2,1,1,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == poison_type)
            {
                double weakness_array[] = {0.5,0.5,1,2,1,0.5,0.5,0.5,1,1,2,1,2,0.5,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == flying_type)
            {
                double weakness_array[] = {0.5,0.5,1,4,1,0.5,1,0.5,1,1,1,2,0,1,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case bug_type:
        {
            if (type2 == none)
            {
                double weakness_array[] = {1,1,1,1,1,2,1,0.5,1,0.5,1,2,0.5,1,2};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == flying_type)
            {
                double weakness_array[] = {1,0.5,1,2,1,2,2,0.25,1,0.25,1,4,0,1,2};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == poison_type)
            {
                double weakness_array[] = {1,0.5,1,1,1,2,1,0.25,1,0.25,2,2,1,0.5,2};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == grass_type)
            {
                double weakness_array[] = {0.5,2,1,0.5,1,4,0.5,1,1,0.25,1,2,0.25,2,4};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case dragon_type:
        {
            if (type2 == none)
            {
                double weakness_array[] = {0.5,1,2,0.5,1,0.5,2,1,1,0.5,1,1,1,1,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == flying_type)
            {
                double weakness_array[] = {0.5,0.5,2,1,1,0.5,4,0.5,1,0.25,1,2,0,1,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case electric_type:
        {
            if (type2 == none)
            {
                double weakness_array[] = {1,1,1,0.5,1,1,1,1,1,1,1,1,2,1,0.5};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == flying_type)
            {
                double weakness_array[] = {1,0.5,1,1,1,1,2,0.5,1,0.5,1,2,0,1,0.5};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case ghost_type:
        {
            if(type2 == poison_type)
            {
                double weakness_array[] = {1,0.25,1,1,2,1,1,0,0,0.5,2,1,2,0.25,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case fire_type:
        {
            if (type2 == none)
            {
                double weakness_array[] = {2,0.5,1,1,1,0.5,0.5,1,1,0.5,1,2,2,1,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == flying_type)
            {
                double weakness_array[] = {2,0.25,1,2,1,0.5,1,0.5,1,0.25,1,4,0,1,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case ice_type:
        {
            if (type2 == psychic_type)
            {
                double weakness_array[] = {1,2,1,1,2,2,0.5,1,1,1,0.5,2,1,1,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == flying_type)
            {
                double weakness_array[] = {1,0.5,1,2,1,2,1,1,1,0.5,1,4,0,1,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case fighting_type:
        {
            double weakness_array[] = {1,0.5,1,1,1,1,1,1,1,1,2,0.5,1,1,2};
            memcpy(weakness, weakness_array, sizeof (double)*15);

            return weakness;
        }
        case normal_type:
        {
            if (type2 == none)
            {
                double weakness_array[] = {1,1,1,1,0,1,1,2,1,1,1,1,1,1,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == flying_type)
            {
                double weakness_array[] = {1,0.5,1,2,0,1,2,1,1,0.5,1,2,0,1,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case grass_type:
        {
            if (type2 == none)
            {
                double weakness_array[] = {0.5,2,1,0.5,1,2,2,1,1,0.5,1,1,0.5,2,2};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == psychic_type)
            {
                double weakness_array[] = {0.5,4,1,0.5,2,2,2,0.5,1,0.5,0.5,1,0.5,2,2};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == poison_type)
            {
                double weakness_array[] = {0.5,1,1,0.5,1,2,2,0.5,1,0.25,2,1,1,1,2};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case psychic_type:
        {
            double weakness_array[] = {1,2,1,1,2,1,1,0.5,1,1,0.5,1,1,1,1};
            memcpy(weakness, weakness_array, sizeof (double)*15);

            return weakness;
        }
        case rock_type:
        {
            if (type2 == water_type)
            {
                double weakness_array[] = {1,1,1,2,1,0.25,0.5,2,0.5,4,1,1,2,0.5,0.5};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == ground_type)
            {
                double weakness_array[] = {4,1,1,0,1,0.5,2,2,0.5,4,1,0.5,2,0.25,0.5};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == flying_type)
            {
                double weakness_array[] = {2,0.5,1,2,1,0.5,2,1,0.5,1,1,2,0,0.5,0.5};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case ground_type:
        {
            if (type2 == none)
            {
                double weakness_array[] = {2,1,1,0,1,1,2,1,1,2,1,0.5,1,0.5,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == rock_type)
            {
                double weakness_array[] = {4,1,1,0,1,0.5,2,2,0.5,4,1,0.5,2,0.25,0.5};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
        }
        case poison_type:
        {
            if (type2 == none)
            {
                double weakness_array[] = {1,0.5,1,1,1,1,1,0.5,1,0.5,2,1,2,0.5,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == ground_type)
            {
                double weakness_array[] = {2,0.5,1,0,1,1,2,0.5,1,1,2,0.5,2,0.25,1};
                memcpy(weakness, weakness_array, sizeof (double)*15);

                return weakness;
            }
            else if (type2 == flying_type)
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