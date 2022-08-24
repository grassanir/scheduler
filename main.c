#include <pthread.h>
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include "fcfs.h"
#include "rr.h"
#include "sjf.h"
#include "srtf.h"
#include "prioc.h"
#include "priop.h"
#include "imprime.h"


int main()
{


    pthread_t p[6];
    int continuar, i;
    

        printf("\n\nMenu de opções de escalonamento\n");
        printf("1. Executar todos em Threads\n");
        printf("2. First Come First Served\n");
        printf("3. Round Robin\n");
        printf("4. Shortest Job First\n");
        printf("5. Shortest Remaining Time First\n");
        printf("6. Escalonamento por prioridades Fixas Cooperativo\n");
        printf("7. Escalonamento por prioridades Fixas Preemptivo\n");
        printf("0. Sair\n");

        scanf("%d", &continuar);
        system("clear");

        switch(continuar)
        {
            case 1:
                
                printf("Executando todas as threads\n");
                
                    pthread_create(&p[0], NULL, FCFS, (void *)0);
                    pthread_create(&p[1], NULL, RR, (void*)1);
                    pthread_create(&p[2], NULL, SJF, (void*)2);
                    pthread_create(&p[3], NULL, SRTF, (void*)3);
                    pthread_create(&p[4], NULL, PRIOc, (void*)4);
                    pthread_create(&p[5], NULL, PRIOp, (void*)5);
                    

                    for(i=0;i<6;i++)
                    {
                    pthread_join(p[i], NULL);
                    }

                    imprimeResultados();
             
                break;

            case 2:
                
                pthread_create(&p[0], NULL, FCFS, (void*)0);
                pthread_exit(NULL);
                break;
                
            case 3:
        
               
                pthread_create(&p[1], NULL, RR, (void*)1);
                pthread_exit(NULL);
                
                break;

            case 4:
                
                pthread_create(&p[2], NULL, SJF, (void*)2);
                pthread_exit(NULL);
                
                break;
                
            case 5:
                
                pthread_create(&p[3], NULL, SRTF, (void*)3);
                pthread_exit(NULL);
                
                break;
                
            case 6:
                
                pthread_create(&p[4], NULL, PRIOc, (void*)4);
                pthread_exit(NULL);
                
                break;
                
            case 7:
                
                pthread_create(&p[5], NULL, PRIOp, (void*)5);
                pthread_exit(NULL);
                
                break;
                
            case 0:
                return 0;
                break;

            default:
                printf("Digite uma opcao valida\n");
        }


}
  
