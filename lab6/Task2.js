var s;
WScript.StdOut.Write("������� ������ �������:");
s=WScript.StdIn.ReadLine();
if((!s) || !(parseInt(s))) WScript.Echo("������"); else{
                var N = s;
    	        var matr = create(s);
				WScript.Echo("������� ");
    	        showmatrix(matr);
                var i = two_task(matr);
                WScript.Echo("���������� ���������, ������� 7: " + i);
                summ_line(matr);
                four_task(matr);
                i = summ(matr);
                WScript.Echo("����� ��������� ���� �������� ���������: " + i);
                var sort_matr = sort_m(create(s));
                //sort(sort_matr);
                WScript.Echo("��������������� �������: ");
                showmatrix(sort_matr);
                var m2 = inversion(matr, s);
                WScript.Echo("��������:");
				showmatrix(m2);
				mart = create(s);
                result(matr,sort_matr);
            }
function inversion(matr,size)
{
			var i,j,k;

    var E_mat = new Array(size);
	for(var i = 0; i < N; i++)
{
	E_mat[i] = new Array(N);
}

for (i=0;i<size;i++){
for (j=0;j<size;j++){    
if (i==j) E_mat[i][j]=1;
else E_mat[i][j]=0;
}
}

 for (k=0;k<size;k++){    
for (j=k+1;j<size;j++){
matr[k][j]=matr[k][j]/matr[k][k]; 
}
for (j=0;j<size;j++){
E_mat[k][j]=E_mat[k][j]/matr[k][k]; 
}
matr[k][k]=matr[k][k]/matr[k][k];

if (k>0) {
    for (i=0;i<k;i++){  
  for (j=0;j<size;j++){
  E_mat[i][j]=E_mat[i][j]-E_mat[k][j]*matr[i][k];  
  }
  for (j=size-1;j>=k;j--){
    matr[i][j]=matr[i][j]-matr[k][j]*matr[i][k];//��������� �������� ������� a,��� �� �������� � ���������� � k-���
  }
    }    
}
for (i=k+1;i<size;i++){   
    for (j=0;j<size;j++){    
  E_mat[i][j]=E_mat[i][j]-E_mat[k][j]*matr[i][k];
  }
    for (j=size-1;j>=k;j--){
matr[i][j]=matr[i][j]-matr[k][j]*matr[i][k];
    }
}
               }
return E_mat;
}
	
			function mulnum(a,m,num)
{

	for (var i=0;i<m;i++)
	for (var j=0;j<m;j++) a[i][j] *= num;
	
}

function trans(a,m)
{
	na = new Array(m);

	for (var i=0;i<m;i++)
	{
		na[i] = new Array(m);
		for (var j=0;j<m;j++) na[i][j] = a[j][i];
	}

	return na;
	
}

function obr(a,m)
{
    var na = trans(a,m);
	var k = det(a,m);
	mulnum(na,m,1/k);
	return na;
}

/*function minor(arr,num,t)
{
	na = new Array(num);
	for (var i=0;i<num;i++) na[i] = new Array(num);
	

//WScript.Echo("����� "+num+" "+t);	
	for (var i=0;i<num;i++)
	{
		var s = "";
		for (var j=0;j<num;j++)
		{
			if (j<t) na[i][j] = arr[i+1][j];
			else na[i][j] = arr[i+1][j+1];
			s += na[i][j]+" ";
		}

	//WScript.Echo(s);
	}
	

	return na;
}


/*function det(a,m)
{
	if (m<2) return 0; //error
	if (m==2) return a[0][0]*a[1][1]-a[0][1]*a[1][0];
	else
	{
		k = 0;

		for(var j=0;j<m;j++)
		{			
			na = minor(a,m-1,j);
			if (j%2==0) k+=a[0][j]*det(na,m-1);
			else k-=a[0][j]*det(na,m-1);
//			WScript.Echo(") "+k);
		}

		return k;
	}

	return 0;
}
*/
function showmatrix(arr)
{
	var out = new Array(arr.length);
	var str = "";
	for(var i = 0; i < N; i++)
	{
		out[i] = "";
		for(var j = 0; j < N; j++)
		{
			out[i] += " " + arr[i][j];
		}
	}
	for(var i = 0; i < N; i++)
	{
		str = str+out[i]+"\n";
	}
	WScript.Echo(str);
	delete out;
}

