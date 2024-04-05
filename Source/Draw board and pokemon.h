#pragma once
#include "Lib.h"

// The functions change the color of the text and boxes of the cards to make identifying the cards easier
void set_color(int code);
void repColor(char c);
void repBoard(char** a, int m, int n, int px, int py, int x1, int y1, int x2, int y2);
void repBoardHidden(char** a, int m, int n, int px, int py, int x1, int y1, int x2, int y2);

// Function to draw Pokemon
void print_pokemon(int n_pokemon);

//print(("                              ,-'   ,\"\",\n"))
//print(("                             / / ,-'.-'\n"))
//print(("                   _,..-----+-\".\".-'_,..\n"))
//print(("           ,...,.\"'             `--.---'\n"))
//print(("         /,..,'                     `.\n"))
//print(("       ,'  .'                         `.\n"))
//print(("      j   /                             `.\n"))
//print(("      |  /,----._           ,.----.       .\n"))
//print(("     ,  j    _   \\        .'  .,   `.     |\n"))
//print(("   ,'   |        |  ____  |         | .\"--+,^.\n"))
//print(("  /     |`-....-',-'    `._`--....-' _/      |\n"))
//print((" /      |     _,'          `--..__  `        '\n"))
//print(("j       | ,-\"'    `    .'         `. `        `.\n"))
//print(("|        .\\                        /  |         \\\n"))
//print(("|         `\\                     ,'   |          \\\n"))
//print(("|          |                    |   ,-|           `.\n"))
//print((".         ,'                    |-\"'  |             \\\n"))
//print((" \\       /                      `.    |              .\n"))
//print(("  ` /  ,'                        |    `              |\n"))
//print(("   /  /                          |     \\             |\n"))
//print(("  /  |                           |      \\           /\n"))
//print((" /   |                           |       `.       _,\n"))
//print((".     .                         .'         `.__,.',.----,\n"))
//print(("|      `.                     ,'             .-\"\"      /\n"))
//print(("|        `._               _.'               |        /\n"))
//print(("|           `---.......,--\"                  |      ,'\n"))
//print(("'                                            '    ,'\n"))
//print((" \\                                          /   ,'\n"))
//print(("  \\                                        /  ,'\n"))
//print(("   \\                                      / ,'\n"))
//print(("    `.                                   ,+'\n"))
//print(("      >.                               ,'\n"))
//print(("  _.-'  `-.._                      _,-'-._\n"))
//print((",__          `\",-............,.---\"       `.\n"))
//print(("   \\..---. _,-'            ,'               `.\n"))
//print(("          \"                '..,--.___,-\"\"\"---' mh\n"))