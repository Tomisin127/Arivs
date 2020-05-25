#ifndef THE_CLASSES_H
#define THE_CLASSES_H

class generic{
private:
    string txt;

public:

    string mode_of_styling;
    string name_of_tag;
    string type_of_tag;

    vector<generic*>children;

    generic *parent = NULL;

    string output;

    string type_t;

    string inline_attributes;

    vector<string> style_used;

 generic(string type, lambda h,string text)
{

    type_t = type;

    type_tuple value = lambda_expression_manipulator(h,this);

    string all;

    for(auto r : all_existing_tags_in_html)
    {
        all += r;
    }

    if(type!="" and boost::algorithm::contains(all, type))
        {
            txt = text;
        }

    else{
            cout<< "----ERROR: " << type << " is not a valid HTML TAG" <<endl;
            //return "";
        }

    mode_of_styling = get<5>(value);

    name_of_tag = get<4>(value);

    type_of_tag = type;


    get<0>(value) = get<1>(value)+quote+get<2>(value)+quote;

    inline_attributes = get<3>(value)+get<0>(value);

    if(get<5>(value)=="inline")
    {

        arivs::attribute.clear();
        arivs::composition_a.clear();
        arivs::composition_b.clear();

    }

    all_objects.push_back(this);
}

generic(string type,string text)
{

    string type_t = type;

    string all;

    for(auto r : all_existing_tags_in_html)
    {
        all += r;
    }

    if(type!="" and boost::algorithm::contains(all, type))
        {
        txt = text;
        }

    else{
            cout<< "----ERROR: " << type << " is not a valid HTML TAG" <<endl;
       // return "";
        }

        all_objects.push_back(this);

}

generic(string type)
{
    type_t = type;

    string all;

    for(auto r : all_existing_tags_in_html)
    {
        all += r;
    }

    if(type!="" and boost::algorithm::contains(all, type))
        {
        txt = type;
        }

    else{
            cout<< "----ERROR: " << type << " is not a valid HTML TAG" <<endl;
        //return "";
      }

        all_objects.push_back(this);

}


    void add_element(generic& element)
    {
        element.make_parent(this);
        children.push_back((generic*)&element);

    }


    template<typename... T>
    void add_element(generic& element, T&...args)
    {
        element.make_parent(this);
        children.push_back((generic*)&element);

        for(auto &i:{args...})
            {
                generic *g = (generic*)&i;
                g->make_parent();
               children.push_back(g);
            }

            //for(auto &get_child :children)
            {
            //    cout <<"type returned: "<< get_child->type_return()<<endl;
            }



    }
    void add_element(generic* element)
    {
        element->make_parent(this);
        children.push_back(element);

    }

    /*
    template<typename... T>
    void add_element(generic* element, T&...args)
    {
        element->make_parent(this);
        children.push_back(element);
        children.push_back(args...);

    }

    */
    generic* get_parent()
    {
        return parent;
    }
    void make_parent(generic* parent)
    {
        this->parent = parent;
    }

    void make_parent()
    {
        this->parent = this;
    }

    int get_child_index(generic* element)
    {
			int _count = 0;
			for(generic* child : children)
                {
				if(child == element)
				{
					return _count;
				}
				++_count;
			}
			return -1;
    }

		string calculate_position()
		 {
			vector<string> path;
			stringstream ss;

			calculate_position_recursive(this, path);

			int size = path.size();
			for(int i = size - 1; i >= 0; --i)
            {
				ss << path[i];
				if(i != 0)
				 {
					ss << " > ";
				 }
			}
			return ss.str();
		}

    	void calculate_position_recursive(generic* e, vector<string>& path)
    	{
            if(e->parent)
                {
                int location = e->parent->get_child_index(e);

                if(location == -1)
                    {
                        if(name_of_tag=="")
                        {
                            path.push_back(e->type_t);
                        }

                        else
                        {
                            path.push_back(sort_simple_css_arrangement());
                        }
                    }
                    else
						{
						    if(name_of_tag!="")
                            {
                                path.push_back(sort_complex_css_arrangement(location));
							}
                            else
                            {
                                path.push_back(e->type_t+ ":nth-child(" + to_string(location + 1) + ")");
                            }
						}
					}
					else
                        {
                            if(name_of_tag=="")
                            {
                                path.push_back(e->type_t);
                            }
                            else
                            {
                                path.push_back(sort_simple_css_arrangement());
                            }
                        }

				if(e->parent)
                    {
                        calculate_position_recursive(e->parent, path);
                    }
			}


		void print_spaces(int depth)
		 {
			for(int i = 0; i < depth; ++i) {
				total_text << "  ";
			}
		}

		string sort_simple_css_arrangement()
		{
		    string text;

		    auto itr= details.find(name_of_tag);
            if( (itr->first== name_of_tag) && itr->second == "class")
            {
                text ="."+name_of_tag;

            }
            else if((itr->first== name_of_tag) && itr->second == "id")
            {
                text= "#"+name_of_tag;


            }

            return text;
		}

