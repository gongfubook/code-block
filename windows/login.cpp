#include "login.h"
#include <QMessageBox>
#include <QPainter>
#include <QPixmap>

Login::Login(QWidget *parent)
    : QWidget(parent),  m_loginSuccess(false)
{
    setMinimumWidth(1080);
    setMinimumHeight(750);
    // 设置背景色和边框样式
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(228, 230, 235));
    setPalette(pal);
    setAutoFillBackground(true);
    setStyleSheet("border-radius: 10px; border: 1px solid #ccc;");
   // 初始化用户名和密码输入框
    m_usernameEdit = new QLineEdit(this);
    m_passwordEdit = new QLineEdit(this);
    m_loginBtn = new QPushButton("登录", this);

    m_usernameEdit->setPlaceholderText("用户名");
    m_passwordEdit->setPlaceholderText("密码");
    m_passwordEdit->setEchoMode(QLineEdit::Password);
    m_loginBtn->setFixedSize(80, 32);

    // 设置位置和大小
    m_usernameEdit->setGeometry(1080 / 2 - 30, 100, 200, 30);
    m_passwordEdit->setGeometry(1080 / 2 - 30, 140, 200, 30);
    m_loginBtn->setGeometry(1080 / 2 + 30, 190, 80, 32);

    // 连接登录按钮的槽函数
    connect(m_loginBtn, &QPushButton::clicked, this, &Login::on_loginBtn_clicked);
}

Login::~Login()
{
}

bool Login::isLoginSuccess() const
{
    return m_loginSuccess;
}

void Login::on_loginBtn_clicked()
{
    QString username = m_usernameEdit->text();
    QString password = m_passwordEdit->text();

    // 验证用户名和密码
    if (username == "admin" && password == "admin") {
        // 登录成功，关闭登录界面
        m_loginSuccess = true;
        close();
    } else {
        // 登录失败，显示错误信息
        QMessageBox::warning(this, "登录失败", "用户名或密码错误，请重新输入！");
    }
}

void Login::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    // 绘制渐变背景色
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QLinearGradient gradient(rect().topLeft(), rect().bottomRight());
    gradient.setColorAt(0, QColor(255, 255, 255));
    gradient.setColorAt(1, QColor(228, 230, 235));
    painter.fillRect(rect(), gradient);

    // 绘制圆角矩形边框
    painter.setPen(QPen(QColor(183, 183, 183), 1));
    painter.setBrush(Qt::NoBrush);
    painter.drawRoundedRect(rect(), 10, 10);
}

void Login::closeEvent(QCloseEvent *event)
{
    // 释放资源
    deleteLater();
    // 阻止事件传递
    event->ignore();
}