function two_task(arr)
{
	var k = 0;
	for(var i = 0; i < N; i++)
	{
		for(var j = 0; j < N; j++)
		{
			if(arr[i][j]%7 == 0) k++;
		}
	}
	return k;
    WScript.Echo(k);
}


function summ_line(arr)
{
	for(var i = 0; i < N; i++)
	{
		var k = 0;
		if((i+1)%2 == 1)
		{
			for(var j = 0; j < N; j++)
			{
				k+= arr[i][j];
			}
			WScript.Echo("����� ��-��� ������",i+1,":",k);
		}
	}
}

function four_task(arr)
{
	for(var j = 0; j < N; j++)
	{
		var k = 1;
		if((j+1)%2 == 1)
		{
			for(var i = 0; i < N; i++)
			{
				if(arr[i][j]%2 == 0)
				{
					k *= arr[i][j];
				}
			}
			if(k != 1)WScript.Echo("������������ ������ ��-��� �������",j+1,":",k);
			else WScript.Echo("� �������",j+1,"��� ������ ��-���");
		}
	}
}

function summ(arr)
{
	var k = 0;
	for(var i = 0; i < N; i++)
	{
		for(var j = 0; j < N; j++)
		{
			if((i+j)<(N-1)) k += arr[i][j];
		}
	}
	return k;
      WScript.Echo(k);
}

function sort_m(arr)
{
	for(var i = 0; i < N; i++)
	{
		if ((i+1)%2 == 0)
		for(var k = 0; k < N; k++)
		{
			for(var j = k; j < N; j++)
			{
				if(arr[i][j] < arr[i][k]) 
				{
					var temp = arr[i][j];
					arr[i][j] = arr[i][k];
					arr[i][k] = temp;
				}
			}
		}
		else
		for(var k = 0; k < N; k++)
		{
			for(var j = k+1; j < N; j++)
			{
				if(arr[i][j] > arr[i][k]) 
				{
					var temp = arr[i][j];
					arr[i][j] = arr[i][k];
					arr[i][k] = temp;
				}
			}
		}
	}
	return arr
}

function result(arr1,arr2)
{

	var c = new Array(arr1.length);
	for(var i = 0; i < N; ++i)
	{
		c[i] = new Array(N);
	}
	for(var i = 0; i < N; ++i)
	{
		for(var j = 0; j < N; ++j)
		{
			//var t = 0;
			c[i][j] = 0;
			for(var r = 0; r < N; r++) {
				c[i][j] = c[i][j] + arr1[i][r]*arr2[r][j];
			}
			//c[i][k] = t;
		}
	}	
	WScript.Echo("��������� �������� �� ���������������:");
	showmatrix(c);

	var k = "";
	for(var i = 0; i < N; i++)
	{
		for(var j = 0; j < N; j++)
		{
			k += " " + c[i][j];
		}
	}
	WScript.Echo("����� ���������� � ���� ������:");
	WScript.Echo(k);	
}

function seven(T)
{
	var E = new Array(N);
	var arr = new Array(N);
	for(var i = 0; i < N; i++)
	{
		E[i] = new Array(N);
		arr[i] = new Array(N);
	}
	for(var i = 0; i < N; i++)
	{
		for(var j = 0; j < N; j++)
		{
			if(i == j) E[i][j] = 1;
			else E[i][j] = 0;
			arr[i][j] = T[i][j];
		}
	}

	for(var i=0;i<N;i++)
	{
		var tmp = arr[i][i];
		for(var j=N-1;j>=0;j--)
		{
			E[i][j]/=tmp;
			arr[i][i]/=tmp;
		}

		for(var j=0;j<N;j++)
		if (j!=i)
		{
			tmp=arr[j][i];
			for(var k=N-1;k>=0;k--)
			{
				E[j][k]-=E[i][k]*tmp;
				arr[j][k]-=arr[i][k]*tmp;
			}
		}
	}

	WScript.Echo("��������:");
	showmatrix(E);
}
function create(N) {
var matrix = new Array(N);
for(var i = 0; i < N; i++)
{
	matrix[i] = new Array(N);
}

for(var i = 0; i < N; i++)
{
	for(var j = 0; j < N; j++)
	{
		if (i == j) matrix[i][j] = 1;
		else
		{
			if (i > j) matrix[i][j] = 4;
			else matrix[i][j] = 7;
		}
	}
}
return ( matrix );
}
