# Pokemon-C

### Es responsabilidad del jugador seleccionar de manera correcta las opciones que se le dan en cada uno de los menus para el correcto funcionamiento del juego

## Player
En nuestra libreria de player se define la estructura del jugador principal y enemigos: 
```
struct redPlayer{
    List *pokemons;
    Potion potions[5];
};

struct enemy{
    List *enemyPokemons;
    int defeated;
    char *name;
};
```
A partir de estas estructuras creamos las funciones inicializadoras o constructores de cada una de ellas, ademas definimos los setters y getters necesarios 
para acceder a los atributos de cada una de estas estructuras en otras partes del programa. 

## Type
La libreria type.c es una enciplpedia de los diferentes tipos de pokemones y sus debilidades, 
a partir de un switch y diferentes estructuras selectivas determina el tipo de pokemon de cada uno de estos y les asigna un
arreglo de debilidades, en donde cada espacio corresponde a un tipo de de pokemon y el valor que esta asignado es la debilidad que tiene ante este, 
ademas de esto al final de nuestra funcion tenemos una funcion normalizadora que establece los valores de los atributos de los pokemones a un default. 

## Atacks
En la libreria de ataques se definio la estructura de los ataques: 

```
struct attack{
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
```
Una vez realizado esto se definieron los getters y setters necesarios para poder acceder a los atributos de los ataques desde otros archivos, en especial desde la libreria pokemon.c

- Se implemento la funcion init_attack para guardar la memoria correspondiente a los ataques y asignarles sus valores correspondientes que le fueron pasados como argumentos a la funcion
- Se implemento la funcion attack_normalize que regresa los valores de los atributos del ataque que recibe a valores default

## Pokemon

En nuestra libreria de Pokemon tenemos definidas las estructuras de los stats y de los pokemones
```
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
```
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

## Battle
- La funcion select_pokemon_for_battle actua como un controlador que manda a llamar las funciones que se ven en pantalla, las cuales
despliegan el menu de pokemones que tiene el jugador, as?? como el menu de posiones y el de ataques disponibles por medio de las siguientes funciones: 
   - fight_menu: Esta funci??n revisa si el pokemon que se selecciono tiene vida para pelear, y si si la tiene
   entonces despliega un menu para decidir si va a seguir peleando o tomara una posion
   - potions_menu: Esta funcion accede a las posiones que el jugador tiene por medio del getterget_player_potions, no sin antes hacer una validacion sobre la existencia de las posiones en el arsenal del jugador, por medio de la funcion potion_exist despues por medio de un switch casedependiendo de la pision que el jugador haya escogido, manda a llamar la funcion pokemon_use_potion y por medio del setter set_player_potion_to_none elimina esa posion del arsenal del jugador
   - select_attack: La siguiente funcion accede a la lista en la que los pokemones y sus ataques se encuentran almacenados y los asigna a los 4 ataques definidos, despues imprime un menu donde accede a los atributos de los atauqes por medio de getters y dependiendo de la eleccion que se realice un switch escoge el ataque a retronar 
   - getEnemyAttack: Hace exactamente lo mismo que la funcion anterior pero escoge el ataque de manera aleatoria 
   - get_random: Funcion trivial para sacar un numero aleatorio  
- potion_exist: Esta funcion accede a las posiones que el jugador tiene por medio de get_player_potions y las recorre por medio de un ciclo for para revisar que al menos haya una
- is_paralysed: Esta funcion define si un pokemon esta paralizado o no y con base a esto define si su ataque puede o no proceder
- is_sleep: Esta funcion define si un pokemon esta dormido o no y con base a esto define si su ataque puede o no proceder
- is_frozen: Esta funcion define si un pokemon esta congelado o no y con base a esto define si su ataque puede o no proceder
- player_move: La funcion player_move determina de acuerdo con el estado del pokemon actual si este tiene o puede atacar o no, esto lo hace por medio de estructuras selectivas que mandan llamar el getter get_pokemon_current_state, el cual accede al estado actual del pokemon y en dado caso de no estar ni congelado, paralizado o recibiendo un ataque, te deja atacar
- battle: La siguiente funcion es la que maneja lo que ocurre en la batalla primero a travez del getter get_enemy_pokemons y get_element saca al pokemon que el enemigo va a usar y lo imprime, seguido de esto manda a llamar a la funcion select_pokemon_for_battle, con la cual el jugador principal va a poder escoger un pokemon y si el jugador tiene pokemones vivos y el enemigo tambien entonces por medio la velocidad de los pokemones es el que ataca primero por medio de la funcion player_move que es la que controla el turno del jugador
