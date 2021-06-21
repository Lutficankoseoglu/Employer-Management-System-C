#include <stdio.h> ///for input output functions like printf, scanf
#include <stdlib.h>
#include <conio.h>
#include <windows.h> ///for windows related functions (not important)
#include <string.h>  ///string operations


#define MAX 256



int first_setup();
int find();
int searchName(char nameToSearch[]);
int rem_register();
int main_menu();
int case_1();
int case_2();
int case_3();
int case_4();
int case_5();
int case_6();







int first_setup(){ 	// this function is for calibrate the system. if the user didn't calibrate her/his system, the system will not work properly.
	
	FILE *List;
	List = fopen("employer.dat", "w+");		//open employee logs in write mode.
	fprintf(List, "\n");					//write a space line for calibration.
	fclose(List);							//close the employee log file.
		
}









int find(){		//this function is for find to specific line. For example : Find ; employee_name ==>  employee_name, employee_surname, employee_age, employee_position, employee_salary.
	char nameToSearch[40];						//sets a char value for the name to search
	FILE *List;									
	List = fopen("employer.dat","r");			//open employee logs in read mode.
	if(List == NULL)							//if the employer.dat is empty
	{
		system("cls");							//clear the screen,
		printf("No Contacts Available");		//write "No Contacts Avaible" to the screen.
		getch();
		exit(0);								//exit the function.
	}
	
	printf("\n**************||Employee Management System||**************\n");			
	printf("                ||Search Employee Screen||\n\n\n");							
	printf("Enter name to search : ");													//enter a name for search.
	scanf("%s",&nameToSearch);
	fflush(stdin);
	printf("\n-------------------------------------------------------\n");
	printf("|| Name  || Surname  || Age  || Position  || Salary  ||\n");
	searchName(nameToSearch);															//searches for the name entered from the keyboard in employer.dat file.
	printf("\n-------------------------------------------------------\n");
	
	
}



int searchName(char nameToSearch[]){		//this function is working with 'find' function.
	char line[401];											//this char value creates one line of space.
	FILE *List;												
	List = fopen("employer.dat","r");						//open emloyee logs in read mode.
	while(!feof(List))										//read the lines from start line till finish line.
	{
		fgets(line,400,List);
		if(strstr(line,nameToSearch)!=NULL)					//check the searched name in the employee.dat
		printf("\n%s",line);		
	}	
	
	
}









