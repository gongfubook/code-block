
#ifndef __BLOCK_TYPES__
#define __BLOCK_TYPES__


/**
 *  块接口
*/
enum Connector{
    none = 0,
    male = 1,
    female = 2
};

/**
 * 一个块四个方位的连接口
*/
struct BlockConnector{
    Connector up, right, down, left;
};


/**
 * 块类型
*/
enum BlockType{
    normal = 0,               // 普通方块
    pluggable = 1,            // 可连接块
    with_inside = 2           // 内部包含其它块
};

/**
 * 单个块的形状
*/
struct BlockShape{
    int block_width, block_height;
    BlockConnector connector;
};


#endif // __BLOCK_TYPES__