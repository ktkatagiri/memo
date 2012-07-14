#include <iostream>
using namespace std;

class samp{
		int i;     // private なメンバ変数 (private キーワードの省略)
	public:
		// 以下のように簡単なメンバ関数であればクラス定義内で定義できる
		samp(int n){i=n;}       // 引数つきのコンストラクタ
		void set_i(int n){i=n;} // i に値をセット
		int get_i(){return i;}  // i の値を取得
};

// 以下の 3 つの関数は、C 言語的な関数である

int sqr_it1(samp o){   // 資料 3 ページに相当
 	return o.get_i()*o.get_i(); // i の 2 乗を戻す
}

void sqr_it2(samp o){  // 資料 4 ページに相当
 	o.set_i(o.get_i()*o.get_i()); // i の 2 乗を i にセット (？)
	cout << "iのコピーの値は" << o.get_i() << "\n";
}

void sqr_it3(samp *o){  // 資料 7 ページに相当
 	o->set_i(o->get_i()*o->get_i()); // i の 2 乗を i にセット
	cout << "iのコピーの値は" << o->get_i() << "\n";
}

int main(){
  samp a(10);  // 初期値 10 でクラス samp のオブジェクト a を宣言
  samp b(100);
  samp c(1000);
  cout << "関数終了後のiの値は" << b.get_i() << "\n";
  cout << "関数終了後のiの値は" << c.get_i() << "\n";
	

	cout << "***sqr_it1 の呼び出し***\n";
	cout << sqr_it1(a) << "\n";
	
	cout << "\n";
	
	cout << "***sqr_it2 の呼び出し***\n";
	sqr_it2(a);
	cout << "関数終了後のiの値は" << a.get_i() << "\n";
	
	cout << "\n";
	
	cout << "***sqr_it3 の呼び出し***\n";
	sqr_it3(&a);
	cout << "関数終了後のiの値は" << a.get_i() << "\n";

}
