## Istilah Monotonically Increasing Subsequence
 Kondisi dimana niai setiap elemen berikutnya selalu lebih besar dari elemen sebelumnya dalam subsequence
<br>

## Contoh Monotically increasing subsequence

<br>

<img width="1888" height="804" alt="image" src="https://github.com/user-attachments/assets/9bbc1760-d561-4ea0-9f9f-f0c09791fa81" />
Aplikasi tree untuk mencari largest monotonically increaing subsequence dari urutan bilang : 4, 1, 13, 7, 0, 2, 8, 11, 3

## Penjelasan Algoritma

<br>

array tails menyimpan nilai ujung terkecil dari semua increasing subsequence dengan panjang i+1 pada tails[i]

contoh jika punya array nums = [4,1,13,7,14] maka 
len = 1: [4] , [1], [13], [7],[14] => tails[0] = 1
len = 2: [4,13], [4,7],[1,13],[1,7],[4,14],[1,14],[13,14],[7,14] => tails[1] = 7
len = 3: [4,13,14],[1,13,14],[1,7,14],[4,7,14] => tails[2] = 14
dengan tails yang sudah pasti naik terus maka bisa menggunakan binary search untuk mencari indeks yang perlu diperbarui

### 1. Jika X lebih dari semua elemen di tails
append x dan panjang increasing subsequence tambah satu
### 2. Tails[i-1] < x <= tails[i] 
update tails[i] = x
<br>
## Backtracking untuk mendapatkan Jalur increasing subsequence nya
<br>
Untuk mengambil isi jalurnya bisa menggunakan BackTracking (tails cuman mencatat panjang maksimum)

### 1. Catat panjang elemen
Tiap sebuah angka di indeks i di tails, catat (i+1) contoh : [4,1,13,7,14] => [1,1,2,2,3]

### 2 Pilih titik awal backtrack
mulai dari elemen yang punya max length contoh : panjang 3 maka kandidatnya 14 jika di array [4,1,13,7,14]

### 3. Backtrack satu langkah
dari elemen aktif dengan panjang target, cari elemen yang kurang dari elemen saat ini dan memiliki panjang target - 1, dan lakukan backtrack
contoh 
iterasi 1 : 14 -> 7 dan 14 -> 13
iterasi 2 : 14 -> 7 -> 1 , 14-> 7 -> 4 , 14 -> 13 -> 1 , 14 -> 13 -> 4
