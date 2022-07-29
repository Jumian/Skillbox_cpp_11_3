#include <iostream>
#include <string>
bool isIpNumber(std::string str){
    if (str[0]=='0'&&str.length()>1||str=="")return false;
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
    int start=0, stop=0,seq=0;
    for (int i =0;i<str.length();++i){

        if(str.find('.',start)!=-1){

            stop = str.find('.',start+1);
        } else {
            stop = str.length()-1;
            break;
        }

        std::cout <<(char)(start+'0') << " - " <<(char)(stop+'0') << std::endl;
//        start++;
    }
    for (int i=start;i<=stop;++i){
        number+=str[i];
    }

    return number;
}

bool isValidIp(std::string ip){


    for (int i=0; i<4;i++){
        if (!isIpNumber(get_address_part(ip,i))) return false;
    }
    return true;
}

void test(std::string ipstr){
    std::cout << ipstr << std::endl;
    std::cout << (isValidIp(ipstr)?"Valid":"Invalid");
}

int main() {
    std::cout << "Validate IPv4:" << std::endl;
    std::cout << (isIpNumber("")?"Valid":"Invalid") << std::endl;
    std::cout << (std::string)get_address_part("192.168.1.254",2) << std::endl;
    return 0;
}
