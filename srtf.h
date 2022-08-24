float awt_srtf, att_srtf;


void *SRTF (void *id) //corpo da thread FCFS
{
    
            int pn=10,pno[20],at[20],bt[20],i,tat[20], prio[20], pc, com[20],wt[20],temp,j,bttemp[20]={},temp1=0,temp2;
			
			float avg,avg2,avgtat,avgwt;
		
			FILE *fp;
            
        
            fp = fopen("entrada.txt", "r");
        
            fscanf(fp, "%*[^\n]");  // Read and discard a line
        
            for(pc=0; pc<10; pc++) fscanf(fp, "%d\t%d\t%d\t%d", &pno[pc], &bt[pc], &at[pc], &prio[pc]); //aquisição de dados  
            
        
            printf("\n\n========================== ESCALONAMENTO SRTF ============================\n");
        
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
			
			temp2=1;
			temp1=bttemp[0]=bt[0]-1;
			
				com[0]=at[0]+1;
					
				for(i=1;i<pn;i++)
				{
					bttemp[i]=bt[i];
				}
				
			
			if(bttemp[0]>bttemp[1])
			{
				bttemp[pn]=temp2;
				
				for(i=0;i<=pn;i++)
				{
					for(j=i+1;j<=pn;j++)
					{
						if(bttemp[i]>bttemp[j])
						{
							temp=at[i];
							at[i]=at[j];
							at[j]=temp;
							
							temp=pno[i];
							pno[i]=pno[j];
							pno[j]=temp;
							
							temp=bttemp[i];
							bttemp[i]=bttemp[j];
							bttemp[j]=temp;
								
						}
					}
				}
			
			
				pno[0]=bttemp[0];
				at[0]=bttemp[0];

				
				if(at[1]<at[2])
				{
					com[1]=com[0]+bttemp[1];
					
				
					
					for(i=0;i<=pn;i++)
					{
						for(j=i+1;j<=pn;j++)
						{
							if(at[i]>at[j])
							{
								temp=at[i];
								at[i]=at[j];
								at[j]=temp;
								
								temp=pno[i];
								pno[i]=pno[j];
								pno[j]=temp;
								
								temp=bttemp[i];
								bttemp[i]=bttemp[j];
								bttemp[j]=temp;
									
							}
						}
					}
					
					com[2]=com[1]+bttemp[1];
					
					for(i=0;i<=pn;i++)
					{
						for(j=i+1;j<=pn;j++)
						{
							if(bttemp[i]>bttemp[j])
							{
								temp=at[i];
								at[i]=at[j];
								at[j]=temp;
								
								temp=pno[i];
								pno[i]=pno[j];
								pno[j]=temp;
								
								temp=bttemp[i];
								bttemp[i]=bttemp[j];
								bttemp[j]=temp;
									
							}
						}
					}
				
				tat[0]=0;
				tat[1]=bttemp[0];
				
				
				wt[0]=0;
				for(i=3;i<=pn;i++)
					com[i]=abs(com[i-1]+bttemp[i]);		//completion time
				
				for(i=1;i<=pn;i++)
					tat[i]=abs(com[i]-at[i]);		//turn aroun time
					
					
				for(i=1;i<=pn;i++)
				{
					wt[i]=abs(tat[i]-bttemp[i]);		//waiting time
					if(wt[i]==temp1)
						wt[i]=wt[i]-1;
					
				}
				}
				else
				{
					for(i=0;i<=pn;i++)
					{
						for(j=i+1;j<=pn;j++)
						{
							if(at[i]>at[j])
							{
								temp=at[i];
								at[i]=at[j];
								at[j]=temp;
								
								temp=pno[i];
								pno[i]=pno[j];
								pno[j]=temp;
								
								temp=bttemp[i];
								bttemp[i]=bttemp[j];
								bttemp[j]=temp;
									
							}
						}
					}
					
					com[1]=com[0]+bttemp[2];
					
					for(i=0;i<=pn;i++)
					{
						for(j=i+1;j<=pn;j++)
						{
							if(bttemp[i]>bttemp[j])
							{
								temp=at[i];
								at[i]=at[j];
								at[j]=temp;
								
								temp=pno[i];
								pno[i]=pno[j];
								pno[j]=temp;
								
								temp=bttemp[i];
								bttemp[i]=bttemp[j];
								bttemp[j]=temp;
									
							}
						}
					}
					
					
					com[2]=com[1]+bttemp[1];
					
					
					if(at[1]>at[2])
					{
						temp=at[1];
						at[1]=at[2];
						at[2]=temp;
								
						temp=pno[1];
						pno[1]=pno[2];
						pno[2]=temp;
								
						temp=bttemp[1];
						bttemp[1]=bttemp[2];
						bttemp[2]=temp;
					}
					
					
				tat[0]=0;
				tat[1]=bttemp[0];
				
				
				wt[0]=0;
				for(i=3;i<=pn;i++)
					com[i]=abs(com[i-1]+bttemp[i]);		//completion time
				
				for(i=1;i<=pn;i++)
					tat[i]=abs(com[i]-at[i]);		//turn aroun time
					
					
				for(i=1;i<=pn;i++)
				{
					if(temp1==bttemp[i])
						bttemp[i]+=1;
					wt[i]=abs(tat[i]-bttemp[i]);		//waiting time
					if(wt[i]==temp1)
						wt[i]=wt[i]-1;
					
				}
						
				}
				
				
				
				for(i=0;i<=pn;i++)
					avg=avg+tat[i];				//average TAT
				
				avgtat=avg/pn;
				
				for(i=0;i<=pn;i++)
					avg2=avg2+wt[i];			//average WT
				
				avgwt=avg2/pn;
				
				
				printf("pno\tat\tbt\tcom\ttat\twt\t\n");
				for(i=0;i<=pn;i++)
				{
					printf("P%d\t%d\t%d\t%d\t%d\t%d\n",pno[i],at[i],bttemp[i],com[i],tat[i],wt[i]);
				}
				
				printf("\n\nTempo de espera medio : %f\nTempo de vida medio : %f\n\n",avgwt, avgtat);
				
				
			}
			else
			{
				
				bttemp[0]=bttemp[0]+temp2;
				com[0]=bttemp[0];
				tat[0]=bttemp[0];
				wt[0]=0;
				
				for(i=1;i<pn;i++)
				{
					for(j=i+1;j<pn;j++)
					{
						if(bttemp[i]>bttemp[j])
						{
							temp=at[i];
							at[i]=at[j];
							at[j]=temp;
							
							temp=pno[i];
							pno[i]=pno[j];
							pno[j]=temp;
							
							temp=bttemp[i];
							bttemp[i]=bttemp[j];
							bttemp[j]=temp;
								
						}
					}
				}
				
				
				for(i=1;i<pn;i++)
					com[i]=abs(com[i-1]+bttemp[i]);		//completion time
				
				for(i=0;i<pn;i++)
					tat[i]=abs(com[i]-at[i]);		//turn aroun time
					
					
				for(i=0;i<pn;i++)
					wt[i]=abs(tat[i]-bttemp[i]);		//waiting time
				
				for(i=0;i<pn;i++)
					avg=avg+tat[i];				//average TAT
				
				avgtat=avg/pn;
				
				for(i=0;i<pn;i++)
					avg2=avg2+wt[i];			//average WT
				
				avgwt=avg2/pn;
				
				awt_srtf = avgwt;
				att_srtf = avgtat;
				
				
				printf("\n\npno\tat\tbt\tcom\ttat\twt\t\n");
				for(i=0;i<pn;i++)
				{
					printf("P%d\t%d\t%d\t%d\t%d\t%d\n",pno[i],at[i],bttemp[i],com[i],tat[i],wt[i]);
				}
				
				printf("\n\nTempo de espera medio : %f\nTempo de vida medio : %f\n\n",avgwt, avgtat);
			}




		        fclose(fp);

   
                printf ("Thread SRTF Finalizada!\n\n\n\n") ;

                printf("====================================================================\n\n\n");
   
                pthread_exit (NULL) ;	
			
		}