#include <stdio.h>

int XOR_cnf(FILE *fp,int x0, int x1, int &var)
{  
    //((!x0|x1|vars) & (x0|!x1|vars) & (x0|x1|!vars) & (!x0|!x1|vars) 
	fprintf(fp, "%d %d %d 0\n", -x0 , x1 , var );
    fprintf(fp, "%d %d %d 0\n", x0 , -x1 , var );
    fprintf(fp, "%d %d %d 0\n",  x0 , x1 , -var );
    fprintf(fp, "%d %d %d 0\n",  -x0 , -x1 , -var );
       
}

int AND_cnf(FILE *fp,int x0, int x1, int &var)
{
    //((x0|x1|-var) & (x0|!x1|!var) & (!x0|x1|!var) & (!x0|!x1|var) 
	fprintf(fp, "%d %d %d 0\n", x0 , x1 , -var );
    fprintf(fp, "%d %d %d 0\n",  x0 , -x1 , -var );
    fprintf(fp, "%d %d %d 0\n",  -x0 , x1 , -var );
    fprintf(fp, "%d %d %d 0\n",  -x0 , -x1 , var );
      
}    
     
int SBOX_cnf(FILE *fp,int x1, int x2,int x3, int x4,int x5,int &z1, int &z2, int &z3, int &z4, int &z5, int &vars,int &claus)
{
    int v6=vars;
    int	v7=vars+1;
    int v8=vars+2;
    int v9=vars+3;
    int v10=vars+4;
    int v11=vars+5;
    int v12=vars+6;
    int v13=vars+7;
    int v14=vars+8;
    int v15=vars+9;
    int v16=vars+10;
    int v17=vars+11;
    int v18=vars+12;
    int v19=vars+13;
    int v20=vars+14;
    int v21=vars+15;
    int v22=vars+16;
    int v23=vars+17;
    int v24=vars+18;
    int v25=vars+19;
    int v26=vars+20;
    
    
	//cnf for bit 1
	XOR_cnf(fp,x1,x5,v6);
    XOR_cnf(fp,x2,x3,v7);
    XOR_cnf(fp,x4,x5,v8);
    XOR_cnf(fp,-x1,x5,v9);
    AND_cnf(fp,-x2,v7,v10);
    AND_cnf(fp,x2,v9,v11);
    XOR_cnf(fp,v6,v10,v12);
    XOR_cnf(fp,v12,v8,v13);      
    
    //cnf for bit 2
    AND_cnf(fp,-v7,x4,v14);
    XOR_cnf(fp,x2,v14,v15);     
    
    //cnf for bit 3
    AND_cnf(fp,-x4,v8,v16);      
    
    //cnf for bit 4
    AND_cnf(fp,-x4,x5,v17);
    AND_cnf(fp,-v8,v6,v18);
    XOR_cnf(fp,v7,v17,v19);
    XOR_cnf(fp,v19,x4,v20);      
    
    //cnf for bit 4
    AND_cnf(fp,-v6,x2,v21);
    
    //Final bits
   	XOR_cnf(fp,v13,v11,v22);
   	XOR_cnf(fp,v12,v15,v23);
   	XOR_cnf(fp,-v7,v16,v24);
   	XOR_cnf(fp,v18,v20,v25);
   	XOR_cnf(fp,v8,v21,v26);
   	
   	//output bits
   	z1=v22;
   	z2=v23;
   	z3=v24;
   	z4=v25;
   	z5=v26;
    
    vars=vars+21; 
	claus=claus+32+8+4+16+4+20;  
}

