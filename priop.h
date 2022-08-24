float awt_priop, att_priop;




void *PRIOp (void *id) 
{
    int n=10,temp[10],t,count=0,short_p;
    float total_WT=0,total_TAT=0,Avg_WT,Avg_TAT;
    int at[30], bt[30], p[30], prio[30], wt[30], tat[30],pt[30], i, j, pc;
    
    FILE *fp;

    fp = fopen("entrada.txt", "r");

    fscanf(fp, "%*[^\n]");  // Read and discard a line

    for(pc=0; pc<10; pc++) fscanf(fp, "%d\t%d\t%d\t%d", &p[pc], &bt[pc], &at[pc], &pt[pc]); //aquisição de dados  
    

    printf("\n\n========================== ESCALONAMENTO PRIOp ============================\n");

    printf("Dados Inseridos\n\n");

    printf("Pi\tTd\tTc\tPrio");
    
    for(i=0; i<n; i++) printf("\n%d\t%d\t%d\t%d", p[i], bt[i], at[i], pt[i]); //printa os dados
            
    //Início da lógica de escalonamento    
    
    
   
    for(int i=0;i<n;i++)
    {
   
        temp[i]=bt[i];
    }
    
    // we initialize the burst time
    // of a process with maximum 
    pt[9]=10000;
    
    for(t=0;count!=n;t++)
    {
        short_p=9;
        for(int i=0;i<n;i++)
        {
            if(pt[short_p]>pt[i] && at[i]<=t && bt[i]>0)
            {
                short_p=i;
            }
        }
        
        bt[short_p]=bt[short_p]-1;
        
        // if any process is completed
        if(bt[short_p]==0)
        {
            // one process is completed
            // so count increases by 1
            count++;
            wt[short_p]=t+1-at[short_p]-temp[short_p];
            tat[short_p]=t+1-at[short_p];
            
            // total calculation
            total_WT=total_WT+wt[short_p];
            total_TAT=total_TAT+tat[short_p];
            
        }
    }
    
    Avg_WT=total_WT/n;
    Avg_TAT=total_TAT/n;
    
    // printing of the answer
    printf("\n\n\nID WT TAT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d %d\t%d\n",i+1,wt[i],tat[i]);
    }
    
    printf("\n\nTempo de espera medio : %f\nTempo de vida medio : %f\n\n",Avg_WT, Avg_TAT);
    
    awt_priop = Avg_WT;
    att_priop = Avg_TAT;
    

    fclose(fp);

   
    printf ("Thread PRIOp Finalizada!\n\n\n\n") ;

    printf("====================================================================\n\n\n");
   
   pthread_exit (NULL) ;
    
    
}