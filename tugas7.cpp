#include<iostream>
#include<stdio.h>
using namespace std;

    int saldoAwal = 1000000, dana = 10000, ovo = 10000, gopay = 10000;

    int cekKartu(int nominal = 1000, int opsi = 1, string opsiTopUp = "0"){
       
        // cout << opsi;
        int cekPin,salahPin=1;

        struct {
            int pinAtm;
        }kartu;

        kartu.pinAtm = 123456;
            do{
                    cout <<"Masukan PIN anda :";
                    cin >>cekPin;
                    if(kartu.pinAtm == cekPin){
                        // cout <<"bisa dong " << opsi;
                        if(opsi == 3){
                            system("clear");
                            if (opsiTopUp == "1"){
                                saldoAwal = saldoAwal - nominal;
                                dana = dana + nominal;
                                cout << "\n\nTransaksi Berhasil !!!\n\n";
                                salahPin = salahPin + 6;
                            }else if(opsiTopUp == "2"){
                                saldoAwal = saldoAwal - nominal;
                                ovo = ovo + nominal;
                                cout << "\n\nTransaksi Berhasil !!!\n\n";
                                salahPin = salahPin + 6;
                            }else {
                                saldoAwal = saldoAwal - nominal;
                                gopay = gopay + nominal;
                                cout << "\n\nTransaksi Berhasil !!!\n\n";
                                salahPin = salahPin + 6;
                            }
                        }else{
                            system("clear");
                            saldoAwal = saldoAwal - nominal;
                            cout << "\n\nTransaksi Berhasil !!!\n\n";
                            salahPin = salahPin + 6;
                        }
                        
                    }else{
                        cout << "Pin Salah! ("<<salahPin<<"x)\n";
                        salahPin = salahPin +1;
                    }
                    
                }while(salahPin <= 4);

                return 0;
    }


void login(){
    string password_input;
    int i = 1;
    string cek = "block";
    string password = "wahyu12345"; 
    do{ 
        cout << "Selamat Datang di mbanking Online \n";
        cout << "Masukan Password : ";
        cin >> password_input;
        
        if(password_input == password){
        system("clear");
        cout << "Selamat Datang Wahyu Prayogo\n\n";
        
        i = i + 6;
        cek = "berhasil";
        }else{
             cout << "Password Salah! ("<<i<<"x)\n";
              i = i +1;
        }
    }while(i <= 4);

    if(cek != "berhasil"){
        
        cout<<"Anda telah 3x salah login.\n";       
        cout<<"Silahkan coba Telpon Customer Service OK. Terima Kasih..\n\n";      
	}  
    
}

int transfer(){ 
    string atmBank[] = {"","Mandiri ", "BCA ", "BSI ", "BNI"};
    long int rekening,nominal;
    int pilihAtm,cekPin,salahPin=1;
    string lanjutkan,lanjutkanSaldo;

    repeatMenu:
    repeatSaldo:
    system("clear");
    cout << "Menu Tampilan Transfer\n";
    cout <<"Saldo Anda : "<< saldoAwal<<"\n\n";

    cout <<"Masukan No Rekening : ";
    cin >> rekening;
    cout <<"Masukan Nominal : ";
    cin >> nominal;
    cout <<"\n";
    

    for (int i = 1; i < 5; i++)
    {
        cout <<i<<"." <<atmBank[i] <<endl;
    }
    cout << "Pilih Bank : ";
    cin >> pilihAtm;
    cout <<"\n";
    system("clear");
    cout <<"Nama Rekening : Denis Rustandi\n";
    cout <<"Nama Bank : " << atmBank[pilihAtm]<<"\n";
    cout <<"No Rekening : "<< rekening<<"\n";
    cout <<"Nominal : "<< nominal<<"\n\n";

    if(nominal > saldoAwal){
        cout << "Saldo Tidak Cukup\n";
        repeatSaldoCek:
        cout << "Mau Mengulang lagi ya/tidak ";
        cin >> lanjutkanSaldo;
        if(lanjutkanSaldo == "ya"){
            goto repeatSaldo;
        }else if(lanjutkanSaldo == "tidak"){
            cout << " ";
        }else{
            goto repeatSaldoCek;
        }
        // goto repeatMenu;
    }else{
        repeat:
        cout << "Lanjutkan ya/tidak : ";
        cin >> lanjutkan;
        if(lanjutkan == "ya"){
            cekKartu(nominal);
            
        }else if(lanjutkan == "tidak"){
            goto repeatMenu;
        }else{
            goto repeat;
        }

      
    }
      return 0;
}

