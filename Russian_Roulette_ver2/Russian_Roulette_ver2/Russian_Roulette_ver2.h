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
    printf("�ٽ� ���� ���� ȭ������ �Ѿ�ϴ�.\n");
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
        //printf("%d�� źâ�� �������.\n\n", revolver);
        first = rand() % number_of_user + 1;

        temp = user;

        while (temp->num != first) {
            temp = temp->next;
        }

        while(revolver != 0) {
            if(revolver != 1) {
                Sleep(1500);
                printf("ƽ\n");
                printf("%d�� �����ڰ� �����Ͽ����ϴ�.\n", temp->num);
                printf("���� �����ڷ� �Ѿ�ϴ�.\n\n");
                temp = temp->next;
            }
            else {
                Sleep(1500);
                printf("��!!\n");
                printf("%d�� �����ڰ� ����Ͽ����ϴ�.\n\n", temp->num);
                user = delete_user(temp->num, user);
                printf("����� ������ ������ ��ȣ�� 1�� ������ϴ�.\n\n");
                printlist(user);
                number_of_user--;
            }

            revolver--;
        }

    }

    printf("���� �����ڴ� %s�Դϴ�.\n", user->name);

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
        printf("����\n");
        exit(1);
    }

    printf("%d�� ������� �̸��� �Է��ϼ���. ", player_num);
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

    //ù��° ���� ���ִ� ���
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

        //������ ���� ���ִ� ���
        if((del->next) == user) {
            temp->next = user;
            free(del);

            return user;
        }

        //������ ���Ұ� �ƴ� ���� ���ִ� ���
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
        printf("%d�� %s -> ", temp->num, temp->name);
        temp = temp->next;
    }

    printf("%d�� %s -> ", temp->num, temp->name);
    printf("\n");
}

#endif // Russian_Roulette_ver2_H_INCLUDED
