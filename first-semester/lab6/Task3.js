var Num;
WScript.StdOut.Write("������� n:");
Num=WScript.StdIn.ReadLine();
var rex=0;
var summ=0;
var sum =0; 
 if((!Num) || !(parseInt(Num)) || (Num<=0))
			{
                          if (Num==0) 
				{
					WScript.Echo("����� ������ "+Num+" ������ ���� �����: "+1);  
				}
				else 
				{
					WScript.Echo("������."); 
				}
			}			
			else{
				var Result=0;
				       
                                        Recurs(Num);
                                   
				}
	
			WScript.Echo("����� ������ "+Num+" ������ ���� �����: "+sum);   

function Recurs(i)
{
var x=0;
	if(i == 1) 
	{
             x=1;
              // return i;
	}
	else 
	{
                
               // WScript.Echo((Math.log(Recurs(i-1)*i)+9));
		x = Math.log(Recurs(i-1)*i)+9;
          // return (Math.log(Recurs(i-1)*i)+9)+Recurs(i-1);
	}
sum+=x;
return x;
}



