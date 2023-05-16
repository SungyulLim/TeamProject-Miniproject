#include "manager.h"
#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

//관리자용 기능 여기서 만들기 + 서브매인도.
// 헤더는 (void student_main())는 무조건 헤더파일에 선언해주어야 합니다.

void manager_main(){
    printf("관리자용 서브메인 입니다\n");


    while(1){
        int menu;

        printf("\n-------관리자용-------\n");
        printf("1. 기숙사 신청자 방 배치\n");
        printf("2. 기숙사 리스트 보기\n");
        printf("3. 벌점 부과하기\n");
        printf("4. 리스트 저장\n");
        printf("5. 리스트 불러오기\n");
        printf("6. 메인 화면으로\n");
        printf("----------------------\n");

        printf("원하는 메뉴를 입력하세요 > ");
        scanf("%d", &menu);

        if (menu == 6) break;
        if (menu == 1){
            room_numbering();
        }
        else if (menu == 2){
            dormitory_list();
        }
        else if (menu == 3){
            penalty_points();
        }
        else if (menu == 4){
            save_list();
        }
        else if (menu ==5){
            recall_list();
        }
        else{
            printf("\n!!입력오류!!\n");
            printf("!!다시 입력해주세요!!\n");
        }


    }


    //

    //여기에 기능 메뉴 만들어서 기능 사용.
    //여기서 retun 하면 메인으로 돌아가짐.
    return;
}

//여기 밑에 각 기능을 위한 함수 구현. 헤더파일에 헤더부분 꼭 선언 해야 오류 안남.

//1. 기숙사 신청자 방 배치
void room_numbering(){
    int num;
    int chek_num = 0;

    printf("\n----------------------기숙사 신청자 리스트------------------\n");
    printf("번호 이름    학번   성별 생활관  호실 인실  벌점 방배정여부\n");
    for(int i=0; i<count; i++){
        if(students[i] ->Y_N == 'N'){
            if(students[i]->total_num_room == -1) {
                continue;
            }
            chek_num ++ ;
            printf("%2d. %-4s %s  %s  %-4s %3d호 %d인실 %2d점  %3c\n",i+1 , students[i]->name, students[i]->s_ID, students[i]->f_m, students[i]->Dormitory_name, students[i]->room_num, students[i]->total_num_room, students[i]->demerit, students[i]->Y_N); 
        }
    }
    if(chek_num == 0 || count==0){
        printf("\n기숙사 신청자가 없습니다!\n");
        
    }
    printf("------------------------------------------------------------\n\n");
    if(chek_num == 0 || count==0){
        return;
    }
    printf("방 배정 할 학생의 번호를 입력하세요( 돌아가려면 0을 입력하세요) > ");
    scanf("%d", &num);

    if(num == 0){
        printf("\n메인으로 돌아갑니다!\n");
        return;
    }

    num--; //배열이라 -1 해줘여함.
    int chek = 0;
    for(int i=0; i<count; i++){
        if(i == num){
            chek = 1;
        }
    }

    if(chek == 0){
        printf("\n잘못된 번호를 입력 하셨습니다\n메인으로 돌아갑니다!\n");
        return;
    }
    

    printf("%s(%s)학우님을 배정학 방 호수를 입력하세요 > ", students[num]->name, students[num]->s_ID);
    scanf("%d", &students[num] ->room_num);
    students[num] ->Y_N = 'Y';

    printf("%s(%s)학우님을 %d호에 방배정 했습니다.\n", students[num] ->name, students[num] ->s_ID, students[num] ->room_num);
}

//2. 기숙사 리스트 보기
void dormitory_list(){
    printf("\n-----------------전체 리스트(사용자, 신청자)-----------------\n");
    printf("번호 이름    학번   성별 생활관  호실 인실  벌점 방배정여부\n");
    for(int i=0; i<count; i++){
        
        printf("%2d. %-4s %s  %s  %-4s %3d호 %d인실 %2d점  %3c\n",i+1 , students[i]->name, students[i]->s_ID, students[i]->f_m, students[i]->Dormitory_name, students[i]->room_num, students[i]->total_num_room, students[i]->demerit, students[i]->Y_N); 
        
    }
    printf("-------------------------------------------------------------\n\n");
}


