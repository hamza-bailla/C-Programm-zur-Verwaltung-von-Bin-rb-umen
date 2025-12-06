C Binary Tree Management System
This C program implements a comprehensive set of functionalities for managing and manipulating Binary Trees. The system allows users to work with two primary types of trees: Horizontally Ordered Binary Search Trees (BSTs) and General Binary Trees.

The project uses a recursive approach for many operations and provides a command-line interface menu for easy interaction.

Key Features
Node Creation: Function to dynamically allocate and initialize a new tree node.

Insertion:

BST: Inserts a node while maintaining the BST property (smaller values to the left, larger to the right).

General Tree: Allows for arbitrary insertion (left or right) based on user choice.

Traversal & Display:

Prefix Traversal (NLR): Displays nodes in Root, Left, Right order.

Infix Traversal (LNR): Displays nodes in Left, Root, Right order (results in sorted order for BSTs).

Postfix Traversal (LRN): Displays nodes in Left, Right, Root order.

Schematic Display: Visual representation of the tree (rotated 90 degrees).

Leaf Display: Lists all leaf nodes.

Metrics:

Size: Calculates the total number of nodes in the tree.

Height: Calculates the maximum height/depth of the tree.

Value Search: Finds the minimum and maximum node values.

Search: Checks for the existence of a specific value.

Deletion:

BST: Implements standard BST deletion, including the use of the minimum value from the right subtree for nodes with two children.

General Tree: Deletes a node by replacing it with a leaf from the left subtree.

Emptying the Tree: Functions to completely deallocate all nodes for both BST and general trees.

--------------------------------------------------------------------------------------------------

C-Programm zur Verwaltung von Binärbäumen
Dieses C-Programm implementiert einen umfassenden Satz von Funktionalitäten zur Verwaltung und Bearbeitung von Binärbäumen. Das System ermöglicht die Arbeit mit zwei Haupttypen von Bäumen: Horizontal geordneten Binären Suchbäumen (BSTs) und Allgemeinen Binärbäumen.

Das Projekt verwendet für viele Operationen einen rekursiven Ansatz und bietet ein Menü über die Kommandozeile für eine einfache Interaktion.

Hauptmerkmale
Knotenerstellung: Funktion zur dynamischen Zuweisung und Initialisierung eines neuen Baumknotens.

Einfügen (Insertion):

BST: Fügt einen Knoten ein, wobei die BST-Eigenschaft beibehalten wird (kleinere Werte links, größere rechts).

Allgemeiner Baum: Ermöglicht willkürliches Einfügen (links oder rechts) basierend auf der Benutzerwahl.

Durchlaufen & Anzeige (Traversal & Display):

Pre-Order-Durchlauf (NLR): Zeigt Knoten in der Reihenfolge Wurzel, Links, Rechts an.

In-Order-Durchlauf (LNR): Zeigt Knoten in der Reihenfolge Links, Wurzel, Rechts an (ergibt eine sortierte Reihenfolge für BSTs).

Post-Order-Durchlauf (LRN): Zeigt Knoten in der Reihenfolge Links, Rechts, Wurzel an.

Schematische Anzeige: Visuelle Darstellung des Baumes (um 90 Grad gedreht).

Blattknoten-Anzeige: Listet alle Blattknoten auf.

Metriken:

Größe (Size): Berechnet die Gesamtzahl der Knoten im Baum.

Höhe (Height): Berechnet die maximale Höhe/Tiefe des Baumes.

Wertsuche: Findet den minimalen und maximalen Knotenwert.

Suche (Search): Prüft auf die Existenz eines bestimmten Wertes.

Löschung (Deletion):

BST: Implementiert die Standard-BST-Löschung, einschließlich der Verwendung des Minimums aus dem rechten Teilbaum für Knoten mit zwei Kindern.

Allgemeiner Baum: Löscht einen Knoten, indem er durch ein Blatt aus dem linken Teilbaum ersetzt wird.

Baum leeren: Funktionen zum vollständigen Freigeben aller Knoten für BSTs und allgemeine Bäume.

