/* A PART OF ENIGMATIC SOFTWARE
THIS PROJECT AIMS AT GENERATING HTML/CSS CODE IN C++
PRESENTLY HTML AND CSS IS SUPPORTED, JAVASCRIPT MAY COME IN THE FUTURE(ARIVS.JS)
THIS PROJECT IS SUITABLE FOR WEB PAGE DESIGNING

__DONATIONS AND SUPPORT__
		CRPYTOCURRENCIES
		BTC = 37tEEcXY3xDd3t9KB4J3ELj8BnPaTiR4xg
		ETH = 0xdf3e81ef2bbc1c9cff37f8a3ffdf88e62bd9439d
		XRP = rnNQs4WAKUHes7kJtqqRiU3Wq9q1pHuDEt [destination tag = 337866511]
		LTC = MN2MRYWjdRpT9sZ9tSik7W24Kiipj4G7oR
		DASH = XjnAj7bbUzDU96j2RXzvZcYSgsvZcjj1za
		USDT = 17JDDhpnvBPz3FEQsUxEyYEPtH6KVjVUZJ
*/

#include "arivs.h"


    vector<pair<string,string>> ul_style = {i("lst","none"),i("margin","-8px"),i("padding","0"),i("w","auto")
                                ,i("overflow","hidden"),i("position","sticky"),i("bg_clr","#6218A7")};

    vector<pair<string,string>> li_style= {i("float","left"),i("display","inline")};

    vector<pair<string,string>> a_style= {i("display","block"),i("color","white"),i("padding","20px 16px"),i("text_align","center"),i("text_decoration","none"),i("font_family"," 'Segoe UI',Tahoma, Geneva,Verdana, sans-serif;"),
                                i("transition","200ms ease-in-out")};

    vector<string> combo1 ={" "," "};
    vector<string> combo2 ={" "," "};
    vector<string> combo3 ={" "," "," "};
    vector<string> combo4 ={" "," "," "," "};

    vector<pair<string,string>>a_not_style = {i("href","about.html")};

    generic *a[2];

void a_func()
{
        for(int k=0; k<=2; k++)
    {

     a[k]={ new generic("a",[&](){blueprint_a(a_not_style); blueprint_b(a_style);
        return as_tuple(arivs::external_style,combo4);
        },"")};
    }

}

int main()
{
    exterior anchor_point;

    link_css("text/css", "css_demo.css","stylesheet", "");

    set_file("html_demo.html","css_demo.css");


    generic nav("nav",[&](){
            return as_tuple(arivs::external_style,combo1);
    },"");

    generic ul("ul",[&](){
                    blueprint_b(ul_style);
                    return as_tuple(arivs::external_style,combo2);
    },"");


    generic *li[2];

    for(int i=0; i <= 2;i++)
    {
        li[i]= {new generic("li",[&](){ blueprint_b(li_style); return as_tuple(arivs::external_style,combo3); },"")};
    }

    a_func();

    nav.add_element(ul);

    for(int i=0;i <=2; i++)
    {
        ul.add_element(li[i]);

        a[0]->txt="Home";
        a[1]->txt="Advertise";
        a[2]->txt="About";

        li[i]->add_element(a[i]);


    }

    //finalize the objects

    nav.finalize();
    ul.finalize();
    li[0]->finalize();
    a[0]->finalize();

    //for the hover styling

    a[0]->inherit=":hover";
    a[0]->style_used={("background-color : #FFFFFF; "),("color: black")};
    a[0]->finalize();

    generic ads("div",[](){
                blueprint_a({i("class","ads_div")});
                blueprint_b({i("border_radius","8px"),i("box_shadow","0 0 10px #888888"),i("w","1200px"),
                i("h","420px"),i("padding","4px"),i("margin","100px"),i("display","flex"),i("jc","center"),
                i("ai","center"),i("font_family", " 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif "),i("font_size","32px")});

                return as_tuple(arivs::external_style,{});

                },"MADE WITH ARIVS");

    generic footer("div",[](){
                   blueprint_a({i("id","footer")});
                   blueprint_b({i("h","100px"),i("font_size","16px"),i("display","flex"),i("flex_direction","row"),
                               i("flex_wrap","wrap"),i("jc","space-evenly"),i("ai","center"),i("font_family"," 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif"),
                               i("bg_clr","#6218A7 !important"),i("color","white")});

                   return as_tuple(arivs::external_style,{});

                   },"The Ads Page<br>&copy;Copyright 2020");

    ads.finalize();
    footer.finalize();

    anchor_point.root =&nav;
    anchor_point.display();

    anchor_point.root = &ads;
    anchor_point.display();


    anchor_point.root = &footer;
    anchor_point.display();


    read_to_html_at_once();

}
