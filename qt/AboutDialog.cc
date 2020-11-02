/*
 * This file Copyright (C) 2009-2015 Mnemosyne LLC
 *
 * It may be used under the GNU GPL versions 2 or 3
 * or any future license endorsed by Mnemosyne LLC.
 *
 */

#include <QApplication>
#include <QIcon>
#include <QMessageBox>
#include <QPushButton>

#include <libtransmission/transmission.h>
#include <libtransmission/version.h>

#include "AboutDialog.h"
#include "LicenseDialog.h"
#include "Utils.h"

AboutDialog::AboutDialog(QWidget* parent) :
    BaseDialog(parent)
{
    ui_.setupUi(this);

    ui_.iconLabel->setPixmap(QApplication::windowIcon().pixmap(48));
    ui_.titleLabel->setText(tr("<b style='font-size:x-large'>Transmission %1</b>").arg(QStringLiteral(LONG_VERSION_STRING)));

    QPushButton const* b = ui_.dialogButtons->addButton(tr("C&redits"), QDialogButtonBox::ActionRole);
    connect(b, &QAbstractButton::clicked, this, &AboutDialog::showCredits);

    b = ui_.dialogButtons->addButton(tr("&License"), QDialogButtonBox::ActionRole);
    connect(b, &QAbstractButton::clicked, this, &AboutDialog::showLicense);

    ui_.dialogButtons->button(QDialogButtonBox::Close)->setDefault(true);
}

void AboutDialog::showCredits()
{
    QMessageBox::about(this, tr("Credits"), QString::fromUtf8(
        "Charles Kerr (Backend; Daemon; GTK+; Qt)\n"
        "Mitchell Livingston (OS X)\n"
        "Mike Gelfand\n"));
}

void AboutDialog::showLicense()
{
    Utils::openDialog(license_dialog_, this);
}
