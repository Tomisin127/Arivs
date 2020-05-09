/* A PART OF ENIGMATIC SOFTWARE
THIS PROJECT AIMS AT GENERATING HTML/CSS CODE IN C++
PRESENTLY HTML AND CSS IS SUPPORTED, JAVASCRIPT COMING IN THE FUTURE
THIS PROJECT IS SUITABLE FOR WEB PAGE DESIGNS IN ITS BASIC FORM

__DONATIONS AND SUPPORT__
		CRPYTOCURRENCIES
		BTC = 37tEEcXY3xDd3t9KB4J3ELj8BnPaTiR4xg
		ETH = 0xdf3e81ef2bbc1c9cff37f8a3ffdf88e62bd9439d
		XRP = rnNQs4WAKUHes7kJtqqRiU3Wq9q1pHuDEt [destination tag = 337866511]
		LTC = MN2MRYWjdRpT9sZ9tSik7W24Kiipj4G7oR
		DASH = XjnAj7bbUzDU96j2RXzvZcYSgsvZcjj1za
		USDT = 17JDDhpnvBPz3FEQsUxEyYEPtH6KVjVUZJ
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <cstring>
#include <variant>
#include "boost/filesystem.hpp"
#include <filesystem/include/ghc/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/proto/proto.hpp>
#include <boost/proto/context/null.hpp>
#include <boost/proto/context.hpp>
#include <boost/proto/context/default.hpp>
#include <boost/proto/eval.hpp>
#include <boost/typeof/std/ostream.hpp>
#include <tuple>
#include <functional>


using namespace std;

boost::filesystem::fstream html_object;
boost::filesystem::fstream css_object;


string quote = "\"";
string q = "\"";

string store_structure_name;

struct color_type
{
    using color =string;
    color aliceblue = "#F0F8FF";
    color antiquewhite = "#FAEBD7";
    color aqua = "#00FFFF";
    color aquamarine = "#7FFFD4";
    color azure = "#F0FFFF";
    color beige = "#F5F5DC";
    color bisque = "#FEE4C4";
    color black = "#000000";
};

struct style
{
	string width;
	string height;
	string _float= "none";

	string background;
	string background_blend_mode;
	string background_clip;
	string background_image;
	string background_color;
	string background_position;
	string background_repeat;
	string background_size;
	string background_attachment;

	string border;
	string color;

	string border_style;
	string border_top_style;
    string border_right_style;
    string border_bottom_style;
    string border_left_style;
    string border_bottom;
    string border_bottom_color;
    string border_radius;
    string border_bottom_left_radius;
    string border_bottom_right_radius;
    string border_bottom_width;
    string border_collapse;
    string border_color;
    string border_image;
    string border_image_outset;
    string border_image_repeat;
    string border_image_slice;
    string border_image_source;
    string border_image_width;
    string border_left;
    string border_left_color;
    string border_left_width;
    string border_right;
    string border_right_color;
    string border_right_width;
    string border_spacing;
    string border_top;
    string border_top_color;
    string border_top_left_radius;
    string border_top_right_radius;
    string border_top_width;

    string bottom;
    string box_decoration_break;
    string box_shadow;
    string box_sizing;
    string break_after;
    string break_before;
    string break_inside;

    string caption_side;
    string caret_color;
    string _charset;
    string _clear;
    string clip;
    string column_count;
    string column_fill;
    string column_gap;
    string column_rule;
    string column_rule_color;
    string column_rule_style;
    string column_rule_width;
    string column_span;
    string column_width;
    string columns;
    string content;
    string counter_increment;
    string counter_reset;
    string cursor;

    string direction;
    string display;

    string empty_cells;

    string filter;
    string flex;
    string flex_basis;
    string flex_direction;
    string flex_flow;
    string flex_grow;
    string flex_shrink;
    string flex_wrap;
    string font;

    string _font_face;
    string font_feature_settings;
    string _font_feature_values;
    string font_kerning;
    string font_language_override;
    string font_size_adjust;
    string font_stretch;
    string font_style;
    string font_synthesis;
    string font_variant;
    string font_variant_alternates;
    string font_variant_caps;
    string font_variant_east_asian;
    string font_variant_ligatures;
    string font_variant_numeric;
    string font_variant_position;
    string font_weight;

    string grid;
    string grid_area;
    string grid_auto_columns;
    string grid_auto_flow;
    string grid_auto_rows;
    string grid_column;
    string grid_column_end;
    string grid_column_gap;
    string grid_column_start;
    string grid_gap;
    string grid_row;
    string grid_row_end;
    string grid_row_gap;
    string grid_row_start;
    string grid_template;
    string grid_template_areas;
    string grid_template_columns;
    string grid_template_rows;

    string hanging_punctuation;
    string hyphens;

    string image_rendering;
    string _import;
    string isolation;
    string justify_content;

    string _keyframes;


    string margin;
    string margin_top;
    string margin_right;
    string margin_bottom;
    string margin_left;

    string padding;
    string padding_top;
    string padding_right;
    string padding_bottom;
    string padding_left;

    string outline_style;
    string outline_color;
    string outline_width;
    string outline_offset;
    string outline;

	string border_width;


	string text_align;
	string font_family;
	string font_size;
	string align_content;
	string align_items;
	string align_self;
	string all;
	string animation;
	string animation_delay;
	string animation_direction;
	string animation_duration;
	string animation_fill_mode;
	string animation_iteration_count;
	string animation_name;
	string animation_play_state;
	string animation_timing_function;

    string left;
    string letter_spacing;
    string line_break;
    string line_height;
    string list_style;
    string list_style_image;
    string list_style_position;
    string list_style_type;

    string max_height;
    string max_width;
    string _media;
    string min_height;
    string min_width;
    string mix_blend_mode;

    string object_fit;
    string object_position;
    string opacity;
    string order;
    string orphans;

    string overflow;
    string overflow_wrap;
    string overflow_x;
    string overflow_y;

    string page_break_after;
    string page_break_before;
    string page_break_inside;
    string perspective_origin;
    string perspective;
    string pointer_events;
    string position;

    string _resize;
    string right;
    string scroll_behavior;
    string tab_size;
    string table_layout;
    string text_align_last;

    string text_combine_upright;
    string text_decoration;
    string text_decoration_color;
    string text_decoration_line;

    string text_decoration_style;
    string text_indent;
    string text_justify;
    string text_orientation;
    string text_overflow;
    string text_shadow;
    string text_transform;
    string text_underline_position;
    string top;
    string _transform;
    string transform_origin;
    string transform_style;
    string transition;
    string transition_delay;
    string transition_duration;
    string transition_property;
    string transition_timing_function;

    string quotes;

    string unicode_bidi;
    string user_select;

    string vertical_align;
    string visibility;

    string white_space;
    string widows;
    string word_break;
    string word_spacing;
    string word_wrap;
    string writing_mode;

    string z_index;

	string backface_visibility;

    color_type color_obj;

	friend ostream &operator<<(ostream &os, style &c);

};

using lambda = function<tuple<multimap<string,vector<pair<string,string>>>,multimap<string,vector<pair<string,string>>>,string>(void)>;

vector<string> style_used;

vector<string>all_existing_tags_in_html={"header","nav","h1","h2","h3","h4","h5","h6","ul","ol","title","base","bdi","button","center","a","abbr","acronym","address","applet","area",
"audio","b","body","basefont","bdo","br","bdo","blockquote","canvas","caption","cite","code","col","colgroup","data","datalist","dd","del","details","dfn",
"dialog","dir","div","dl","dt","em","embed","fieldset","figcaption","figure","font","footer","form","frame","frameset","p1","p2","p3","p4","p5","p6","head",
"hr","html","i","iframe","img","input","ins","kbd","label","legend","li","link","main","map","mark","meter","noframes","noscript","object","var","optgroup","option",
"output","p","param","picture","pre","progress","q","rp","rt","ruby","s","samp","script","section","select","small","source","span","strike","strong","style","sub",
"summary","sup","svg","table","tbody","td","template","textarea","tfoot","th","thead","time","title","tr","track","tt","u","video","wbr"
};

ostream &operator<<(ostream &os, style &c)
{
    os << c <<endl;
    return os;
}

struct coords
{
    int x=0;
    int y=0;
    int z=0;
    int w=0;
};

template<typename... Args>
void blueprint_a(Args&&... args){}

template<typename T, typename... Args>
void blueprint_a(T&& arg,Args&&...optional);

template<typename... Args>
void blueprint_b(Args&&... args){}

template<typename T, typename... Args>
void blueprint_b(T&& arg,Args&&...optional);



template<typename... T>
inline string body(string text,T&&... args);

template<typename... T>
inline string stylings(string text,T&&... args);

inline string _list(list<string> ls,string specify);

inline string area(string shape , coords &c, string href, string alt);

template<typename... T>
inline string script(string text,T&&... args);

auto lambda_expression_manipulator(lambda p);

void automatic_nest_matcher(string main_name);

auto initializer_list_manipulator(initializer_list<string> inserted_text);

auto assert_mode_of_styling(string sty_typ, string name);

template<typename... T>
auto expression_pack_manipulator(T&&... exp);

inline string rgb(int red, int green, int blue);
inline string hsl(int hue,int saturation, int lightness);
inline string rgba(int red, int green, int blue, int alpha);

inline string h_text(int h_level,string text);

inline string h_text(int h_level,lambda r, string text);

template<typename... T>
inline string h_text(int h_level,lambda r, string text,T&&... args );

inline string p_text(int p_level,string text);

inline string p_text(int p_level,lambda r, string text);

template<typename... T>
inline string p_text(int p_level,lambda r, string text,T&&... args );

template<typename ...T>
string generic(string type, lambda h,string text,T&&... args);

string generic(string type, lambda h,string text);

string generic(string type,string text);

template<typename... T>
string generic(string type,string text,T&&...args);

string generic(string type);

string load_image(string img,string alt_value, string title, string identity, string usemap);

string link_css(string type, string href, string rel, string media);

string stylesheet_internal(string div_name);

string stylesheet_external(string div_name);
string stylesheet_external(string div_name,string selector);
string stylesheet_external(string selector,string a,string b);

void read_to_file(string read);
void read_to_css_file(string item);
void read_to_html_at_once(vector<string>args);
void read_to_css_at_once();

vector<string> html_code_list;
vector<string> css_code_list_external;

map<string,string>div_details;
vector<string> file_names;

style s;

map<string,string> one_to_many;

inline void set_file(string &&html_file_name,string &&css_file_name);
string get_file_names(const string &key);

template<typename A, typename B>
style& construct_attributes(A name,B value)
{

    list<string>::iterator a;
    list<string>::iterator b;

        for(a = name.begin(), b=value.begin(); a!=name.end(),b!=value.end(); a++,b++)
        {

            cout << "a: "<< *a <<endl;
            cout << "b: "<< *b <<endl;

            //a

                if(*a=="align_content" || *a=="ac")
            {

                s.align_content= *b;
                string text = "align-content: "+s.align_content+";";
                style_used.push_back(text);
            }

                if(*a=="align_items" || *a=="ai")
            {
                s.align_items= *b;
                string text = "align-items: "+s.align_items+";";
                style_used.push_back(text);
            }

                    if(*a=="align_self" || *a =="as")
            {
                s.align_self= *b;
                string text = "align-self: "+s.align_self+";";
                style_used.push_back(text);
            }

                    if(*a=="all")
            {
                s.all= *b;
                string text = "all: "+s.all+";";
                style_used.push_back(text);
            }

                    if(*a=="animation" || *a=="anim")
            {
                s.animation= *b;
                string text = "animation: "+s.animation+";";
                style_used.push_back(text);
            }

                    if(*a=="animation_delay" || *a=="anim_dly")
            {
                s.animation_delay= *b;
                string text = "animation-delay: "+s.animation_delay+";";
                style_used.push_back(text);
            }

                if(*a=="animation_direction" or *a=="anim_dir")
            {
                s.animation_direction= *b;
                string text = "animation-direction: "+s.animation_direction+";";
                style_used.push_back(text);
            }

                    if(*a=="animation_duration" ||*a=="anim_dur")
            {
                s.animation_duration= *b;
                string text = "animation-duration: "+s.animation_duration+";";
                style_used.push_back(text);
            }

                    if(*a=="animation_fill_mode" ||*a =="afm")
            {
                s.animation_fill_mode= *b;
                string text = "animation-fill-mode: "+s.animation_fill_mode+";";
                style_used.push_back(text);
            }

                    if(*a=="animation_iteration_count" || *a=="aic")
            {
                s.animation_iteration_count= *b;
                string text = "animation-iteration-count: "+s.animation_iteration_count+";";
                style_used.push_back(text);
            }

                    if(*a=="animation_name" || *a=="anim_name")
            {
                s.animation_name= *b;
                string text = "animation-name: "+s.animation_name+";";
                style_used.push_back(text);
            }

                    if(*a=="animation_play_state" ||*a=="aps")
            {
                s.animation_play_state= *b;
                string text = "animation-play-state: "+s.animation_play_state+";";
                style_used.push_back(text);
            }

                    if(*a=="animation_timing_function" || *a=="atf")
            {
                s.animation_timing_function= *b;
                string text = "animation-timing-function: "+s.animation_timing_function+";";
                style_used.push_back(text);
            }

            //b

                    if(*a=="backface_visibility" ||*a=="bv")
            {
                s.backface_visibility= *b;
                string text = "backface-visibility: "+s.backface_visibility+";";
                style_used.push_back(text);
            }

                    if(*a=="background" || *a=="bg")
            {
                s.background= *b;
                string text = "background: "+s.background+";";
                style_used.push_back(text);
            }

                    if(*a=="background_attachment" || *a=="bg_atch" )
            {
                s.background_attachment= *b;
                string text = "background-attachment: "+s.background_attachment+";";
                style_used.push_back(text);
            }

                    if(*a=="background_blend_mode" || *a=="bg_bm")
            {
                s.background_blend_mode= *b;
                string text = "background-blend-mode: "+s.background_blend_mode+";";
                style_used.push_back(text);
            }

                    if(*a=="background_clip" || *a=="bg_clip")
            {
                s.background_clip= *b;
                string text = "background-clip: "+s.background_clip+";";
                style_used.push_back(text);
            }

                    if(*a=="background_color" || *a=="bg_clr")
            {
                s.background_color= *b;
                string text = "background-color: "+s.background_color+";";
                style_used.push_back(text);
            }

                    if(*a=="background_image" || *a=="bg_img")
            {
                s.background_image= *b;
                string text = "background-image: "+s.background_image+";";
                style_used.push_back(text);
            }

               if(*a =="border_bottom_color" || *a =="bbc")
            {
                s.border_bottom_color=*b;
                string text ="border-bottom-color: "+s.border_bottom_color+";\n";
                style_used.push_back(text);
            }
               if(*a =="border_bottom-left_radius" || *a =="bblr")
            {
                s.border_bottom_left_radius=*b;
                string text ="border-bottom-left-radius: "+s.border_bottom_left_radius+";\n";
                style_used.push_back(text);
            }

               if(*a =="border_bottom_right_radius" || *a =="bbrr")
            {
                s.border_bottom_right_radius=*b;
                string text ="border-bottom-right-radius: "+s.border_bottom_right_radius+";\n";
                style_used.push_back(text);
            }
               if(*a =="border_bottom_width" ||*a =="bbw")
            {
                s.border_bottom_width=*b;
                string text ="border-bottom-width: "+s.border_bottom_width+";\n";
                style_used.push_back(text);
            }

               if(*a =="border_collapse" || *a =="b_clp")
            {
                s.border_collapse=*b;
                string text ="border-collapse: "+s.border_collapse+";\n";
                style_used.push_back(text);
            }

               if(*a =="border_color" || *a =="b_clr")
            {
                s.border_color=*b;
                string text ="border-color: "+s.border_color+";\n";
                style_used.push_back(text);
            }

               if(*a =="border_image" || *a =="b_img")
            {
                s.border_image=*b;
                string text ="border-image: "+s.border_image+";\n";
                style_used.push_back(text);
            }

               if(*a =="border_image_outset" || *a =="bio")
            {
                s.border_image_outset=*b;
                string text ="border-image-outset: "+s.border_image_outset+";\n";
                style_used.push_back(text);
            }

                if(*a =="border_image_repeat" || *a =="bir")
            {
                s.border_image_repeat=*b;
                string text ="border-image-repeat: "+s.border_image_repeat+";\n";
                style_used.push_back(text);
            }

                if(*a =="border_image_slice" || *a =="bisl")
            {
                s.border_image_slice=*b;
                string text ="border-image-slice: "+s.border_image_slice+";\n";
                style_used.push_back(text);
            }

                if(*a =="border_image_source" ||*a =="biso")
            {
                s.border_image_source=*b;
                string text ="border-image-source: "+s.border_image_source+";\n";
                style_used.push_back(text);
            }

                if(*a =="border_image_width" || *a =="biw")
            {
                s.border_image_width=*b;
                string text ="border-image-width: "+s.border_image_width+";\n";
                style_used.push_back(text);
            }

                if(*a =="border_left" || *a =="bl")
            {
                s.border_left=*b;
                string text ="border-left: "+s.border_left+";\n";
                style_used.push_back(text);
            }

                if(*a =="border_left_color" || *a =="blc")
            {
                s.border_left_color=*b;
                string text ="border-left-color: "+s.border_left_color+";\n";
                style_used.push_back(text);
            }


                if(*a =="border_left_style" || *a =="bls")
            {
                s.border_left_style=*b;
                string text ="border-left-style: "+s.border_left_style+";\n";
                style_used.push_back(text);
            }


                if(*a =="border_left_width" || *a =="blw")
            {
                s.border_left_width=*b;
                string text ="border-left-width: "+s.border_left_width+";\n";
                style_used.push_back(text);
            }


                if(*a =="border_radius" || *a =="b_rad")
            {
                s.border_radius=*b;
                string text ="border-radius: "+s.border_radius+";\n";
                style_used.push_back(text);
            }


                if(*a =="border_right" || *a =="b_rht")
            {
                s.border_right=*b;
                string text ="border-right: "+s.border_right+";\n";
                style_used.push_back(text);
            }


                if(*a =="border_right_color" || *a =="brc")
            {
                s.border_right_color=*b;
                string text ="border-right-color: "+s.border_right_color+";\n";
                style_used.push_back(text);
            }


                if(*a =="border_right_style" || *a =="brs")
            {
                s.border_right_style=*b;
                string text ="border-right-style: "+s.border_right_style+";\n";
                style_used.push_back(text);
            }


                if(*a =="border_right_width" || *a =="brw")
            {
                s.border_right_width=*b;
                string text ="border-right-width: "+s.border_right_width+";\n";
                style_used.push_back(text);
            }


                if(*a =="border_spacing" || *a =="b_spc")
            {
                s.border_spacing=*b;
                string text ="border-spacing: "+s.border_spacing+";\n";
                style_used.push_back(text);
            }


                if(*a =="border_style" || *a =="b_sty")
            {
                s.border_style=*b;
                string text ="border-style: "+s.border_style+";\n";
                style_used.push_back(text);
            }

                if(*a =="border_top" || *a =="bt")
            {
                s.border_top=*b;
                string text ="border-top: "+s.border_top+";\n";
                style_used.push_back(text);
            }

                if(*a =="border_top_color" || *a =="btc")
            {
                s.border_top_color=*b;
                string text ="border-top-color: "+s.border_top_color+";\n";
                style_used.push_back(text);
            }

                if(*a =="border_top_left_radius" || *a =="btlr")
            {
                s.border_top_left_radius=*b;
                string text ="border-top-left-radius: "+s.border_top_left_radius+";\n";
                style_used.push_back(text);
            }

                if(*a =="border_top_right_radius" || *a =="btrr")
            {
                s.border_top_right_radius=*b;
                string text ="border-top-right-radius: "+s.border_top_right_radius+";\n";
                style_used.push_back(text);
            }

                if(*a =="border_top_style" || *a =="bts")
            {
                s.border_top_style=*b;
                string text ="border-top-style: "+s.border_top_style+";\n";
                style_used.push_back(text);
            }

                if(*a =="border_top_width" || *a =="btw")
            {
                s.border_top_width=*b;
                string text ="border-top-width: "+s.border_top_width+";\n";
                style_used.push_back(text);
            }

                if(*a =="border_width" || *a =="bw")
            {
                s.border_width=*b;
                string text ="border-width: "+s.border_width+";\n";
                style_used.push_back(text);
            }

                if(*a =="bottom" || *a =="btm")
            {
                s.bottom=*b;
                string text ="bottom: "+s.bottom+";\n";
                style_used.push_back(text);
            }

                if(*a =="box_decoration_break" || *a =="bdb")
            {
                s.box_decoration_break=*b;
                string text ="box-decoration-break: "+s.box_decoration_break+";\n";
                style_used.push_back(text);
            }

                if(*a =="box_shadow" || *a =="b_shd")
            {
                s.box_shadow=*b;
                string text ="box-shadow: "+s.box_shadow+";\n";
                style_used.push_back(text);
            }

                if(*a =="box_sizing" || *a =="b_siz")
            {
                s.box_sizing=*b;
                string text ="box-sizing: "+s.box_sizing+";\n";
                style_used.push_back(text);
            }

                if(*a =="break_after" || *a =="brk_af")
            {
                s.break_after=*b;
                string text ="break-afer: "+s.break_after+";\n";
                style_used.push_back(text);
            }

                if(*a =="break_before" || *a =="brk_bf")
            {
                s.break_before=*b;
                string text ="break-before: "+s.break_before+";\n";
                style_used.push_back(text);
            }

                if(*a =="break_inside" || *a =="brk_ins")
            {
                s.break_inside=*b;
                string text ="break-inside: "+s.break_inside+";\n";
                style_used.push_back(text);
            }


            //C

                if(*a =="caption_side" || *a =="cs")
            {
                s.caption_side=*b;
                string text ="caption-side: "+s.caption_side+";\n";
                style_used.push_back(text);
            }

                if(*a =="caret_color" || *a =="cc")
            {
                s.caret_color=*b;
                string text ="caret-color: "+s.caret_color+";\n";
                style_used.push_back(text);
            }

                if(*a =="charset" || *a =="chr")
            {
                s._charset=*b;
                string text ="@charset: "+s._charset+";\n";
                style_used.push_back(text);
            }

                if(*a =="clear" || *a =="clr")
            {
                s._clear=*b;
                string text ="clear: "+s._clear+";\n";
                style_used.push_back(text);
            }
                if(*a =="clip" || *a =="clp")
            {
                s.clip=*b;
                string text ="clip: "+s.clip+";\n";
                style_used.push_back(text);
            }

                if(*a =="color"  || *a =="clr")
            {
                s.color=*b;
                string text ="color: "+s.color+";\n";
                style_used.push_back(text);
            }

                if(*a =="column_count" || *a =="cln_cnt")
            {
                s.column_count=*b;
                string text ="column-count: "+s.column_count+";\n";
                style_used.push_back(text);
            }

                if(*a =="column_fill" || *a =="cln_fil")
            {
                s.column_fill=*b;
                string text ="column-fill: "+s.column_fill+";\n";
                style_used.push_back(text);
            }

                if(*a =="column_gap"  || *a =="cln_gp")
            {
                s.column_gap=*b;
                string text ="column-gap: "+s.column_gap+";\n";
                style_used.push_back(text);
            }
                if(*a =="column_rule" || *a =="cln_rul")
            {
                s.column_rule=*b;
                string text ="column-rule: "+s.column_rule+";\n";
                style_used.push_back(text);
            }


            //D

                if(*a =="direction" || *a =="dir")
            {
                s.direction=*b;
                string text ="direction: "+s.direction+";\n";
                style_used.push_back(text);
            }

                if(*a =="display" || *a =="dsp")
            {
                s.display=*b;
                string text ="display: "+s.display+";\n";
                style_used.push_back(text);
            }

            //E

                if(*a =="empty_cells" || *a =="ec")
            {
                s.empty_cells=*b;
                string text ="empty-cells: "+s.empty_cells+";\n";
                style_used.push_back(text);
            }


            //F

                if(*a =="filter"  || *a =="flt")
            {
                s.filter=*b;
                string text ="filter: "+s.filter+";\n";
                style_used.push_back(text);
            }

                if(*a =="flex" || *a =="flx")
            {
                s.flex=*b;
                string text ="flex: "+s.flex+";\n";
                style_used.push_back(text);
            }

                if(*a =="flex_basis" || *a =="flx_bs")
            {
                s.flex_basis=*b;
                string text ="flex-basis: "+s.flex_basis+";\n";
                style_used.push_back(text);
            }

                if(*a =="flex_direction" || *a =="flx_dir")
            {
                s.flex_direction=*b;
                string text ="flex-direction: "+s.flex_direction+";\n";
                style_used.push_back(text);
            }

                if(*a =="flex_flow" || *a =="flx_flw")
            {
                s.flex_flow=*b;
                string text ="flex-flow: "+s.flex_flow+";\n";
                style_used.push_back(text);
            }

                if(*a =="flex_grow" || *a =="flx_grw")
            {
                s.flex_grow=*b;
                string text ="flex-grow: "+s.flex_grow+";\n";
                style_used.push_back(text);
            }

                if(*a =="flex_shrink" || *a =="flx_shr")
            {
                s.flex_shrink=*b;
                string text ="flex-shrink: "+s.flex_shrink+";\n";
                style_used.push_back(text);
            }

                if(*a =="flex_wrap" || *a =="flx_wrp")
            {
                s.flex_wrap=*b;
                string text ="flex-wrap: "+s.flex_wrap+";\n";
                style_used.push_back(text);
            }

                if(*a =="float" || *a =="f")
            {
                s._float=*b;
                string text ="float: "+s._float+";\n";
                style_used.push_back(text);
            }


                if(*a =="font" || *a =="fnt")
            {
                s.font=*b;
                string text ="font: "+s.font+";\n";
                style_used.push_back(text);
            }


                if(*a =="font_face" || *a =="fnt_fce")
            {
                s._font_face=*b;
                string text ="@font_face: "+s._font_face+";\n";
                style_used.push_back(text);
            }


                if(*a =="font_family" || *a =="fnt_fam")
            {
                s.font_family=*b;
                string text ="font-family: "+s.font_family+";\n";
                style_used.push_back(text);
            }


                if(*a =="font_feature_settings" || *a =="ffs")
            {
                s.font_feature_settings=*b;
                string text ="font-feature-settings: "+s.font_feature_settings+";\n";
                style_used.push_back(text);
            }


                if(*a =="font_feature_values" || *a =="ffv")
            {
                s._font_feature_values=*b;
                string text ="@font-feature-values: "+s._font_feature_values+";\n";
                style_used.push_back(text);
            }


                if(*a =="font_kerning" || *a =="fnt_krn")
            {
                s.font_kerning=*b;
                string text ="font-kerning: "+s.font_kerning+";\n";
                style_used.push_back(text);
            }


                if(*a =="font_language_override" || *a =="flo")
            {
                s.font_language_override=*b;
                string text ="font-language-override: "+s.font_language_override+";\n";
                style_used.push_back(text);
            }


                if(*a =="font_size" || *a =="fnt_sz")
            {
                s.font_size=*b;
                string text ="font-size: "+s.font_size+";\n";
                style_used.push_back(text);
            }


                if(*a =="font_size_adjust" || *a =="fsa")
            {
                s.font_size_adjust=*b;
                string text ="font-size-adjust: "+s.font_size_adjust+";\n";
                style_used.push_back(text);
            }


                if(*a =="font_stretch" || *a =="fnt_str")
            {
                s.font_stretch=*b;
                string text ="font-stretch: "+s.font_stretch+";\n";
                style_used.push_back(text);
            }

            //G


                if(*a =="grid" || *a =="grd")
            {
                s.grid=*b;
                string text ="grid: "+s.grid+";\n";
                style_used.push_back(text);
            }


                if(*a =="grid_area" || *a =="grd_ar")
            {
                s.grid_area=*b;
                string text ="grid-area: "+s.grid_area+";\n";
                style_used.push_back(text);
            }


                if(*a =="grid_auto_columns" || *a =="gac")
            {
                s.grid_auto_columns=*b;
                string text ="grid-auto-columns: "+s.grid_auto_columns+";\n";
                style_used.push_back(text);
            }

                if(*a =="grid_auto_flow" || *a =="gaf")
            {
                s.grid_auto_flow=*b;
                string text ="grid-auto-flow: "+s.grid_auto_flow+";\n";
                style_used.push_back(text);
            }


                if(*a =="grid_auto_rows" || *a =="gar")
            {
                s.grid_auto_rows=*b;
                string text ="grid-auto-rows: "+s.grid_auto_rows+";\n";
                style_used.push_back(text);
            }

                if(*a =="grid_column" || *a =="grd_cln")
            {
                s.grid_column=*b;
                string text ="grid-column: "+s.grid_column+";\n";
                style_used.push_back(text);
            }


                if(*a =="grid_column_end" || *a =="gce")
            {
                s.grid_column_end=*b;
                string text ="grid-column-end: "+s.grid_column_end+";\n";
                style_used.push_back(text);
            }


                if(*a =="grid_column_gap" || *a =="gcg")
            {
                s.grid_column_gap=*b;
                string text ="grid-column-gap: "+s.grid_column_gap+";\n";
                style_used.push_back(text);
            }

                if(*a =="grid_column_start" || *a =="gcs")
            {
                s.grid_column_start=*b;
                string text ="grid-column-start: "+s.grid_column_start+";\n";
                style_used.push_back(text);
            }


                if(*a =="grid_gap" || *a =="grd_gp")
            {
                s.grid_gap=*b;
                string text ="grid-gap: "+s.grid_gap+";\n";
                style_used.push_back(text);
            }

                if(*a =="grid_row" || *a =="grd_rw")
            {
                s.grid_row=*b;
                string text ="grid-row: "+s.grid_row+";\n";
                style_used.push_back(text);
            }


                if(*a =="grid_row_end" || *a =="gre")
            {
                s.grid_row_end=*b;
                string text ="grid-row-end: "+s.grid_row_end+";\n";
                style_used.push_back(text);
            }

                if(*a =="grid_row_gap" || *a =="grg")
            {
                s.grid_row_gap=*b;
                string text ="grid-row-gap: "+s.grid_row_gap+";\n";
                style_used.push_back(text);
            }

                if(*a =="grid_row_start" || *a =="grs")
            {
                s.grid_row_start=*b;
                string text ="grid-row-start: "+s.grid_row_start+";\n";
                style_used.push_back(text);
            }

                if(*a =="grid_template" || *a =="grd_tem")
            {
                s.grid_template=*b;
                string text ="grid-template: "+s.grid_template+";\n";
                style_used.push_back(text);
            }


                if(*a =="grid_template_areas" || *a =="gta")
            {
                s.grid_template_areas=*b;
                string text ="grid-template-areas: "+s.grid_template_areas+";\n";
                style_used.push_back(text);
            }


                if(*a =="grid_template_columns" || *a =="gtc")
            {
                s.grid_template_columns=*b;
                string text ="grid-template-columns: "+s.grid_template_columns+";\n";
                style_used.push_back(text);
            }


                if(*a =="grid_template_rows" || *a =="gtr")
            {
                s.grid_template_rows=*b;
                string text ="grid-template-rows: "+s.grid_template_rows+";\n";
                style_used.push_back(text);
            }

            //H

                if(*a =="hanging_punctuation" || *a =="hp")
            {
                s.hanging_punctuation=*b;
                string text ="hanging-punctuation: "+s.hanging_punctuation+";\n";
                style_used.push_back(text);
            }


                if(*a =="hyphens" || *a =="hyp")
            {
                s.hyphens=*b;
                string text ="hyphens: "+s.hyphens+";\n";
                style_used.push_back(text);
            }

            //I


                if(*a =="image_rendering" || *a =="ir")
            {
                s.image_rendering=*b;
                string text ="image-rendering: "+s.image_rendering+";\n";
                style_used.push_back(text);
            }


                if(*a =="import" || *a =="i")
            {
                s._import=*b;
                string text ="@import: "+s._import+";\n";
                style_used.push_back(text);
            }


                if(*a =="isolation" || *a =="iso")
            {
                s.isolation=*b;
                string text ="isolation: "+s.isolation+";\n";
                style_used.push_back(text);
            }

            //J


                if(*a =="justify_content" || *a =="jc")
            {
                s.justify_content=*b;
                string text ="justify-content: "+s.justify_content+";\n";
                style_used.push_back(text);
            }

            //K


                if(*a =="keyframes" || *a =="kf")
            {
                s._keyframes=*b;
                string text ="@keyframes: "+s._keyframes+";\n";
                style_used.push_back(text);
            }

            //L


                if(*a =="left" || *a =="l")
            {
                s.left=*b;
                string text ="left: "+s.left+";\n";
                style_used.push_back(text);
            }

                if(*a =="letter_spacing" || *a =="ls")
            {
                s.letter_spacing=*b;
                string text ="letter-spacing: "+s.letter_spacing+";\n";
                style_used.push_back(text);
            }

                if(*a =="line_break" || *a =="lb")
            {
                s.line_break=*b;
                string text ="line-break: "+s.line_break+";\n";
                style_used.push_back(text);
            }

                if(*a =="line_height" || *a =="lh")
            {
                s.line_height=*b;
                string text ="line-height: "+s.line_height+";\n";
                style_used.push_back(text);
            }

                if(*a =="list_style" || *a =="ls")
            {
                s.list_style=*b;
                string text ="list-style: "+s.list_style+";\n";
                style_used.push_back(text);
            }


                if(*a =="list_style_image" || *a =="lsi")
            {
                s.list_style_image=*b;
                string text ="list-style-image: "+s.list_style_image+";\n";
                style_used.push_back(text);
            }


                if(*a =="list_style_position" || *a =="lsp")
            {
                s.list_style_position=*b;
                string text ="list-style-position: "+s.list_style_position+";\n";
                style_used.push_back(text);
            }


                if(*a =="list_style_type" || *a =="lst")
            {
                s.list_style_type=*b;
                string text ="list-style-type: "+s.list_style_type+";\n";
                style_used.push_back(text);
            }

            //M

                if(*a =="margin_bottom" || *a =="mb")
            {
                s.margin_bottom=*b;
                string text ="margin-bottom: "+s.margin_bottom+";\n";
                style_used.push_back(text);
            }


                if(*a =="margin_left" || *a =="ml")
            {
                s.margin_left=*b;
                string text ="margin-left: "+s.margin_left+";\n";
                style_used.push_back(text);
            }


                if(*a =="margin_right" || *a =="mr")
            {
                s.margin_right=*b;
                string text ="margin-right: "+s.margin_right+";\n";
                style_used.push_back(text);
            }

                if(*a =="margin_top" || *a =="mt")
            {
                s.margin_top=*b;
                string text ="margin-top: "+s.margin_top+";\n";
                style_used.push_back(text);
            }


                if(*a =="max_height" || *a =="max_h")
            {
                s.max_height=*b;
                string text ="max-height: "+s.max_height+";\n";
                style_used.push_back(text);
            }


                if(*a =="max_width" || *a =="max_w")
            {
                s.max_width=*b;
                string text ="max-width: "+s.max_width+";\n";
                style_used.push_back(text);
            }


                if(*a =="media" || *a =="med")
            {
                s._media=*b;
                string text ="@media: "+s._media+";\n";
                style_used.push_back(text);
            }


                if(*a =="min_height" || *a =="min_h")
            {
                s.min_height=*b;
                string text ="min-height: "+s.min_height+";\n";
                style_used.push_back(text);
            }

                if(*a =="min_width" || *a =="min_w")
            {
                s.min_width=*b;
                string text ="min-width: "+s.min_width+";\n";
                style_used.push_back(text);
            }


                if(*a =="mix_blend_mode" || *a =="mbm")
            {
                s.mix_blend_mode=*b;
                string text ="mix-blend-mode: "+s.mix_blend_mode+";\n";
                style_used.push_back(text);
            }

            //O

                if(*a =="object_fit" || *a =="of")
            {
                s.object_fit=*b;
                string text ="object-fit: "+s.object_fit+";\n";
                style_used.push_back(text);
            }

                if(*a =="object_position" || *a =="op")
            {
                s.object_position=*b;
                string text ="object-position: "+s.object_position+";\n";
                style_used.push_back(text);
            }

                if(*a =="opacity" || *a =="opc")
            {
                s.opacity=*b;
                string text ="opacity: "+s.opacity+";\n";
                style_used.push_back(text);
            }


                if(*a =="order" || *a =="ord")
            {
                s.order=*b;
                string text ="order: "+s.order+";\n";
                style_used.push_back(text);
            }


                if(*a =="orphans" || *a =="oph")
            {
                s.orphans=*b;
                string text ="orphans: "+s.orphans+";\n";
                style_used.push_back(text);
            }


                if(*a =="outline" || *a =="ol")
            {
                s.outline=*b;
                string text ="outline: "+s.outline+";\n";
                style_used.push_back(text);
            }


                if(*a =="outline_color" || *a =="oc")
            {
                s.outline_color=*b;
                string text ="outline-color: "+s.outline_color+";\n";
                style_used.push_back(text);
            }

                if(*a =="outline_offset" || *a =="oo")
            {
                s.outline_offset=*b;
                string text ="outline-offset: "+s.outline_offset+";\n";
                style_used.push_back(text);
            }

                if(*a =="outline_style" || *a =="os")
            {
                s.outline_style=*b;
                string text ="outline-style: "+s.outline_style+";\n";
                style_used.push_back(text);
            }


                if(*a =="outline_width" || *a =="ow")
            {
                s.outline_width=*b;
                string text ="outline-width: "+s.outline_width+";\n";
                style_used.push_back(text);
            }


                if(*a =="overflow" || *a =="of")
            {
                s.overflow=*b;
                string text ="overflow: "+s.overflow+";\n";
                style_used.push_back(text);
            }


                if(*a =="overflow_wrap" || *a =="ofw")
            {
                s.overflow_wrap=*b;
                string text ="overflow-wrap: "+s.overflow_wrap+";\n";
                style_used.push_back(text);
            }


                if(*a =="overflow_x" || *a =="ofx")
            {
                s.overflow_x=*b;
                string text ="overflow-x: "+s.overflow_x+";\n";
                style_used.push_back(text);
            }


                if(*a =="overflow_y" || *a =="ofy")
            {
                s.overflow_y=*b;
                string text ="overflow-y: "+s.overflow_y+";\n";
                style_used.push_back(text);
            }

            //Q


                if(*a =="quotes" || *a =="q")
            {
                s.quotes=*b;
                string text ="quotes: "+s.quotes+";\n";
                style_used.push_back(text);
            }


                if(*a=="width" || *a=="w")
            {
                s.width = *b;

                string text = "width:"  +s.width+";\n";

                style_used.push_back(text);

            }

            if(*a=="height" ||*a=="h")
            {
                s.height = *b;

                string text = "height:" +s.height+";\n";

                style_used.push_back(text);
            }

            if(*a =="border" )
            {
                s.border = *b;

                string text = "border:" +s.border+";\n";

                style_used.push_back(text);
            }

            if(*a =="margin")
            {
                s.margin = *b;
                string text ="margin: "+s.margin+";\n";
                style_used.push_back(text);

            }
            if(*a =="border_bottom" or *a =="bb")
            {
                s.border_bottom=*b;
                string text ="border-bottom: "+s.border_bottom+";\n";
                style_used.push_back(text);
            }
            if(*a=="border_bottom_style" or *a=="bbs")
            {
                s.border_bottom_style=*b;
                string text = "border-bottom: "+s.border_bottom_style+";\n";
                style_used.push_back(text);
            }
            if(*a=="padding")
            {
                s.padding = *b;
                string text = "padding: "+s.padding+";\n";
                style_used.push_back(text);
            }
            if(*a=="padding_left")
            {
                s.padding = *b;
                string text = "padding_left: "+s.padding_left+";\n";
                style_used.push_back(text);
            }

             if(*a=="padding_right")
            {
                s.padding_right = *b;
                string text = "padding_right: "+s.padding_right+";\n";
                style_used.push_back(text);
            }
             if(*a=="padding_top")
            {
                s.padding_top = *b;
                string text = "padding_top: "+s.padding_top+";\n";
                style_used.push_back(text);
            }
            if(*a=="padding_bottom")
            {
                s.padding_bottom = *b;
                string text = "padding_bottom: "+s.padding_bottom+";\n";
                style_used.push_back(text);
            }
            if(*a=="cursor")
            {
                s.cursor = *b;
                string text = "cursor: "+s.cursor+";";
                style_used.push_back(text);
            }

              if(*a=="counter_reset")
            {
                s.cursor = *b;
                string text = "counter-reset: "+s.counter_reset+";\n";
                style_used.push_back(text);
            }


                if(*a=="counter_increment")
            {
                s.cursor = *b;
                string text = "counter-increment: "+s.counter_increment+";\n";
                style_used.push_back(text);
            }

                if(*a=="content")
            {
                s.cursor = *b;
                string text = "content: "+s.content+";\n";
                style_used.push_back(text);
            }

                if(*a=="column_width")
            {
                s.column_width = *b;
                string text = "counter-reset: "+s.column_width+";\n";
                style_used.push_back(text);
            }

               if(*a=="column_span")
            {
                s.column_width = *b;
                string text = "counter-span: "+s.column_span+";";
                style_used.push_back(text);
            }

               if(*a=="column_rule_width")
            {
                s.column_rule_width = *b;
                string text = "column-rule-width: "+s.column_rule_width+";";
                style_used.push_back(text);
            }
                if(*a=="column_rule_style")
            {
                s.column_rule_style = *b;
                string text = "column-rule-style: "+s.column_rule_style+";";
                style_used.push_back(text);
            }

                if(*a=="column_rule_color")
            {
                s.column_rule_color = *b;
                string text = "column-rule-color: "+s.column_rule_color+";";
                style_used.push_back(text);
            }

                if(*a=="font_weight")
            {
                s.font_weight = *b;
                string text = "font-weight: "+s.font_weight+";";
                style_used.push_back(text);
            }

                if(*a=="font_variant_position")
            {
                s.font_variant_position = *b;
                string text = "font-weight: "+s.font_variant_position+";";
                style_used.push_back(text);
            }
                if(*a=="font_variant_position")
            {
                s.font_variant_position = *b;
                string text = "font-variant-position: "+s.font_variant_position+";";
                style_used.push_back(text);
            }
                if(*a=="font_variant_numeric")
            {
                s.font_variant_numeric = *b;
                string text = "font-variant-numeric: "+s.font_variant_numeric+";";
                style_used.push_back(text);
            }
                if(*a=="font_variant_ligatures")
            {
                s.font_variant_ligatures = *b;
                string text = "font-variant-ligatures: "+s.font_variant_ligatures+";";
                style_used.push_back(text);
            }
                if(*a=="font_variant_east_asian")
            {
                s.font_variant_east_asian = *b;
                string text = "font-variant-east-asian: "+s.font_variant_east_asian+";";
                style_used.push_back(text);
            }
                if(*a=="font_variant_caps")
            {
                s.font_variant_caps = *b;
                string text = "font-variant-caps: "+s.font_variant_caps+";";
                style_used.push_back(text);
            }
                if(*a=="font_variant_alternates")
            {
                s.font_variant_alternates= *b;
                string text = "font-variant-alternates: "+s.font_variant_alternates+";";
                style_used.push_back(text);
            }
                if(*a=="font_variant")
            {
                s.font_variant = *b;
                string text = "font-variant: "+s.font_variant+";";
                style_used.push_back(text);
            }

                if(*a=="font_synthesis")
            {
                s.font_synthesis = *b;
                string text = "font-synthesis: "+s.font_synthesis+";";
                style_used.push_back(text);
            }
                if(*a=="font_style")
            {
                s.font_variant_numeric = *b;
                string text = "font-style: "+s.font_style+";";
                style_used.push_back(text);
            }

                   if(*a=="z_index")
            {
                s.z_index = *b;
                string text = "z-index: "+s.z_index+";";
                style_used.push_back(text);
            }

                   if(*a=="writing_mode")
            {
                s.writing_mode = *b;
                string text = "writing-mode: "+s.writing_mode+";";
                style_used.push_back(text);
            }
                    if(*a=="word_wrap")
            {
                s.word_wrap = *b;
                string text = "word-wrap: "+s.word_wrap+";";
                style_used.push_back(text);
            }

                    if(*a=="word_spacing")
            {
                s.word_spacing = *b;
                string text = "word-spacing: "+s.word_spacing+";";
                style_used.push_back(text);
            }
                    if(*a=="word_break")
            {
                s.word_break = *b;
                string text = "word-break: "+s.word_break+";";
                style_used.push_back(text);
            }

                    if(*a=="widows")
            {
                s.word_wrap = *b;
                string text = "widows: "+s.widows+";";
                style_used.push_back(text);
            }


                    if(*a=="white_space")
            {
                s.white_space = *b;
                string text = "white-space: "+s.white_space+";";
                style_used.push_back(text);
            }

                     if(*a=="unicode_bidi")
            {
                s.white_space = *b;
                string text = "unicode-bidi: "+s.unicode_bidi+";";
                style_used.push_back(text);
            }

                    if(*a=="user_select")
            {
                s.white_space = *b;
                string text = "user-select: "+s.user_select+";";
                style_used.push_back(text);
            }

                      if(*a=="vertical_align")
            {
                s.white_space = *b;
                string text = "vertical-align: "+s.vertical_align+";";
                style_used.push_back(text);
            }

                if(*a=="visibility")
            {
                s.visibility = *b;
                string text = "visibility: "+s.visibility+";";
                style_used.push_back(text);
            }

                 if(*a=="transition_timing_function")
            {
                s.transition_timing_function = *b;
                string text = "transition-timing-function: "+s.transition_timing_function+";";
                style_used.push_back(text);
            }

                 if(*a=="transition_property")
            {
                s.transition_property = *b;
                string text = "transition-property: "+s.transition_property+";";
                style_used.push_back(text);
            }

                   if(*a=="transition_duration")
            {
                s.transition_duration = *b;
                string text = "transition-duration: "+s.transition_duration+";";
                style_used.push_back(text);
            }
                   if(*a=="transition_delay")
            {
                s.transition_delay = *b;
                string text = "transition-delay: "+s.transition_delay+";";
                style_used.push_back(text);
            }

                if(*a=="transition")
            {
                s.transition = *b;
                string text = "transition: "+s.transition+";";
                style_used.push_back(text);
            }

                if(*a=="transform_style")
            {
                s.transform_style = *b;
                string text = "transform-style: "+s.transform_style+";";
                style_used.push_back(text);
            }

                 if(*a=="transform_origin")
            {
                s.transform_origin = *b;
                string text = "transform-origin: "+s.transform_origin+";";
                style_used.push_back(text);
            }

                if(*a=="top")
            {
                s.transform_origin = *b;
                string text = "top: "+s.top+";";
                style_used.push_back(text);
            }

                 if(*a=="text_underline_position" or *a=="tup")
            {
                s.transform_origin = *b;
                string text = "top: "+s.top+";";
                style_used.push_back(text);
            }
                 if(*a=="text_transform")
            {
                s.text_transform = *b;
                string text = "text-transform: "+s.text_transform+";";
                style_used.push_back(text);
            }

                    if(*a=="text_shadow")
            {
                s.text_shadow= *b;
                string text = "text-shadow: "+s.text_shadow+";";
                style_used.push_back(text);
            }

                    if(*a=="text_overflow")
            {
                s.text_overflow= *b;
                string text = "text-overflow: "+s.text_overflow+";";
                style_used.push_back(text);
            }

                    if(*a=="text_orientation")
            {
                s.text_orientation= *b;
                string text = "text-orientation: "+s.text_orientation+";";
                style_used.push_back(text);
            }

                    if(*a=="text_justify")
            {
                s.text_justify= *b;
                string text = "text-justify: "+s.text_justify+";";
                style_used.push_back(text);
            }
                    if(*a=="text_indent")
            {
                s.text_indent= *b;
                string text = "text-indent: "+s.text_indent+";";
                style_used.push_back(text);
            }

                    if(*a=="text_decoration_style")
            {
                s.text_decoration_style= *b;
                string text = "text-decoration-style: "+s.text_decoration_style+";";
                style_used.push_back(text);
            }

                if(*a=="text_decoration_line")
            {
                s.text_decoration_line= *b;
                string text = "text-decoration-line: "+s.text_decoration_line+";";
                style_used.push_back(text);
            }

                if(*a=="text_decoration_color")
            {
                s.text_decoration_color= *b;
                string text = "text-decoration-color: "+s.text_decoration_color+";";
                style_used.push_back(text);
            }

                if(*a=="text_decoration")
            {
                s.text_decoration= *b;
                string text = "text-decoration: "+s.text_decoration+";";
                style_used.push_back(text);
            }

                if(*a=="text_combine_upright")
            {
                s.text_combine_upright= *b;
                string text = "text-combine-upright: "+s.text_combine_upright+";";
                style_used.push_back(text);
            }

                if(*a=="text_align_last")
            {
                s.text_align_last= *b;
                string text = "text-align-last: "+s.text_align_last+";";
                style_used.push_back(text);
            }

                if(*a=="text_align")
            {
                s.text_align= *b;
                string text = "text-align: "+s.text_align+";";
                style_used.push_back(text);
            }

                if(*a=="table_layout")
            {
                s.table_layout= *b;
                string text = "table-layout: "+s.table_layout+";";
                style_used.push_back(text);
            }

                if(*a=="tab_size")
            {
                s.text_align= *b;
                string text = "tab-size: "+s.tab_size+";";
                style_used.push_back(text);
            }

                  if(*a=="scroll_behavior")
            {
                s.scroll_behavior= *b;
                string text = "scroll-behavior: "+s.scroll_behavior+";";
                style_used.push_back(text);
            }
                  if(*a=="right")
            {
                s.right= *b;
                string text = "right: "+s.right+";";
                style_used.push_back(text);
            }

                if(*a=="resize")
            {
                s._resize= *b;
                string text = "resize: "+s._resize+";";
                style_used.push_back(text);
            }

                if(*a=="page_break_after")
            {
                s.page_break_after= *b;
                string text = "page-break-after: "+s.page_break_after+";";
                style_used.push_back(text);
            }

                if(*a=="page_break_before")
            {
                s.page_break_before= *b;
                string text = "page-break-before: "+s.page_break_before+";";
                style_used.push_back(text);
            }

                   if(*a=="page_break_inside")
            {
                s.page_break_inside= *b;
                string text = "page-break-inside: "+s.page_break_inside+";";
                style_used.push_back(text);
            }

                   if(*a=="perspective_origin")
            {
                s.perspective_origin= *b;
                string text = "perspective-origin: "+s.perspective_origin+";";
                style_used.push_back(text);
            }
                   if(*a=="perspective")
            {
                s.perspective= *b;
                string text = "perspective: "+s.perspective+";";
                style_used.push_back(text);
            }

                if(*a=="pointer_events")
            {
                s.pointer_events= *b;
                string text = "pointer-events: "+s.pointer_events+";";
                style_used.push_back(text);
            }

                if(*a=="position")
            {
                s.position= *b;
                string text = "position: "+s.position+";";
                style_used.push_back(text);
            }

        }

        return s;
}

vector<string> raked_names;

class design{

private:

    map<string,string>sty;
    vector<pair<string,string>>get_sty;
    multimap<string,vector<pair<string,string>>>ss;
    vector<decltype(get_sty)>save_methodology;

public:


    design()
    {
        //cout << "DESIGN CONSTRUCTOR "<<endl;
    }
    void dispose_methodology(vector<pair<string,string>>d)
    {
        save_methodology.push_back(d);

    }
    void dispose_methodology(multimap<string,vector<pair<string,string>>>d)
    {

        ss =d;
    }


     void make_external(multimap<string,vector<pair<string,string>>>p)
    {
        ss = p;

        multimap<string,vector<pair<string,string>>>::iterator it;
        vector<pair<string,string>>::iterator vp;

        list<string>prop;
        list<string>val;

        string key;

        string structural_name;

        for(it =p.begin(); it!=p.end(); it++)
        {
            key = it->first;

            for(vp=(it->second).begin();vp!= (it->second).end();vp++)
            {
                if(vp->first=="class"|| vp->first=="c")
                {
                    structural_name = vp->second;
                    break;

                }

                else{

                    prop.insert(prop.begin(),vp->first);
                    val.insert(val.begin(),vp->second);

                }

            }
        }


        construct_attributes(prop,val);

        stylesheet_external(structural_name);

    }


        void make_external(vector<pair<string,string>>g)
    {

        get_sty=g;

        list<string> prop;
        list<string> val;

        string structural_name;

        for(auto &r : get_sty)
        {

            sty.insert(r);

        }

            for(auto &f:sty)
        {
            if(f.first=="class" || f.first=="c")
            {
                structural_name = f.second;
                break;
            }

        }
        list<string>::iterator it;
        for(auto&f:sty)
        {


            {
                prop.insert(prop.begin(),f.first);

                val.insert(val.begin(),f.second);

            }


        }

            construct_attributes(prop,val);

            stylesheet_external(structural_name);

    }

void rake_structural_tree()
    {

        vector<string>::iterator ip;


        for(auto &t : save_methodology)
        {
            for (auto&v :t)
            {
                if(v.first =="class" ||v.first=="c")
                {

                raked_names.push_back(v.second);


                }


            }
        }

     /*   ip = std::unique(raked_names.begin(),raked_names.begin()+raked_names.size());

        raked_names.resize(std::distance(raked_names.begin(),ip));


        for (ip = raked_names.begin(); ip != raked_names.end(); ip++)
            cout << "raked names: "<< *ip <<endl;

     */

    }


    string make_inline(multimap<string,vector<pair<string,string>>>p)
    {
        multimap<string,vector<pair<string,string>>>::iterator it;
        vector<pair<string,string>>::iterator vp;

        string _start,total="";

        string key;

        for(it =p.begin(); it!=p.end(); it++)
        {
            key = it->first;

            for(vp=(it->second).begin();vp!= (it->second).end();vp++)
            {
                 _start =vp->first +": "+vp->second +";";

                 total+=_start;


            }
        }

        string construct = key+"= "+quote+total+quote;

        //style_used.push_back(construct);

        return construct;

    }

    string make_inline(vector<pair<string,string>>g)
    {
        get_sty=g;

            string _sty,total ="";

        for(auto &r : get_sty)
        {

            sty.insert(r);

        }

            for(auto &f:sty)
        {
            _sty = f.first +" : "+f.second;

            total+=_sty;

        }

        string construct = quote+total+quote;


        return construct;

    }

    template<typename u,typename... args>
    design(pair<string,u> w, pair<string,args>... p)
    {
        sty.insert(w,(p)...);

    }
        template<typename u,typename... args>
        design(pair<const char*,u> w, pair<const char*,args>... p)
    {
        sty.insert(w,(p)...);

    }

    string* get_design_value(string&& attr)
    {
     return &sty[attr];
    }

};

