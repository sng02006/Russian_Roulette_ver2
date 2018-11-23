//���þ� �귿
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "Russian_Roulette_ver2.h"

int main()
{
    int i = 0;
    int select_num = 0;
    int number_of_user = 0;
    USER *user = NULL;

    printf("�ȳ��ϼ���. ���þ� �귿 �����Դϴ�.\n\n");

    while(1) {
        printf("1. ���ӽ���\n");
        printf("2. ����� ���\n");
        printf("3. ����� ����\n");
        printf("4. ����� ��� ����\n");
        printf("5. ���� ����\n");

        printf("��ȣ�� ������ �ּ���. ");
        scanf("%d", &select_num);
        printf("\n");
        Sleep(1000);
        system("cls");

        switch(select_num) {
            case 1 :
                if ((number_of_user == 0) || (number_of_user == 1)) {
                    printf("������ ���� ��� ������ ������ �� �����ϴ�.\n");
                    printf("����ڸ� 2�� �̻� ����ϰ� ������ �������ּ���.\n");
                    return_to_1st_scr();
                    break;
                }
                else {
                    printf("������ �����մϴ�.\n");
                    Sleep(1000);
                    system("cls");

                    user = game_start(number_of_user, user);
                    number_of_user = 1;

					Sleep(3000);
                    system("cls");
                    break;
                }

            case 2 :
                printf("����ڸ� ����մϴ�.\n");
                printf("����ڴ� 6�� ������ ����� �� �ֽ��ϴ�.\n");
                printf("�� ���� ����ڸ� ����Ͻðڽ��ϱ�? ");
                scanf("%d", &i);
                printf("\n");

                number_of_user += i;

                if((i > 6) || (number_of_user > 6)) {
                    printf("����ڴ� 6�� ������ ����� �� �ֽ��ϴ�.\n");
                    return_to_1st_scr();
                    break;
                }

                user = create_users(i, user);

                i = 0;

                printf("����� ����� ���ƽ��ϴ�.\n");
                return_to_1st_scr();
                break;

            case 3 :
                if(number_of_user == 0) {
                    printf("������ ����ڰ� �����ϴ�.\n");
                    return_to_1st_scr();
                    break;
                }
                else {
                    printf("����ڸ� �����մϴ�.\n");
                    printf("�� �� ����ڸ� ���� �Ͻðڽ��ϱ�? ");
                    scanf("%d", &i);
                    printf("\n");

                    if(i > number_of_user) {
                        printf("%d�� ����ڰ� ��ϵǾ����� �ʽ��ϴ�.\n", i);
                        return_to_1st_scr();
                        break;
                    }

                    user = delete_user(i, user);
                    printf("%d�� ����� ������ ���ƽ��ϴ�.\n", i);

                    number_of_user--;
                    i = 0;

                    if(number_of_user == 0)
                        user = NULL;

                    return_to_1st_scr();
                    break;
                }

            case 4 :
                printf("����� ����Դϴ�.\n");
                printf("���� %d�� ��ϵǾ� �ֽ��ϴ�.\n", number_of_user);

                if(number_of_user != 0) {
                    printlist(user);
                }

				Sleep(3000);
                system("cls");
                break;

            case 5 :
                printf("������ �����մϴ�.\n");
                Sleep(1000);
                exit(0);

            default :
                printf("�߸��� �Է��Դϴ�. ��ȣ�� �ٽ� �Է����ּ���.\n");
                return_to_1st_scr();
                break;
        }

    }
    return 0;
}
