/*
    This file is part of Cute Chess.

    Cute Chess is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Cute Chess is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Cute Chess.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <board/side.h>

namespace Chess { class Board; class Move; }
class QMenu;
class QAction;
class QTextEdit;
class QCloseEvent;
class BoardScene;
class QGraphicsView;
class MoveListModel;
class EngineConfigurationModel;
class ChessClock;
class PlainTextLog;
class ChessGame;
class PgnGame;

/**
 * MainWindow
*/
class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		MainWindow(ChessGame* game);
		virtual ~MainWindow();
		QString windowListTitle() const;

	protected:
		virtual void closeEvent(QCloseEvent* event);

	private slots:
		void newGame();
		void gameProperties();
		void manageEngines();
		void saveLogToFile();
		void onWindowMenuAboutToShow();
		void showGameWindow();
		void updateWindowTitle();
		bool save();
		bool saveAs();
		void import();

	private:
		void createActions();
		void createMenus();
		void createToolBars();
		void createDockWindows();
		void readSettings();
		QString genericWindowTitle() const;
		bool saveGame(const QString& fileName);
		bool askToSave();

		QMenu* m_gameMenu;
		QMenu* m_viewMenu;
		QMenu* m_enginesMenu;
		QMenu* m_windowMenu;
		QMenu* m_helpMenu;

		BoardScene* m_boardScene;
		QGraphicsView* m_boardView;
		MoveListModel* m_moveListModel;
		ChessClock* m_chessClock[2];

		QAction* m_quitGameAct;
		QAction* m_gamePropertiesAct;
		QAction* m_newGameAct;
		QAction* m_closeGameAct;
		QAction* m_saveGameAct;
		QAction* m_saveGameAsAct;
		QAction* m_importGameAct;
		QAction* m_manageEnginesAct;
		QAction* m_showGameDatabaseWindowAct;

		PlainTextLog* m_engineDebugLog;

		ChessGame* m_game;
		PgnGame* m_pgn;

		QString m_currentFile;

};

#endif // MAINWINDOW_H
