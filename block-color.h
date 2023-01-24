
#ifndef __BLOCK_COLOR__
#define __BLOCK_COLOR__

#include <Qcolor>
#include <Qstring>


constexpr const int TEXT_COLOR = 0x000000;
constexpr const int TYPE_COLOR = 0x006633;
constexpr const int VARIABLE_COLOR = 0x6600FF;
constexpr const int MATH_COLOR = 0x6666CC;
constexpr const int STRING_COLOR = 0xCC9933;
constexpr const int LOGIC_COLOR = 0x336699;
constexpr const int LOOP_COLOR = 0x33CC99;
constexpr const int ARRAY_COLOR = 0x663399;
constexpr const int FUNCTION_COLOR = 0xFFCC33;

constexpr const int BLACK = 0x000000;


QColor rgbColor(const int hex_color);





#endif // __BLOCK_COLOR__
