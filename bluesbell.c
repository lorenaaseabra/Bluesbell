#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  char name[30];
  char mail[50];
  char password[50],passwordTest[50];
}People;
/// numeros podem ser float no input 
typedef struct
{
  int input;
}ValueIn;

typedef struct
{
  int outputLazer, outputAlimentacao, outputFixo;
}ValueOut;

People Person;
ValueIn Entrada[10];
ValueOut Saida[10];
char **lines_split;

//////////////////// pessoa////////////////////////

////// cadastro ////////////

People fullfillPerson(int tam)
{
  for(int i = 0; i < tam; i++)
    {
      int flag = 0;
      printf("Qual seu nome?\n");
      scanf("%s", Person.name);
      getchar();

      printf("\nDigite o seu email: \n");
      scanf("%s", Person.mail);
      getchar();

      /////////////// check password /////////////
      do{
        printf("\nDigite sua senha: \n");
        scanf("%s",Person.password);
        getchar();
        
        printf("\nConfirme sua senha: \n");
        scanf("%s",Person.passwordTest);
        getchar();
        if (!strcmp(Person.password,Person.passwordTest)){
          printf("\nVocê se cadastrou com sucesso, já pode fazer o seu login!\n");
          flag = 0;
        }
        else{
          printf("\nAs senhas não conferem. Tente novamente.\n");
          flag = 1;
        }
      }while (flag != 0);
    }
    return Person;
}
// apos se cadastrar o programa ta encerrando, e tem que ser em loop 

void savePerson(int tam)
{
  
  FILE* file = fopen("Person.txt", "a+");
  fprintf(file,"%s,%s,%s\n",Person.name,Person.password,Person.mail);
  fclose(file);

  
}

void printPerson(int tam)
{
  for(int i = 0; i < tam; i++)
    {
      // nao ta pegando o nome - detail
      printf("\nOla, %s !\nEsse é o seu email: %s\nEssa é a sua senha: %s", Person.name, Person.mail, Person.password);
    }
}

///////// Login/////////
/// e se o cadastro e login fizer com switch case? acho valido fazer assim 


People loginPerson(int tam)
{

    printf("Email: \n");
    scanf("%s", Person.mail);
    getchar();

    printf("\nDigite sua senha: \n");
    scanf("%s",Person.password);
    getchar();

    return Person;

}

int count_lines()
{
  int count = 0,test;
  char buffer[100];
  FILE* file = fopen("Person.txt", "r");
  while (test != EOF){
    test = fscanf(file, "%s", buffer);
    if(test != EOF){
      count++;
    }
  }
  fclose(file);
  return count;
}

void my_split(char *st,int lines)
{
  int i = 0;
  char *token = strtok(st, ",");
  char *newstr;
  while( token != NULL ) {
      if(i==2){
        newstr = strtok(token, "\n");
        lines_split[i] = newstr;
      }else{
        lines_split[i] = token;
      }
      token = strtok(NULL, ",");
      i++;
   }
}

int check_login(int lines)
{
  int test,i=0;
  int flag = 0;
  size_t read;
  size_t len = 0;
  char **lines_file = malloc(lines);
  for (int i = 0; i < lines; i++){
    lines_file[i] = malloc(100);
  }
  
  FILE* file = fopen("Person.txt", "r");
  while(read != -1){
      read = getline(&lines_file[i], &len, file);
      i++;
  }
  fclose(file);
  
  
  lines_split = (char **)malloc(3);
  for (int i = 0; i < lines; i++){
    lines_split[i] = (char *)malloc(50);
  }

  char *mail_check = Person.mail;
  char *pass_check = Person.password;

  for (int i = 0; i < lines; i++){
    my_split(lines_file[i],lines);
    if(!strcmp(mail_check,lines_split[2]) && !strcmp(pass_check,lines_split[1])){
      flag = 1;
      break;
    }else{
      flag = 0;
    }
    
  }
  
  free(lines_split);
  free(lines_file);
  if(flag == 1){
    return 1;
  }
  return 0;
  
}

/////////////////////// extrato //////////////////////////////////
/////////////input//////////////
int fillInput(int tam)
{
      int i = 0;
      printf("\n\ninforme o valor da entrada: \n");
      scanf("%d", &Entrada[i].input);
    return 0;
}
void saveInput(int tam)
{
  for(int i = 0;i<tam;i++)
  {
    FILE* file = fopen("Input.txt", "a+");
    fprintf(file,"%d\n",Entrada[i].input);
    fclose(file);
  }
}

void printInput(int tam)
{
   printf("\nEntradas: \n");
  for(int i = 0; i < tam; i++){
      //int sum;
    // fazer  a soma dos valores das entradas 
      //sum = Entrada[i].input ++; ?
    // pegar do arqv 
      printf("%d \n", Entrada[i].input);
    }
}
/////////////output////////////////
int fillOutput(int tam)
{
  int gasto;
  printf("\nInforme com o que voce gastou\n\n");
  printf("1- lazer\n");
  printf("2- alimentacao\n");
  printf("3- contas fixas\n");
  scanf("%d", &gasto);
  switch(gasto)
  {
    case 1:
      for(int i = 0; i < tam; i++)
      {
        printf("\ninforme o valor da saida: \n");
        scanf("%d", &Saida[i].outputLazer);
      }
      break;
    case 2:
      for(int i = 0; i < tam; i++)
      {
        printf("\ninforme o valor da saida: \n");
        scanf("%d", &Saida[i].outputAlimentacao);
      }
      break;
    case 3:
      for(int i = 0; i < tam; i++)
      {
        printf("\ninforme o valor da saida: \n");
        scanf("%d", &Saida[i].outputFixo);
      }
      break;
  }
  return 0;
}

