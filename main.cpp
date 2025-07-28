    #include <iostream>
    #include <string>
    #include <vector> //C++에서의 2차원 배열
    #include <algorithm>
    #include <fstream> //C++에서 파일 입출력
    #include <locale> //C++에서 로케일 설정
    #include <iomanip>

    using namespace std;

    // 학생 정보를 담을 구조체 정의
    struct Student {
       int id; // 학생 ID
       string name; // 학생 이름
       int kor, eng, math; // 국어, 영어, 수학 점수
       int sum; // 총점
       double average; // 평균
       int rank; // 석차

    };

    // 학생 정보를 저장할 벡터(Vector) 1치원 배열
    vector<Student> students; // Global 변수 

    //각 기능별 함수 선언 
    void addStudent(); // 학생 정보 추가 
    void calculateRanks(); // 석차 계산
    void printAllStudents(); // 전체 학생 정보 출력 
    void saveDataFromFile(); // 파일에 저장 
    void loadDataFromFile(); // 파일에서 데이터 불러오기


    int main() {
        //Vscode에서 한글 입력을 위해 로케일 설정 
        setlocale(LC_ALL, "Korean"); // "Ko_KR.UTF-8"
     
        
        // 프로그램 시작시 파일에서 데이터 불러오기
        loadDataFromFile();

        //불러온 데이터에서 석차 계산
        calculateRanks();

        int choice = 0; // 메뉴 선택 변수
        while (1) {
            cout << "\n----- 학생 성적 관리 시스템 -----\n";
            cout << "1. 학생 정보 추가\n";
            cout << "2. 전체 학생 성적 정보 출력\n";
            cout << "3. 데이터 저장\n";
            cout << "4. 프로그램 종료\n";
            cout << "메뉴를 선택하세요.: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addStudent(); //학생 정보 추가
                    calculateRanks(); //석차 계산
                    break;
                case 2:
                    printAllStudents(); //전체 학생 성적 정보 출력
                    break;
                case 3:
                    saveDataFromFile(); //파일에 데이터 저장
                    break;
                case 4:
                    cout << "프로그램을 종료합니다." << endl;
                    return 0; //프로그램 종료
                default:
                    cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
            }   
        }

        return 0;

    }

    //학생 정보 추가 함수
    void addStudent() {
        Student newStudent;
        cout << "----- 학생 정보 입력 -----" << endl;
        cout << "학번: ";
        cin >> newStudent.id; //학번 입력한다.
        cout << "이름: ";
        cin >> newStudent.name; //이름 입력한다.
        cout << "국어 점수: "; 
        cin >> newStudent.kor; //국어 점수 입력한다.
        cout << "영어 점수: ";
        cin >> newStudent.eng; //영어 점수 입력한다.
        cout << "수학 점수: ";
        cin >> newStudent.math; //수학 점수 입력한다.

        //총점과 평균 계산
        newStudent.sum = newStudent.kor + newStudent.eng + newStudent.math; //총점 계산
        newStudent.average = newStudent.sum / 3.0; //평균 계산
        students.push_back(newStudent); // 벡터에 학생 정보 추가

    }

    //석차 계산 함수
    void calculateRanks() {
        for(int i = 0; i < students.size(); i++) {
            int rank = 1; //석차 초기화 
            for(int j = 0; j < students.size(); j++){
                if(students[i].sum < students[j],sum){
                    rank++; //현재 학생의 총점이 다른 학생보다 낮으면 석차 증가
                }
            }
            students[i].rank = rank; //석차 저장
        }
    }


    //전체 학생 정보 출력 함수
    void printAllStudents() {
        //석차 기준으로 오름차순 정렬(람다 함수)
        sort(students.begin(), students.end(), [](const Student& a, const Student& b)
         {
            return a.rank < b.rank;
        });

        cout << "\n----- 전체 학생 성적 정보 -----\n";
        cout << setw(5) << "등수"
             << setw(10) << "학번"
             << setw(15) << "이름"
                << setw(10) << "국어"
                << setw(10) << "영어"
                << setw(10) << "수학"
                << setw(10) << "총점"
                << setw(10) << "평균" << endl;
        cout << string(70, '-') << endl; // 구분선 출력
        
        for(auto &student : students)
        {
            cout << setw(5) << student.rank
                 << setw(10) << student.id
                 << setw(15) << student.name
                 << setw(10) << student.kor
                 << setw(10) << student.eng
                 << setw(10) << student.math
                 << setw(10) << student.sum
                 << fixed << setprecision(2) // 소수점 둘째 자리까지 출력
                 << setw(10) << student.average << endl; 
        }
            
    }

    //파일에 데이터 저장 함수
    void saveDataFromFile(){
        ofstream outFile("students.txt");
        if(!outFile.is_open()){
            cerr << "오류: 파일을 열 수 없습니다." << endl;
            return;
        }
        for(auto &s : students) {
            outFile << s.id << " "
                    << s.name << " "
                    << s.kor <<  " "
                    << s.eng << " "
                    << s.math << " "
                    << s.sum << " "
                    << fixed << setprecision(2) << s.average << " "
                    << s.rank << endl; // 학생 정보를 파일에 저장 
        }

        //파일에서 데이터 불러오기 함수
        void loadDataFromFile() {
            ifstream inFile ("students.txt")
            if(!inFile.is_open()) {
                cerr << "오류: 파일을 열 수 없습니다. 새로 시작합니다." << endl;
                return;
            }
        }
        Students.clear(); // 기존 데이터 초기화
        Student s; 
        while (inFile >> s.id >> s.name >> s.kor >> s.eng >> s.math >> s.sum >> s.average >> s.rank) {
            students.push_back(s); // 파일에서 읽은 학생 정보를 벡터에 추가
        }

        inFile.close();
        cout << "데이터가 성공적으로 불러왔습니다." << endl; 

        

    }
