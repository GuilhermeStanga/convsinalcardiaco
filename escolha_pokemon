#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


typedef struct Habilidade{//bloquinho das habilidades
    char nome[20];
    int forca;
    struct Habilidade *proxim;
}Habilidade;


typedef struct PokemonAtaque{// bloquinho pokemons
    char nome[20];
    struct Habilidade *habilidade;
    struct Habilidade *fim_habilidade;
    struct PokemonAtaque *prox;
}PokemonAtaque;

typedef struct{
    struct PokemonAtaque *Inicio;//lista do começo
    struct PokemonAtaque *Fim;
    int quantidade;
}Pokemons;

Pokemons ListaPoke;

void inicializapokemon(Pokemons *x){
    x->Inicio=NULL;
    x->Fim=NULL;
    x->quantidade=0;
}

void adicionarpokemon( char *pokeAtaque){

    PokemonAtaque *newPoke = (PokemonAtaque*) malloc(sizeof(PokemonAtaque));
    strcpy(newPoke->nome,pokeAtaque);
    newPoke->habilidade=NULL;
    newPoke->fim_habilidade=NULL;

    if(ListaPoke.Inicio==NULL) ListaPoke.Inicio=newPoke;
    else ListaPoke.Fim->prox=newPoke;
    ListaPoke.Fim = newPoke;
    newPoke->prox = NULL;
    ListaPoke.quantidade++;

}

void adicionarataques(char *nom, char *dan){

    Habilidade *newhabilidade = ( Habilidade*) malloc(sizeof(Habilidade));
    strcpy(newhabilidade->nome,nom);
    newhabilidade->forca=atoi(dan);

    if(ListaPoke.Fim->habilidade==NULL) ListaPoke.Fim->habilidade = newhabilidade;
    else ListaPoke.Fim->fim_habilidade->proxim=newhabilidade;
    ListaPoke.Fim->fim_habilidade=newhabilidade;
    newhabilidade->proxim=NULL;
}

main(){
    inicializapokemon (&ListaPoke);
    PokemonAtaque *aux;
    Habilidade *aux_hab;
    char pokemon[20];
    char nometaque[20];
    int guardatak=0;
    int ehesse;


    char nomepokemon[20];
    char nomeataque[20];
    char danoataque[10];
    int i,atakinimigo;

    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        getchar();
        scanf("%s",nomepokemon);
        //adcinar na lista de pokemon pikachu
        adicionarpokemon(nomepokemon);
        scanf("%s",nomeataque);// para eliminar o [
        while(1){
            scanf("%s",nomeataque);
            if(strcmp(nomeataque,"]")==0) break;
            scanf("%s",danoataque); //<- mudar para inteiro
            //adicionar os ataques dos pokemons
            adicionarataques(nomeataque,danoataque);
        }
    }
    char atak_final[20];

    while(1){
        getchar();
        scanf("%s",nomepokemon);
        if(strcmp(nomepokemon,"FIM")==0) break;
        scanf("%s",nomepokemon);
        while(1){
            scanf("%s",nomeataque);
            if(strcmp(nomeataque,"]")==0) break;
            scanf("%s",danoataque);
            atakinimigo=atoi(danoataque);

            aux = ListaPoke.Inicio;
            while(aux!=NULL){
                aux_hab = aux->habilidade;
                while(aux_hab!=NULL){
                    if(strcmp(aux_hab->nome,nomeataque)==0){
                        if(aux_hab->forca*atakinimigo>guardatak){
                            guardatak=aux_hab->forca*atakinimigo;
                            strcpy(pokemon,aux->nome);
                                                             //nome do seu prokemon
                            strcpy(atak_final, aux_hab->nome);

                            //100 dividido melho atak arredonda pra cima
                        }
                    }
                    aux_hab=aux_hab->proxim; // pula proxima habilidade
                }

                aux=aux->prox;// pula pr
            }

        }
        atak_final[strlen(atak_final)-1]='\0';
        double conta;
        conta = 100.0/guardatak;
        if(conta-(int)conta>0) conta = (int)conta+1;
        printf("%s %s %d\n",pokemon,atak_final,(int)conta);
        guardatak=0;
        atakinimigo=0;
    }
}