		string sort_complex_css_arrangement(int locate)
		{
		    string text;

		    auto itr= details.find(name_of_tag);

            if( (itr->first== name_of_tag) && itr->second == "class")
            {
                text =("."+name_of_tag+ ":nth-child(" + to_string(locate + 1) + ")");

            }
            else if((itr->first== name_of_tag) && itr->second == "id")
            {
                text= ("#"+name_of_tag+ ":nth-child(" + to_string(locate + 1) + ")");

            }

            cout << "text: "<< text <<endl;

            return text;
		}

		void print_tag_start(generic* e, int depth)
		{
			print_spaces(depth);

            total_text << "<" << e->type_t <<" " <<e->inline_attributes << ">";

		}

		void print_children(generic* e, int depth)
		 {
		     if(e==NULL)
                return;
            //int _count =0;
			for(generic* child : e->children)
                {

               // cout << "print child in vector: "<< child->type_return() <<endl;


                    //if(child ==NULL)
                      //  cout << "BOOM FAILED,ERROR AT POSITION : "<<(_count+1) <<endl;

				total_text << endl;

                display_recursive(child, depth + 1);

             //_count +=1;

                }

		}
		void print_text(generic* e, int depth)
		{
			if(!e->txt.empty())
                {
				total_text << endl;
				print_spaces(depth + 1);
				total_text << e->txt;
                }
		}

		void print_tag_end(generic* e, int depth)
		{
				print_spaces(depth);
				total_text << "</" << e->type_t +">";
		}

		void display_recursive(generic* e, int depth)
		{


			if(e != NULL)
                {
                    print_tag_start(e, depth);

				{
					print_children(e, depth);
					print_text(e, depth);
				}
				print_tag_end(e, depth);
			}

			else{
                cout <<"failed to display"<<endl;
			}
		}

		void display()
		{
            display_recursive(this,0);
		}

		void finalize()
		{
		        assert_mode_of_styling(this->mode_of_styling,this->name_of_tag,this->calculate_position(),this,
                               this->type_of_tag);

                               cout << "the mode of styling: "<< this->mode_of_styling <<endl;
                               cout << "the name of tag: "<< this->name_of_tag <<endl;
                               cout << "position: "<< this->calculate_position() <<endl;
                               cout << "type of tag: "<< this->type_of_tag <<endl;
		}

};


void construct_attributes(list<string> name,list<string>value,generic *point)
{

    for(auto n :all_existing_style)
{
    all_style +=n;
}

    list<string>::iterator a;
    list<string>::iterator b;

        for(a = name.begin(), b=value.begin(); a!=name.end(),b!=value.end(); a++,b++)
        {

            //a

                if(*a=="align_content" || *a=="ac")
            {

                s.align_content= *b;
                string text = "align-content: "+s.align_content+";";
                (point->style_used).push_back(text);
            }

                if(*a=="align_items" || *a=="ai")
            {
                s.align_items= *b;
                string text = "align-items: "+s.align_items+";";
                (point->style_used).push_back(text);
            }

               /*     if(*a=="align_self" || *a =="as")
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
                string text = "background-image: url("+quote+s.background_image+quote+");";
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

            */


            if(*a=="" || *b=="")
            {
                cout << "\n\n ---WARNING: a pair part of your blueprint is empty!!\n This may cause unusual behaviour" <<endl;
             //   break;
            }

            if(*a=="" || *b!="")
            {
                cout << "\n\n ---WARNING: You did not specify the first pair part of your blueprint_b!!\n This may cause unusual behaviour" <<endl;
               // break;
            }

            if(*a!="" || *b=="")
            {
                cout << "\n\n ---WARNING: You did not specify the second pair part of your blueprint_b!!\n This may cause unusual behaviour" <<endl;
                //break;
            }

            if(*a=="" || *b!="")
            {
                cout << "\n\n ---WARNING: You did not specify the first pair part of your blueprint_b!!\n This may cause unusual behaviour" <<endl;
                //break;
            }

            if(!boost::algorithm::contains(all_style,*a))

            {

                 cout << "\n\n ---ERROR: The style '"<< *a <<"' you entered in blueprint_b is not a valid CSS style" <<endl;
                 //break;
            }

        }

}




// THIS CLASS WAS WRITTEN BY ATMA
class exterior {
	public:
		generic* root;
		exterior() = default;
		explicit exterior(const generic& root) : root((generic*)&root) { }
		explicit exterior(generic* root) : root(root) { }

		void set_root(generic* root)
		 {
			this->root = root;
		 }
		void set_root(const generic& root)
		 {
			this->root = (generic*)&root;
         }
		generic* getRoot()
		{
			return root;
		}
		void display()
		{
			if(root != NULL)
                {
				root->display();
                }
			else
			{
				cout << "EMPTY EXTERIOR!";
			}
		}

};


string sty;

using i = pair<string,string>;

auto as_tuple(decltype(arivs::composition) a,decltype(arivs::composition) b,string style_type="")
{
    return make_tuple(a,b,style_type);

}

auto empty_lambda = [](){return as_tuple(arivs::nothing,arivs::nothing);};

void composition_a();
void composition_b();
//void style_the_objects();

#endif
