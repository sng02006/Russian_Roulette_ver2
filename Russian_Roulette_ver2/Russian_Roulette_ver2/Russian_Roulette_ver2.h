#ifndef Russian_Roulette_ver2_H_INCLUDED
#define Russian_Roulette_ver2_H_INCLUDED

typedef struct user {
    int num;
    char *name;
    struct user *next;
}USER;

void return_to_1st_scr();
USER* game_start(int number_of_user, USER* user);
USER* create_users(int i, USER* user);
USER* create_user(int player_num);
USER* delete_user(int i, USER* user);
void printlist(USER* user);

void return_to_1st_scr() {
    printf("다시 게임 시작 화면으로 넘어갑니다.\n");
    Sleep(3000);
    system("cls");
}

USER* game_start(int number_of_user, USER* user) {
    int revolver;
    int first;
    USER* temp;

    srand(time(NULL));

    printlist(user);

    while(number_of_user > 1) {
        revolver = rand() % 6 + 1;
        //printf("%d번 탄창에 들어있음.\n\n", revolver);
        first = rand() % number_of_user + 1;

        temp = user;

        while (temp->num != first) {
            temp = temp->next;
        }

        while(revolver != 0) {
            if(revolver != 1) {
                Sleep(1500);
                printf("틱\n");
                printf("%d번 참가자가 생존하였습니다.\n", temp->num);
                printf("다음 참가자로 넘어갑니다.\n\n");
                temp = temp->next;
            }
            else {
                Sleep(1500);
                printf("탕!!\n");
                printf("%d번 참가자가 사망하였습니다.\n\n", temp->num);
                user = delete_user(temp->num, user);
                printf("사망한 참가자 이후의 번호가 1씩 당겨집니다.\n\n");
                printlist(user);
                number_of_user--;
            }

            revolver--;
        }

    }

    printf("최종 생존자는 %s입니다.\n", user->name);

    return user;
}

USER* create_users(int i, USER* user) {
    int player_num = 1;
    int k = 1;

    USER* head;
	USER* ptr;
	USER* newptr;

	if(!user) {
        user = head = ptr = create_user(player_num);
	}
	else {
        head = ptr = user;

        while(ptr->next != head) {
            ptr = ptr->next;
            player_num++;
        }

        k--;
        player_num++;
	}

	for(; k < i; k++) {
        newptr = create_user(player_num + k);
        ptr->next = newptr;
        newptr->next = head;
        ptr = newptr;
	}

	return user;
}

USER* create_user(int player_num) {
    USER *newptr;
    char name_temp[11];

    newptr = (USER*)malloc(sizeof(USER));

    newptr->num = (int)malloc(sizeof(int));
    newptr->name = (char*)malloc(sizeof(char)*strlen(name_temp)+1);

    if(newptr == NULL) {
        printf("에러\n");
        exit(1);
    }

    printf("%d번 사용자의 이름을 입력하세요. ", player_num);
    scanf("%s", name_temp);

    newptr->num = player_num;
    strcpy(newptr->name, name_temp);
    newptr->next = newptr;

	return newptr;
}

USER* delete_user(int i, USER* user) {
    USER* del;
    USER* temp;
    int k = 2;

    del = user;

    //첫번째 원소 없애는 경우
    if(i == 1) {
        user = temp = user->next;
        user->num -= 1;

        while(temp->next != del) {
            temp = temp->next;
            temp->num -= 1;
        }

        temp->next = user;

        free(del);

        return user;
    }
    else {
        temp = user;
        del = del->next;

        while (k < i) {
            temp = temp->next;
            del = del->next;
            k++;
        }

        //마지막 원소 없애는 경우
        if((del->next) == user) {
            temp->next = user;
            free(del);

            return user;
        }

        //마지막 원소가 아닌 원소 없애는 경우
        else {
            temp->next = del->next;
            free(del);

            temp = temp->next;

            while(temp->next != user) {
                temp->num -= 1;
                temp = temp->next;
            }

            temp->num -= 1;

            return user;
        }
    }
}

void printlist(USER* user) {
    USER* temp;
    temp = user;

    while(temp->next != user) {
        printf("%d번 %s -> ", temp->num, temp->name);
        temp = temp->next;
    }

    printf("%d번 %s -> ", temp->num, temp->name);
    printf("\n");
}

#endif // Russian_Roulette_ver2_H_INCLUDED