string sty;

namespace arivs{

    using style_property = list<string>;
    using style_value = list<string>;
    style null;
    uintmax_t zero = 0;

    vector<pair<string,string>> attribute;
    multimap<string,vector<pair<string,string>>>composition;

    multimap<string,vector<pair<string,string>>>composition_a;
    multimap<string,vector<pair<string,string>>>composition_b;

    multimap<string,vector<pair<string,string>>>nothing;

    string gt= ">";
    string lt= ">";
    string gte =">=";
    string lte ="<=";

    string descendant_selector = " ";
    string child_selector = ">";
    string adjacent_slibing_selector = "+";
    string general_slibing_selector ="~";

    string internal_style="internal";
    string external_style="external";
    string inline_style="inline";

    string internal_stylesheet_manipulator;
    string main_body_manipulator;

};

using i = pair<string,string>;

auto as_tuple(decltype(arivs::composition) a,decltype(arivs::composition) b,string style_type="")
{
    return make_tuple(a,b,style_type);

}

auto empty_lambda = [](){return as_tuple(arivs::nothing,arivs::nothing);};

void conceptual_methodology(list<string>&properties,list<string>&values)
{

    construct_attributes(properties,values);

}

map<string,string> structural_tree;

void composition_a();
void composition_b();


//template<string(*F)(string,T&&...)>