int rotate(FILE *fp,int s[],int s1[],int s2[])
{
	//rotation for x1    
	for( int i=0; i<320; i=i+5)
	{
       s1[((19*5)+i)%320]=s[i];
    }
    
    for( int i=0; i<320; i=i+5)
	{
       s2[((28*5)+i)%320]=s[i];
    }
    //rotation for x1
    for( int i=1; i<320; i=i+5)
	{
       s1[((61*5)+i)%320]=s[i];
    }
    
    for( int i=1; i<320; i=i+5)
	{
       s2[((39*5)+i)%320]=s[i];
    }
    
    //rotation for x2
    for( int i=2; i<320; i=i+5)
	{
       s1[((1*5)+i)%320]=s[i];
    }
    
    for( int i=2; i<320; i=i+5)
	{
       s2[((6*5)+i)%320]=s[i];
    }
    
    //rotation for x3
    for( int i=3; i<320; i=i+5)
	{
       s1[((10*5)+i)%320]=s[i];
    }
    
    for( int i=3; i<320; i=i+5)
	{
       s2[((17*5)+i)%320]=s[i];
    }
    
    //rotation for x4
    for( int i=4; i<320; i=i+5)
	{
       s1[((7*5)+i)%320]=s[i];
    }
    
    for( int i=4; i<320; i=i+5)
	{
       s2[((41*5)+i)%320]=s[i];
    }    
    
}

void linear_cnf(FILE *fp,int s[],int s1[],int s2[],int &vars,int &claus)
{   
    for(int i=0;i<64;i++)
    {   
	    int v16=vars;
    	int v17=vars+1;
        int v18=vars+2;
        int v19=vars+3;
        int v20=vars+4;
        int v21=vars+5;
        int v22=vars+6;
        int v23=vars+7;
        int v24=vars+8;
        int v25=vars+9;
        
    	XOR_cnf(fp,s[5*i+0],s1[5*i+0],v16);
    	XOR_cnf(fp,s[5*i+1],s1[5*i+1],v17);
	    XOR_cnf(fp,s[5*i+2],s1[5*i+2],v18);
        XOR_cnf(fp,s[5*i+3],s1[5*i+3],v19);
     	XOR_cnf(fp,s[5*i+4],s1[5*i+4],v20);		
    	XOR_cnf(fp,v16,s2[5*i+0],v21);
		XOR_cnf(fp,v17,s2[5*i+1],v22);
		XOR_cnf(fp,v18,s2[5*i+2],v23);
		XOR_cnf(fp,v19,s2[5*i+3],v24);
		XOR_cnf(fp,v20,s2[5*i+4],v25); 
		
		//output bits
		s[5*i+0]=v21;
		s[5*i+1]=v22;
		s[5*i+2]=v23;
		s[5*i+3]=v24;
		s[5*i+4]=v25;
		
		claus=claus+40;
		vars=vars+10;   
	}
}

void SBOX_layer(FILE *fp, int s[],int &vars, int &claus)
{  int t[320];
	for(int i=0;i<64;i++)
	{	  
      SBOX_cnf(fp,s[5*i+0], s[5*i+1], s[5*i+2], s[5*i+3],s[5*i+4], t[5*i+0], t[5*i+1], t[5*i+2], t[5*i+3],t[5*i+4], vars, claus );
	  s[5*i+0]=t[5*i+0];
	  s[5*i+1]=t[5*i+1];
	  s[5*i+2]=t[5*i+2];
	  s[5*i+3]=t[5*i+3];
	  s[5*i+4]=t[5*i+4];                    
    }
}

void Linear_layer(FILE *fp, int s[], int &vars, int &claus)
{
  int s1[320],s2[320];
  rotate(fp,s,s1,s2);
  linear_cnf(fp,s,s1,s2,vars,claus); 	
}

