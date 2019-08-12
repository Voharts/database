#include<iostream>
#include<cstdlib> //  exit()
#include<iomanip>
#include<fstream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<conio.h>
using namespace std;

struct student
{
	char surname[30];
	char name[30];
	
	int mark;
	
};


void Vxod()
{
	const char pass_word[50]="Hellow";
	char password[50];
	cout<<"Введите пароль: "<<"\t";
	cin>>password;
	if(strstr(password,pass_word))
	cout<<"пароль верный"<<endl;

	else
	{
		cout<<"Пароль не верный"<<endl;
		exit(0);
	}
}

void sort(student *Otdel, int N)
{	
	for(int i=0; i<N; i++)
		for(int j= N-1; j>i; j--)
			if(Otdel[j-1].mark > Otdel[j].mark)
				swap(Otdel[j-1], Otdel[j]);
}
void Sort_Alf(student *Otdel, int N)
{	student tmp;
	for(int t=0; t<N; t++)
		for(int i=0; i<N; i++)
			if(Otdel[i].surname >Otdel[t].surname)
			{
				tmp=Otdel[i];
				Otdel[i]=Otdel[t];
				Otdel[t]=tmp;
			}
			cout<<endl;
}


void poisk()
{
	ifstream ff;
	ff.open("list.txt", ios::in | ios::binary);
	struct student s;
	char fam[30];
	int poisk=0;
	cout<<"Введите фамилию для поиска"<<endl;
	cin>>fam;
	if(!ff.is_open()) cout<<"Error";
	while(ff.read((char*) &s, sizeof(s)))
	{	  

	
		if(strcmp(s.surname,fam)==0)
		{   
			poisk=1;
			cout<<"FIO "<<s.surname<<" "<<s.name<<" Mark "<<s.mark<<endl;
			break;
		}
	}
		if(poisk==0) 
		{
			cout<<"Такой фамилии нет"<<endl;
		}
	ff.close();
}

	
void Delete()
{
	ifstream in("list.txt", ios::in | ios::binary);
	ofstream out("list1.txt", ios::out | ios::binary);
	
	struct student s;
	char fam[30];
	int poisk=0;
	cout<<"Введите фамилию для удаления"<<endl;
	cin>>fam;
	if(!in.is_open()) cout<<"Error";
	while(in.read((char*) &s, sizeof(s)))
	{	  

	
		if(strcmp(s.surname,fam)==0)
		{   
			poisk=1;
			cout<<"FIO  "<<s.surname<<endl<<"mark  "<<s.mark<<endl;
			continue;
		}
		out.write((char*)&s,sizeof(s));
	}
		if(poisk==0) 
		{
			cout<<"Такой фамилии нет"<<endl;
		}
		else
		cout<<"запись удалена"<<endl;
		in.close();
		out.close();
		remove("list.txt");
		rename("list1.txt", "list.txt");
}