//struct ariv{};

int main()
{


    link_css("text/css", "ads.css","stylesheet", "");

    set_file("html_demo.html","css_demo.css");

    string list_type = _list({"Home","About","Contact"},"ul");

    arivs::main_body_manipulator =   body(

                                    generic("div",[](){

                                       blueprint_a(i("class","overall"),i("align","center"));

                                       blueprint_b(i("w","auto"),i("h","700px"),i("clr","white"),i("bg_img","url("+quote+"ryan.jpg"+quote+")"));

                                       return as_tuple(arivs::composition_a,arivs::composition_b,arivs::internal_style);

                                       },
                                        generic("nav",[](){

                                               blueprint_a(i("class","swet"),i("align","center"));

                                               blueprint_b(i("lst","none"),i("font_size","32px"));

                                               return as_tuple(arivs::composition_a,arivs::composition_b,arivs::internal_style);

                                               },list_type)
                                                              )
                                         ,

                                       generic("div",[](){

                                               blueprint_a(i("class","extraordinary"),i("align","center"));

                                               blueprint_b(i("w","auto"),i("h","50px"),i("text","center"),i("font_size","32px"),i("bg_clr","black"),i("color","white"),i("vertical_align","center"));

                                               return as_tuple(arivs::composition_a,arivs::composition_b,arivs::internal_style);

                                               },"FOOTER")

                                               , generic("oldtown",empty_lambda,"something")




    );

    //ariv<body>t;

    read_to_html_at_once({arivs::main_body_manipulator,arivs::internal_stylesheet_manipulator});


}


