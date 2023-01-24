

#include "main-window.h"
#include "block-base.h"
#include <Qdebug>
#include <Qvector>

main_window::main_window(QWidget *parent): QWidget(parent) {
    setMinimumWidth(1080);
    setMinimumHeight(750);
    setWindowTitle(QObject::tr("Code Block"));

    vboxLayout = new QVBoxLayout(this);

    horizontalLayout1 = new QHBoxLayout(this);
    QPushButton *compiler = new QPushButton("编译");
    QPushButton *run = new QPushButton("运行");
    QPushButton *clean = new QPushButton("清空");
    horizontalLayout1->addWidget(compiler);
    horizontalLayout1->addWidget(run);
    horizontalLayout1->addWidget(clean);

    horizontalLayout2 = new QHBoxLayout(this);
    block_list_window = new block_list(this);
    code_list_window = new code_list(this);
    code_display_window = new code_display(this);

    horizontalLayout2->addWidget(block_list_window);
    horizontalLayout2->addWidget(code_list_window);
    horizontalLayout2->addWidget(code_display_window);

    vboxLayout->addLayout(horizontalLayout1);
    vboxLayout->addLayout(horizontalLayout2);
    connect(compiler, SIGNAL(clicked()), this, SLOT(click_compiler()));
    connect(run, SIGNAL(clicked()), this, SLOT(click_run()));
    connect(clean, SIGNAL(clicked()), this, SLOT(click_clean()));

}


void main_window::click_compiler(){
    auto codes = code_list_window->children();
    QVector<block_base*> bbs;
    for (auto code : codes) {
        block_base * bb = dynamic_cast<block_base *>(code);
        bbs.append(bb);
    }
    QVector<block_base*> parents;
    for(auto bb : bbs) {
        if(bb->isParentBlock()){
            parents.append(bb);
        } else {
            if (parents.size() != 0) {
                parents[parents.size()-1]->insertCode(bb->toCode());
            }
        }
    }
    for(auto b : parents) {
        code_str.append(b->toCode());
    }
    qDebug() << code_str;
    code_display_window->setPlainText(code_str);

}

void main_window::click_run(){

}

void main_window::click_clean(){
    code_str.clear();
    code_display_window->setPlainText(code_str);
}