#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QCloseEvent>

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    bool isLoginSuccess() const;

private slots:
    void on_loginBtn_clicked();

private:
    QLineEdit *m_usernameEdit;
    QLineEdit *m_passwordEdit;
    QPushButton *m_loginBtn;
    bool m_loginSuccess;
protected:
    void paintEvent(QPaintEvent *event);
    void closeEvent(QCloseEvent *event);
};

#endif // LOGIN_H
