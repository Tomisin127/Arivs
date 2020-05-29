#ifndef FUNCTION_DEFINE_H
#define FUNCTION_DEFINE_H

type_tuple lambda_expression_manipulator(lambda p,generic* val)
{
    lambda local = p;

    auto first_multimap = get<0>(local());
    auto second_multimap = get<1>(local());
    auto third_param = get<2>(local());

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

    vector<pair<string,string>>h;

    for(fm = first_multimap.begin();fm!= first_multimap.end();fm++)
    {

        h = fm->second;

    }

    string all;

    for(auto n : all_existing_tags_in_html)
    {
        all+=n;

    }


    for(vm=(h).begin(); vm!=(h).end();vm++)
        {

            if (vm->first=="class")
            {
                class_name = vm->second;

                details.insert(pair<string,string>(vm->second,vm->first));

                (val->all_classes).push_back(class_name);

            }

            else if(vm->first=="id")
            {
                class_name = vm->second;

                details.insert(pair<string,string>(vm->second,vm->first));

                (val->all_id).push_back(class_name);
            }

            else if(boost::algorithm::contains(all,vm->first))
            {

                class_name = vm->second;

                details.insert(pair<string,string>(vm->second,vm->first));

            }
            else
            {
                break;
            }

        }

            for(vm=(h).begin(); vm!=(h).end();vm++)
        {

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

            {
                temp1.insert(temp1.end(),pv->first);

                temp2.insert(temp2.end(),pv->second);

            }

        }

            construct_attributes(temp1,temp2,val);

            for(auto st = (val->style_used).begin(); st!=(val->style_used).end(); st++)
            {
                sty += *st;
            }

             s_cummulative+=sty;

             style_type = third_param;

        if (style_type=="inline")
            {
                (val->style_used).clear();
            }

    arivs::attribute.clear();
    arivs::composition_a.clear();
    arivs::composition_b.clear();


    return make_tuple(construct,referal,s_cummulative,l_cummulative,class_name,style_type);
}

void assert_mode_of_styling(string sty_typ, string name,generic *invoke,string type_name)
{

    if(sty_typ =="internal")
    {
          arivs::internal_stylesheet_manipulator += stylings(

       stylesheet_internal(name,invoke,type_name)

                );

    }
    if(sty_typ=="external")
    {
        stylesheet_external(name,invoke,type_name);

    }

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

  //  html_code_list.push_back(load_image);

    return load_image;

}
string stylesheet_internal(string div_name,generic *k,string type_name)
{
    string stylesheet;

    map<string,string>::iterator it;

    string styl;

    string pos = k->calculate_position();

    string all;

    for(auto sty:(k->style_used))
    {
        styl+=sty;

    }

    for(auto n: all_existing_tags_in_html)
    {
        all+=n;
    }

      for( it = details.begin(); it !=details.end();it++)
    {

        if(div_name==it->first)
        {
            {
                stylesheet = pos+"{\n"+ styl+";\n}";
            }
        }

    }

    if(div_name=="")
        {
            cout << "\n\n---WARNING: class or id not specified\n using '"<<type_name<< "' as structure identifier!!" <<endl;
            stylesheet =type_name+"{\n"+ styl+";\n}";
        }

    (k->style_used).clear();

    arivs::attribute.clear();
    arivs::composition_a.clear();
    arivs::composition_b.clear();

    return stylesheet;

}
string stylesheet_external(string div_name,generic *k,string type_name)
{

    string stylesheet;

    map<string,string>::iterator it;

    string styl;

    string pos = k->calculate_position();

    cout << "pos: "<< pos <<endl;

    string all;

    for(auto n : all_existing_tags_in_html)
    {
        all+= n;
    }

    for(auto sty:(k->style_used))
    {

        styl+=sty;

    }

    for( it = details.begin(); it !=details.end();it++)
    {

        if(div_name==it->first)
        {

            stylesheet = pos+"{\n"+ styl+";\n}";

        }

    }


        if(div_name =="")
        {

             stylesheet =pos+"{\n"+ styl+";\n}";

             cout << "\n\n---WARNING: class or id not specified\n using '"<<type_name<< "' as structure identifier!!" <<endl;

        }

    css_code_list_external.push_back(stylesheet);


    (k->style_used).clear();

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

inline string body(string text)
{

    string _start = "<body> "+text+"</body>";

    arivs::main_body_manipulator = _start;

    return _start;

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

            }

        }

    }

    return total;
}
inline string stylings(string text)
{

    string _start = "<style> "+text+"</style>";
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
void read_to_html_at_once()
{
   // style_the_objects();

    body(total_text.str());

    html_code_list.push_back(arivs::main_body_manipulator);

    html_code_list.push_back(arivs::internal_stylesheet_manipulator);

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
        cout << "HTML FILE '"<< html_file_name <<"' IS OPEN FOR READING\n";

    css_object.open(css_file_name);
    if(css_object.is_open())
        cout << "CSS FILE '"<<css_file_name <<"' IS OPEN FOR READING\n\n";


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

void composition_a()
{
    arivs::composition_a.insert(pair<string,decltype(arivs::attribute)>("",arivs::attribute));
}

void composition_b()
{
arivs::composition_b.insert(pair<string,decltype(arivs::attribute)>("style=",arivs::attribute));
}

#endif
