/********************************************
**
** Copyright 2016 JustCode Justyna Kulinska
**
** This file is part of Resto.
**
** Resto is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** any later version.
**
** Resto is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with Resto; if not, write to the Free Software
** Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
**
********************************************/

// to format resource info

var licences = {
    "CC0": { "name": "CC0", "url": "https://creativecommons.org/publicdomain/zero/1.0" },
    "CC-BY-SA-3.0": { "name": "CC BY-SA 3.0", "url": "https://creativecommons.org/licenses/by-sa/3.0/" },
    "CC-BY-NC-ND-3.0": { "name": "CC BY-NC-ND 3.0", "url": "https://creativecommons.org/licenses/by-nc-nd/3.0/" },
    "OFL": { "name": "OFL", "url": "http://scripts.sil.org/OFL" },
}

var resources = [
            {
                "description": qsTr("Background"),
                "name": "Rice paper 2",
                "url": "http://subtlepatterns.com/rice-paper-2/",
                "author": "Atle Mo",
                "authorUrl": "http://atle.co/",
                "licence": "CC-BY-SA-3.0",
                "additionalInfo": ""
            },
            {
                "description": qsTr("Decorative"),
                "name": "Ivy",
                "url": "https://pixabay.com/pl/ivy-wirowa%C4%87-upadek-design-okr%C4%85g-303546/",
                "author": "Clker-Free-Vector-Images",
                "authorUrl": "https://pixabay.com/pl/users/Clker-Free-Vector-Images-3736/",
                "licence": "CC0",
                "additionalInfo": qsTr("Colors changed")
            },
            {
                "description": qsTr("Icons"),
                "name": "Devine",
                "url": "http://findicons.com/pack/1579/devine/1",
                "author": "ipapun",
                "authorUrl": "http://ipapun.deviantart.com/",
                "licence": "CC-BY-NC-ND-3.0",
                "additionalInfo": ""
            },
            {
                "description": qsTr("Font"),
                "name": "Josefin Sans",
                "url": "http://www.1001freefonts.com/josefin_sans.font",
                "author": "Santiago Orozco",
                "authorUrl": "http://www.1001freefonts.com/designer-santiago-orozco-fontlisting.php",
                "licence": "OFL",
                "additionalInfo": ""
            },
]

function formatLink(description, address) {
    return "<a href=\"" + address + "\">" + description + "</a>";
}

function getInfo() {
    var infoString = ""
    var indent = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"

    for (var i=0; i<resources.length; ++i)
    {
        var item = resources[i];
        var licence = licences[item.licence]

        infoString += "<u>" + item.description + ":</u>" + "<br/>";
        infoString += indent + formatLink(item.name, item.url)
                + " " + qsTr("by") + " " + formatLink(item.author, item.authorUrl)
                + " " + qsTr("under") + " " + formatLink(licence.name, licence.url) + "<br/>";
        if (item.additionalInfo.length)
        {
            infoString += indent + "<i>" + item.additionalInfo + "</i>" + "<br/>";
        }
    }
    return infoString;
}
