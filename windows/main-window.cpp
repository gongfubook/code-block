

#include "main-window.h"
#include "block-base.h"
#include <Qdebug>
#include <Qvector>
#include <QTemporaryDir>
#include <QTemporaryFile>
#include <QProcess>

main_window::main_window(QWidget *parent): QWidget(parent) {
    setMinimumWidth(1080);
    setMinimumHeight(750);
    setWindowTitle(QObject::tr("Code Block"));

    vboxLayout = new QVBoxLayout(this);

    main_menu = new QHBoxLayout;
    QPushButton *open_project = new QPushButton("打开");
    QPushButton *save_project = new QPushButton("保存");
    QPushButton *generate_code = new QPushButton("生成");
    QPushButton *compiler = new QPushButton("编译");
    QPushButton *run = new QPushButton("运行");
    QPushButton *clean = new QPushButton("清空");
    main_menu->addWidget(open_project);
    main_menu->addWidget(save_project);
    main_menu->addWidget(generate_code);
    main_menu->addWidget(compiler);
    main_menu->addWidget(run);
    main_menu->addWidget(clean);

    code_block_windows = new QHBoxLayout;
    block_menu_window_object = new block_menu_window(this);
    block_list_window_object = new block_list_window(this);
    code_list_window_object = new code_list_window(this);
    code_display_window_object = new code_display_window(this);

    code_block_windows->addWidget(block_menu_window_object);
    code_block_windows->addWidget(block_list_window_object);
    code_block_windows->addWidget(code_list_window_object);
    code_block_windows->addWidget(code_display_window_object);
    

    output_display_window_object = new output_display_window(this);
    vboxLayout->addLayout(main_menu);
    vboxLayout->addLayout(code_block_windows);
    vboxLayout->addWidget(output_display_window_object);
    
    connect(compiler, SIGNAL(clicked()), this, SLOT(click_compiler()));
    connect(run, SIGNAL(clicked()), this, SLOT(click_run()));
    connect(clean, SIGNAL(clicked()), this, SLOT(click_clean()));

    connect(block_menu_window_object->math_btn, SIGNAL(clicked()), block_list_window_object, SLOT(show_number()));
    connect(block_menu_window_object->string_btn, SIGNAL(clicked()), block_list_window_object, SLOT(show_string()));
    connect(block_menu_window_object->logic_btn, SIGNAL(clicked()), block_list_window_object, SLOT(show_logic()));
    connect(block_menu_window_object->loop_btn, SIGNAL(clicked()), block_list_window_object, SLOT(show_loop()));
    connect(block_menu_window_object->function_btn, SIGNAL(clicked()), block_list_window_object, SLOT(show_function()));
    connect(block_menu_window_object->variable_btn, SIGNAL(clicked()), block_list_window_object, SLOT(show_variable()));
    connect(block_menu_window_object->input_output_btn, SIGNAL(clicked()), block_list_window_object, SLOT(show_input_output()));
    connect(block_menu_window_object->list_btn, SIGNAL(clicked()), block_list_window_object, SLOT(show_list()));
    connect(block_menu_window_object->dict_btn, SIGNAL(clicked()), block_list_window_object, SLOT(show_dict()));

    setAttribute(Qt::WA_DeleteOnClose);
}


void main_window::click_compiler(){
    qDebug() <<  "click_compiler all block";
    for (auto child : code_list_window_object->children() ) {
        auto b = qobject_cast<QWidget*>(child);
        if (b) {
            auto bb = static_cast<block_base*>(b);
            if (bb) {
                qDebug() <<  bb->whatsThisBlockName();
            }
        }
    }
    // auto codes = code_list_window->children();
    // QVector<block_base*> bbs;
    // for (auto code : codes) {
    //     block_base * bb = dynamic_cast<block_base *>(code);
    //     bbs.append(bb);
    // }
    // QVector<block_base*> parents;
    // for(auto bb : bbs) {
    //     if(bb->isParentBlock()){
    //         parents.append(bb);
    //     } else {
    //         if (parents.size() != 0) {
    //             parents[parents.size()-1]->insertCode(bb->toCode());
    //         }
    //     }
    // }
    // for(auto b : parents) {
    //     code_str.append(b->toCode());
    // }
    // code_str.insert(0, "#include <stdio.h>\n\n");
    // qDebug() << code_str;
    // code_display_window->setCodeText(code_str);

    // code_path = QDir::tempPath() +  QDir::separator() + "code_block";
    // qDebug() << "code_path: " << code_path;
    // QDir dir(code_path);
    // if(!dir.exists()){
    //     if (!dir.mkdir(code_path)) {
    //         qDebug() << "mkdir failed!";
    //         return;
    //     } 
    // }
    // exe_file = code_path + QDir::separator() + "test";
    // code_file = exe_file + ".c";
    // QFile file(code_file);
    // bool ret = file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
    // if (!ret) {
    //     qDebug() << code_file << " file open failed!";
    // }
    // file.write(code_str.toUtf8());
    // file.close();
    // qDebug() << "code_file: " << code_file;

    // QProcess process(this);
    // process.setProgram("gcc");
    // QStringList argument;
    // argument << code_file << "-o" << exe_file;
    // process.setArguments(argument);
    // process.start();
    // process.waitForStarted(); 
    // process.waitForFinished();
    // QString output = QString::fromUtf8(process.readAllStandardOutput()); 
    // output_display_window->setOutputText(output + "编译完成\n");
}

void main_window::click_run(){
    // if (!QFile::exists(exe_file + ".exe")){
    //     qDebug() << "not exists";
    //     return;
    // }
    // output_display_window->setOutputText("");
    // QProcess process(this);
    // process.setProgram(exe_file);
    // process.start();
    // process.waitForStarted(); 
    // process.waitForFinished();
    // QString output = QString::fromUtf8(process.readAllStandardOutput()); 
    // output_display_window->setOutputText(output);
}

void main_window::click_clean(){
    // code_str.clear();
    // code_display_window->setCodeText(code_str);
    // output_display_window->setOutputText("");
}

main_window::~main_window(){
    // if (code_file.size() && QFile::exists(code_file)){
    //     qDebug() << "exists";
    //     QFile::remove(code_file);
    // }
    // if (exe_file.size() && QFile::exists(exe_file)){
    //     qDebug() << "exists";
    //     QFile::remove(exe_file);
    // }
    if (code_path.size()) {
        QDir code_path_dir(code_path);
        if (code_path_dir.exists()){
            qDebug() << "exists";
            code_path_dir.removeRecursively();
        }
    }
}