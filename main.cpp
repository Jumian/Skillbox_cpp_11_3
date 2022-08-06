#include <iostream>
#include <string>
bool isIpNumber(std::string str){
    if (str[0]=='0'&&str.length()>1||str.empty())return false;
    int multi = 1,ip=0;
    for (int i=str.length()-1; i>=0;i--){
        if (str[i]>'9' || str[i]<'0') return false;
        ip+=(str[i]-'0')*multi;
        multi*=10;
    }
    if (ip>255 || ip<0)return false;
    return true;
}
std::string get_address_part(std::string str, int index){
    std::string number="";
    int seq=0;
    for (int i =0;i<str.length();i++){
        if(str[i]=='.'){
            if (seq>=index) break;
            ++seq;
        } else if (seq == index )
            number+=str[i];
        else if (i==str.length()-1) number = "e";
    }
//    std::cout << start << " - " << stop << std::endl;

    return number;
}

bool isValidIp(std::string ip){
    for (int ii=0; ii<4;ii++){
        if (!isIpNumber(get_address_part(ip,ii))) return false;
    }
    if (get_address_part(ip,4) != "e")
        return false;
    return true;
}

void test(std::string ipstr){
    std::cout << ipstr << std::endl;
    std::cout << (isValidIp(ipstr)?"Valid":"Invalid") << std::endl;
}
void all_tests(){
    std::cout << "Valid IPv4:" << std::endl;
    test("192.168.1.254");
    test("255.255.255.255");
    test("1.2.3.4");
    test("55.77.213.101");
    std::cout << "\nInvalid IPv4:" << std::endl;
    test("255.256.257.258");
    test("0.55.33.22.");
    test("10.00.000.0 ");
    test("23.055.255.033");
    test("65.123..9");
    test("a.b.c.d");
}

int main() {
    std::string str;
    std::cin >>str;
    test(str);
//    all_tests();

    return 0;
}
