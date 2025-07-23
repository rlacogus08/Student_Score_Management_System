    #include <iostream>
    #include <string>
    #include <vector> //C++에서의 2차원 배열
    #include <algorithm>
    #include <fstream> //C++에서 파일 입출력
    #include <locale> //C++에서 로케일 설정

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
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.rank < b.rank;
        });
    }
