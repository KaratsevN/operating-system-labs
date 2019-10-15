/**********************************************************/
/* ���: 2.js */
/* ����: JScript */
/* ��������: 1) ������������ ������� n*n ���� 1 7 7 7 ... 7
 *                                            4 1 7 7 ... 7
 *											  4 4 1 7 ... 7
 * 											  	   ...
 *											  4 4 4 4 ... 1
 * 2) ���������� ���������� ��������� ������� 7
 * 3) ���������� ����� ��������� ������� � ������ �������� ������
 * 4) ���������� ������������ ������ ��������� � ������ �������� �������
 * 5) ���������� ����� ��������� ���� �������� ���������
 * 6) ���������� ������� ������ ������ ������� �� �����������,
 *    ������ �������� - �� ��������
 * 7) ���������� �������� ������� ��� ��������
 * 8) ��������� �������� ������� �� �������������
 * 9) ����� ���������� ��������� � ���� ������
 */
/**********************************************************/

// �������� �������
function create_matrix(n) {
var matrix = new Array(n);

for(var i = 0; i < n; i++)
	matrix[i] = new Array(n);

for(var i = 0; i < n; i++)
{
	for(var j = 0; j < n; j++)
	{
		if (i == j)
			matrix[i][j] = 1;
		else if (i > j)
			matrix[i][j] = 4;
		else 
			matrix[i][j] = 7;
	}
}
return  (matrix);
}

// ����� �������
function show_matrix(matrix , n, string) {
	var outputString = new Array(matrix.length);
	var currentString =  string;
	for(var i = 0; i < n; i++)
	{
		outputString[i] = "";
		for(var j = 0; j < n; j++)
			outputString[i] += " " + matrix[i][j];
	}
	for(var i = 0; i < n; i++)
		currentString += outputString[i]+"\n";
	WScript.Echo(currentString);
	delete outputString;
}

// ���������� ���������� ��������� ������� 7
function show_seven_multiple (matrix, n) {
	var sevenMultiple = 0;
	for(var i = 0; i < n; i ++) {
		for(var j = 0; j < n; j++) {
			if(matrix[i][j] % 7 == 0)
				sevenMultiple++;
		}
	}
	sevenMultiple = "� ������� ���������� ��������� ������� 7: " + sevenMultiple;
	WScript.echo(sevenMultiple);
}

// ���������� ����� ��������� ������� � ������ �������� ������
function summ_elem_ine_string (matrix, n) {
	var outputString = ""
	for(var i = 0; i < n; i ++) {
		var summ_elem_ine = 0;
		if ((i+1) % 2 == 1) {
		for(var j = 0; j < n; j++)
			summ_elem_ine += matrix[i][j];
		outputString += "����� ��������� " + (i+1) + " ������ = "+ summ_elem_ine + "\n";
		}
	}
	WScript.Echo(outputString);
}

// ���������� ������������ ������ ��������� � ������ �������� �������
function mult_eelem_ine_column(matrix, n) {
	var outputString = ""
	for(var i = 0; i < n; i ++) {
		var summ_eelem_ine = 1;
		if ((i+1) % 2 == 1) {
		for(var j = 0; j < n; j++) {
			if ((j+1) % 2 == 0)
					summ_eelem_ine *= matrix[i][j];
		}
		outputString += "������������ ������ ��������� � " + (i+1) + " �����e = "+ summ_eelem_ine + "\n";
		}
	}
	WScript.Echo(outputString);
}

// ���������� ����� ��������� ���� �������� ���������
function summ_elem_up_diagonal (matrix, n) {
	var summ_elem_up_diag = 0;
	for(var i = 0; i < n; i++) {
		for(var j = 0; j < n; j++) {
			if (i != j && i<j)
				summ_elem_up_diag += matrix[i][j];
		}
	}
	WScript.Echo("����� ��������� ���� �������� ��������� �����: " + summ_elem_up_diag);
}

// ���������� ������� ������ ������ ������� �� �����������, ������ �������� - �� ��������
function sorting(matrix, n) {
	var outputString = ""
	var buf;
	for(var i = 0; i < n; i++) {
		if ((i+1)%2 == 0) {
			for(var k = 0; k < n; k++) {
				for(var j = k; j < n; j++)
				{
					if(matrix[i][j] < matrix[i][k]) 
					{
						buf = matrix[i][j];
						matrix[i][j] = matrix[i][k];
						matrix[i][k] = buf;
					}
				}
			}
		}
		else {			
			for(var k = 0; k < n; k++) {
				for(var j = k+1; j < n; j++) {
					if(matrix[i][j] > matrix[i][k]) {
						buf = matrix[i][j];
						matrix[i][j] = matrix[i][k];
						matrix[i][k] = buf;
					}
				}
			}
		}
	}
	return (matrix);
}

// ���������� �������� ������� ��� ��������
function reverse_matrix(matrix, n)
{
	var bufMatrix = new Array(n);
	var newMatrix = new Array(n);
	for(var i = 0; i < n; i++) {
		bufMatrix[i] = new Array(n);
		newMatrix[i] = new Array(n);
	}
	for(var i = 0; i < n; i++) {
		for(var j = 0; j < n; j++) {
			if(i == j) 
				bufMatrix[i][j] = 1;
			else 
				bufMatrix[i][j] = 0;
			newMatrix[i][j] = matrix[i][j];
		}
	}

	for(var i=0;i<n;i++) {
		var tmp = newMatrix[i][i];
		for(var j=n-1;j>=0;j--) {
			bufMatrix[i][j]/=tmp;
			newMatrix[i][i]/=tmp;
		}

		for(var j=0;j<n;j++)
		if (j!=i) {
			tmp=newMatrix[j][i];
			for(var k=n-1;k>=0;k--) {
				bufMatrix[j][k]-=bufMatrix[i][k]*tmp;
				newMatrix[j][k]-=newMatrix[i][k]*tmp;
			}
		}
	}
	return (bufMatrix);
}


function mult_matrix(first,second, n)
{
	var c = new Array(n);
	for(var i = 0; i < n; i++) {
		c[i] = new Array(n);
	}
	for(var i = 0; i < n; i++) {
		for(var j = 0; j < n; j++) {
			c[i][j] = 0;
			for(var r = 0; r < n; r++) c[i][j] += first[i][r]*second[r][j];
		}
	}
	show_matrix(c, n, "��������� �������� �� ���������������:\n");

	var k = "";
	for(var i = 0; i < n; i++) {
		for(var j = 0; j < n; j++)
		{
			k += " " + c[i][j];
		}
	}
	WScript.Echo("����� ���������� � ���� ������:\n" + k);	
}
