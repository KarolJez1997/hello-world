/*
 * ptr2.c
 * 
 * Copyright 2020  <pi@raspberrypi>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *ptr;

int *enter_array(int *var, int *var2)
{
	printf("Enter a size of your array:\n");
	scanf("\n%d", var2);
	ptr = malloc(*var2*sizeof(int));
	for(int i =0; i<*var2; i++)
	{
		scanf("\n%d" , var);
		*(*(&ptr) + i) =*var;
	}
	
	return ptr;
}

void display_array(int **array, int*var2)
{
	for(int i =0; i<*var2; i++)
	{
		printf("\n%p",(*array + i));
		printf(" %d",*(*(array) + i));
	}
}

int *sort_array(int **arr, int *var2)
{
	bool cmp;
	do
	{
		cmp=false;
		for(int i=1; i<*var2; i++)
		{
			if(*(*(arr) + i)<*(*(arr) + (i-1)))
			{
				int tmp;
				cmp = true;
				tmp=*(*(arr) + i);
				*(*(arr) + i)=*(*(arr) + (i-1));
				*(*(arr) + (i-1))=tmp;
			}
		}
	}while(cmp == true);
	return *arr;
}

int main(int argc, char **argv)
{
	int var,var2;
	int *array;
	
	array = enter_array(&var, &var2);
	display_array(&array, &var2);
	printf("\n");
	*array=*sort_array(&array, &var2);
	display_array(&array, &var2);
	free(ptr);
	printf("\n");
	
	return 0;
}
