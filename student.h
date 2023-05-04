// 여기에 학생용 구조체 선언과, 외박 정보용 구조체 선언도 하기.

typedef struct {
    char overnight_date[10]; //외박신청날짜. 1박씩 가능. 
    char overnight_reason[50]; //외박 사유
}overnight_stay;

typedef struct {
    char naem[20]; // 이름 : 이수민
    char s_ID[10]; //gkrqjs : 22200533
    char f_m[5]; // 성별(여/남) 
    char Dormitory_name[15]; // 건물이름(은혜관, 벧엘관, 비전관, 하용조관, 국제관, 로뎀관, 갈대상자
    int room_num; //방호실(204) 
    int total_num_room; // 인실(2/4/1)
    int demerit; //벌점 (0~10)
    char Y_N; //기숙사 배정 여부(Y/N) char
    overnight_stay student_overnight_list[50];//하나의 학생의 외박 신청서 50번 가능.
}student;

void student_main();