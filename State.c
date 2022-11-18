//
// Created by jplop on 18/11/2022.
//

#include "State.h"

void efecto(Pokemon *pokemon, Attack *attack)
{
    switch (attack->state_change)
    {
        case NORMAL:
        {
            int probabilidad = ThreadLocalRandom.current().nextInt(0, 100 + 1);
            if(probabilidad <= movimiento.PROBA_ESPECIAL)
                if(movimiento.STAT_AFECTADO == Estado.ATAQUE)
                {
                    pokemon.setAtaque(pokemon.getAtaque() + (int)movimiento.agregado);
                }
                else if(movimiento.STAT_AFECTADO == Estado.DEFENSA)
                {
                    pokemon.setDefensa(pokemon.getDefensa() + (int) movimiento.agregado);
                }
                else if(movimiento.STAT_AFECTADO == Estado.ATAQUE_ESP)
                {
                    pokemon.setAtaqueEsp(pokemon.getAtaqueEsp() + (int) movimiento.agregado);
                }
                else if(movimiento.STAT_AFECTADO == Estado.DEFENSA_ESP)
                {
                    pokemon.setDefensaEsp(pokemon.getDefensaEsp() + (int)movimiento.agregado);
                }
                else if(movimiento.STAT_AFECTADO == Estado.VELOCIDAD)
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
            if(pokemon.getEstado() == Estado.NORMAL)
            {
                int probabilidad = ThreadLocalRandom.current().nextInt(0, 100 + 1);
                if(probabilidad <= movimiento.PROBA_ESPECIAL)
                {
                    pokemon.setEstado(PARALIZADO);
                }
            }
        }
        case QUEMADO:
        {
            if(pokemon.getEstado() == Estado.NORMAL)
            {
                int probabilidad = ThreadLocalRandom.current().nextInt(0, 100 + 1);
                if(probabilidad <= movimiento.PROBA_ESPECIAL)
                {
                    pokemon.setEstado(QUEMADO);
                }
            }
        }
        case DORMIDO:
        {
            if(pokemon.getEstado() == Estado.NORMAL)
            {
                int probabilidad = ThreadLocalRandom.current().nextInt(0, 100 + 1);
                if(probabilidad <= movimiento.PROBA_ESPECIAL)
                {
                    pokemon.setEstado(DORMIDO);
                }
            }
        }
        case ENVENENADO:
        {
            if(pokemon.getEstado() == Estado.NORMAL)
            {
                int probabilidad = ThreadLocalRandom.current().nextInt(0, 100 + 1);
                if(probabilidad <= movimiento.PROBA_ESPECIAL)
                {
                    pokemon.setEstado(ENVENENADO);
                }
            }
        }
        case CONFUNDIDO:
        {
            if(pokemon.getEstado() == Estado.NORMAL)
            {
                int probabilidad = ThreadLocalRandom.current().nextInt(0, 100 + 1);
                if(probabilidad <= movimiento.PROBA_ESPECIAL)
                {
                    pokemon.setEstado(CONFUNDIDO);
                }
            }
        }
        case CONGELADO:
        {
            if(pokemon.getEstado() != Estado.NORMAL)
            {
                int probabilidad = ThreadLocalRandom.current().nextInt(0, 100 + 1);
                if(probabilidad <= movimiento.PROBA_ESPECIAL)
                {
                    pokemon.setEstado(CONGELADO);
                }
            }
        }
        case CRITICO:
        {
//				int probabilidad = ThreadLocalRandom.current().nextInt(0, 100 + 1);
//				if(probabilidad <= movimiento.PROBA_ESPECIAL)
//				{
//					pokemon.setEstado(CRITICO);
//				}

        }
        case RETROCEDER:
        {

//				int probabilidad = ThreadLocalRandom.current().nextInt(0, 100 + 1);
//				if(probabilidad <= movimiento.PROBA_ESPECIAL)
//				{
//					pokemon.setEstado(RETROCEDER);
//				}

        }
    }
}
public static void efecto(Pokemon pokemonAtaque, Pokemon pokemonEfecto, Movimiento movimiento)
{
    if(movimiento == Movimiento.ABSORBER)
    {
        int agregado = (int)(pokemonEfecto.getDanio(movimiento,pokemonAtaque)*.5);
        pokemonAtaque.setPs(pokemonAtaque.getStatPs() + agregado);
        if(pokemonAtaque.getStatPs() > pokemonAtaque.getPs())
            pokemonAtaque.setPs(pokemonAtaque.getPs());
    }
    else if(movimiento == Movimiento.AUTODESTRUCCION)
    {
        pokemonAtaque.setPs(0);
    }
    else if(movimiento == Movimiento.SUMISION || movimiento == Movimiento.DERRIBO || movimiento == Movimiento.DOBLE_FILO)
    {
        int agregado = (int)(pokemonEfecto.getDanio(movimiento,pokemonAtaque)*.25);
        pokemonAtaque.setPs(pokemonAtaque.getStatPs() - agregado);
    }
    else if(movimiento == Movimiento.DESCANSO)
    {
        pokemonAtaque.setPs(pokemonAtaque.getPs());
    }
}