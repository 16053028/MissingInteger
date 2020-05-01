# MissingInteger
 AlgoChallange2. Problem find missing smallest integer number

Buatlah sebuah fungsi

function solution(int[] &A)

untuk mengembalikan hasil bilangan pertama positif yang lebih besar dari 0. Yang hilang dari input yang diberikan. jika tidak ada bilangan positif didalamnya, maka hasilnya adalah 1.

Contoh
A=[1,2,3,5] maka hasilnya adalah 4.

A=[-3, -1] maka hasilnya adalah 1.

A=[-2, -1, 0, 3, 1, 3, 5] maka hasilnya adalah 5.

A=[1,2,3] maka hasilnya adalah 4.

# Answer
Solusi saya
Pertama saya akan melakukan teknik sorting atau mengurutkan bilangan-bilangan tersebut.
contoh A=[-2, -1, 0, 3, 1, 3, 5] maka hasil setelah disorting adalah A=[-2, -1, 0, 1, 3, 3, 5]. kemudian saya menghilangkan angka negatif atau yang lebih kecil dari pada 0 sehingga menjadi A=[0, 1, 3, 3, 5] Setelah itu saya akan menghilangkan angka yang muncul lebih dari 1 atau duplikasi. A=[0, 1, 3, 5].

Setelah itu saya mulai memberitahu komputer untuk menebak angka yang hilang tersebut dengan cara melakukan looping dan membandingkan angka A[x] dengan g_numb. dimana g_numb = A[x]+1. misal value A[0] = 0, dan value g_numb adalah 1. Apakah angka 1 ada didalam deret? jika tidak maka kembalikan angka 1 sebagai angka yang hilang. jika ada lanjutkan sampai ada angka yang hilang. 

dari sini bisa diambil kesimpulan bahwa  :
1. jika A[0] > 1 maka pasti ada angka yang hilang lebih kecil sebelum angka tersebut dan itu pasti 1.
2. jika A[0] = 1 atau A[0] = 0 maka pasti angka yang hilang ada ditengah atau diakhir dari deret.
3. Jika A memiliki element yang semuanya negatif. maka pasti angka yang hilang adalah 1


Pseudo-Code
Declaration :
g_numb : integer;

Description
function solution(int[] &A){
	g_numb = 0;
	sort(A.begin(), A.end()); //Sorting The Array
    A.erase( remove_if(A.begin(), A.end(), [](int i){return i < 0;}) , A.end() ); // Remove Negative Value
    A.erase( unique(A.begin(), A.end()) , A.end() ); // Remove duplicate Value
	if(A[i] > 1){
		g_numb = 1;
	} else if (A[0] == 0 || A[0] == 1){
		for(i to A){
			g_numb = A[i]+1;
			if(A[i+1] != g_numb){
				break;
			}
		}
	}else{
		g_numb = 1;
	}
	return g_numb;
}

saya kira Time Complexitynya adalah yang saya tahu hanya untuk loopnya yaitu O(n^) untuk totalnya sendiri saya tidak tahu dan Space Complexitynya adalah O(0) karena tidak memakai space tambahan. Koreksi saya jika salah.

Ada banyak solusi. Tapi saya menggunakan solusi ini. karena menurut saya ini cukup bagus.

anda punya solusi lain yang lebih baik dan efisien? Submit it and let me know about your solution. hehehehe

Terima kasih.