float awt_fcfs, att_fcfs;


void *FCFS (void *id) //corpo da thread FCFS
{

   
FILE *fp;

    int a[30], b[30], p[30], prio[30], i, j, pc, ttotal=0, tt[30], wt[30], ex[30], wtotal=0;
    float awt, att, np=10;

    fp = fopen("entrada.txt", "r");

    fscanf(fp, "%*[^\n]");  // Read and discard a line

    for(pc=0; pc<10; pc++) fscanf(fp, "%d\t%d\t%d\t%d", &p[pc], &b[pc], &a[pc], &prio[pc]); //aquisição de dados  
    

    printf("\n\n========================== ESCALONAMENTO FCFS ============================\n");

    printf("Dados Inseridos\n\n");

    printf("Pi\tTd\tTc\tPrio");
    
    for(i=0; i<np; i++) printf("\n%d\t%d\t%d\t%d", p[i], b[i], a[i], prio[i]); //printa os dados
            
    //Início da lógica de escalonamento    

    for(i=0; i<np-1; i++) {
        for(j=i+1; j<np; j++) {
            int t1, t2, t3, t4;
            if(a[i]>a[j]) {
                t1 = a[i];
                t2 = b[i];
                t3 = p[i];
                t4 = prio[i];

                a[i] = a[j];
                b[i] = b[j];
                p[i] = p[j];
                prio[i] = prio[j];

                a[j] = t1;
                b[j] = t2;
                p[j] = t3;
                prio[j] = t4;
            }
        }
    }

    printf("\n\n\nPi\tTEMPO DE EXECUÇÃO");

    if(a[0]!=0) {
        printf("[x]\t1");
    }

    ex[0] = a[0];
    printf("\n%d\t\t%d", p[0], a[0]);

    for(i=1; i<np; i++) {
        if(a[i]>(ex[i-1]+b[i-1])) {
            printf("\n%d\t\t%d", p[i], a[i]);
            ex[i] = a[i];
        }
        else {
            ex[i] = ex[i-1]+b[i-1];
            printf("\n%d\t\t%d\t", p[i], ex[i]);
        }
    }

    for(i=0; i<np; i++) {
        wt[0]=0;
        wt[i+1] = (ex[i]-a[i]);
        wtotal=wtotal+wt[i+1];
        tt[i] = (ex[i]-a[i])+b[i];
        ttotal = ttotal + (ex[i]-a[i])+b[i];
    }

    printf("\n\n\nPi\tTEMPO DE ESPERA\tTEMPO DE VIDA");

    for(i=0; i<np; i++) {    
        
            printf("\n%d\t%d\t\t\t%d", p[i], wt[i+1], tt[i]);
            
        }

    awt = (float)wtotal/np;
    att = (float)ttotal/np;

    awt_fcfs = awt;
    att_fcfs = att;



    printf("\n\nTempo de espera medio : %f\nTempo de vida medio : %f\n\n", awt, att);

    fclose(fp);

   
    printf ("Thread FCFS Finalizada!\n\n\n\n") ;

     printf("====================================================================\n\n\n");
   
   pthread_exit (NULL) ;
}