int bayar(){
    long int kodeBayar,hargaEcommerce=900000,hargaPendidikan=150000,hargaPln=150000;
    string lanjutkanEcommerce,lanjutkanPendidikan,lanjutkanPln,pilihBayar,selectEcommerce,selectPendidikan,selectPln,lanjutkanSaldo;
    int cekPin,salahPin=1;

    string bayarMandiri[] = {"","E Commerce ", "Pendidikan ", "PLN "};
     struct {
        int pinAtm;
    }kartu;

    kartu.pinAtm = 123456;
    repeatMenu:
    system("clear");
    
    cout <<"===== Menu Bayar ===== \n";
     for (int i = 1; i < 4; i++)
    {
        cout <<i<<"." <<bayarMandiri[i] <<endl;
    }

    returnBayar:
    cout <<"Pilih yang mana : ";
    cin >> pilihBayar;

    if(pilihBayar == "1"){
        system("clear");
        string ecommerce[] = {"","Shope ", "Tokopedia ", "Lazada ", "Blibli"};
        for (int i = 1; i < 5; i++)
        {
        cout <<i<<"." <<ecommerce[i] <<endl;
        }
        repeatEcommerce:
        
        cout <<"\nPenyedia Jasa apa : ";
        cin >> selectEcommerce;

        if((selectEcommerce == "1")|(selectEcommerce == "2")|(selectEcommerce == "3")|(selectEcommerce == "4")){
            cout << "Masukan Kode Bayar "<< ecommerce[stoi(selectEcommerce)] << " : ";
            cin >> kodeBayar;

            cout << "Yang harus dibayar Rp." << hargaEcommerce << endl;
            repeat:
            cout << "Lanjutkan ya/tidak : ";
            cin >> lanjutkanEcommerce;
            if(lanjutkanEcommerce == "ya"){
                if( saldoAwal < hargaEcommerce ){
                    cout << "Saldo Tidak Cukup\n";
                }else{
                    cekKartu(hargaEcommerce);
                }

                
            }else if(lanjutkanEcommerce == "tidak"){
                goto repeatMenu;
            }else{
                goto repeat;
            }
        }else{
            goto repeatEcommerce;
        }

            
        
        
    }else if(pilihBayar == "2"){

        system("clear");
        string pendidikan[] = {"","SMK Teknik IT ", "Universitas Muhammadiyah", "Universitas IPB ", "Universitas Telkom Bandung"};
        for (int i = 1; i < 5; i++)
        {
        cout <<i<<"." <<pendidikan[i] <<endl;
        }

        repeatPendidikanMenu:
        cout <<"Cari Penyedia Pendidikan : ";
        cin >> selectPendidikan;
        if((selectPendidikan == "1")|(selectPendidikan == "2")|(selectPendidikan == "3")|(selectPendidikan == "4")){

            cout << "Masukan Kode Bayar "<< pendidikan[stoi(selectPendidikan)] << " : ";
            cin >> kodeBayar;

            cout << "Yang harus dibayar Rp." << hargaPendidikan << endl;
            repeatPendidikan:
            cout << "Lanjutkan ya/tidak : ";
            cin >> lanjutkanPendidikan;
            if(lanjutkanPendidikan == "ya"){
                if( saldoAwal < hargaPendidikan ){
                    cout << "Saldo Tidak Cukup\n";
                }else{
                    cekKartu(hargaPendidikan);
                }
            }else if(lanjutkanPendidikan == "tidak"){
                goto repeatMenu;
            }else{
                goto repeatPendidikan;
            }
        }else{
            goto repeatPendidikanMenu;
        }

    }else if(pilihBayar == "3"){
        system("clear");
        string pln[] = {"","PLN Postpaid ", "PLN Iconpay", "PLN Batam ", "PLN Jateng DIY"};
        for (int i = 1; i < 5; i++)
        {
        cout <<i<<"." <<pln[i] <<endl;
        }
        repeatPlnMenu:
        cout <<"Cari Penyedia Jasa : ";
        cin >> selectPln;
        if((selectPln == "1")|(selectPln == "2")|(selectPln == "3")|(selectPln == "4")){

            cout << "Masukan Kode Bayar "<< pln[stoi(selectPln)] << " : ";
            cin >> kodeBayar;

            cout << "Yang harus dibayar Rp." << hargaPln << endl;
            repeatPln:
            cout << "Lanjutkan ya/tidak : ";
            cin >> lanjutkanPln;
            if(lanjutkanPln == "ya"){
                if( saldoAwal < hargaPln ){
                    cout << "Saldo Tidak Cukup\n";
                }else{
                    cekKartu(hargaPln);
                }
            }else if(lanjutkanPln == "tidak"){
                goto repeatMenu;
            }else{
                goto repeatPln;
            }
        }else{
            goto repeatPlnMenu;
        }

    }else{
        goto returnBayar;
    }

    return 0;
}

