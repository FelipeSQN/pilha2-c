#include <stdio.h>

#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = -1;

int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isfull()
{
    if (top == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

int peek()
{
    if (!isempty())
        return stack[top];
    else
        return -1;
}

void push(int value)
{
    if (!isfull())
    {
        top++;
        stack[top] = value;
        printf("%d foi adicionado na pilha.\n", value);
    }
    else
        printf("A pilha está cheia.\n");
}

void pop()
{
    if (!isempty())
    {
        printf("%d foi removido da pilha.\n", stack[top]);
        top--;
    }
    else
        printf("A pilha está vazia.\n");
}

void print_stack()
{
    if (!isempty())
    {
        printf("Pilha: ");
        for (int i = 0; i <= top; i++)
            printf("%d ", stack[i]);
        printf("\n");
    }
    else
        printf("A pilha está vazia.\n");
}

int main()
{
    int op, value;

    do
    {
        printf("\nMenu:\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Verificar o topo\n");
        printf("4 - Imprimir a pilha\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                printf("Digite o valor a ser empilhado: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                value = peek();
                if (value != -1)
                    printf("Topo da pilha: %d\n", value);
                else
                    printf("A pilha está vazia.\n");
                break;
            case 4:
                print_stack();
                break;
            case 5:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (op != 5);

    return 0;
}