int rem_register(){			//this function is for remove a employee register.
	
	 int lno, ctr = 0;											//introduce the int values to the computer.
        char ch;												//introduce the char value to the computer.
        FILE *fptr1, *fptr2;									//introduce the FILE values to the computer.
		char fname[MAX] = "employer.dat";						//fname[MAX] = "employer.dat", so when computer see the 'fmax' in the code line, it will change them with "employer.dat"
        char str[MAX], temp[] = "temp.txt";						//temp[] = "temp.txt", so the temp[] function is open the 'temp.txt' file.
        fptr1 = fopen(fname, "r");								//open the employee logs in read mode.
        rewind(fptr1);											//go to the employee.dat's first line.
        if (!fptr1) 
		{
                printf(" File not found or unable to open the input file!!\n");				//if the computer can not open the 'employer.dat' or can not find this file, write "File not found or unable to open the input file!!" to the screen.
                return 0;
        }
        fptr2 = fopen(temp, "w"); 								// open the temporary file in write mode 
        if (!fptr2) 
		{
                printf("Unable to open a temporary file to write!!\n");						//if the computer can not open the temporary file, write "Unable to open a temporary file to write!!" to the screen.
                fclose(fptr1);																//close the employee.dat
                return 0;
        }
        printf(" Input the line you want to remove : ");		//type the number of the line you want to delete.
        scanf("%d", &lno);
        fflush(stdin);
		lno++;
        											// copy all contents to the temporary file except the specific line
        while (!feof(fptr1)) 
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
            if (!feof(fptr1)) 
            {
                ctr++;
                									/* skip the line at given line number */
                if (ctr != lno) 
                {
                    fprintf(fptr2, "%s", str);
                }
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(fname);  						//remove the original file 
        rename(temp, fname); 					//rename the temporary file to original name
		
		
		
	/*------ Read the file ----------------*/
	
   fptr1=fopen(fname,"r"); 
            ch=fgetc(fptr1); 
          printf(" Now the content of the file %s is : \n",fname); 
          while(ch!=EOF) 
            { 
                printf("%c",ch); 
                 ch=fgetc(fptr1); 
            }
        fclose(fptr1);
        
	/*------- End of reading ---------------*/
	
	
	
        return 0;
	
	
}










int main_menu(){			//this function is for main menu select.
	
		char secim;				//introduce the char value of 'choice' to the computer.
		
	
	system("cls");				//clear the screen.


	/*this lines for caution.*/
	
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf(" \t\t\t\t\t\t    WARNING !!! \n !!!! If you are opening this program for the first time, press the '6' and go to the set the calibration settings !!!!\n\t(This is just for first set up. If you calibrate the system, employer log will be removed. Be carefully!)\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");

	/*this lines for caution.*/



	printf ("\n\n ");
	printf ("***********||Employee Management System||***********\n\n\n");	
	printf ("\t 1.Add record\n\n");			//press 1 for the register new employee to the employer.dat
	printf ("\t 2.List records\n\n");		//press 2 for the list registers.
	printf ("\t 3.Find record\n\n");		//press 3 for the find a specific register.
	printf ("\t 4.Delete record\n\n");		//press 4 for delete a specific register.
	printf ("\t 5.Exit\n\n");				//press 5 for exit from the application.
	printf ("\n\n\n\t 6.Calibration Settings !!!!(Just For First Time)!!!!\n\n\n");		//press 6 for calibrate the system.
	
	m_menu_ask :
	printf ("\n Enter Your Choice : ");
		

	secim=getche();
	if (secim == '1'){				//if the choice is 1, go to case 1.
		
		case_1();
		
	}
	
	
	else if (secim == '2'){			//if the choice is 2, go to case 2.
		
		case_2();
		
	}
	
	
		else if (secim == '3'){		//if the choice is 3, go to case 3.
		
		case_3();
		
	}
	
	
		else if (secim == '4'){		//if the choice is 4, go to case 4.
		
		case_4();
		
	}
	
	
		else if (secim == '5'){		//if the choice is 5, go to case 5.
		
		case_5();
		
	}
			
			
		else if (secim == '6'){		//if the choice is 6, go to case 6.
		
		case_6();
	
	}
	
		else if (secim != '1' || secim != '2' || secim != '3' || secim != '4' || secim != '5' || secim != '6'){
			
			goto m_menu_ask;
			
		}
	
	
	
	
}










int case_1(){		//this function is for choice 1.
	
			FILE *List;
	List = fopen("employer.dat", "a+");			//open employee logs in append mode.


	
	
		struct info{				//declare a 'struct'  named "info" to the computer.
	
	char name[20], surname [30], age[3], position[40];
	char salary[6];
	};
	
	
		struct info infos;		

	
	
				system("cls");			//clear the screen.
		
		printf ("\n\n\n ");
		printf ("**************||Employee Management System||**************");			


		printf ("\n\n\n Person Name : ");
		scanf("%s", infos.name);			//write a name for the 'name' line to the employee.dat.
		fflush(stdin);


		printf ("\n Surname : ");
		scanf("%s", infos.surname);			//write a surname for the 'surname' line to the employee.dat
		fflush(stdin);


		printf ("\n Age : ");
		scanf("%s", infos.age);				//write a age for the 'age' line to the employee.dat
		fflush(stdin);


		printf ("\n Position : ");
		scanf("%s", infos.position);		//write a position for the 'position' line to the employee.dat
		fflush(stdin);


		printf ("\n Basic Salary : ");
		scanf("%s", infos.salary);			//write a salary for the 'salary' line to the employee.dat
		fflush(stdin);
		
		printf("\n\n--------- || Informations || ---------\n\n");		//write the informations to the screen.
		printf("Name : ");
		printf("%s \n", infos.name);			//write name to the screen.
		
		printf("Surname : ");
		printf("%s \n", infos.surname);			//write surname to the screen.
		
		printf("Age : ");
		printf("%s \n", infos.age);				//write the age to the screen.
		
		printf("Position : ");
		printf("%s \n", infos.position);		//write the position to the screen.
		
		printf("Salary : ");
		printf("%s \n", infos.salary);			//write the salary to the screen.
		
		
 
		char ch2;
		reg_con :
		printf("\n\nDo you confirm to registration ? (Y/N) : ");		//ask to user : Do you confirm to registration ?
		ch2 = getche();
		if(ch2 == 'y' || ch2 == 'Y') {
		
			printf("\n\n-Okay. The informations has saved.\n\n");			//if the user want to confirm to registration, write the "-Okay. The informations has saved." to the screen.
			fopen("employer.dat", "a+");			//open employee logs in append+ mode.
			fprintf(List, "%s \t", infos.name);				//print the name to the employee.dat
			fprintf(List, "%s \t", infos.surname);			//print the surname to the employee.dat
			fprintf(List, "%s \t", infos.age);				//print the age to the employee.dat
			fprintf(List, "%s \t", infos.position);			//print the position to the employee.dat
			fprintf(List, "%s \t\n", infos.salary);			//print the salary to the employee.dat
			fclose(List);							//close the employee.dat
						
		}
		
		else if(ch2 == 'n' || ch2 == 'N') {									//if the user don't want to confirm registration, write the "-Okay. The informations has not saved." to the screen.
			
			printf("\n\n-Okay. The informations has not saved.\n\n");
		
		}
		
		else if(ch2 != 'n' || ch2 != 'N' || ch2 != 'y' || ch2 != 'Y'){		//if the user press other button from "N" or "Y", ask the question again.
			
			goto reg_con;
			
		}
		
			char ask_new_record;
		printf("\n Do you want to add new record ? (Y/N) : ");				//ask to user : Do you want to add new record ?
		ask_new_record = getche();
			
		
		if (ask_new_record == 'y' || ask_new_record == 'Y') {				//if the user want to add new register, clean the screen and 
		
			system("cls");
			case_1();
						
		}
		
		if (ask_new_record == 'n' || ask_new_record == 'N') {				//if the user don't want to add new register, clean the screen and go to the main menu.
			
			system("cls");
				main_menu();	
		
		}
	
		return 0;

			
	
}	











int case_2(){				//this function is for see the list of employee.
	
		FILE *List;
		List = fopen("employer.dat", "r+");		//open the employee logs in read+ mode.

	system("cls");			//clean the screen.
		printf("\n**************||Employee Management System||**************\n");
		printf("                  ||List Of Employees||");
		printf("\n\n\n");
		printf("-----------------------------------------------------------------------------------\n");
		printf("|| Name \t || Surname \t || Age \t\t || Position \t\t || Salary \t\t ||\n\n\n");

		rewind(List);		//go to the firs line of emloyer.dat
		char print;				//introduce the char value of 'print' to the computer.
		
		
		while (!feof(List)) {		//read employer.dat from first line to finish line.
				
			fopen("employer.dat", "r");			//open the employee logs in read mode.
			print = getc(List);					//get the informations from employer.dat.
			printf("%c", print);				//write the informations to the screen.

			}
			
		fclose(List);		//close the employer.dat.

		char mm;			//introduce the char value of 'mm' to the computer. The value of 'mm' is to ask the user if he/she wants to return to the main menu.
		printf("\n-----------------------------------------------------------------------------------\n");
		printf("Press 'M' For Go To Main Menu or Press Another One For Exit.");
		mm = getche();		//get a value from keyboard.
		if(mm == 'm' || mm == 'M'){		//if the user wants to go to the main menu, go to main_menu function.
			
			main_menu();
			
		}
		
		else{							//if the user don't want to go to the main menu, close the system.
			
			return 0;
			
		}
	
}










int case_3(){		//this function is for find a specific name informations in employer.dat
	
	char wdyw;		//introduce the char value of wdyw to the computer. The value of 'wdyw' is to ask the user if he/she wants to return to the main menu or do another thing.
	
	
			FILE *List;
			List = fopen("employer.dat", "r+");		//open employee logs in read+ mode.
	
		system("cls");			//clear the screen.
			    rewind(List);		//go to the first line of employer.dat.
                find();				//go to the 'find' function.
                
				what_dyw :		//ask to user : What do you want ?
                printf("\nWhat do you want ? (M = Main menu, A = Find again, E = Exit) : ");
                wdyw = getche();
                
                if(wdyw == 'm' || wdyw == 'M'){					//if the user go to the main menu, he/she should press to "M".
                	main_menu();
                	
				}
                
                else if(wdyw == 'e' || wdyw == 'E'){			//if the user exit from the program, he/she should press to "E".
                	
                	return 0;
                	
				}
                
                else if(wdyw == 'a' || wdyw == 'A'){			//if the user find another register, he/she should press to "A".
                	
                	case_3();
				}
				
				else if(wdyw != 'm' || wdyw != 'M' || wdyw != 'e' || wdyw != 'E' || wdyw != 'a' || wdyw != 'A'){			//if the user press other button from "M", "E" or "A", ask the question again.
					
					goto what_dyw;
					
				}
                
	
	
}










int case_4(){				//this function is for delete a specific register from "employer.dat".

	char sfr;				//introduce the char value of 'sfr' to the computer. The value of 'sfr' is to ask the user if he/she wants to remove an another specific register from the "employer.dat".
	char wdyw2;				//introduce the char value of 'wdyw2' to the computer. The value of 'wdyw2' is to ask the user if he/she wants to return to the main menu or do another thing.
	

	system("cls");		//clear the screen.
	
		printf("-----------------------------------------------------------------------------------\n"); 
		printf("\n**************||Employee Management System||**************\n");
		printf("           ||Delete Employee Register Screen||\n\n");
		printf(" WARNING : If this function does not work properly, turn off the system then turn it on again.\n\n ");
		printf("-----------------------------------------------------------------------------------\n"); 
		
		
		rem_register();		//go to "rem_register" function.
				printf("\n\nDo you want to delete another register ? (Y/N) : ");		//ask to user : Do you want to delete another register ?.
				sfr = getche();		//get the value from keyboard.
				
				if(sfr == 'y' || sfr == 'Y'){				//if the user want to delete another register, go to the function of "case_4".
					
					case_4();
				
			}
				
				else if(sfr == 'n' || sfr == 'N'){	
					
					whdyw :
					printf("\n\n Okay than, what do you want ? (M = Main menu, E = Exit) : ");		//if the user don't want to delete another register, ask to user :  Okay than, what do you want ?.
					wdyw2 = getche();
					
					if(wdyw2 == 'm' || wdyw2 == 'M'){			//if the user wants to go to the main menu, he/she should press to the "M".
						
						main_menu();
						
					}
					
					
					else if(wdyw2 == 'e' || wdyw2 == 'E'){		//if the user wants to exit from the program, he/she should press to the "E".
						
						return 0;
						
					}
					
					
					else if(wdyw2 != 'm' || wdyw2 != 'M' || wdyw2 != 'e' || wdyw2 != 'E'){			//if the user press other button from "M" or "E", ask the question again.
						
						goto whdyw;
						
					}
					
					
				}
				
				
}










int case_5(){		//this function is for exit from the application.
	
			system("cls");		//clear the screen.
		printf("\n**************||Employee Management System||**************\n\n");
		printf("\nOkay than. I will close the system...\n\n\n");
	
	return 0;					//exit from the program.
}










int case_6(){		//this function is the calibration screen for the system to run properly.
	
	
		system("cls");		//clear the screen.
		char c_correct;		//introduce the char values to the computer.
		char ret_ma_me;
		c_ask :
			
		printf("\n\n\n------------------------------------------------------------------------------------------------------------------------");
		printf("\n WARNING !!!! Your choice was 'C'. Your employer logs will be removed. Are you sure to this ? (Y/N)");							//this line warns the user. "This function is dangerious".
		printf("\n------------------------------------------------------------------------------------------------------------------------\n");
		printf(" Your choice is : ");		//ask to the user : "Are you sure to this ?".
		c_correct = getche();		//get the value from the keyboard.
		
		if (c_correct == 'y' || c_correct == 'Y'){						//if the user wants to calibrate the system, go to the calibration function "first_setup".
			
					first_setup();
					
				press_m :
			
				printf("\n Calibration has completed. Press 'M' for return to 'Main Menu'. \n");		//after the calibration, say to the user : "Press 'M' for return to the main menu".
				ret_ma_me = getche();		//ger the value from the keyboard.
				
				if (ret_ma_me == 'm' || ret_ma_me == 'M'){		//if the user press the "M", go to the main menu.
				
					main_menu();
				
				}

			else if (ret_ma_me != 'M' || ret_ma_me != 'm'){		//if the user press other button from "M", say again : "Press 'M' for return to the main menu".
				
				goto press_m;
				
				}
				
					
			}

		else if (c_correct == 'n' || c_correct == 'N'){					//if the user dont want to calibrate the system, say : "Press 'M' for return to the main menu" to the user.
			
			
			press_m2 :
			printf("\n Okay than. Press 'M' for return to main menu. \n");		//if the user wants to return to main menu, he/she should press to the "M".
			ret_ma_me = getche();
			if (ret_ma_me == 'm' || ret_ma_me == 'M'){			//if the user press the "M", return to the main menu.
				
					main_menu();
				
				}

			else if (ret_ma_me != 'M' || ret_ma_me != 'm'){		//if the user pross other button from "M", say again : "Press 'M' for return to the main menu".
				
				goto press_m2;
				
				}
			
			
				
						
		}

		else if (c_correct != 'n' || c_correct != 'N' || c_correct != 'y' || c_correct != 'Y'){				//if the user press other button from "N" or "Y" when the calibration screen, ask to the user again : "Are you sure to this ?".
			
			goto c_ask;
			
		}
		
	
}










int main(void) {		//this funciton is our main function.
	
	
	long int recsize;
	
	
	main_menu();		//go to the main menu.
	


	return 0;

}


