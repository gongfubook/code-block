// #include "dnd-events.h"


// void createQDrag(
//     QDropEvent *event,
//     const QWidget * target
// ){
//     if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
//         QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
//         QDataStream dataStream(&itemData, QIODevice::ReadOnly);

//         QPixmap pixmap;
//         QPoint offset;
//         QString block_name;
//         dataStream >> pixmap >> offset >> block_name;

//         if (block_name == "output") {
//             block_print *new_block_print = new block_print(this);
//             block_base *child = static_cast<block_base*>(childAt(event->pos()));
//             if (child) {
//                 if (child->whatsThisBlockName() == "function" || child->whatsThisBlockName() == "main function"){
//                     qDebug() << "child->whatsThisBlockName()" << child->whatsThisBlockName();
//                     qDebug() << "child->widget_height" << child->widget_height << "child->block_height: " << child->block_height;
//                     auto cp = child->pos() + QPoint(5,5);
//                     int x = cp.x() + BLOCK_LEFT_WIDTH - BLOCK_X;
//                     int y = cp.y() + BLOCK_HEIGHT - BLOCK_Y;
//                     block_base *inner_child = static_cast<block_base*>(childAt(x, y));
//                     if (inner_child && inner_child != child) {
//                         qDebug() << inner_child->whatsThisBlockName();
//                         qDebug() << "child->widget_height" << child->widget_height << "child->block_height: " << child->block_height;
//                         qDebug() << "new_block_print->block_height" << new_block_print->block_height;
//                         child->widget_height = child->widget_height + new_block_print->block_height;
//                         child->block_height += new_block_print->block_height;

//                         qDebug() << "child->widget_height" << child->widget_height << "child->block_height: " << child->block_height;
//                         child->createPixmap();
//                         child->update();
//                         child->show();
//                         new_block_print->move(x, y+new_block_print->block_height);
//                     } else {
//                         new_block_print->move(x, y);
//                     }
//                 }
//             } else {
//                 new_block_print->move(event->pos() - offset);
//             }
//             new_block_print->show();
//             new_block_print->setAttribute(Qt::WA_DeleteOnClose);
//         }

//         if (block_name == "function") {
//             block_function *new_block_function = new block_function(this, false);
//             new_block_function->move(event->pos() - offset);
//             new_block_function->show();
//             new_block_function->setAttribute(Qt::WA_DeleteOnClose);
//         }

//         if (block_name == "main_function") {
//             block_main_function *main = new block_main_function(this);
//             main->move(event->pos() - offset);
//             main->show();
//             main->setAttribute(Qt::WA_DeleteOnClose);
//         }

//         if (event->source() == this) {
//             event->setDropAction(Qt::MoveAction);
//             event->accept();
//         } else {
//             event->acceptProposedAction();
//         }
//     } else {
//         event->ignore();
//     }
// }