void constant( FILE *fp, int s[], int rnd )
{
	if(rnd==0)
	{
		s[282]= -s[282];
		s[287]= -s[287];
		s[292]= -s[292];
		s[297]= -s[297];
		s[302]=  s[302];
		s[307]=  s[307];
		s[312]=  s[312];
		s[317]=  s[317];		
	}
	else if(rnd==1)
	{   s[282]= -s[282];
		s[287]= -s[287];
		s[292]=  s[292];
		s[297]=  s[297];
		s[302]=  s[302];
		s[307]=  s[307];
		s[312]=  s[312];
		s[317]= -s[317];   
	}
	else if(rnd==2)
	{
		s[282]= -s[282];
		s[287]= -s[287];
		s[292]=  s[292];
		s[297]= -s[297];
		s[302]=  s[302];
		s[307]=  s[307];
		s[312]= -s[312];
		s[317]=  s[317];  	   	
	}
	else if(rnd==3)
	{
		s[282]= -s[282];
		s[287]= -s[287];
		s[292]=  s[292];
		s[297]=  s[297];
		s[302]=  s[302];
		s[307]=  s[307];
		s[312]= -s[312];
		s[317]= -s[317];  	
	    
	}
	else if(rnd==4)
	{
		s[282]= -s[282];
		s[287]=  s[287];
		s[292]= -s[292];
		s[297]= -s[297];
		s[302]=  s[302];
		s[307]= -s[307];
		s[312]=  s[312];
		s[317]=  s[317];  	
	    
	}
	else if(rnd==5)
	{
		s[282]= -s[282];
		s[287]=  s[287];
		s[292]= -s[292];
		s[297]=  s[297];
		s[302]=  s[302];
		s[307]= -s[307];
		s[312]=  s[312];
		s[317]= -s[317];  		
	   	
	}
	else if(rnd==6)
	{
		s[282]= -s[282];
		s[287]=  s[287];
		s[292]=  s[292];
		s[297]= -s[297];
		s[302]=  s[302];
		s[307]= -s[307];
		s[312]= -s[312];
		s[317]=  s[317];  		
	    
	}
	else if(rnd==7)
	{
		s[282]= -s[282];
		s[287]=  s[287];
		s[292]=  s[292];
		s[297]=  s[297];
		s[302]=  s[302];
		s[307]= -s[307];
		s[312]= -s[312];
		s[317]= -s[317];	
	    	
	}
	else if(rnd==8)
	{
		s[282]=  s[282];
		s[287]= -s[287];
		s[292]= -s[292];
		s[297]= -s[297];
		s[302]= -s[302];
		s[307]=  s[307];
		s[312]=  s[312];
		s[317]=  s[317]; 	
	    
	}
	else if(rnd==9)
	{
		s[282]=  s[282];
		s[287]= -s[287];
		s[292]= -s[292];
		s[297]=  s[297];
		s[302]= -s[302];
		s[307]=  s[307];
		s[312]=  s[312];
		s[317]= -s[317];  		
	    	
	}
	else if(rnd==10)
	{
		s[282]=  s[282];
		s[287]= -s[287];
		s[292]=  s[292];
		s[297]= -s[297];
		s[302]= -s[302];
		s[307]=  s[307];
		s[312]= -s[312];
		s[317]=  s[317];    	
	}
	else 
	{
		s[282]=  s[282];
		s[287]= -s[287];
		s[292]=  s[292];
		s[297]=  s[297];
		s[302]= -s[302];
		s[307]=  s[307];
		s[312]= -s[312];
		s[317]= -s[317];  
			    	
	} 
}
  
void round( FILE *fp, int s[], int &vars, int &claus, int rnd)
{   
    constant(fp, s, rnd );
	SBOX_layer(fp,s,vars,claus );		
	Linear_layer(fp,s,vars,claus);
	
	constant(fp, s, rnd );
	SBOX_layer(fp,s,vars,claus );	

} 
 
int main()
{	
    FILE *fp;
    fp = fopen("\d: tempclaus1.txt","w");
    
    FILE *f;
    f = fopen("\d: sboxop1.txt","w");
    int s[320];
    for(int i=0;i<320;i++)
    {
       s[i]=i+1;
	}
	
	for(int i=0;i<320;i++)
    {  
	   if(i%2==0)   
	   fprintf(f,"\n%d %d",s[i],0);
	   else 
	   fprintf(f,"\n%d %d",-s[i],0);     
	}
	int vars=321,claus=0;
	
	//loop for number of rounds
	for(int r=0;r<1;r++) 
    {
    	round(fp,s,vars,claus,r);
	}
    fprintf(f,"\n ");  
    for(int i=0;i<128;i++)
    {
       fprintf(f,"\n%d %d",s[i],0); 
    }
    fprintf(fp,"\np cnf %d %d",vars-1,claus);   
    	     
    	
}

 

