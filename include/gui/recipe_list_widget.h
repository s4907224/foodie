#ifndef FUDIE_GUI_RECIPE_LIST_H
#define FUDIE_GUI_RECIPE_LIST_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QString>

#include <string>
#include <map>


class RecipeListWidget : public QWidget
{
  public:
    RecipeListWidget();
    void add_recipe_list_widget_item(std::string _name, int _price, int _total_cooking_time, int _calories);


  private:
    std::map<std::string, std::map<std::string, int>> m_recipe_widget_items;

    QGridLayout* m_grid_layout;

    QFont* m_small_font;
};

#endif
