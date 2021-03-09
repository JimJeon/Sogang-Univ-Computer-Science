/*
 * * * * * * * * * * * * * * * * * * * * *
 * Video Shop Management Program		 *
 *										 *
 * Developer	: 전진우				 *
 * Student ID	: 20151603				 *
 * Web Mail		: irregular@sogang.ac.kr *
 * * * * * * * * * * * * * * * * * * * * *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
#include<stdbool.h>
// C99부터 지원되는 bool타입 _Bool을 이용하기 위해서 사용하는 헤더파일이다.
// _Bool은 bool로 false는 0, true는 1로 정의되어있다.

enum Video_Genre { ACTION = 1, COMIC, SCIFI, ROMANCE };
const char Genre_Hashing[][15] = { "액션", "코믹", "Sci-Fi", "로맨스" };
// 비디오 장르에 대한 열거형이다.
// 열거형과 그 값을 인덱스로 갖는 문자열 배열을 이용했다.

typedef struct _rental
{
	bool status;

	char id[11];

	int year;
	int month;
	int day;

	struct _rental *nextNode;
} RENTAL;
// 비디오 대여기록에 대한 정보를 저장하는 RENTAL 노드이다.
// status가 true이면 대여 가능 false이면 대여 불가능이다.
// id에는 대여자의 정보가 저장되어 있다.
// year, month, day에는 대여 날짜 정보가 저장되어 있다.

typedef struct _client
{
	char id[11];
	char name[31];
	char tel[15];

	struct _client *nextNode;
} CLIENTS;
// 고객 정보를 저장하는 CLIENTS 노드이다.
// id에는 고객 id가 name에는 고객의 이름이 tel에는 전화번호가 저장된다.

typedef struct _video_object
{
	char ISBN[15];
	char title[31];
	enum Video_Genre genre;

	RENTAL *rental_history;
	RENTAL status;

	struct _video_object *nextNode;
} VIDEOS;
// 비디오 정보를 저장하는 VIDEOS 노드이다.
// ISBN에 비디오 ISBN이 title에는 비디오 제목이 genre에는 비디오 장르가 저장된다.
// rental_history는 해당 비디오의 대여 기록을 저장하는 RENTAL 리스트의 헤드이다.
// status는 현재 대여 정보를 기록하는 현재 RENTAL 노드를 저장한다.

// Global Declarations
CLIENTS	*headClient = NULL;
VIDEOS	*headVideo	= NULL;
// CLIENTS 리스트의 헤드인 headClient이며 NULL로 초기화 했다.
// VIDEOS 리스트의 헤드인 headVideo이며 NULL로 초기화 했다.

bool createNewClient(void);			// 새로운 고객을 추가하는 함수이다.
bool createNewVideo(void);			// 새로운 비디오를 추가하는 함수이다.
bool isAvailableID(char* ID);		// 사용자가 입력한 ID가 유효한지 확인하는 함수이다.
bool isAvailableISBN(char *ISBN);	// 사용자가 입력한 ISBN이 유효한지 확인하는 함수이다.
CLIENTS *clientSearch(char *ID);	// ID를 이용하여 고객을 검색하는 함수이다.
VIDEOS	*videoSearch(char *ISBN);	// ISBN을 이용하여 비디오를 검색하는 함수이다.
bool LendingProcess(void);			// 비디오 대여를 진행하는 함수이다.
bool ReturningProcess(void);		// 비디오 반납을 진행하는 함수이다.
bool PrintHistory(char *ISBN);		// 비디오 대여 기록을 출력하는 함수이다.
void freeList(void *head,int type); // Linked List를 free시키는 함수이다. TYPE(0: CLIENTS 1: VIDEOS 2: RENTAL)

int main(void)
{
	// Local Declarations
	CLIENTS *tmpClient = NULL;
	VIDEOS	*tmpVideo  = NULL;

	char user_choice = 0;
	char flag = 0;

	char ID[11];
	char ISBN[15];
	int i;
	
	// Statements
	while(1)
	{
		puts("----------메 뉴----------");
		puts("1. 신규가입\n2. 고객검색");
		puts("-------------------------");
		puts("3. 비디오 등록\n4. 비디오 검색");
		puts("-------------------------");
		puts("5. 비디오 대여\n6. 비디오 반납");
		puts("-------------------------");
		puts("7. 비디오 대여고객 전체 조회\n8. 종료");
		puts("-------------------------");

		printf("선택>> ");
		user_choice = getchar();
		getchar();

		switch(user_choice)
		{
			case '1': // 1. 신규가입
				if(createNewClient())
					puts("가입이 완료되었습니다.");
				else
					puts("해당 ID는 사용 중에 있습니다. 다른 ID를 선택해 주세요.");
				break;
			case '2': // 2. 고객검색
				printf("찾는 ID 입력: ");
				scanf("%[^\n]",ID);
				getchar();

 				tmpClient = clientSearch(ID);
				if(!tmpClient)
				{
					puts("찾는 고객이 없습니다.");
					break;
				}
				printf("ID: %s\n",tmpClient->id);
				printf("이름: %s\n",tmpClient->name);
				printf("전화번호: %s\n",tmpClient->tel);
				break;
			case '3': // 3. 비디오 등록
				if(createNewVideo())
					puts("등록이 완료되었습니다.");
				else
					puts("해당 ISBN은 이미 등록되었습니다.");
				break;
			case '4': // 4. 비디오 검색
				printf("찾는 ISBN 입력: ");
				scanf("%s",ISBN);
				getchar();

				tmpVideo = videoSearch(ISBN);
				if(!tmpVideo)
				{
					puts("찾는 비디오가 없습니다.");
					break;
				}
				printf("ISBN: %s\n",tmpVideo->ISBN);
				printf("타이틀: %s\n",tmpVideo->title);
				printf("장르: %s\n",Genre_Hashing[tmpVideo->genre - 1]);
				break;
			case '5': // 5. 비디오 대여
				LendingProcess();
				break;
			case '6': // 6. 비디오 반납
				if(ReturningProcess())	puts("반납이 완료되었습니다.");
				break;
			case '7': // 7. 비디오 대여고객 전체 조회
				printf("찾는 ISBN 입력: ");
				scanf("%s",ISBN);
				getchar();

				PrintHistory(ISBN);
				break;
			case '8': // 8. 종료
				tmpVideo = headVideo;
				while(tmpVideo != NULL)
				{
					freeList(tmpVideo->rental_history,offsetof(RENTAL,nextNode));

					tmpVideo = tmpVideo->nextNode;
				}

				freeList(headVideo,offsetof(VIDEOS,nextNode));
				freeList(headClient,offsetof(CLIENTS,nextNode));

				puts("이용해 주셔서 고마워요~");
				printf("계속하려면 엔터 키를 누르십시오...");
				getchar();
				flag = 1;
				break;
			default: // 사용자 입력 예외 처리
				puts("잘못 입력하셨습니다");
				printf("계속하려면 엔터 키를 누르십시오...");
				getchar();
				break;
		}

		if(flag) break;
	}

	return 0;
}
// 고객 정보 노드를 생성하는 함수이다.
// 고객의 정보를 입력받아서 새로운 노드에 저장하고 노드를 리스트 마지막에 추가한다.
// 성공적으로 등록하면 true를 그렇지 못하면 false를 반환한다.
bool createNewClient(void)
{
	CLIENTS *newClient = malloc(sizeof(CLIENTS));
	CLIENTS *curNode = headClient;

	char client_ID[11];
	char client_name[31];
	char client_tel[15];
	
	printf("ID 입력: ");
	scanf("%[^\n]",client_ID);
	getchar();
	
	if(!isAvailableID(client_ID))
	{
		free(newClient);
		return false;
	}
	
	printf("이름 입력: ");
	scanf("%[^\n]",client_name);
	getchar();

	printf("전화번호 입력: ");
	scanf("%[^\n]",client_tel);
	getchar();

	strcpy(newClient->tel,client_tel);
	strcpy(newClient->id,client_ID);
	strcpy(newClient->name,client_name);
	newClient->nextNode = NULL;

	if(headClient == NULL)
	{
		headClient = newClient;
		return true;
	}

	while(curNode->nextNode != NULL)
		curNode = curNode->nextNode;

	curNode->nextNode = newClient;

	return true;
}
// 인자로 받은 ID가 현재 이용중에 있는지 확인하는 함수이다.
// 인자로는 ID를 받으며 이용가능하면 true 불가능하면 false를 반환한다.
bool isAvailableID(char* ID)
{
	CLIENTS *curNode = headClient;
	while(curNode != NULL)
	{
		if(!strcmp(curNode->id,ID)) return false;
		curNode = curNode->nextNode;
	}
	return true;
}
// isAvailableID와 작동 방식이 같으나 반환 값만 다른 함수이다.
// 찾는 ID와 동일한 ID를 갖는 노드를 반환한다. 없으면 NULL을 반환한다.
CLIENTS *clientSearch(char *ID)
{
	CLIENTS *curNode = headClient;
	while(curNode != NULL)
	{
		if(!strcmp(curNode->id,ID)) return curNode;
		curNode = curNode->nextNode;
	}
	return NULL;
}
// 비디오 정보 노드를 생성하는 함수이다.
// 비디오의 정보를 입력받아서 새로운 노드에 저장하고 노드를 리스트 마지막에 추가한다.
// 성공적으로 등록하면 true를 그렇지 못하면 false를 반환한다.
bool createNewVideo(void)
{
	VIDEOS *newVideo = malloc(sizeof(VIDEOS));
	VIDEOS *curNode = headVideo;

	char video_ISBN[15];
	char video_title[31];
	enum Video_Genre video_genre;

	printf("ISBN 입력: ");
	scanf("%[^\n]",video_ISBN);
	getchar();

	if(!isAvailableISBN(video_ISBN))
	{
		free(newVideo);
		return false;
	}

	printf("제목 입력: ");
	scanf("%[^\n]",video_title);
	getchar();

	printf("장르 입력 (1. 액션 2. 코믹 3. Sci-Fi 4. 로맨스) : ");
	scanf("%u",&video_genre);
	getchar();

	strcpy(newVideo->ISBN,video_ISBN);
	strcpy(newVideo->title,video_title);
	newVideo->genre = video_genre;
	newVideo->status.status = true; // 대여가능한 상태이다.
	newVideo->nextNode = NULL;
	newVideo->rental_history = NULL;

	if(headVideo == NULL)
	{
		headVideo = newVideo;
		return true;
	}

	while(curNode->nextNode != NULL)
		curNode = curNode->nextNode;

	curNode->nextNode = newVideo;

	return true;
}
// 인자로 받은 ISBN이 현재 이용중에 있는지 확인하는 함수이다.
// 인자로는 ISBN을 받으며 이용가능하면 true 불가능하면 false를 반환한다.
bool isAvailableISBN(char *ISBN)
{
	VIDEOS *curNode = headVideo;
	while(curNode != NULL)
	{
		if(!strcmp(curNode->ISBN,ISBN)) return false;
		curNode = curNode->nextNode;
	}
	return true;
}
// isAvailableISBN과 작동 방식이 같으나 반환 값만 다른 함수이다.
// 찾는 ISBN과 동일한 ISBN을 갖는 노드를 반환한다. 없으면 NULL을 반환한다.
VIDEOS *videoSearch(char *ISBN)
{
	VIDEOS *curNode = headVideo;
	while(curNode != NULL)
	{
		if(!strcmp(curNode->ISBN,ISBN)) return curNode;
		curNode = curNode->nextNode;
	}
	return NULL;
}
// 대여과정을 진행하는 함수이다.
// 대여 ISBN을 확인하고 대여자의 ID를 확인하는 과정을 거친다.
// 대여 날짜 정보를 입력받고 비디오의 대여정보에 기록한다.
// 대여가 완료되면 대여 기록 리스트에 노드를 추가한다.
// 성공적으로 진행되면 true를 그렇지 못하면 false를 반환한다.
bool LendingProcess(void)
{
	RENTAL  *newHistory = malloc(sizeof(RENTAL));

	CLIENTS *clientNode = NULL;
	VIDEOS	*videoNode  = NULL;
	RENTAL	*historyNode= NULL;

	char ISBN[15];
	char ID[11];

	printf("대여 DVD ISBN 입력: ");
	scanf("%[^\n]",ISBN);
	getchar();

	videoNode = videoSearch(ISBN);

	if(!videoNode)
	{
		puts("미등록 비디오입니다.");
		return false;
	}
	if(!videoNode->status.status)
	{
		puts("이미 대출된 비디오입니다.");
		return false;
	}

	puts("대여가 가능합니다. 대여 과정을 진행합니다.");
	printf("대여 고객 ID 입력: ");
	scanf("%[^\n]",ID);
	getchar();

	clientNode = clientSearch(ID);

	if(!clientNode)
	{
		puts("가입 고객이 아닙니다.");
		return false;
	}

	printf("대여 날짜 입력: ");
	scanf("%d-%d-%d",&videoNode->status.year,&videoNode->status.month,&videoNode->status.day);
	getchar();

	videoNode->status.status = false; // 대여 불가능한 상태이다.
	strcpy(videoNode->status.id,ID);
	*newHistory = videoNode->status;

	// 대여 기록 리스트에 추가
	historyNode = videoNode->rental_history;

	if(historyNode == NULL)
		videoNode->rental_history = newHistory;
	else
	{
		while(historyNode->nextNode != NULL)
			historyNode = historyNode->nextNode;

		historyNode->nextNode = newHistory;
	}

	puts("대여가 완료되었습니다.");

	return true;
}
// 반납 과정을 진행하는 함수이다.
// 비디오의 ISBN 정보를 입력받아서 대여중이면 반납을 진행한다.
// 대여 중이지 않으면 에러메세지를 출력한다.
// 성공적으로 수행하면 true를 그렇지 못하면 false를 반환한다.
bool ReturningProcess(void)
{
	VIDEOS	*videoNode	= NULL;

	char ISBN[15];

	printf("반납 비디오 ISBN 입력: ");
	scanf("%[^\n]",ISBN);
	getchar();

	videoNode = videoSearch(ISBN);
	if(!videoNode)
	{
		puts("등록되지 않은 ISBN 입니다.");
		return false;
	}
	if(videoNode->status.status)
	{
		puts("대여되지 않은 비디오 입니다.");
		return false;
	}
	videoNode->status.status = true; // 대여 가능한 상태이다.

	return true;
}
// 비디오 대여 기록을 조회하는 함수이다.
// 비디오의 ISBN을 입력받아 해당 노드를 찾는다.
// 해당 노드에서 비디오 대여 기록 리스트의 헤드를 가져온다.
// 헤드를 이용해 전체 대여 기록을 출력한다.
// 성공적으로 수행하면 true를 그렇지 못하면 false를 출력한다.
bool PrintHistory(char *ISBN)
{
	VIDEOS  *videoNode	= videoSearch(ISBN);
	RENTAL  *historyNode= NULL;
	CLIENTS *clientNode = NULL;

	if(videoNode == NULL)
	{
		puts("등록되지 않은 ISBN 입니다.");
		return false;
	}

	puts("---------------------------------");
	
	historyNode = videoNode->rental_history;
	while(historyNode != NULL)
	{
		clientNode = clientSearch(historyNode->id);

		printf("대여일 : %d%02d%02d\n",historyNode->year,historyNode->month,historyNode->day);
		printf("ID : %s\n",clientNode->id);
		printf("이름 : %s\n",clientNode->name);
		printf("전화번호 : %s\n",clientNode->tel);

		historyNode = historyNode->nextNode;

		puts("---------------------------------");
	}

	puts("조회를 완료하였습니다.");

	return true;
}
// 타입 0: 고객 리스트, 1: 비디오 리스트, 2: 대여 기록 리스트
// 리스트의 헤드를 인자로 받아 해당 리스트의 모든 노드를 free 시키는 함수이다.
// 반환값은 없다.
void freeList(void *head, int type)
{
	void *target  = NULL;
	void *curNode = head;

	switch(type)
	{
		case 0:
			while(curNode != NULL)
			{
				target = curNode;
				curNode = ((CLIENTS *)curNode)->nextNode;

				free(target);
			}
		case 1: 
			while(curNode != NULL)
			{
				target = curNode;
				curNode = ((VIDEOS *)curNode)->nextNode;

				free(target);
			}
		case 2:
			while(curNode != NULL)
			{
				target = curNode;
				curNode = ((RENTAL *)curNode)->nextNode;

				free(target);
			}
	}

	return;
}