void saveOutput(int tam)
{
  for(int i = 0;i<tam;i++){
    FILE* file = fopen("Output.txt", "a+");
    fprintf(file,"%d%d%d\n",Saida[i].outputLazer,Saida[i].outputAlimentacao,Saida[i].outputFixo );
    fclose(file);
  }
}

void printOutput(int tam)
{
  // ta printando sõ um valor por categoria 
  printf("\nSaidas: \n");
  for(int i = 0; i < tam; i++){
      printf("\nLazer: ");
      printf("%d", Saida[i].outputLazer);
    //sum dos outputs por categoria e no total 
  
  }
  for(int i = 0; i < tam; i++){
      printf("\nAlimentação: ");
      printf("%d", Saida[i].outputAlimentacao);

  }
  for(int i = 0; i < tam; i++){
      printf("\nGasto fixo: ");
      printf("%d", Saida[i].outputFixo);
       
  }
}

////Relatorio por categoria////
void reportCategory(int tam)
{
  int opc;
  printf("\nInforme qual categoria voce quer o extrato\n\n");
  printf("1- lazer\n");
  printf("2- alimentacao\n");
  printf("3- contas fixas\n");
  printf("4- todos\n");
  scanf("%d", &opc);
  
  switch(opc)
  {
    case 1:
      printf("\nGastos com Lazer: \n");
      for(int i = 0; i < tam; i++){
          printf("%d \n", Saida[i].outputLazer);
      }
      break;
    case 2:
      printf("\nGastos com alimentacao: \n");
      for(int i = 0; i < tam; i++){
          printf("%d \n", Saida[i].outputAlimentacao);
      }
      break;
    case 3:
      printf("\nGastos fixos: \n");
      for(int i = 0; i < tam; i++){
          printf("%d \n", Saida[i].outputFixo);
      }
      break;
    case 4:
      printf("\naqui estao todos os seus gastos: \n\n");
      printf("\nGastos com Lazer: \n");
      for(int i = 0; i < tam; i++){
          printf("%d \n", Saida[i].outputLazer);
      }
      printf("\nGastos com alimentacao: \n");
      for(int i = 0; i < tam; i++){
          printf("%d \n", Saida[i].outputAlimentacao);
      }
      printf("\nGastos fixos: \n");
      for(int i = 0; i < tam; i++){
          printf("%d \n", Saida[i].outputFixo);
      }
      break;
  }
}

void financesControl()
{
        int menu;
        printf("\n\n------------CONTROLE FINANCEIRO------------");
        printf("\n\n");
        printf("\n 1- Extrato total");
        printf("\n 2- Entradas");
        printf("\n 3- Saídas");
        printf("\n 4- Relatório de gastos por categoria");
        printf("\n 5- Relatório em um determinado periodo de tempo");
        printf("\n 6- Ver os dados");
        printf("\n 7- Encerrar as atividades");
        printf("\n\n");
        printf("\nDigite a opção desejada: ");
        scanf("%d",&menu);
        switch(menu){
                case 1:
                // nao ta salvando as info
                        printf("\nVocê solicitou o extrato total\n");
                        printInput(10);
                        printOutput(10);
                        financesControl();
                        break;
                
                case 2:
                        printf("\nInputs\n");
                        fillInput(10);
                        saveInput(10);  
                        printInput(10);
                        financesControl();  
                        break;
                
                case 3:
                        printf("\nOutputs\n");
                        fillOutput(10);
                        saveOutput(10);
                        printOutput(10); 
                        financesControl();
                        break;
                
                case 4:
                        printf("\nVocê solicitou o relatório de gastos por categoria\n");
                        reportCategory(10);
                        financesControl();
                        break;
                
                case 5:
                        printf("\nVocê solicitou o relatório em um período de tempo\n/");
                        //reportTime();
                        financesControl();
                        break;
                
                case 6:
                        //pq nao salva os dados??? e coloca senha aleatoria
                        printPerson(1);
                        financesControl();
                        break;
                case 7:
                        printf("\nAte a proxima!");
                        break;
        }
}

void finance(){
  // trazer o controle financeiro pra ca 
}

int main(void) 
{  
  int acess;
  int flag = 0;
  
  printf("-------------------------\n");
  printf("   BLUEBELL$ FINANC€\n");
  printf("-------------------------\n\n");

  printf("-------------INÍCIO-------------\n");
  printf("1 - Cadastro\n");
  printf("2 - Login\n \n");
  printf("seleciona a opcao:");
  scanf("%d",&acess);
  
  switch(acess){
    case 1:
      printf("\n-------------CADASTRO-------------\n");
      Person = fullfillPerson(1);
      savePerson(1);
      do{
          int lines = count_lines();
          Person = loginPerson(1);
          int verified = check_login(lines);
          
          if (verified == 1){
              printf("\nBem vindo!\n");
              financesControl();
              flag = 0;
        }
        else{
          printf("\nSenha Errada!\n");
          main();
          flag = 1;
        }
      }while (flag != 0);
      break;
    case 2:
      printf("\n-------------LOGIN-------------\n");
      do{
          int lines = count_lines();
          Person = loginPerson(1);
          int verified = check_login(lines);
          
          if (verified == 1){
              printf("\nBem vindo!\n");
              financesControl();
              flag = 0;
        }
        else{
          printf("\nSenha Errada!\n");
          main();
          flag = 1;
        }
      }while (flag != 0);

      break;
  }
  return 0;