auto lambda_expression_manipulator(lambda p)
{

    auto first_multimap = get<0>(p());
    auto second_multimap = get<1>(p());
    auto third_param = get<2>(p());

    string labels,l_cummulative="";
    string stylings,s_cummulative="";
    string construct,referal="";
    string class_name;
    string style_type;

    string sty;

    multimap<string,vector<pair<string,string>>>::iterator fm;
    vector<pair<string,string>>::iterator vm;

    multimap<string,vector<pair<string,string>>>::iterator sm;
    vector<pair<string,string>>::iterator pv;

    list<string>temp1,temp2;

    for(auto st = style_used.begin(); st!=style_used.end(); st++)
    {
        sty += *st;

    }

    vector<pair<string,string>>h;

    for(fm = first_multimap.begin();fm!= first_multimap.end();fm++)
    {

        h = fm->second;



       // cout << "fm->second->second: "<< (fm->second)[0].second <<endl;

        //h.insert(h.end(),(fm->second).begin(),(fm->second).end());

        //cout << "hsecond: "<< h[0].second <<endl;

    }


    for(vm=(h).begin(); vm!=(h).end();vm++)
        {

            if (vm->first=="class")
            {
                class_name = vm->second;

                div_details.insert(pair<string,string>(vm->second,vm->first));

                //cout << "vm-><>>>>second: "<< vm->second <<endl;

                //break;

            }

        }

    //vector<pair<string,string>>::iterator ih;
    //ih = unique(h.begin(),h.begin()+h.size());
    //h.resize(distance(h.begin(),ih));

            for(vm=(h).begin(); vm!=(h).end();vm++)
        {

            cout << "vm->firstlskdsd: "<< vm->first << endl;

            labels+=(vm->first+"="+quote+vm->second+quote);

        }

        l_cummulative=labels;


    vector<pair<string,string>>k;

    for(sm = second_multimap.begin();sm!= second_multimap.end();sm++)
    {
        referal = sm->first;

        k = (sm->second);

        break;

    }

         for(pv=(k).begin(); pv!=(k).end();pv++)
        {
         //   cout << "pv->second: "<< pv->second <<endl;

            {
                temp1.insert(temp1.end(),pv->first);

                temp2.insert(temp2.end(),pv->second);

            }


            /* if(pv->first!="id")
            {
                temp1.insert(temp1.begin(),pv->first);
                temp2.insert(temp2.begin(),pv->second);
                construct_attributes(temp1,temp2);

                //stylings = pv->first+": "+pv->second+";";
                s_cummulative+=sty;
                break;

            }

            */


    }

               construct_attributes(temp1,temp2);

                //cout << "sty: "<<sty<<endl;

             s_cummulative+=sty;

             style_type = third_param;


    return make_tuple(construct,referal,s_cummulative,l_cummulative,class_name,style_type);
}