int topUp(){
    system("clear");
    string pilihTopup,nomerHP,lanjutkanTopUp,lanjutkanSaldoTopUp;
    long int nominal,opsi = 3;
    repeatMenuTopUp:
    string topUp[] = {"","Dana ", "OVO ", "Gopay "};
    cout <<"===== Menu Top UP ===== \n";
    system("clear");
    for (int i = 1; i < 4; i++)
    {
        cout <<i<<"." <<topUp[i] <<endl;
    }
    
    cout << "Pilih yang mana : ";
    cin >> pilihTopup;
    cout <<"\n";

    
    

    if((pilihTopup == "1")|(pilihTopup == "2")|(pilihTopup == "3")){
            repeatSaldoTopUp:
            system("clear");

            cout << "Masukan Nominal : ";
            cin >> nominal;

            system("clear");
            cout << "Yakin dah bener?\n\n";
            cout <<"Nominal : "<< nominal<<"\n\n";         

            repeatTopup:
            cout << "Lanjutkan ya/tidak : ";
            cin >> lanjutkanTopUp;
            if(lanjutkanTopUp == "ya"){

                if(saldoAwal < nominal){
                    cout << "Saldo Tidak Cukup\n";
                    repeatSaldoCek:
                    cout << "Mau Mengulang lagi ya/tidak : ";
                    cin >> lanjutkanSaldoTopUp;
                    if(lanjutkanSaldoTopUp == "ya"){
                        goto repeatSaldoTopUp;
                    }else if(lanjutkanSaldoTopUp == "tidak"){
                        
                    }else{
                        goto repeatSaldoCek;
                    }
                }else{
                     cekKartu(nominal,opsi,pilihTopup);
                }
                
               
            }else if(lanjutkanTopUp == "tidak"){
                goto repeatMenuTopUp;
            }else{
                goto repeatTopup;
            }
        
    }else{
        goto repeatMenuTopUp;
    }
    return 0;
}

void lihatSaldo(){
    system("clear");
    cout <<"masuk ke menu Lihat Saldo";
}

int getOption(){
    system("clear");
    int pilih;

    cout <<"========== M Banking Mandiri ==========\n\n";
    cout << "Saldo Anda : Rp."<< saldoAwal<<"\n";
    cout <<"Dana : Rp"<< dana <<" | OVO : Rp"<<ovo<<" | Gopay : Rp"<< gopay<<"\n\n";
    cout <<"1.Transfer\n";
    cout <<"2.Bayar\n";
    cout <<"3.Top UP\n";
    cout <<"4.Logout\n\n";
    repeatMenu:
    cout <<"Pilih mau kemana : ";
    cin >> pilih;
    return pilih;
}

int main() {
    
    login();
    int pilihan = getOption();
    char myLetter;  
    

    while (pilihan != 4)
    {
        switch (pilihan)
        {
        case 1:
            
            transfer();
            break;
        case 2:
            bayar();
        break;
        case 3:
            topUp();
        break;
        default:
            break;
        } 

        repeat:
        cout << "\nMasuk ke Menu Utama (y/t)";
        cin >> myLetter;
        if ((myLetter == 'y'))
        {
            pilihan = getOption();
        }else if((myLetter == 't')){
            break;
        }else{
            goto repeat;
        }
    }

    cout <<"\nAnda Telah Logout\n";

    
}
