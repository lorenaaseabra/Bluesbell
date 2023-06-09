# Bluesbell
## Sistema de Controle Financeiro em C
Este repositório contém um código em C para um sistema de controle financeiro. O sistema permite que os usuários cadastrem-se, façam login, registrem entradas e saídas financeiras, gerem relatórios de gastos por categoria e tenham acesso aos dados salvos.

## Funcionalidades
* Cadastro de usuários: Os usuários podem se cadastrar fornecendo seu nome, e-mail e senha.
* Login: Os usuários podem fazer login no sistema usando seu e-mail e senha.
* Registro de entradas: Os usuários podem registrar valores de entrada financeira.
* Registro de saídas: Os usuários podem registrar valores de saída financeira em três categorias: lazer, alimentação e contas fixas.
* Extrato total: Os usuários podem visualizar o extrato total de suas entradas e saídas financeiras.
* Relatório de gastos por categoria: Os usuários podem gerar um relatório detalhando os gastos em cada categoria selecionada.
* Encerramento: Os usuários podem encerrar as atividades do sistema.

## Como executar
Certifique-se de ter um compilador C instalado em seu sistema. Em seguida, siga as instruções abaixo:

1.. Clone este repositório em sua máquina:

```
git clone https://github.com/lorenaaseabra/bluesbell.git
```
2. Acesse o diretório do projeto:
```
cd bluesbell
```
3. Compile o código usando o compilador C:

```
gcc -o bluesbell bluesbell.c
```
4. Execute o programa:

```
./bluesbell
```
## Observações
* Os dados de usuário são salvos em um arquivo "Person.txt".
* Os valores de entrada são salvos em um arquivo "Input.txt".
* Os valores de saída são salvos em um arquivo "Output.txt".
Sinta-se à vontade para contribuir para este repositório ou utilizar o código como base para o seu próprio sistema de controle financeiro.
