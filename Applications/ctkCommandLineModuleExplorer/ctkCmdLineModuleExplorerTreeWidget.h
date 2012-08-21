/*=============================================================================

  Library: CTK

  Copyright (c) German Cancer Research Center,
    Division of Medical and Biological Informatics

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=============================================================================*/

#ifndef CTKCMDLINEMODULEEXPLORERTREEWIDGET_H
#define CTKCMDLINEMODULEEXPLORERTREEWIDGET_H

#include <ctkCmdLineModuleReference.h>

#include <QTreeWidget>

class ctkCmdLineModuleFrontend;
struct ctkCmdLineModuleFrontendFactory;

class ctkCmdLineModuleExplorerTreeWidget : public QTreeWidget
{
  Q_OBJECT

public:

  explicit ctkCmdLineModuleExplorerTreeWidget(QWidget* parent = 0);

  void setModuleFrontendFactories(const QList<ctkCmdLineModuleFrontendFactory*>& frontendFactories);

  Q_SLOT void addModuleItem(const ctkCmdLineModuleReference& moduleRef);

  Q_SIGNAL void moduleDoubleClicked(ctkCmdLineModuleReference moduleRef);
  Q_SIGNAL void moduleFrontendCreated(ctkCmdLineModuleFrontend* moduleFrontend);

protected:

  void contextMenuEvent(QContextMenuEvent* event);

private:

  Q_SLOT void moduleDoubleClicked(const QModelIndex& index);
  Q_SLOT void frontendFactoryActionTriggered();

  static QString CATEGORY_UNKNOWN;

  QMenu* ContextMenu;
  QMenu* ShowFrontendMenu;

  ctkCmdLineModuleReference ContextReference;
  QList<ctkCmdLineModuleFrontendFactory*> FrontendFactories;
  QHash<QString, QTreeWidgetItem*> TreeWidgetCategories;
  QHash<QAction*, ctkCmdLineModuleFrontendFactory*> ActionsToFrontendFactoryMap;
};

#endif // CTKCMDLINEMODULEEXPLORERTREEWIDGET_H