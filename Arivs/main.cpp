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

int main()
{


    exterior anchor_point;

    link_css("text/css", "css_demo.css","stylesheet", "");

    set_file("html_demo.html","css_demo.css");

    generic nav("nav",[](){
            return as_tuple(arivs::nothing,arivs::nothing,arivs::inline_style);
    },"");

    generic ul("ul",[](){
                    blueprint_b(i("lst","none"),i("margin","-8px"),i("padding","0"),i("w","auto")
                                ,i("overflow","hidden"),i("position","sticky"),i("bg_clr","#6218A7"));

                    return as_tuple(arivs::nothing,arivs::composition_b,arivs::inline_style);
    },"");


    generic li("li",[](){
                    blueprint_b(i("float","left"),i("display","inline"));

                    return as_tuple(arivs::nothing,arivs::composition_b,arivs::inline_style);
    },"");


    generic a("a",[](){
                    blueprint_a(i("href","ads.html"));
                    blueprint_b(i("display","block"),i("color","white"),i("padding","20px 16px"),i("text_align","center"),i("text_decoration","none"),i("font_family"," 'Segoe UI',Tahoma, Geneva,Verdana, sans-serif;"),
                                i("transition","200ms ease-in-out"));

                    return as_tuple(arivs::composition_a,arivs::composition_b,arivs::external_style);
    },"Home");


    nav.add_element(ul);

    ul.add_element(li);

    li.add_element(a);
    li.add_element(a);
    li.add_element(a);

    nav.finalize();
    ul.finalize();
    li.finalize();
    a.finalize();

    anchor_point.root =&nav;

    anchor_point.display();

    read_to_html_at_once();


}
