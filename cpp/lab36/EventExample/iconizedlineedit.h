#ifndef ICONIZEDLINEEDIT_H
#define ICONIZEDLINEEDIT_H

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>


class IconizedLineEdit : public QLineEdit
{
    Q_OBJECT
signals:
    void iconPressed();
public:
    //Режимы отображения пиктограммы, которые определяют её поведение
    enum IconVisibilityMode{
        //Всегда отображать пиктограмму
        IconAlwaysVisible=0,
        //Отображать пиктограмму после наведения курсора на поле ввода
        IconVisibleOnHover,
        //Отображать пиктограмму при присутствии текста
        IconVisibleOnTextPresence,
        //Отображать пиктограмму при отсутствии текста
        IconVisibleOnEmptyText,
        //Всегда прятать пиктограмму
        IconAlwaysHidden
    };
    explicit IconizedLineEdit(QWidget *parent = 0);
    bool isIconVisible() const;
    void setIconPixmap(const QPixmap &pPixmap);
    void setIconTooltip(const QString &pToolTip);
    void setIconVisibility(IconVisibilityMode pIconVisibilityMode);
    void setIconClickable(bool is_icon_clickable);
private :
    void updateIconPositionAndSize();
    void setIconVisible(bool pIsVisible);
protected:
    bool eventFilter(QObject*, QEvent*);
private :
    QLabel *mIconLabel;  //Указатель на метку, которая отображает пиктограмму
    IconVisibilityMode mIconVisibilityMode;  //Режим отображения
    QHBoxLayout *layout;
    bool is_icon_clickable;
private slots:
    void slotTextChanged(const QString &pText);
    void slotClear();
};

#endif // ICONIZEDLINEEDIT_H
