#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>
#define PI 3.1415926
double sankaku(double ang,char b){//角度とサインとか入れると値求めてくれる
    double answer;
    switch(b){
    case's':
    answer=sin(ang*PI/180.0);
    break;
    case'c':
    answer=cos(ang*PI/180.0);
    break;
    case't':
    answer=tan(ang*PI/180.0);
    break;
    }
    return answer;
}
int main(void)
{
    int i=0, a=0, uranai , kaomozi, fg ,fg2=0 , kaizyou;
    double sum=0 , b ,ang;
    char sw , sannkaku , q, uraura;
    printf("求めたいものは何ですか？\n四則演算→a\n三角関数→f\n平方根→r\n階乗→p\n");
    scanf("%c",&q);
    if(q=='a'){//////////////////////////////////////////四則演算//////////////////////////////
        fg=0;
        scanf("%lf",&sum);
    }else if(q=='f'){//////////////////////////////////三角関数////////////////////////////////////
        fg=1;
        scanf("%c",&sannkaku);
    while(sannkaku=='\n'){//////////改行/////////////
        scanf("%c",&sannkaku);
    }//////////////改行///////////
    scanf("%lf",&ang);
        if(sannkaku=='t'&&ang==90){
            printf("ERROR:無限になるけどだいじょぶそ？");
        return 0;
        }
        if(sannkaku=='t'&&ang==270){
            printf("ERROR:無限になるけどだいじょぶそ？");
        return 0;
        }            
        sum=sankaku(ang,sannkaku); 
    }else if(q=='r'){////////////////////////////////////平方根////////////////////////////////////////
        fg=2;
        scanf("%lf",&sum);
        sum=sqrt(sum);
    }else if(q=='p'){////////////////////////////////////階乗///////////////////////////////////////////
        int a; 
        sum=1;
        scanf("%d",&a);
        if(a==0){
            sum=1;
            fg=3;
        }else if(a>12){
        printf("ERROR:計算できません");
        return 0;
        }else{
            for(int i=1;i<=a;i++){
            sum*=i;
        }
        fg=3;
        }
    }else{
        printf("ERROR:最初からやり直してください。");
        return 0;
    }
    
    ///////////////////////////////////始め///////////////////////////////
    while(a<1){  
        if(fg==3){
            fg2=2;
            break;
        } 
        scanf("%c",&sw);
    while(sw=='\n'){
        scanf("%c",&sw);
    }
    //入力終了
        if(sw=='='){
            fg2=2;
            break;
        }else if(sw=='f'){
            fg=1;/*kannsuu*/
            scanf("%c",&sw);
            while(sw=='\n'){
            scanf("%c",&sw);
            }
        }else if(sw=='a'){
            fg=0;//modoru
            scanf("%c",&sw);
            while(sw=='\n'){
            scanf("%c",&sw);
            }
        }else if(sw=='r'){
            fg=2;
            scanf("%c",&sw);
            while(sw=='\n'){
                scanf("%c",&sw);
            }
        }//フラグ
        if(fg==1){//////////////////////三角関数
            scanf("%c",&sannkaku);
            scanf("%lf",&ang);
            if(sannkaku=='t'&&ang==90){
                printf("ERROR:無限になるけどだいじょぶそ？");
                return 0;
            }
            if(sannkaku=='t'&&ang==270){
                printf("ERROR:無限になるけどだいじょぶそ？");
                return 0;
            }            
            b=sankaku(ang,sannkaku);
        }else if(fg==0){////////////四則演算
            scanf("%lf",&b); 
        }else if(fg==2){//////////平方根
            scanf("%lf",&b);
            b=sqrt(b);
        }
 
        switch(sw){

        case '+':
            sum+=b;
            i++;
            break;
        case '-':
            sum-=b;
            i++;
            break;
        case'*':
            sum*=b;
            i++;    
            break;
        case '/':
            if(b==0){
                printf("ERROR:0じゃ割れません！ばいばい！");
                return 0;
        }
        sum/=b;
        i++;
        break;
        
        default:
            printf("ERROR:");
            return 0;
        }if(fg2==0)
        printf("現在の値;%lf\n",sum);
    }
i=0;
printf("\nA.%lf\n\n",sum);
printf("何を占いますか？\n仕事運→w\n恋愛運→r\n金運→m\n");
scanf("\n%c",&uraura);  
srand((unsigned int)time(NULL));       
uranai=rand()%3;
kaomozi=rand()%5;
switch(uraura){
case 'w'://仕事運
    if(uranai==0){
        printf("今日はあまりツキがなさそう。");
    }else if(uranai==1){
        printf("年上の人がヒントをくれそうです。目上の人を立てておいて。");
    }else if(uranai==2){
        printf("真面目が過ぎて生真面目になっているようですが、運気は抜群なので、少し砕けた感じでも何も問題ないでしょう。");
    }
break;
case 'r'://恋愛
    if(uranai==0){
        printf("急に誘って、いっしょにイベントへ行くと望んだ進展があります。");
    }else if(uranai==1){
        printf("自分の趣味の話題で、楽しんでくれる相手との距離を縮めてみて。");
    }else if(uranai==2){
        printf("恋愛については肩の力を抜いて、今日は「まあいいか」という気持ちで過ごすと良いでしょう。");
    }
break;
case 'm'://金運
    if(uranai==0){
        printf("気になる情報は、ネットであらためて検索してみて。思わぬお買い得情報にたどり着けるでしょう。");
    }else if(uranai==1){
        printf("安いからと不要な物も買いそう。結局は使わない物になります。");
    }else if(uranai==2){
        printf("臨時収入があったりと、金運は絶好調です。ゆったりと自由に過ごせる時間を持つようにして、感情を高ぶらせないようにすると良いでしょう。");
    }

break;
case 's'://顔文字
    if(kaomozi==0){
        printf("˚‧º·(˚ ˃̣̣̥⌓˂̣̣̥ )‧º·˚");
    }else if(kaomozi==1){
        printf("ฅ( ̳• ·̫ • ̳ฅ)");
    }else if(kaomozi==2){
        printf("（＾・ω・＾）ニャー");
    }else if(kaomozi==3){
        printf("(´；ω；`)");
    }else if(kaomozi==4){
        printf("(⋈◍＞◡＜◍)。✧♡");
    }
break;
default:
    printf("占わないってマジ？");
break;
}
printf("\n");
return 0;
}