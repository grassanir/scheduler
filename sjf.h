float awt_sjf, att_sjf;


void *SJF (void *id) //corpo da thread FCFS
{
    
    int pn=10,pno[20],at[20],bt[20],i,tat[20], prio[20], pc, com[20],wt[20],temp,j;
    
	float avg,avg2,avgtat,avgwt;
    
   
		
			FILE *fp;
            
        
            fp = fopen("entrada.txt", "r");
        
            fscanf(fp, "%*[^\n]");  // Read and discard a line
        
            for(pc=0; pc<10; pc++) fscanf(fp, "%d\t%d\t%d\t%d", &pno[pc], &bt[pc], &at[pc], &prio[pc]); //aquisição de dados  
            
        
            printf("\n\n========================== ESCALONAMENTO SJF ============================\n");
        
            printf("Dados Inseridos\n\n");
        
            printf("Pi\tTd\tTc\tPrio");
            
            for(i=0; i<pn; i++) printf("\n%d\t%d\t%d\t%d", pno[i], bt[i], at[i], prio[i]); //printa os dados
                    
            //Início da lógica de escalonamento    
			
		
			for(i=0;i<pn;i++)
			{
				for(j=i+1;j<pn;j++)
				{
					if(at[i]>at[j])
					{
						temp=at[i];
						at[i]=at[j];
						at[j]=temp;
						
						temp=pno[i];
						pno[i]=pno[j];
						pno[j]=temp;
						
						temp=bt[i];
						bt[i]=bt[j];
						bt[j]=temp;
							
					}
				}
			}
			
			com[0]=bt[0]+at[0];
			
			if(com[0]>at[pn-1])
			{
				for(i=1;i<pn;i++)
				{
					for(j=i+1;j<pn;j++)
					{
						if(bt[i]>bt[j])
						{
							temp=at[i];
							at[i]=at[j];
							at[j]=temp;
							
							temp=pno[i];
							pno[i]=pno[j];
							pno[j]=temp;
							
							temp=bt[i];
							bt[i]=bt[j];
							bt[j]=temp;
								
						}
					}
				}
				tat[0]=bt[0];
				wt[0]=0;
				
				
				for(i=1;i<pn;i++)
					com[i]=abs(com[i-1]+bt[i]);		//completion time
			}
			else
			{
				for(i=1;i<pn;i++)
				{
					for(j=i+1;j<pn;j++)
					{
						if(at[i]>at[j])
						{
							temp=at[i];
							at[i]=at[j];
							at[j]=temp;
							
							temp=pno[i];
							pno[i]=pno[j];
							pno[j]=temp;
							
							temp=bt[i];
							bt[i]=bt[j];
							bt[j]=temp;
								
						}
					}
				}
				
				com[1]=bt[1]+at[1];
				
				for(i=2;i<pn;i++)
				{
					for(j=i+1;j<pn;j++)
					{
						if(bt[i]>bt[j])
						{
							temp=at[i];
							at[i]=at[j];
							at[j]=temp;
							
							temp=pno[i];
							pno[i]=pno[j];
							pno[j]=temp;
							
							temp=bt[i];
							bt[i]=bt[j];
							bt[j]=temp;
								
						}
					}
				}
				
					tat[0]=bt[0];
					wt[0]=0;
					
					
					for(i=2;i<pn;i++)
						com[i]=abs(com[i-1]+bt[i]);		//completion time
			}
			
			for(i=0;i<pn;i++)
				tat[i]=abs(com[i]-at[i]);		//turn aroun time
				
				
			for(i=0;i<pn;i++)
				wt[i]=abs(tat[i]-bt[i]);		//waiting time
			
			for(i=0;i<pn;i++)
				avg=avg+tat[i];				//average TAT
			
			avgtat=avg/pn;
			
			for(i=0;i<pn;i++)
				avg2=avg2+wt[i];			//average WT
			
			avgwt=avg2/pn;
			
			awt_sjf = avgwt;
			att_sjf = avgtat;
			
			
			printf("\n\npno\tat\tbt\tcom\ttat\twt\t\n");
			for(i=0;i<pn;i++)
			{
				printf("P%d\t%d\t%d\t%d\t%d\t%d\n",pno[i],at[i],bt[i],com[i],tat[i],wt[i]);
			}
			
			printf("\n\nTempo de espera medio : %f\nTempo de vida medio : %f\n\n",avgwt, avgtat);
				
			
			fclose(fp);

   
            printf ("Thread SJF Finalizada!\n\n\n\n") ;

            printf("====================================================================\n\n\n");
   
            pthread_exit (NULL) ;	
		}