/**
 ******************************************************************************
 *
 * @file       endpage.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2012.
 * @see        The GNU Public License (GPL) Version 3
 *
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup SetupWizard Setup Wizard
 * @{
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>
 */
#include "tlendpage.h"
#include "ui_endpage.h"
#include <coreplugin/modemanager.h>
#include <extensionsystem/pluginmanager.h>
#include <configgadgetfactory.h>
#include <QMessageBox>

TLEndPage::TLEndPage(SetupWizard *wizard, QWidget *parent) :
    AbstractWizardPage(wizard, parent),
    ui(new Ui::EndPage)
{
    ui->setupUi(this);
    setFinalPage(true);
    connect(ui->inputWizardButton, SIGNAL(clicked()), this, SLOT(openInputWizard()));
}

TLEndPage::~TLEndPage()
{
    delete ui;
}

void TLEndPage::openInputWizard()
{
    ExtensionSystem::PluginManager *pm = ExtensionSystem::PluginManager::instance();
    ConfigGadgetFactory *configGadgetFactory = pm->getObject<ConfigGadgetFactory>();

    if (configGadgetFactory) {
        // Core::ModeManager::instance()->activateModeByWorkspaceName("Configuration");
        getWizard()->close();
        configGadgetFactory->startInputWizard();
    } else {
        QMessageBox msgBox;
        msgBox.setText(tr("Unable to open Input Wizard since the Config Plugin is not\nloaded in the current workspace."));
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
}