void automatic_nest_matcher(string main_name)
{
  bool b;

 string actual_sub_name;

       for(auto i =raked_names.begin();i!=raked_names.end(); i++)
        {
            if (*i != main_name)
            {

                // b = boost::algorithm::contains(store_created_tags,*i);
                 actual_sub_name = *i;
                 cout << "actual sub name : "<< actual_sub_name <<endl;
            }

              if (b==true)
                {
                    structural_tree.insert(pair<string,string>(main_name,actual_sub_name));

                    break;
                }
        }
}

template<typename... T>
auto expression_pack_manipulator(T&&... exp)
{
    auto get_value = {exp...};
    string store_value;
    for(auto t : get_value)
        {
            store_value+=t;
        }
        return store_value;
}

auto assert_mode_of_styling(string sty_typ, string name)
{

    if(sty_typ =="internal")
    {
          arivs::internal_stylesheet_manipulator += stylings(

       stylesheet_internal(name),""

                );

    }
    if(sty_typ=="external")
    {
        stylesheet_external(name);

    }

}

auto initializer_list_manipulator(initializer_list<string> inserted_text)
{
    string txt;

    for(auto i=inserted_text.begin(); i!=inserted_text.end();i++)
    {
        txt += *i;

    }
    return txt;
}

template<typename T, typename... Args>
void blueprint_a(T&& arg,Args&&...optional)
{

    arivs::attribute.push_back(pair<string,string>(arg));
    blueprint_a(optional...);
    composition_a();

}

