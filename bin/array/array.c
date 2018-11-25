#include <stdio.h>
#include <string.h>
#include "../array/array.h"
#include "../boolean/boolean.h"

void MakeEmpty (TabChar * T)
{
    Neff(*T) = 0;
}

int NbElmt (TabChar T)
{
    return Neff(T);
}

int MaxNbEl (TabChar T)
{
    return IdxMax-IdxMin+1;
}

IdxType GetFirstIdx (TabChar T)
{
    return IdxMin;
}


IdxType GetLastIdx (TabChar T)
{
    return Neff(T);
}

boolean IsEmptyArr (TabChar T)
{
    return (NbElmt(T) == 0);
}

boolean IsFullArr (TabChar T)
{
    return (GetLastIdx(T) == MaxNbEl(T));
}

void TulisIsiTab (TabChar T)
{
    for(int i=1; i<=Neff(T); i++)
    {
		printf("%s", Elmt(T,i));
        if(i!=Neff(T))
        {
            printf(",");
        }
    }
}

IdxType Search (TabChar T, ElType X)
{
	int i;
	boolean found =  true;
	if (IsEmptyArr(T))
	{
		return IdxUndef;
	}
	else
		{
			while ( (i <= Neff(T)) && found)
			{
				if (strcmp(Elmt(T,i), X) == 0)
				{
					found = false;
				}
				else
					i++;
			}
			if (!found)
			{
				return i;
			}
			else
				return IdxUndef;
		}
}

boolean SearchB (TabChar T, ElType X)
{
	boolean Found = false;
	int i = IdxMin;
	while ( (i <= Neff(T)) && !Found)
	{
		if (strcmp(Elmt(T,i), X) == 0)
		{
			Found = true;
		}
		else
        {
            i++;
        }
	}
	return Found;
}

void AddAsLastEl (TabChar * T, ElType X)
{
    Neff((*T))++;
    strcpy(Elmt((*T), GetLastIdx((*T))), X);
}


void DelLastEl (TabChar * T, ElType * X)
{
    strcpy((*X), Elmt(*T,Neff(*T)));
    Neff((*T))--;
}
