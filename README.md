#Pokemon-C

##Player
En nuestra libreria de player se define la estructura del jugador principal y enemigos: 
`
struct redPlayer{
    List *pokemons;
    Potion potions[5];
};

struct enemy{
    List *enemyPokemons;
    int defeated;
    char *name;
};
`
A partir de estas estructuras creamos las funciones inicializadoras o constructores de cada una de ellas, ademas definimos los setters y getters necesarios 
para acceder a los atributos de cada una de estas estructuras en otras partes del programa. 

##Type
La libreria type.c es una enciplpedia de los diferentes tipos de pokemones y sus debilidades, 
a partir de un switch y diferentes estructuras selectivas determina el tipo de pokemon de cada uno de estos y les asigna un
arreglo de debilidades, en donde cada espacio corresponde a un tipo de de pokemon y el valor que esta asignado es la debilidad que tiene ante este, 
ademas de esto al final de nuestra funcion tenemos una funcion normalizadora que establece los valores de los atributos de los pokemones a un default. 

##Atacks
En la libreria de ataques se definio la estructura de los ataques: 
`struct attack{
    char *name;
    AttackType attack;
    Type type;
    int power;
    int precision;
    int pp; //Power_Points
    Affected_stat affected_stat;
    int direction;
    int aggregated;
    State state_change;
    int state_probability;
    int BASE_PRECISION;
    int BASE_PP; 
};
`
Una vez realizado esto se definieron los getters y setters necesarios para poder acceder a los atributos de los ataques desde otros archivos, en especial desde la libreria pokemon.c

- Se implemento la funcion init_attack para guardar la memoria correspondiente a los ataques y asignarles sus valores correspondientes que le fueron pasados como argumentos a la funcion
- Se implemento la funcion attack_normalize que regresa los valores de los atributos del ataque que recibe a valores default

##Pokemon
En nuestra libreria de Pokemon tenemos definidas las estructuras de los stats y de los pokemones`
`
typedef struct stats
{
    int level;

    //    Base stats
    int base_hp;
    int base_attack;
    int base_defense;
    int base_speed;
    int base_S_attack;
    int base_S_defense;

    //    Variable stats
    int variable_hp;
    int variable_attack;
    int variable_defense;
    int variable_speed;
    int variable_S_attack;
    int variable_S_defense;

    //    Stats
    int fixed_hp;
    int hp;
    int attack;
    int defense;
    int speed;
    int S_attack;
    int S_defense;
}Stats;

struct pokemon
{
    Type type1;
    Type type2;
    double *weaknesses;
    Stats *stats;
    char *name;
    List *attacks;
    State current_state;
    int alive;
};
`
- Tenemos una funcion inicializadora new_pokemon que a partir de los getters y setters que definimos con anterioridad en type.c accede a las debilidades 
de cada tipo de pokemon y se los asigna a sus correspondientes, ademas de esto define los ataques de cada pokemon y sus defensas, junto con todos los demas stats
que recibe como parametro.
- Tenemos una funcion set_level la cual recupera los stats del pokemon y los define.
- Las funciones que inician con get y modify son setters y getters para acceder a los atributos de los pokemones y definirmos de cierta forma
- Contamos con la funcion pokemon_normalize la cual sirve para regresar los stats de cierto pokemon a los valores por defecto definidos en la misma
- La funcion hit recibe un ataque y a los pokemones implicados, el atacante y el que recibe el ataque y a partir de una comparacion entre un numero aleatorio y la 
precision del atauqe determina si este procede o no, en dado caso de que si porceda, por medio del setter modify_pokemon_hp calcula la cantidad de vida que debe de restar y la asigna al atributo, una vez terminado esto, identifica el estado del ataque y dependiendo de esto se manda a llamar la funcion apply_effect la cual le asigna el efecto al pokemon correspondiente, para terminar, por medio del setter modify_atack_pp disminuye la cantidad de veces que puede utilizar el ataque, debido a que lo acaba de usar. 
- La funcion apply_effect se manda a llamar desde la funcion hit, y dependiendo la probabilidad del estado del ataque y un numero aleatorio determina si 
a un pokemon se le va a aplicar un estado despues de un ataque, ademas define que atributos son alterados y de que forma una vez cambia el estado del pokemon. 
- La funcion init_pokemons abre el archivo donde se escribiran los pokemones y sus ataques, los cuales le son pasados por medio del setter define_attacks
- Las funciones teamPlayerAlive y teamEnemyAlive se encargan de revisar que tanto el jugador como el enemigo tengan pokemones vivos para pelear

##Battle