//3. 벌점 부과하기
void penalty_points(){
    int points[4] = {2, 1, 1, 5};
    int choose_points;
    int num;
    printf("\n---------------------기숙사 사용자 리스트------------------\n");
    printf("번호 이름    학번   성별 생활관  호실 인실  벌점 방배정여부\n");
    for(int i=0; i<count; i++){
        if(students[i] ->Y_N == 'Y'){
            printf("%2d. %-4s %s  %s  %-4s %3d호 %d인실 %2d점  %3c\n",i+1 , students[i]->name, students[i]->s_ID, students[i]->f_m, students[i]->Dormitory_name, students[i]->room_num, students[i]->total_num_room, students[i]->demerit, students[i]->Y_N); 
        }
    }
    printf("-----------------------------------------------------------\n\n");
    printf("벌점을 부여 할 학생의 번호를 입력하세요 > ");
    scanf("%d", &num);
    num--; //배열이라 -1 해줘여함.

    printf("* 벌점 리스트 *\n");
    printf("1. 무단외박 (2점)\n");
    printf("2. 미소등(1점)\n");
    printf("3. 침묵시간 안 지킴 (1점)\n");
    printf("4. 외부인 들임 (5점)\n");
    printf("\n벌점 사유를 선택하세요(1~4)> ");
    scanf("%d", &choose_points);
    choose_points--;

    students[num]->demerit = points[choose_points];
    printf("%s(%s)학우님 에게 벌점%d점을 부여했습니다.\n", students[num] ->name, students[num] ->s_ID, points[choose_points]);

}

//4. 리스트 저장
void save_list(){
    FILE *fp;
    fp = fopen("dormitory_List.txt", "w");
        

    for(int i=0; i<count; i++){
        if(students[i]->room_num == -1) continue;
        else{
            fprintf(fp, "%s %s %s %s %d %d %d %c\n",students[i]->name, students[i]->s_ID, students[i]->f_m, students[i]->Dormitory_name, students[i]->room_num, students[i]->total_num_room, students[i]->demerit, students[i]->Y_N); 
        }
    }
   
    fclose(fp);
    printf("\n==> 저장이 완료 되었습니다.\n");
}

//"5. 리스트 불러오기
void recall_list(){

    char filename[256] = "dormitory_List.txt";
    if((access(filename, 0) != -1))  //파일 존재 여부 체크
    { 
        printf("=> 로딩 성공!\n");
    }
    else{
        printf("=> 파일 없음\n");
        return;
    }

    int n=0;
	FILE *file;
	file = fopen("dormitory_List.txt","r");


	while(!feof(file)){
        char a_name[20]; // 이름 : 이수민
        char a_s_ID[10]; // gkrqjs : 22200533
        char a_f_m[5];   // 성별(여/남)
        char a_Dormitory_name[15]; // 건물이름(은혜관, 벧엘관, 비전관, 하용조관, 국제관, 로뎀관, 갈대상자
        int a_room_num;       //방호실(204)
        int a_total_num_room; // 인실(2/4/1)
        int a_demerit;        //벌점 (0~10)
        char a_Y_N;           //기숙사 배정 여부(Y/N) 

		int ret = fscanf(file, "%s %s %s %s %d %d %d %c\n",a_name, a_s_ID, a_f_m, a_Dormitory_name, &a_room_num, &a_total_num_room, &a_demerit, &a_Y_N); 
        
		if(ret < 8) break;
		students[count]=(student*)malloc(sizeof(student));
		strcpy(students[n]->name, a_name);
        strcpy(students[n]->s_ID, a_s_ID);
        strcpy(students[n]->f_m, a_f_m);
        strcpy(students[n]->Dormitory_name, a_Dormitory_name);
		students[n]->room_num = a_room_num; 
        students[n]->total_num_room = a_total_num_room;
        students[n]->demerit = a_demerit;
        students[n]->Y_N = a_Y_N;

		count++;
	}
	fclose(file);

	return;

}