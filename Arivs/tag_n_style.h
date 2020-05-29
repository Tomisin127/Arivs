#ifndef TAG_N_STYLE_H
#define TAG_N_STYLE_H


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <list>
using namespace std;
#include <cstring>
#include <filesystem/include/ghc/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <tuple>
#include <functional>
#include <sstream>

fstream html_object;
fstream css_object;

string quote = "\"";
string q = "\"";

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

vector<string>all_existing_style= {"width","height","_float","background","background_blend_mode","background_clip","background_image",
"background_color","background_position","background_repeat","background_size","background_attachment","border","color","border_style",
"border_top_style","border_right_style","border_bottom_style","border_left_style","border_bottom","border_bottom_color","border_radius",
"border_bottom_left_radius","border_bottom_right_radius","border_bottom_width","border_collapse","border_color","border_image",
"border_image_outset","border_image_repeat","border_image_slice","border_image_source","border_image_width","border_left","border_left_color",
"border_left_width","border_right","border_right_color","border_right_width","border_spacing","border_top",
"border_top_color","border_top_left_radius","border_top_right_radius","border_top_width","bottom","box_decoration_break",
"box_shadow","box_sizing","break_after","break_before","break_inside","caption_side","caret_color","_charset","_clear","clip",
"column_count","column_fill","column_gap","column_rule","column_rule_color","column_rule_style","column_rule_width","column_span",
"column_width","columns","content","counter_increment","counter_reset","cursor","direction","display","empty_cells","filter","flex",
"flex_basis","flex_direction","flex_flow","flex_grow","flex_shrink","flex_wrap","font","_font_face","font_feature_settings","_font_feature_values",
"font_kerning","font_language_override","font_size_adjust","font_stretch","font_style","font_synthesis","font_variant","font_variant_alternates",
"font_variant_caps","font_variant_east_asian","font_variant_ligatures","font_variant_numeric","font_variant_position","font_weight",
"grid","grid_area","grid_auto_columns","grid_auto_flow","grid_auto_rows","grid_column","grid_column_end","grid_column_gap","grid_column_start",
"grid_gap","grid_row","grid_row_end","grid_row_gap","grid_row_start","grid_template","grid_template_areas","grid_template_columns",
"grid_template_rows","hanging_punctuation","hyphens","image_rendering","_import","isolation","justify_content","_keyframes","margin",
"margin_top","margin_right","margin_bottom","margin_left","padding","padding_top","padding_right","padding_bottom","padding_left",
"outline_style","outline_color","outline_width","outline_offset","outline","border_width","text_align","font_family","font_size",
"align_content","align_items","align_self","all","animation","animation_delay","animation_direction","animation_duration","animation_fill_mode",
"animation_iteration_count","animation_name","animation_play_state","animation_timing_function","left","letter_spacing","line_break","line_height",
"list_style","list_style_image","list_style_position","list_style_type","max_height","max_width","_media","min_height","min_width","mix_blend_mode",
"object_fit","object_position","opacity","order","orphans","overflow","overflow_wrap","overflow_x","overflow_y","page_break_after",
"page_break_before","page_break_inside","perspective_origin","perspective","pointer_events","position","_resize","right","scroll_behavior",
"tab_size","table_layout","text_align_last","text_combine_upright","text_decoration","text_decoration_color","text_decoration_line",
    "text_decoration_style","text_indent","text_justify","text_orientation","text_overflow","text_shadow","text_transform",
    "text_underline_position","top","_transform","transform_origin","transform_style","transition","transition_delay",
    "transition_duration","transition_property","transition_timing_function","quotes","unicode_bidi","user_select","vertical_align",
    "visibility","white_space","widows","word_break","word_spacing","word_wrap","writing_mode",
    "z_index", "backface_visibility"};

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

vector<string>all_existing_tags_in_html={"header","nav","h1","h2","h3","h4","h5","h6","ul","ol","title","base","bdi","button","center","a","abbr","acronym","address","applet","area",
"audio","b","body","basefont","bdo","br","bdo","blockquote","canvas","caption","cite","code","col","colgroup","data","datalist","dd","del","details","dfn",
"dialog","dir","div","dl","dt","em","embed","fieldset","figcaption","figure","font","footer","form","frame","frameset","p1","p2","p3","p4","p5","p6","head",
"hr","html","i","iframe","img","input","ins","kbd","label","legend","li","link","main","map","mark","meter","noframes","noscript","object","var","optgroup","option",
"output","p","param","picture","pre","progress","q","rp","rt","ruby","s","samp","script","section","select","small","source","span","strike","strong","style","sub",
"summary","sup","svg","table","tbody","td","template","textarea","tfoot","th","thead","time","title","tr","track","tt","u","video","wbr"
};

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


struct coords
{
    int x=0;
    int y=0;
    int z=0;
    int w=0;
};

#endif // TAG_N_STYLE_H
