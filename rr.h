float awt_rr, att_rr;

void *RR (void *id) //corpo da thread FCFS
{

   
FILE *fp;

    int a[30], b[30], p[30], prio[30], i, pc, temp[30];
    int wait_time = 0, turnaround_time = 0, total = 0, x=10, counter = 0, time_quantum = 3;
    float awt, att, np=10;

    fp = fopen("entrada.txt", "r");

    fscanf(fp, "%*[^\n]");  // Read and discard a line

    for(pc=0; pc<10; pc++) fscanf(fp, "%d\t%d\t%d\t%d", &p[pc], &b[pc], &a[pc], &prio[pc]); //aquisição de dados  
    

    printf("\n\n========================== ESCALONAMENTO RR ============================\n");

    printf("Dados Inseridos\n\n");

    printf("Pi\tTd\tTc\tPrio");
    
    for(i=0; i<np; i++) 
    {
     printf("\n%d\t%d\t%d\t%d", p[i], b[i], a[i], prio[i]); //printa os dados
     temp[i] = b[i];
    }        
    //Início da lógica de escalonamento    

     printf("\n\n\nPi\tDuracao\t Tempo de Vida\t Tempo de Espera\n");
      for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= time_quantum && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - time_quantum;
                  total = total + time_quantum;
            }
            if(temp[i] == 0 && counter == 1)
            {
                  x--;
                  printf("\n%d\t%d\t\t%d\t\t%d", i + 1, b[i], total - a[i], total - a[i] - b[i]);
                  wait_time = wait_time + total - a[i] - b[i];
                  turnaround_time = turnaround_time + total - a[i];
                  counter = 0;
            }
            if(i == np - 1)
            {
                  i = 0;
            }
            else if(a[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
 
      awt = wait_time * 1.0 / np;
      att = turnaround_time * 1.0 / np;

    awt_rr = awt;
    att_rr = att;



    printf("\n\nTempo de espera medio : %f\nTempo de vida medio : %f\n\n", awt, att);

    fclose(fp);

   
   printf ("Thread RR Finalizada!\n\n\n\n") ;

   printf("====================================================================\n\n\n");
   
   pthread_exit (NULL) ;
}