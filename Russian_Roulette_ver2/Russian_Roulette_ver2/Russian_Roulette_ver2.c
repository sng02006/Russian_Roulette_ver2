//러시안 룰렛
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

    printf("안녕하세요. 러시안 룰렛 게임입니다.\n\n");

    while(1) {
        printf("1. 게임시작\n");
        printf("2. 사용자 등록\n");
        printf("3. 사용자 삭제\n");
        printf("4. 사용자 목록 보기\n");
        printf("5. 게임 종료\n");

        printf("번호를 선택해 주세요. ");
        scanf("%d", &select_num);
        printf("\n");
        Sleep(1000);
        system("cls");

        switch(select_num) {
            case 1 :
                if ((number_of_user == 0) || (number_of_user == 1)) {
                    printf("참가자 수가 적어서 게임을 시작할 수 없습니다.\n");
                    printf("사용자를 2명 이상 등록하고 게임을 시작해주세요.\n");
                    return_to_1st_scr();
                    break;
                }
                else {
                    printf("게임을 시작합니다.\n");
                    Sleep(1000);
                    system("cls");

                    user = game_start(number_of_user, user);
                    number_of_user = 1;

					Sleep(3000);
                    system("cls");
                    break;
                }

            case 2 :
                printf("사용자를 등록합니다.\n");
                printf("사용자는 6명 까지만 등록할 수 있습니다.\n");
                printf("몇 명의 사용자를 등록하시겠습니까? ");
                scanf("%d", &i);
                printf("\n");

                number_of_user += i;

                if((i > 6) || (number_of_user > 6)) {
                    printf("사용자는 6명 까지만 등록할 수 있습니다.\n");
                    return_to_1st_scr();
                    break;
                }

                user = create_users(i, user);

                i = 0;

                printf("사용자 등록을 마쳤습니다.\n");
                return_to_1st_scr();
                break;

            case 3 :
                if(number_of_user == 0) {
                    printf("삭제할 사용자가 없습니다.\n");
                    return_to_1st_scr();
                    break;
                }
                else {
                    printf("사용자를 삭제합니다.\n");
                    printf("몇 번 사용자를 삭제 하시겠습니까? ");
                    scanf("%d", &i);
                    printf("\n");

                    if(i > number_of_user) {
                        printf("%d번 사용자가 등록되어있지 않습니다.\n", i);
                        return_to_1st_scr();
                        break;
                    }

                    user = delete_user(i, user);
                    printf("%d번 사용자 삭제를 마쳤습니다.\n", i);

                    number_of_user--;
                    i = 0;

                    if(number_of_user == 0)
                        user = NULL;

                    return_to_1st_scr();
                    break;
                }

            case 4 :
                printf("사용자 목록입니다.\n");
                printf("현재 %d명 등록되어 있습니다.\n", number_of_user);

                if(number_of_user != 0) {
                    printlist(user);
                }

				Sleep(3000);
                system("cls");
                break;

            case 5 :
                printf("게임을 종료합니다.\n");
                Sleep(1000);
                exit(0);

            default :
                printf("잘못된 입력입니다. 번호를 다시 입력해주세요.\n");
                return_to_1st_scr();
                break;
        }

    }
    return 0;
}
