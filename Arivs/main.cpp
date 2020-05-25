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

#include "tag_n_style.h"
#include "function_prototype.h"
#include "the_classes.h"
#include "function_define.h"


int main()
{


    exterior anchor_point;

    link_css("text/css", "ads.css","stylesheet", "");

    set_file("html_demo.html","css_demo.css");

    string list_type = _list({"Home","About","Contact"},"ul");

    generic first("div",[](){
                  blueprint_a(i("class","A"));
                  blueprint_b(i("ac","sample1"),i("ac","sample2"));

                  return as_tuple(arivs::composition_a,arivs::composition_b,arivs::internal_style);
    },"text here");

    generic second("p",[](){
                    blueprint_a(i("class","B"));
                    blueprint_b(i("ai","sample3"),i("ai","sample4"));

                    return as_tuple(arivs::composition_a,arivs::composition_b,arivs::external_style);
    },"text here");

    first.add_element(second);

    first.finalize();
    second.finalize();

    anchor_point.root =&first;

    anchor_point.display();

    read_to_html_at_once();


}