template<typename T, typename... Args>
void blueprint_b(T&& arg,Args&&...optional)
{

    arivs::attribute.push_back(pair<string,string>(arg));
    blueprint_b(optional...);
    composition_b();

}

string load_image(string img,string alt_value, string title, string identity,string usemap)
{

    string load_image = "<img src ="+quote+img+quote +" alt="+quote + alt_value+quote+"title=" +quote+title+quote+ " id=" +quote+identity+quote+ " usemap=" +quote +usemap+quote+">";

    html_code_list.push_back(load_image);

    return load_image;

}
string stylesheet_internal(string div_name)
{
    string stylesheet;

    map<string,string>::iterator it;

    string styl;


    for(auto sty:style_used)
    {
        styl+=sty;

    }

      for( it = div_details.begin(); it !=div_details.end();it++)
    {

        if(div_name==it->first)
        {


        if (div_name == it->first and it->second == "class")
        {

            cout << it->first <<"and" << it->second<<endl;

            stylesheet = "."+div_name+"{\n"+ styl+";\n}";

        }

        else if (div_name == it->first and it->second == "id")
        {
            stylesheet = "#"+div_name+"{\n"+ styl+";\n}";

        }

        }

    }

        style_used.clear();
    arivs::attribute.clear();
    arivs::composition_a.clear();
    arivs::composition_b.clear();

        return stylesheet;

}
string stylesheet_external(string div_name)
{

    string stylesheet;

    map<string,string>::iterator it;

    string styl;

    for(auto sty:style_used)
    {

        styl+=sty;

    }
       // stylesheet = "."+div_name+"{\n"+ styl+";\n}";

    bool is_class_available;
    bool is_id_available;

    for( it = div_details.begin(); it !=div_details.end();it++)
    {

        if(div_name==it->first)
        {
            if(it->second=="class")
            {
                is_class_available=true;
            }
            else{
                is_class_available=false;
            }

        }
               if(div_name==it->first)
        {
            if(it->second=="id")
            {
                is_id_available=true;
            }
            else{
                is_id_available=false;
            }

        }
    }


        if (is_class_available==true)
        {

            stylesheet = "."+div_name+"{\n"+ styl+";\n}";

        }

        if (is_id_available==true)
        {
            stylesheet = "#"+div_name+"{\n"+ styl+";\n}";

        }

        css_code_list_external.push_back(stylesheet);


    style_used.clear();

    arivs::attribute.clear();
    arivs::composition_a.clear();
    arivs::composition_b.clear();

        return stylesheet;

    }


    string stylesheet_external(string div_name,string selector)
{
    automatic_nest_matcher(div_name);

    string stylesheet;

    map<string,string>::iterator it;

    string styl;

    string get_key;

    string construct;
    string first;
    string second;

    for(auto r : structural_tree)
    {

        if(div_name==r.first)
            {
             get_key = r.second;
             break;
            }

    }



    for(auto sty:style_used)
    {
        styl+=sty;
    }


    for( it = div_details.begin(); it !=div_details.end();it++)
{
    if(div_name==it->first)
    {
        if (it->second == "class")
            {
                first = "."+div_name;
            }
    }
}
for( it = div_details.begin(); it !=div_details.end();it++)
{
    if (get_key==it->first)
    {
        cout << "is in"<<endl;
        if(it->second=="class")
        {
            second="."+get_key+selector;
        }
    }

}

    construct = second+first;

    stylesheet = construct+"{\n"+ styl+";\n}";

    css_code_list_external.push_back(stylesheet);

    style_used.clear();

    structural_tree.clear();

     arivs::attribute.clear();
    arivs::composition_a.clear();
    arivs::composition_b.clear();

    return stylesheet;

}
    string stylesheet_external(string selector,string a,string b)
{
    string get_key;
    string get_key_structure;
    string value;
    string value_structure;
    string first_construct;
    string second_construct;
    string construct;
    string stylesheet;

    string styl;


    for(auto i : one_to_many)
    {
        for(auto k = div_details.begin();k!=div_details.end();k++)
        {
            if(k->first == i.second)
            {
                value = i.second;
                get_key=i.first;
                value_structure=k->second;
            }
        }

    }

    for(auto k = div_details.begin();k!=div_details.end();k++)
        {
            if(get_key==k->first)
            {
                get_key_structure=k->second;
            }
        }

        if(get_key_structure=="class")
        {
            first_construct= "."+get_key+selector;
        }

        if(value_structure=="class")
        {
            second_construct ="."+value;
        }
    construct = first_construct+second_construct;

    for(auto sty:style_used)
    {
        styl+=sty;
    }


    stylesheet = construct+"{\n"+ styl+";\n}";

    css_code_list_external.push_back(stylesheet);

    style_used.clear();

    one_to_many.clear();

     arivs::attribute.clear();
    arivs::composition_a.clear();
    arivs::composition_b.clear();


    return stylesheet;

}


