/*
 * Copyright 2010-2016 OpenXcom Developers.
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ArticleStateTFTD.h"
#include "ArticleStateTFTDCraftWeapon.h"
#include "../Mod/ArticleDefinition.h"
#include "../Mod/Mod.h"
#include "../Mod/RuleCraftWeapon.h"
#include "../Engine/Game.h"
#include "../Engine/Palette.h"
#include "../Engine/LocalizedText.h"
#include "../Engine/Unicode.h"
#include "../Interface/TextList.h"

namespace OpenXcom
{

	ArticleStateTFTDCraftWeapon::ArticleStateTFTDCraftWeapon(ArticleDefinitionTFTD *defs, std::shared_ptr<ArticleCommonState> state) : ArticleStateTFTD(defs, std::move(state))
	{
		RuleCraftWeapon *weapon = _game->getMod()->getCraftWeapon(defs->id, true);

		_lstInfo = new TextList(150, 50, 168, 126);
		add(_lstInfo);

		_lstInfo->setColor(_listColor1);
		_lstInfo->setColumns(2, 100, 68); // deliberately making this wider than the original to account for finnish.
		_lstInfo->setDot(true);

		_lstInfo->addRow(2, tr("STR_DAMAGE").c_str(), Unicode::formatNumber(weapon->getDamage()).c_str());
		_lstInfo->setCellColor(0, 1, _listColor2);

		_lstInfo->addRow(2, tr("STR_RANGE").c_str(), tr("STR_KILOMETERS").arg(weapon->getRange()).c_str());
		_lstInfo->setCellColor(1, 1, _listColor2);

		_lstInfo->addRow(2, tr("STR_ACCURACY").c_str(), Unicode::formatPercentage(weapon->getAccuracy()).c_str());
		_lstInfo->setCellColor(2, 1, _listColor2);

		_lstInfo->addRow(2, tr("STR_RE_LOAD_TIME").c_str(), tr("STR_SECONDS").arg(weapon->getStandardReload()).c_str());
		_lstInfo->setCellColor(3, 1, _listColor2);

		_lstInfo->addRow(2, tr("STR_ROUNDS").c_str(), Unicode::formatNumber(weapon->getAmmoMax()).c_str());
		_lstInfo->setCellColor(4, 1, _listColor2);

		centerAllSurfaces();
	}

	ArticleStateTFTDCraftWeapon::~ArticleStateTFTDCraftWeapon()
	{}

}
