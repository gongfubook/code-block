
#ifndef __BLOCK_SIZE__
#define __BLOCK_SIZE__

constexpr const int WIDGET_WIDTH = 100;
constexpr const int WIDGET_HEIGHT = 40;
constexpr const int BLOCK_WIDTH = WIDGET_WIDTH - 10;
constexpr const int BLOCK_HEIGHT = WIDGET_HEIGHT - 10;
constexpr const int BLOCK_X = 5;
constexpr const int BLOCK_Y = 5;

constexpr const int WIDGET_IO_WIDTH = WIDGET_WIDTH + 35;
constexpr const int BLOCK_IO_WIDTH = BLOCK_WIDTH + 35;

constexpr const int WIDGET_FUNCTION_WIDTH = WIDGET_WIDTH;
constexpr const int WIDGET_FUNCTION_HEIGHT = BLOCK_HEIGHT * 3 + 10;
constexpr const int BLOCK_FUNCTION_WIDTH = BLOCK_WIDTH;
constexpr const int BLOCK_FUNCTION_HEIGHT = BLOCK_HEIGHT * 3;
constexpr const int BLOCK_FUNCTION_LEFT_WIDTH = 20;

// 代码块上绘制文字的大小
constexpr const int BLOCK_TEXT_SIZE = 12;


#endif // __BLOCK_SIZE__
