float awt_prioc, att_prioc;

void *PRIOc (void *id) //corpo da thread FCFS
{
    
    int pn = 10;                 //Processes Number
    int CPU = 0;            //CPU Current time
    int allTime = 0;        // Time neded to finish all processes
    int AT[20];
    int ATt[20];
    int NoP = pn;
    int PT[20];             //Processes Time
    int PP[20];             //Processes piriorty
    int PPt[20];
    int paux[20];
    int p[30];
    int waittingTime[20];
    int turnaroundTime[20];
    int i=0;
    float awt, att;
    //Scanning Time and Piriorty
    
    FILE *fp;

    fp = fopen("entrada.txt", "r");

    fscanf(fp, "%*[^\n]");  // Read and discard a line
    
    
    for(i=0 ;i<pn ;i++){
        
        fscanf(fp, "%d\t%d\t%d\t%d", &p[i], &PT[i], &AT[i], &PP[i]); //aquisição de dados  
       
        
        if(PP[i] == 5) {PP[i] = 1; paux[i] = 5;}
        else if (PP[i] == 4) {PP[i] = 2; paux[i] = 4;}
        else if (PP[i] == 3) {PP[i] = 3; paux[i] = 3;}
        else if (PP[i] == 2) {PP[i] = 4; paux[i] = 2;}
        else if (PP[i] == 1) {PP[i] = 5; paux[i] = 1;}
        
        PPt[i] = PP[i];
        ATt[i] = AT[i];
        
        
    }
    
    printf("\n\n========================== ESCALONAMENTO PRIOc ============================\n");

    printf("Dados Inseridos\n\n");

    printf("Pi\tTd\tTc\tPrio");
    
    for(i=0; i<pn; i++) printf("\n%d\t%d\t%d\t%d", p[i], PT[i], AT[i], PP[i]); //printa os dados




    int LAT = 0;        //LastArrivalTime
    for(i = 0; i < pn; i++)
        if(AT[i] > LAT)
            LAT = AT[i];

    int MAX_P = 0;        //Max Piriorty
    for(i = 0; i < pn; i++)
        if(PPt[i] > MAX_P)
            MAX_P = PPt[i];




    int ATi = 0;        //Pointing to Arrival Time indix
    int P1 = PPt[0];     //Pointing to 1st piriorty Value
    int P2 = PPt[0];     //Pointing to 2nd piriorty Value


    //findding the First Arrival Time and Highst piriorty Process
    int j = -1;
    while(NoP > 0 && CPU <= 1000){
        for(i = 0; i < pn; i++){
            if((ATt[i] <= CPU) && (ATt[i] != (LAT+10))){
                if(PPt[i] != (MAX_P+1)){
                    P2 = PPt[i];
                    j= 1;

                    if(P2 < P1){
                        j= 1;
                        ATi = i;
                        P1 = PPt[i];
                        P2 = PPt[i];
                    }
                }
            }
        }

        if(j == -1){
            CPU = CPU+1;
            continue;
        }else{


            waittingTime[ATi] = CPU - ATt[ATi];
            CPU = CPU + PT[ATi];
            turnaroundTime[ATi] = CPU - ATt[ATi];
            ATt[ATi] = LAT +10;
            j = -1;
            PPt[ATi] = MAX_P + 1;
            ATi = 0;        //Pointing to Arrival Time indix
            P1 = MAX_P+1;     //Pointing to 1st piriorty Value
            P2 = MAX_P+1;     //Pointing to 2nd piriorty Value
            NoP = NoP - 1;

        }




    }



    printf("\n\n\nPN\tPT\tPP\tAT\tWT\tTT\n\n");
    for(i = 0; i < pn; i++){
       printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,PT[i],paux[i],AT[i],waittingTime[i],turnaroundTime[i]);
    }

    int AvgWT = 0;
    int AVGTaT = 0;
    for(i = 0; i < pn; i++){
        AvgWT = waittingTime[i] + AvgWT;
        AVGTaT = turnaroundTime[i] + AVGTaT;
    }
    
    awt = (float)AvgWT/(float)pn;
    att = (float)AVGTaT/(float)pn;
    awt_prioc = awt;
    att_prioc = att;
    
    


    printf("\n\nTempo de espera medio : %f\nTempo de vida medio : %f\n\n", awt, att);
    
    fclose(fp);

   
    printf ("Thread FCFS Finalizada!\n\n\n\n") ;

    printf("====================================================================\n\n\n");
   
   pthread_exit (NULL) ;
    
    
    
}