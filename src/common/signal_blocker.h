/*
 * This file is part of EasyRPG Editor.
 *
 * EasyRPG Editor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Editor. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <QWidget>

class SignalBlocker {
public:
	SignalBlocker(QObject* item) {
		items = {item};
		item->blockSignals(true);
	}

	SignalBlocker(std::initializer_list<QObject*> items) {
		for (auto& item : items) {
			item->blockSignals(true);
		}
		this->items = items;
	}

	~SignalBlocker() {
		for (auto& item : items) {
			item->blockSignals(false);
		}
	}

private:
	std::vector<QObject*> items;
};