int main()
{    
	
		setlocale( LC_ALL,"Russian" );
    	const char pass_word[50]="Hellow";
    	const char pass_word2[50]="Yes";
		char password[50];
		cout<<"Введите пароль: "<<"\t";
		cin>>password;
		if(strstr(password,pass_word))
		{
			cout<<"пароль верный"<<endl;

	
    	
    	int N;
    	cout<<"Если хотите создать новую базу данных, "<<endl;
    	cout<<"то введите количество учащихся и выберите пункт 1."<<endl;
    	cout<<"Если хотите работать с старой базой данных, то введите любое число"<<endl;
    	cout<<"и используйте все пункты меню, кроме пункта 1."<<endl;
    	cout<<"Если вы нажмете пункт меню 1., то вы сотрете старую базу данных"<<endl;
    	cout<<endl;
    	cout<<"=>";
    	cin>>N;
    	struct student Otdel[N];
    	
   		 int variant = 0;

    	do
		{

    	cout << "Выберите вариант\n" << endl;
    	cout << "1. Введите учащихся\n"<< endl;
    	cout << "2. Просмотр данных об учащихся\n"<< endl;
    	cout << "3. Дополнение учащихся и их данных\n"<< endl;
    	cout << "4. Поиск данных\n"<< endl;
    	cout << "5. Удаление данных\n"<<endl;
       	cout << "0. Выход из программы\n" << endl;
    	cout << "==> ";
    	cin >> variant;
    
 	
		 
		 		    	
   	 	switch (variant) 
		{
        	case 1:
			{	
				ofstream list;
				list.open("list.txt", ios::out | ios::binary);
				int i;
				                         
				for(i=0; i<N; i++)
				{	
					cin.sync();                   // очистка  cin  от  Enter
					cout <<"Введите ФИО учащегося"<<endl; 
				    cin.getline(Otdel[i].surname, 30);
				    cin.getline(Otdel[i].name, 30);
					cout <<"Введите среднюю оценку учащихся"<<endl;   
					cin>>Otdel[i].mark;	
				}
				int variant1=0;
				do
				{
					cout<<"1. Сортировка данных\n"<<endl;
					cout<<"2. Сортировка по алфавиту\n"<<endl;
					cout<<"0. Выход из этого меню\n"<<endl;
					cin>>variant1;
					switch(variant1)
					{
						case 1:
						{
							sort(Otdel, N);
							cout<<"Данные отсортированны\n"<<endl;
							break;
						}
						case 2:
						{
							Sort_Alf(Otdel,N);
							cout<<"Данные отсортированы по алфавиту"<<endl;
							break;
						}
						case 0:
						{
							cout << "Выход" << endl;
            			
            				break;
            			}
        					default:
            				cerr << "ТАКОГО ЧИСЛА НЕТ, ВЫБЕРИТЕ ЗАНОВО" << endl;	
					}
					
				}
				while(variant1 !=0);			
				for(i=0; i<N; i++)
				list.write((char*)&Otdel[i],sizeof(student));
				list.close();
            	
            	break;
            }
        	case 2:
        	{
				
				cout << "Данные об учащихся" << endl;
        	
        		int i;
        	  	ifstream l;
        	   	l.open("C:\\Сережа\\C++\\list.txt", ios::out | ios::binary);
        	   	if(!l.is_open()) cout<<"Error"<<endl;
        	   	student s;
        	   	while(!l.eof())
        	   	{
			   		l.read((char*)&s,sizeof(student));
        	   		cout<<"FIO "<<s.surname<<" "<<s.name<<" "<<"Mark "<<s.mark<<'\n';
        	   		if(l.peek()==EOF) break;
			 	}
			 	l.close();
				break;
            }
        	case 3: 
        	{   
        		cout<<"Введите количество учащихся для дополнения"<<endl;
        		cin>>N;
											   
			    int i;
			    ofstream f("C:\\Сережа\\C++\\list.txt", ios::out|ios::binary|ios::app); //Открытие файла и дозапись в конец
			    
			    for(i=0; i<N; i++)
				{ 
					cin.sync();
					cout <<"Введите ФИО учащегося"<<endl;
					cin.getline(Otdel[i].surname, 30);
					cin.getline(Otdel[i].name, 30);
					cout <<"Введите среднюю оценку учащихся"<<endl;
					cin>>Otdel[i].mark;
				}
				
				for(i=0; i<N; i++)
				f.write((char*)&Otdel[i],sizeof(student));
			    f.close();
            	break;
            }
            case 4:
            {   poisk();
            	break;
			}
			case 5:
            {   Delete();
            	break;
			}
			case 0:
            	cout << "Выход из программы" << endl;
            	exit(EXIT_SUCCESS);
            	break;
        	default:
            	cerr << "ТАКОГО ЧИСЛА НЕТ, ВЫБЕРИТЕ ЗАНОВО" << endl;
            	
   	   }
    }
    
    while(variant !=0);}
	
		if(strstr(password,pass_word2))
		{
				cout<<"пароль верный "<<endl;
				cout<<"ВЫ ВОШЛИ КАК ПОЛЬЗОВАТЕЛЬ"<<endl;
			
		    	
    	int N;
    
    	struct student Otdel[N];
    	
    int variant = 0;

    do
	{

    	cout << "Выберите вариант\n" << endl;
    	cout << "1. Просмотр данных об учащихся\n"<< endl;
       	cout << "2. Поиск данных\n"<< endl;
       	cout << "0. Выход из программы\n" << endl;
    	cout << "==> ";
    	cin >> variant;
    
 	
		 
		 		    	
   	 	switch (variant) 
		{
        
        	case 1:
        	{
				
				cout << "Данные об учащихся" << endl;
        	
        		int i;
        	  	ifstream l;
        	   	l.open("C:\\Сережа\\C++\\list.txt", ios::out | ios::binary);
        	   	if(!l.is_open()) cout<<"Error"<<endl;
        	   	student s;
        	   	while(!l.eof())
        	   	{
			   		l.read((char*)&s,sizeof(student));
        	   		cout<<"FIO "<<s.surname<<" "<<s.name<<" "<<"Mark "<<s.mark<<'\n';
        	   		if(l.peek()==EOF) break;
			 	}
			 	l.close();
				break;
            }
        
            case 2:
            {   poisk();
            	break;
			}
			case 0:
            	cout << "Выход из программы" << endl;
            	exit(EXIT_SUCCESS);
            	break;
        	default:
            	cerr << "ТАКОГО ЧИСЛА НЕТ, ВЫБЕРИТЕ ЗАНОВО" << endl;
            	
   	   }
    }
    
    while(variant !=0);}
		else
		{
		cout<<"Пароль не верный"<<endl;
		exit(0);
		}	
    return 0;
}

