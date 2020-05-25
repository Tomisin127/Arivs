#ifndef FUNCTION_PROTOTYPE_H
#define FUNCTION_PROTOTYPE_H

template<typename... Args>
void blueprint_a(Args&&... args){}

template<typename T, typename... Args>
void blueprint_a(T&& arg,Args&&...optional);

template<typename... Args>
void blueprint_b(Args&&... args){}

template<typename T, typename... Args>
void blueprint_b(T&& arg,Args&&...optional);

inline string body(string text);

template<typename... T>
inline string stylings(string text,T&&... args);

inline string _list(list<string> ls,string specify);

inline string area(string shape , coords &c, string href, string alt);

template<typename... T>
inline string script(string text,T&&... args);

using type_tuple = tuple<string,string,string,string,string,string>;
class generic;
type_tuple lambda_expression_manipulator(lambda p,generic* val);

void automatic_nest_matcher(string main_name);

auto initializer_list_manipulator(initializer_list<string> inserted_text);

void assert_mode_of_styling(string sty_typ, string name,string position,generic *invoke, string type_name="");

template<typename... T>
auto expression_pack_manipulator(T&&... exp);

inline string rgb(int red, int green, int blue);
inline string hsl(int hue,int saturation, int lightness);
inline string rgba(int red, int green, int blue, int alpha);

//inline string h_text(int h_level,string text);

//inline string h_text(int h_level,lambda r, string text);

//template<typename... T>
//inline string h_text(int h_level,lambda r, string text,T&&... args );

//inline string p_text(int p_level,string text);

//inline string p_text(int p_level,lambda r, string text);

//template<typename... T>
//inline string p_text(int p_level,lambda r, string text,T&&... args );

string load_image(string img,string alt_value, string title, string identity, string usemap);

string link_css(string type, string href, string rel, string media);

string stylesheet_internal(string div_name,string pos,generic *k,string type_name="");

string stylesheet_external(string div_name,string pos,generic *k,string type_name="");
//string stylesheet_external(string div_name,string selector);
//string stylesheet_external(string selector,string a,string b);

void read_to_file(string read);
void read_to_css_file(string item);
void read_to_html_at_once();
void read_to_css_at_once();

vector<string> html_code_list;
vector<string> css_code_list_external;

map<string,string>details;
vector<string> file_names;

style s;

map<string,string> one_to_many;

inline void set_file(string &&html_file_name,string &&css_file_name);
string get_file_names(const string &key);

string all_style;


class generic;
vector<generic*>all_objects;

// THIS CLASS WAS WRITTEN BY ATMA

stringstream total_text;

#endif