string link_css(string type, string href, string rel, string media)
{
    string link = "<link type="+quote+type+quote+ "href="+ quote+href +quote+"rel="+ quote+rel+quote+"media="+quote+media+quote+"/>";

    html_code_list.push_back(link);

    return link;

}
void read_to_file(string read)
{

	html_object << read <<endl;

}

template<typename... T>
inline string body(string text , T&&... args)
{

    auto other_text = expression_pack_manipulator(args...);

    string _start = "<body> "+text+other_text+"</body>";

    return _start;

}

inline string h_text(int h_level, string text)
{
        string h;
        h = "<h"+ to_string(h_level)+">" +text +"</h"+to_string(h_level)+">";
        return h;

}

inline string h_text(int h_level,lambda r, string text)
{
     auto value = lambda_expression_manipulator(r);

     assert_mode_of_styling(get<5>(value),get<4>(value));

     get<0>(value) = get<1>(value)+quote+get<2>(value)+quote;

     string h;

     h = "<h"+ to_string(h_level)+" "+ get<3>(value)+get<0>(value)+">" +text +"</h"+to_string(h_level)+">";

     return h;

}

template<typename... T>
inline string h_text(int h_level,lambda r, string text,T&&... args )
{
     auto value = lambda_expression_manipulator(r);

     assert_mode_of_styling(get<5>(value),get<4>(value));

     get<0>(value) = get<1>(value)+quote+get<2>(value)+quote;

     auto other_text = expression_pack_manipulator(args...);

     string h;

     h = "<h"+ to_string(h_level)+" "+ get<3>(value)+get<0>(value)+">" +text+other_text +"</h"+to_string(h_level)+">";

     return h;

}

