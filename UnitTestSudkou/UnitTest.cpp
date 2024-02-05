#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Testen von C-Programmen mit Endung ".c"
// Testdapter fpr CPPUnittest-Framework installieren unter "Erweiterungen/ Erweiterungen verwalten/ Online"
// Projektmappe /Hinzufügen/ Neues Projekt: Suchen nach C++ Test: "Natives Komponententestprojekt" oder Template "Unittest(.zip)" benutzen
// Verweis im Testprojekt auf zu testendes Projekt hinzufuegen
// auf dem Testprojekt: Eigenschaften/ Linker/ Eingabe: Obj-File hinzufügen/ korrigieren
// Funktionsdefinitionen laden
// #include "../anyproject.h"
// darin Funktionen als extern deklarieren: extern "C" void func();
// auf Testprojekt: Tests ausführen (evtl. VS einmal schließen)

#include "C:\Users\Manu\source\repos\Sudoku_Game\Sudoku_Game\anyproject.h"


namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			//int test = ConvertLetterToNumber('A');
			int test = 0;
			Assert::IsTrue(test == 0);
		}
		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(0, 1);
		}
	};
}
