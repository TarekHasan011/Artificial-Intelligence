#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int trial;
    cin>>trial;


    int mx,my,px,py;
    for(int i=0;i<trial;i++){
        for(int j=0;j<trial;j++){
            char ch;
            cin>>ch;
            if(ch=='m'){
                mx=i;
                my=j;
            }
            else if(ch=='p'){
                px=i;
                py=j;
            }
        }
    }

    ///cout<<mx<<" "<<my<<" "<<px<<" "<<py<<endl;
    string hr, vr;
    int no_of_right=px-mx;
    if(no_of_right>0) hr="DOWN";
    else hr="UP";

    int no_of_down=py-my;
    if(no_of_down>0) vr="RIGHT";
    else vr="LEFT";

    for(int i=0;i<abs(no_of_right);i++) cout<<hr<<endl;
    for(int i=0;i<abs(no_of_down);i++) cout<<vr<<endl;

    return 0;
}