inline string _list( list<string> ls, string specify)
{

    list<string>::iterator it;

    vector<string>::iterator all;

    string _start;
    string total;

    for(all=all_existing_tags_in_html.begin(); all!=all_existing_tags_in_html.end(); all++)
    {

        if (specify==*all)
        {

        _start = "<"+specify+">";

        for(it = ls.begin(); it!= ls.end();it++)
        {

            _start = "<li>"+string(*it)+ "</li>";
            total +=_start;

            //html_code_list.push_back(_start);


        }
        _start = "</"+specify+">";
        total+=_start;

        }


        else if(specify=="")
        {

            for(it = ls.begin(); it!= ls.end();it++)
        {

            string _start = "<li>"+string(*it)+ "</li>";
            total+=_start;
           // html_code_list.push_back(_start);

        }

        }

    }

    return total;
}

template<typename... T>
inline string stylings(string text,T&&... args)
{
    auto other_text = expression_pack_manipulator(args...);
    string _start = "<style> "+text + other_text +"</style>";
    return _start;

}

inline string area(string shape , coords &c, string href,  string alt)
{
    string area = "<area shape=" +quote + shape +quote +" coords=" + quote+to_string(c.x) +"," +to_string(c.y)+"," +to_string(c.z)+"," +to_string(c.w) +quote +" href="+quote +href+quote + " alt=" +quote +alt +quote +">";
    html_code_list.push_back(area);
    return area;

}

template<typename... T>
inline string script(string text, T&&...args)
{
    auto other_text = expression_pack_manipulator(args...);

    string _start = "<script>"+text+other_text+"</script>";
    //html_code_list.push_back(_start);
    return _start;

}

string rgb(int red, int green, int blue)
{
    string rgb_color = "rgb("+to_string(red)+"," +to_string(green) + ","+ to_string(blue) +");";
    return rgb_color;

}
string rgba(int red, int green, int blue, int alpha)
{

    string rgb_color = "rgb("+to_string(red)+"," +to_string(green) + ","+ to_string(blue) +","+ to_string(alpha)+");";
    return rgb_color;

}

string hsl(int hue,int saturation, int lightness)
{
    string hsl_color = "hsl(" + to_string(hue) +"," +to_string(saturation) + "%," + to_string(lightness) +"%);";
    return hsl_color;
}

inline string p_text(int p_level, string text)
{
    string p = "<p"+to_string(p_level) +">" +text+"</p"+ to_string(p_level)+">";
   // html_code_list.push_back(p);
    return p;

}

inline string p_text(int p_level,lambda r, string text )
{
     auto value = lambda_expression_manipulator(r);

     assert_mode_of_styling(get<5>(value),get<4>(value));

     get<0>(value) = get<1>(value)+quote+get<2>(value)+quote;

     string h;

     h = "<p"+ to_string(p_level)+" "+ get<3>(value)+get<0>(value)+">" +text+"</p"+to_string(p_level)+">";

     return h;

}

template<typename... T>
inline string p_text(int p_level,lambda r, string text,T&&... args )
{
     auto value = lambda_expression_manipulator(r);

     assert_mode_of_styling(get<5>(value),get<4>(value));

     get<0>(value) = get<1>(value)+quote+get<2>(value)+quote;

     auto other_text = expression_pack_manipulator(args...);

     string h;

     h = "<p"+ to_string(p_level)+" "+ get<3>(value)+get<0>(value)+">" +text+other_text +"</p"+to_string(p_level)+">";

     return h;

}


void read_to_css_file(string item)
{
    css_object << item <<endl;
}

int get_file_size(string filename)
{
    FILE *p_file = NULL;
    p_file = fopen(filename.c_str(),"rb");
    fseek(p_file,0,SEEK_END);
    int size = ftell(p_file);
    fclose(p_file);
    return size;
}


// call this function at the end of the script in the main function
void read_to_html_at_once(vector<string> args)
{

 //auto get_body = []()-> decltype(body)(string,auto&&...){return body;};

 //cout << "body type : "<< decltype(get_body) <<endl;

 //void (*b)(string,auto&&...) = &body;

 //cout <<



    string get_text;

    for(auto i = args.begin();i!=args.end(); i++)
    {
         get_text+=*i;
    }
   // html_code_list.push_back(foo);
    html_code_list.push_back(get_text);

    //default settings for html and doctype
    html_object <<"<!DOCTYPE html>\n";
    html_object << "<html>\n";

               for(auto i = html_code_list.begin(); i !=html_code_list.end() ; i++)
                {

                    html_object << *i <<endl;

                }

    html_object <<"</html>\n";

    read_to_css_at_once();

    }

void read_to_css_at_once()
{

     for(auto i = css_code_list_external.begin(); i !=css_code_list_external.end() ; i++)
    {

        css_object << *i <<endl;
    }

}

inline void set_file(string &&html_file_name,string &&css_file_name)

{

    cout << "---ARIVS C++ WEB FRAMEWORK---\n\n";
    //RESET FILE EVERY RERUN
    ghc::filesystem::resize_file(html_file_name.c_str(),arivs::zero);
    ghc::filesystem::resize_file(css_file_name.c_str(),arivs::zero);


    html_object.open(html_file_name);
    if (html_object.is_open())
        cout << "HTML FILE IS OPEN FOR READING\n";

    css_object.open(css_file_name);
    if(css_object.is_open())
        cout << "CSS FILE IS OPEN FOR READING\n";


    file_names.push_back(html_file_name);
    file_names.push_back(css_file_name);


}
string get_file_names(const string &key)
{
    vector<string>::iterator it;

    string value;
    for(it = file_names.begin(); it!=file_names.end();it++)
    {


        if (key == *it)
        {

            value = *it;

        }

        else{
            cout <<"file does not exist/n";
        }
    }

    return value;

}


template<typename ...T>
string generic(string type, lambda h,string text,T&&... args)
{

    auto value = lambda_expression_manipulator(h);

     cout << "class name : "<< get<4>(value) <<endl;

    auto other_text = expression_pack_manipulator(args...);

    if (get<5>(value)!="inline")
    {

        assert_mode_of_styling(get<5>(value),get<4>(value));

    }

    get<0>(value) = get<1>(value)+quote+get<2>(value)+quote;

    string all;

    for(auto r : all_existing_tags_in_html)
    {
        all += r;
    }

    if(type!="" and boost::algorithm::contains(all, type))
        {
        string create = "<"+type+" "+get<3>(value)+get<0>(value)+">"+text+other_text+"</"+type+">";
        return create;
        }

    else{
            cout<< "----ERROR: " << type << " is not a valid HTML TAG" <<endl;

        return "";
        }

    if(get<5>(value)=="inline")
    {

        arivs::attribute.clear();
        arivs::composition_a.clear();
        arivs::composition_b.clear();

    }
}

string generic(string type, lambda h,string text)
{

    auto value = lambda_expression_manipulator(h);

    cout << "class name : "<< get<4>(value) <<endl;

    if (get<5>(value)!="inline")
    {

        assert_mode_of_styling(get<5>(value),get<4>(value));

    }

    get<0>(value) = get<1>(value)+quote+get<2>(value)+quote;

    string all;

    for(auto r : all_existing_tags_in_html)
    {
        all += r;
    }

    if(type!="" and boost::algorithm::contains(all, type))
        {
        string create = "<"+type+" "+get<3>(value)+get<0>(value)+">"+text+"</"+type+">";
        return create;
        }

    else{
            cout<< "----ERROR: " << type << " is not a valid HTML TAG" <<endl;
        return "";
        }

    if(get<5>(value)=="inline")
    {

        arivs::attribute.clear();
        arivs::composition_a.clear();
        arivs::composition_b.clear();

    }

}

string generic(string type,string text)
{

    string all;

    for(auto r : all_existing_tags_in_html)
    {
        all += r;
    }

    if(type!="" and boost::algorithm::contains(all, type))
        {
        string create = "<"+type+">"+text+"</"+type+">";
        return create;
        }

    else{
            cout<< "----ERROR: " << type << " is not a valid HTML TAG" <<endl;
        return "";
        }

}

template<typename... T>
string generic(string type,string text,T&&...args)
{
    auto other_text = expression_pack_manipulator(args...);

    string all;

    for(auto r : all_existing_tags_in_html)
    {
        all += r;
    }

    if(type!="" and boost::algorithm::contains(all, type))
        {
        string create = "<"+type+">"+text+other_text+"</"+type+">";
        return create;
        }

    else{
            cout<< "----ERROR: " << type << " is not a valid HTML TAG" <<endl;
        return "";
        }

}


string generic(string type)
{

    string all;

    for(auto r : all_existing_tags_in_html)
    {
        all += r;
    }

    if(type!="" and boost::algorithm::contains(all, type))
        {
        string create = "<"+type+">";
        return create;
        }

    else{
            cout<< "----ERROR: " << type << " is not a valid HTML TAG" <<endl;
        return "";
        }

}


void composition_a()
{

    arivs::composition_a.insert(pair<string,decltype(arivs::attribute)>("",arivs::attribute));
}

void composition_b()
{
arivs::composition_b.insert(pair<string,decltype(arivs::attribute)>("style=",arivs::attribute));
}
