//
// Created by jplop on 18/11/2022.
//

#include "State.h"

void effect(Pokemon *pokemon, Attack *attack)
{
    time_t t;
    srand((unsigned) time(&t));
    int probability = (rand() % 100);

    if(probability <= get_attack_state_probability(attack))
    {
        switch (get_attack_state_change(attack))
        {
            case normal_state:
            {
                if(get_attack_affected_stat(attack) == attack_affected_stat)
                {
                    modify_pokemon_attack(get_pokemon_attack(pokemon) + get_attack_aggregated(attack), pokemon);
                }
                else if(get_attack_affected_stat(attack) == defense_affected_stat)
                {
                    modify_pokemon_defense(get_pokemon_defense(pokemon) + get_attack_aggregated(attack), pokemon);
                }
                else if(get_attack_affected_stat(attack) == S_attack_affected_stat)
                {
                    modify_pokemon_S_attack(get_pokemon_S_attack(pokemon) + get_attack_aggregated(attack), pokemon);
                }
                else if(get_attack_affected_stat(attack) == S_defense_affected_stat)
                {
                    modify_pokemon_S_defense(get_pokemon_S_defense(pokemon) + get_attack_aggregated(attack), pokemon);
                }
                else if(get_attack_affected_stat(attack) == speed_affected_stat)
                {

                    pokemon.setVelocidad(pokemon.getDefensa() + (int)movimiento.agregado);
                }
                else if(movimiento.STAT_AFECTADO == Estado.PS)
                {

                    if(movimiento.agregado != -1000)
                    {
                        pokemon.setPs(pokemon.getStatPs() + (int)movimiento.agregado);
                    }

                }
                else
                {
                    for(int i = 0; 1 < 4; i++)
                    {
                        if(pokemon.getMovimiento(i) == null)
                            continue;
                        if(pokemon.getMovimiento(i).getPresicion() == -100)
                            continue;
                        pokemon.getMovimiento(i).setPresicion((int)(pokemon.getMovimiento(i).getPresicion() * movimiento.agregado));
                    }
                }
            }
            case PARALIZADO:
            {
                if(pokemon.getEstado() == Estado.normal_state)
                {
                    int probabilidad = ThreadLocalRandom.current().nextInt(0, 100 + 1);
                    if(probabilidad <= movimiento.get_stat_probability)
                    {
                        pokemon.setEstado(PARALIZADO);
                    }
                }
            }
            case QUEMADO:
            {
                if(pokemon.getEstado() == Estado.normal_state)
                {
                    int probabilidad = ThreadLocalRandom.current().nextInt(0, 100 + 1);
                    if(probabilidad <= movimiento.get_stat_probability)
                    {
                        pokemon.setEstado(QUEMADO);
                    }
                }
            }
            case DORMIDO:
            {
                if(pokemon.getEstado() == Estado.normal_state)
                {
                    int probabilidad = ThreadLocalRandom.current().nextInt(0, 100 + 1);
                    if(probabilidad <= movimiento.get_stat_probability)
                    {
                        pokemon.setEstado(DORMIDO);
                    }
                }
            }
            case ENVENENADO:
            {
                if(pokemon.getEstado() == Estado.normal_state)
                {
                    int probabilidad = ThreadLocalRandom.current().nextInt(0, 100 + 1);
                    if(probabilidad <= movimiento.get_stat_probability)
                    {
                        pokemon.setEstado(ENVENENADO);
                    }
                }
            }
            case CONFUNDIDO:
            {
                if(pokemon.getEstado() == Estado.normal_state)
                {
                    int probabilidad = ThreadLocalRandom.current().nextInt(0, 100 + 1);
                    if(probabilidad <= movimiento.get_stat_probability)
                    {
                        pokemon.setEstado(CONFUNDIDO);
                    }
                }
            }
            case CONGELADO:
            {
                if(pokemon.getEstado() != Estado.normal_state)
                {
                    int probabilidad = ThreadLocalRandom.current().nextInt(0, 100 + 1);
                    if(probabilidad <= movimiento.get_stat_probability)
                    {
                        pokemon.setEstado(CONGELADO);
                    }
                }
            }
            case CRITICO:
            {
//				int probabilidad = ThreadLocalRandom.current().nextInt(0, 100 + 1);
//				if(probabilidad <= movimiento.get_stat_probability)
//				{
//					pokemon.setEstado(CRITICO);
//				}

            }
            case RETROCEDER:
            {

//				int probabilidad = ThreadLocalRandom.current().nextInt(0, 100 + 1);
//				if(probabilidad <= movimiento.get_stat_probability)
//				{
//					pokemon.setEstado(RETROCEDER);
//				}

            }
        }
    }
}