#ifndef FUDIE_GUI_FUDIE_WIDGET_H
#define FUDIE_GUI_FUDIE_WIDGET_H

#include <QMainWindow>
#include <QString>
#include <QFont>
#include <QLabel>
#include <QLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QListWidget>
#include <Qt>

#include "gui/recipe_list_widget.h"

class FudieWidget : public QWidget
{
  public:
    FudieWidget();

  private:
    const QString m_window_title = "fudie";

    QVBoxLayout* m_main_layout = nullptr;

    QLayout* m_active_layout = nullptr;

    QFont* m_button_font;

    void destroy_layout(QLayout *layout);
    void setup_main_menu();
    void setup_recipes_edit_menu();
    void remove_active_layout();
};

#endif
