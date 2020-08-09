#include <iostream>
#include<vector>
#include<fstream>
#include<regex>
#include<string>

using namespace std;

class weather {//クラスweatherの定義
protected: //日付，平均気温，最高気温，降水量，日照時間，平均風速，平均湿度，午前,午後の天気(以降「各気象情報」とする）を，protectedで定義
    string day;
    double temp = 0;
    double tempMax = 0;
    double rain = 0;
    double sun = 0;
    double wind = 0;
    double hum = 0;
    string weatherAM;
    string weatherPM;


public: //各気象情報の設定setと所得get用のアクセッサ
    void setDay(const string& newDay) { day = newDay; }
    string getDay() { return day; }
    void setTemp(double newTemp) { temp = newTemp; }
    double getTemp() { return temp; } 
    void setTempMax(double newTempMax) { tempMax = newTempMax; }
    double getTempMax() { return tempMax; }
    void setRain(double newRain) { rain = newRain; }
    double getRain() { return rain; }
    void setSun(double newSun) { sun = newSun; }
    double getSun() { return sun; }
    void setWind(double newWind) { wind = newWind; }
    double getWind() { return wind; }
    void setHum(double newHum) { hum = newHum; }
    double getHum() { return hum; }
    void setWeatherAM(const string& newWeatherAM) { weatherAM = newWeatherAM; }
    string getWeatherAM() { return weatherAM; }
    void setWeatherPM(const string& newWeatherPM) { weatherPM = newWeatherPM; }
    string getWeatherPM() { return weatherPM; }
};



//ファイルから情報を読み込み,vecterへ格納，表示する関数
void readFromFile(string fileName)
{
    vector<weather>v1;
    ifstream infile(fileName);

    if (!infile) {//ファイルが見つからない場合の処理
        cout << "ファイルが見つかりません、ファイル名や、ファイルの型を確認してください。"<<endl;
    }
    else {//ファイルが見つかった場合の処理

        int n = 0;

        //各気象情報の定義
        string DAY;
        double TEMP;
        double TEMPMAX;
        double RAIN;
        double SUN;
        double WIND;
        double HUM;
        string WEATHERAM;
        string WEATHERPM;

        while (infile >> DAY >> TEMP >> TEMPMAX >> RAIN >> SUN >> WIND >> HUM >> WEATHERAM >> WEATHERPM) {

            v1.emplace_back();//要素の追加

            v1[n].setDay(DAY);
            v1[n].setTemp(TEMP);
            v1[n].setTempMax(TEMPMAX);
            v1[n].setRain(RAIN);
            v1[n].setSun(SUN);
            v1[n].setWind(WIND);
            v1[n].setHum(HUM);
            v1[n].setWeatherAM(WEATHERAM);
            v1[n].setWeatherPM(WEATHERPM);
            n++;
        }

        size_t s = v1.size();
        for (size_t i = 0;i < s;++i) {//要素の最後まで繰り返す

            //気温の表示
            cout << v1[i].getDay() << "　この日の" << fileName << "の平均気温は" << v1[i].getTemp()
                << "℃　最高気温は" << v1[i].getTempMax() << "℃です。" << endl;

            //夏の注意喚起、最高気温について
            if (v1[i].getTempMax() >=30)
            {
                cout << "真夏日となります、熱中症には十分気をつけましょう" << endl;
            }
            else if (v1[i].getTempMax() >= 25)
            {
                cout << "夏日です。野外での活動の際は水分をしっかり補給しましょう" << endl;
            }


            //前日との気温の比較
            if (i == 0) { cout << ""; }
            else if (v1[i].getTemp() > v1[i - 1].getTemp())
            {
                cout << "前日より暑いでしょう" << endl;
            }
            else if (v1[i].getTemp() > v1[i - 1].getTemp())
            {
                cout << "前日より涼しいです" << endl;
            }

            //気象情報の表示
            cout << "また降水量は" << v1[i].getRain()
                << "mm、\n 日照時間は" << v1[i].getSun() << "時間で、平均風速は" << v1[i].getWind()
                << "m/sです。湿度" << v1[i].getHum() << "％　\n 午前中の天気は“" << v1[i].getWeatherAM()
                << "”午後の天気は“" << v1[i].getWeatherPM() << "”です。" << endl;

            //湿度について
            if (v1[i].getHum() >= 80) {
                cout << "蒸し蒸しとした一日になるでしょう" << endl;
            }


            //洗濯物
            if (v1[i].getRain() != 0) {}
            else if (v1[i].getSun() >= 10) {
                cout << "洗濯日和です。" << endl;
                if (v1[i].getWind() > 5) {
                    cout << "しかし，風で飛ばされないよう気をつけましょう" << endl;
                }
            }

            cout << endl;


        }
    }
}

int main() {

    readFromFile("東京.txt");//外部ファイルの指定，関数の実行

}


