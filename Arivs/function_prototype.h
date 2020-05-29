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

inline string stylings(string text);

inline string _list(list<string> ls,string specify);

inline string area(string shape , coords &c, string href, string alt);

template<typename... T>
inline string script(string text,T&&... args);

using type_tuple = tuple<string,string,string,string,string,string>;

class generic;

type_tuple lambda_expression_manipulator(lambda p,generic* val);

void assert_mode_of_styling(string sty_typ, string name,generic *invoke, string type_name="");

inline string rgb(int red, int green, int blue);
inline string hsl(int hue,int saturation, int lightness);
inline string rgba(int red, int green, int blue, int alpha);

string load_image(string img,string alt_value, string title, string identity, string usemap);

string link_css(string type, string href, string rel, string media);

string stylesheet_internal(string div_name,generic *k,string type_name="");

string stylesheet_external(string div_name,generic *k,string type_name="");

void read_to_file(string read);
void read_to_css_file(string item);
void read_to_html_at_once();
void read_to_css_at_once();

vector<string> html_code_list;
vector<string> css_code_list_external;

map<string,string>details;
vector<string> file_names;

style s;

inline void set_file(string &&html_file_name,string &&css_file_name);
string get_file_names(const string &key);

string all_style;

class generic;
vector<generic*>all_objects;

stringstream total_text;

#endif
