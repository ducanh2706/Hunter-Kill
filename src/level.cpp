#include "../library/level.h"

Level::Level() {
    numMaps = 8;
    maps.resize(8);
    maps = {
        Rectangle(1, 2, 8, 12),
        Rectangle(4, 13, 5, 19),
        Rectangle(1, 20, 12, 22),
        Rectangle(9, 7, 16, 10),
        Rectangle(17, 2, 30, 10),
        Rectangle(31, 7, 38, 10),
        Rectangle(27, 11, 28, 17),
        Rectangle(20, 18, 38, 22)
    };

    numOfEnemies.resize(8);
    numOfEnemies = {2, 2, 2, 0, 2, 2, 0, 2};

    obstacles = {
        Rectangle(2, 3, 2, 3),
        Rectangle(3, 3, 3, 3),
        Rectangle(4, 3, 4, 3),
        Rectangle(5, 3, 5, 3),
        Rectangle(18, 3, 18, 3),
        Rectangle(29, 3, 29, 3),
        Rectangle(2, 4, 2, 4),
        Rectangle(3, 4, 3, 4),
        Rectangle(4, 4, 4, 4),
        Rectangle(5, 4, 5, 4),
        Rectangle(18, 4, 18, 4),
        Rectangle(29, 4, 29, 4),
        Rectangle(2, 5, 2, 5),
        Rectangle(3, 5, 3, 5),
        Rectangle(4, 5, 4, 5),
        Rectangle(5, 5, 5, 5),
        Rectangle(18, 5, 18, 5),
        Rectangle(19, 5, 19, 5),
        Rectangle(20, 5, 20, 5),
        Rectangle(21, 5, 21, 5),
        Rectangle(22, 5, 22, 5),
        Rectangle(25, 5, 25, 5),
        Rectangle(26, 5, 26, 5),
        Rectangle(27, 5, 27, 5),
        Rectangle(28, 5, 28, 5),
        Rectangle(29, 5, 29, 5),
        Rectangle(5, 8, 5, 8),
        Rectangle(11, 8, 11, 8),
        Rectangle(12, 8, 12, 8),
        Rectangle(23, 8, 23, 8),
        Rectangle(24, 8, 24, 8),
        Rectangle(36, 8, 36, 8),
        Rectangle(37, 8, 37, 8),
        Rectangle(5, 9, 5, 9),
        Rectangle(11, 9, 11, 9),
        Rectangle(12, 9, 12, 9),
        Rectangle(23, 9, 23, 9),
        Rectangle(24, 9, 24, 9),
        Rectangle(36, 9, 36, 9),
        Rectangle(37, 9, 37, 9),
        Rectangle(2, 10, 2, 10),
        Rectangle(3, 10, 3, 10),
        Rectangle(4, 10, 4, 10),
        Rectangle(5, 10, 5, 10),
        Rectangle(21, 19, 21, 19),
        Rectangle(22, 19, 22, 19),
        Rectangle(23, 19, 23, 19),
        Rectangle(24, 19, 24, 19),
        Rectangle(25, 19, 25, 19),
        Rectangle(26, 19, 26, 19),
        Rectangle(27, 19, 27, 19),
        Rectangle(31, 19, 31, 19),
        Rectangle(32, 19, 32, 19),
        Rectangle(33, 19, 33, 19),
        Rectangle(34, 19, 34, 19),
        Rectangle(35, 19, 35, 19),
        Rectangle(36, 19, 36, 19),
        Rectangle(37, 19, 37, 19),
        Rectangle(27, 20, 27, 20),
        Rectangle(31, 20, 31, 20),
        Rectangle(2, 21, 2, 21),
        Rectangle(3, 21, 3, 21),
        Rectangle(10, 21, 10, 21),
        Rectangle(11, 21, 11, 21),
        Rectangle(27, 21, 27, 21),
        Rectangle(31, 21, 31, 21),
        Rectangle(0, 0, 0, 0),
        Rectangle(1, 0, 1, 0),
        Rectangle(2, 0, 2, 0),
        Rectangle(3, 0, 3, 0),
        Rectangle(4, 0, 4, 0),
        Rectangle(5, 0, 5, 0),
        Rectangle(6, 0, 6, 0),
        Rectangle(7, 0, 7, 0),
        Rectangle(8, 0, 8, 0),
        Rectangle(9, 0, 9, 0),
        Rectangle(16, 0, 16, 0),
        Rectangle(17, 0, 17, 0),
        Rectangle(18, 0, 18, 0),
        Rectangle(19, 0, 19, 0),
        Rectangle(20, 0, 20, 0),
        Rectangle(21, 0, 21, 0),
        Rectangle(22, 0, 22, 0),
        Rectangle(23, 0, 23, 0),
        Rectangle(24, 0, 24, 0),
        Rectangle(25, 0, 25, 0),
        Rectangle(26, 0, 26, 0),
        Rectangle(27, 0, 27, 0),
        Rectangle(28, 0, 28, 0),
        Rectangle(29, 0, 29, 0),
        Rectangle(30, 0, 30, 0),
        Rectangle(31, 0, 31, 0),
        Rectangle(0, 1, 0, 1),
        Rectangle(1, 1, 1, 1),
        Rectangle(2, 1, 2, 1),
        Rectangle(3, 1, 3, 1),
        Rectangle(4, 1, 4, 1),
        Rectangle(5, 1, 5, 1),
        Rectangle(6, 1, 6, 1),
        Rectangle(7, 1, 7, 1),
        Rectangle(8, 1, 8, 1),
        Rectangle(9, 1, 9, 1),
        Rectangle(16, 1, 16, 1),
        Rectangle(17, 1, 17, 1),
        Rectangle(18, 1, 18, 1),
        Rectangle(19, 1, 19, 1),
        Rectangle(20, 1, 20, 1),
        Rectangle(21, 1, 21, 1),
        Rectangle(22, 1, 22, 1),
        Rectangle(23, 1, 23, 1),
        Rectangle(24, 1, 24, 1),
        Rectangle(25, 1, 25, 1),
        Rectangle(26, 1, 26, 1),
        Rectangle(27, 1, 27, 1),
        Rectangle(28, 1, 28, 1),
        Rectangle(29, 1, 29, 1),
        Rectangle(30, 1, 30, 1),
        Rectangle(31, 1, 31, 1),
        Rectangle(0, 2, 0, 2),
        Rectangle(9, 2, 9, 2),
        Rectangle(16, 2, 16, 2),
        Rectangle(31, 2, 31, 2),
        Rectangle(0, 3, 0, 3),
        Rectangle(9, 3, 9, 3),
        Rectangle(16, 3, 16, 3),
        Rectangle(31, 3, 31, 3),
        Rectangle(0, 4, 0, 4),
        Rectangle(9, 4, 9, 4),
        Rectangle(16, 4, 16, 4),
        Rectangle(31, 4, 31, 4),
        Rectangle(0, 5, 0, 5),
        Rectangle(9, 5, 9, 5),
        Rectangle(10, 5, 10, 5),
        Rectangle(11, 5, 11, 5),
        Rectangle(12, 5, 12, 5),
        Rectangle(13, 5, 13, 5),
        Rectangle(14, 5, 14, 5),
        Rectangle(15, 5, 15, 5),
        Rectangle(16, 5, 16, 5),
        Rectangle(31, 5, 31, 5),
        Rectangle(32, 5, 32, 5),
        Rectangle(33, 5, 33, 5),
        Rectangle(34, 5, 34, 5),
        Rectangle(35, 5, 35, 5),
        Rectangle(36, 5, 36, 5),
        Rectangle(37, 5, 37, 5),
        Rectangle(38, 5, 38, 5),
        Rectangle(39, 5, 39, 5),
        Rectangle(0, 6, 0, 6),
        Rectangle(9, 6, 9, 6),
        Rectangle(10, 6, 10, 6),
        Rectangle(11, 6, 11, 6),
        Rectangle(12, 6, 12, 6),
        Rectangle(13, 6, 13, 6),
        Rectangle(14, 6, 14, 6),
        Rectangle(15, 6, 15, 6),
        Rectangle(16, 6, 16, 6),
        Rectangle(31, 6, 31, 6),
        Rectangle(32, 6, 32, 6),
        Rectangle(33, 6, 33, 6),
        Rectangle(34, 6, 34, 6),
        Rectangle(35, 6, 35, 6),
        Rectangle(36, 6, 36, 6),
        Rectangle(37, 6, 37, 6),
        Rectangle(38, 6, 38, 6),
        Rectangle(39, 6, 39, 6),
        Rectangle(0, 7, 0, 7),
        Rectangle(39, 7, 39, 7),
        Rectangle(0, 8, 0, 8),
        Rectangle(39, 8, 39, 8),
        Rectangle(0, 9, 0, 9),
        Rectangle(39, 9, 39, 9),
        Rectangle(0, 10, 0, 10),
        Rectangle(39, 10, 39, 10),
        Rectangle(0, 11, 0, 11),
        Rectangle(9, 11, 9, 11),
        Rectangle(10, 11, 10, 11),
        Rectangle(11, 11, 11, 11),
        Rectangle(12, 11, 12, 11),
        Rectangle(13, 11, 13, 11),
        Rectangle(14, 11, 14, 11),
        Rectangle(15, 11, 15, 11),
        Rectangle(16, 11, 16, 11),
        Rectangle(17, 11, 17, 11),
        Rectangle(18, 11, 18, 11),
        Rectangle(19, 11, 19, 11),
        Rectangle(20, 11, 20, 11),
        Rectangle(21, 11, 21, 11),
        Rectangle(22, 11, 22, 11),
        Rectangle(23, 11, 23, 11),
        Rectangle(24, 11, 24, 11),
        Rectangle(25, 11, 25, 11),
        Rectangle(26, 11, 26, 11),
        Rectangle(29, 11, 29, 11),
        Rectangle(30, 11, 30, 11),
        Rectangle(31, 11, 31, 11),
        Rectangle(32, 11, 32, 11),
        Rectangle(33, 11, 33, 11),
        Rectangle(34, 11, 34, 11),
        Rectangle(35, 11, 35, 11),
        Rectangle(36, 11, 36, 11),
        Rectangle(37, 11, 37, 11),
        Rectangle(38, 11, 38, 11),
        Rectangle(39, 11, 39, 11),
        Rectangle(9, 12, 9, 12),
        Rectangle(26, 12, 26, 12),
        Rectangle(29, 12, 29, 12),
        Rectangle(0, 13, 0, 13),
        Rectangle(1, 13, 1, 13),
        Rectangle(2, 13, 2, 13),
        Rectangle(3, 13, 3, 13),
        Rectangle(6, 13, 6, 13),
        Rectangle(7, 13, 7, 13),
        Rectangle(8, 13, 8, 13),
        Rectangle(9, 13, 9, 13),
        Rectangle(26, 13, 26, 13),
        Rectangle(29, 13, 29, 13),
        Rectangle(3, 14, 3, 14),
        Rectangle(6, 14, 6, 14),
        Rectangle(26, 14, 26, 14),
        Rectangle(29, 14, 29, 14),
        Rectangle(3, 15, 3, 15),
        Rectangle(6, 15, 6, 15),
        Rectangle(26, 15, 26, 15),
        Rectangle(29, 15, 29, 15),
        Rectangle(3, 16, 3, 16),
        Rectangle(6, 16, 6, 16),
        Rectangle(19, 16, 19, 16),
        Rectangle(20, 16, 20, 16),
        Rectangle(21, 16, 21, 16),
        Rectangle(22, 16, 22, 16),
        Rectangle(23, 16, 23, 16),
        Rectangle(24, 16, 24, 16),
        Rectangle(25, 16, 25, 16),
        Rectangle(26, 16, 26, 16),
        Rectangle(29, 16, 29, 16),
        Rectangle(30, 16, 30, 16),
        Rectangle(31, 16, 31, 16),
        Rectangle(32, 16, 32, 16),
        Rectangle(33, 16, 33, 16),
        Rectangle(34, 16, 34, 16),
        Rectangle(35, 16, 35, 16),
        Rectangle(36, 16, 36, 16),
        Rectangle(37, 16, 37, 16),
        Rectangle(38, 16, 38, 16),
        Rectangle(39, 16, 39, 16),
        Rectangle(3, 17, 3, 17),
        Rectangle(6, 17, 6, 17),
        Rectangle(19, 17, 19, 17),
        Rectangle(20, 17, 20, 17),
        Rectangle(21, 17, 21, 17),
        Rectangle(22, 17, 22, 17),
        Rectangle(23, 17, 23, 17),
        Rectangle(24, 17, 24, 17),
        Rectangle(25, 17, 25, 17),
        Rectangle(26, 17, 26, 17),
        Rectangle(29, 17, 29, 17),
        Rectangle(30, 17, 30, 17),
        Rectangle(31, 17, 31, 17),
        Rectangle(32, 17, 32, 17),
        Rectangle(33, 17, 33, 17),
        Rectangle(34, 17, 34, 17),
        Rectangle(35, 17, 35, 17),
        Rectangle(36, 17, 36, 17),
        Rectangle(37, 17, 37, 17),
        Rectangle(38, 17, 38, 17),
        Rectangle(39, 17, 39, 17),
        Rectangle(0, 18, 0, 18),
        Rectangle(1, 18, 1, 18),
        Rectangle(2, 18, 2, 18),
        Rectangle(3, 18, 3, 18),
        Rectangle(6, 18, 6, 18),
        Rectangle(7, 18, 7, 18),
        Rectangle(8, 18, 8, 18),
        Rectangle(9, 18, 9, 18),
        Rectangle(10, 18, 10, 18),
        Rectangle(11, 18, 11, 18),
        Rectangle(12, 18, 12, 18),
        Rectangle(13, 18, 13, 18),
        Rectangle(19, 18, 19, 18),
        Rectangle(39, 18, 39, 18),
        Rectangle(0, 19, 0, 19),
        Rectangle(1, 19, 1, 19),
        Rectangle(2, 19, 2, 19),
        Rectangle(3, 19, 3, 19),
        Rectangle(6, 19, 6, 19),
        Rectangle(7, 19, 7, 19),
        Rectangle(8, 19, 8, 19),
        Rectangle(9, 19, 9, 19),
        Rectangle(10, 19, 10, 19),
        Rectangle(11, 19, 11, 19),
        Rectangle(12, 19, 12, 19),
        Rectangle(13, 19, 13, 19),
        Rectangle(19, 19, 19, 19),
        Rectangle(39, 19, 39, 19),
        Rectangle(0, 20, 0, 20),
        Rectangle(13, 20, 13, 20),
        Rectangle(19, 20, 19, 20),
        Rectangle(39, 20, 39, 20),
        Rectangle(0, 21, 0, 21),
        Rectangle(13, 21, 13, 21),
        Rectangle(19, 21, 19, 21),
        Rectangle(39, 21, 39, 21),
        Rectangle(0, 22, 0, 22),
        Rectangle(13, 22, 13, 22),
        Rectangle(39, 22, 39, 22),
        Rectangle(0, 23, 0, 23),
        Rectangle(1, 23, 1, 23),
        Rectangle(2, 23, 2, 23),
        Rectangle(3, 23, 3, 23),
        Rectangle(4, 23, 4, 23),
        Rectangle(5, 23, 5, 23),
        Rectangle(6, 23, 6, 23),
        Rectangle(7, 23, 7, 23),
        Rectangle(8, 23, 8, 23),
        Rectangle(9, 23, 9, 23),
        Rectangle(10, 23, 10, 23),
        Rectangle(11, 23, 11, 23),
        Rectangle(12, 23, 12, 23),
        Rectangle(13, 23, 13, 23),
        Rectangle(19, 23, 19, 23),
        Rectangle(20, 23, 20, 23),
        Rectangle(21, 23, 21, 23),
        Rectangle(22, 23, 22, 23),
        Rectangle(23, 23, 23, 23),
        Rectangle(24, 23, 24, 23),
        Rectangle(25, 23, 25, 23),
        Rectangle(26, 23, 26, 23),
        Rectangle(27, 23, 27, 23),
        Rectangle(28, 23, 28, 23),
        Rectangle(29, 23, 29, 23),
        Rectangle(30, 23, 30, 23),
        Rectangle(31, 23, 31, 23),
        Rectangle(32, 23, 32, 23),
        Rectangle(33, 23, 33, 23),
        Rectangle(34, 23, 34, 23),
        Rectangle(35, 23, 35, 23),
        Rectangle(36, 23, 36, 23),
        Rectangle(37, 23, 37, 23),
        Rectangle(38, 23, 38, 23),
        Rectangle(39, 23, 39, 23),
        Rectangle(10, 0, 10, 0),
        Rectangle(11, 0, 11, 0),
        Rectangle(12, 0, 12, 0),
        Rectangle(13, 0, 13, 0),
        Rectangle(14, 0, 14, 0),
        Rectangle(15, 0, 15, 0),
        Rectangle(32, 0, 32, 0),
        Rectangle(33, 0, 33, 0),
        Rectangle(34, 0, 34, 0),
        Rectangle(35, 0, 35, 0),
        Rectangle(36, 0, 36, 0),
        Rectangle(37, 0, 37, 0),
        Rectangle(38, 0, 38, 0),
        Rectangle(39, 0, 39, 0),
        Rectangle(10, 1, 10, 1),
        Rectangle(11, 1, 11, 1),
        Rectangle(12, 1, 12, 1),
        Rectangle(13, 1, 13, 1),
        Rectangle(14, 1, 14, 1),
        Rectangle(15, 1, 15, 1),
        Rectangle(32, 1, 32, 1),
        Rectangle(33, 1, 33, 1),
        Rectangle(34, 1, 34, 1),
        Rectangle(35, 1, 35, 1),
        Rectangle(36, 1, 36, 1),
        Rectangle(37, 1, 37, 1),
        Rectangle(38, 1, 38, 1),
        Rectangle(39, 1, 39, 1),
        Rectangle(10, 2, 10, 2),
        Rectangle(11, 2, 11, 2),
        Rectangle(12, 2, 12, 2),
        Rectangle(13, 2, 13, 2),
        Rectangle(14, 2, 14, 2),
        Rectangle(15, 2, 15, 2),
        Rectangle(32, 2, 32, 2),
        Rectangle(33, 2, 33, 2),
        Rectangle(34, 2, 34, 2),
        Rectangle(35, 2, 35, 2),
        Rectangle(36, 2, 36, 2),
        Rectangle(37, 2, 37, 2),
        Rectangle(38, 2, 38, 2),
        Rectangle(39, 2, 39, 2),
        Rectangle(10, 3, 10, 3),
        Rectangle(11, 3, 11, 3),
        Rectangle(12, 3, 12, 3),
        Rectangle(13, 3, 13, 3),
        Rectangle(14, 3, 14, 3),
        Rectangle(15, 3, 15, 3),
        Rectangle(32, 3, 32, 3),
        Rectangle(33, 3, 33, 3),
        Rectangle(34, 3, 34, 3),
        Rectangle(35, 3, 35, 3),
        Rectangle(36, 3, 36, 3),
        Rectangle(37, 3, 37, 3),
        Rectangle(38, 3, 38, 3),
        Rectangle(39, 3, 39, 3),
        Rectangle(10, 4, 10, 4),
        Rectangle(11, 4, 11, 4),
        Rectangle(12, 4, 12, 4),
        Rectangle(13, 4, 13, 4),
        Rectangle(14, 4, 14, 4),
        Rectangle(15, 4, 15, 4),
        Rectangle(32, 4, 32, 4),
        Rectangle(33, 4, 33, 4),
        Rectangle(34, 4, 34, 4),
        Rectangle(35, 4, 35, 4),
        Rectangle(36, 4, 36, 4),
        Rectangle(37, 4, 37, 4),
        Rectangle(38, 4, 38, 4),
        Rectangle(39, 4, 39, 4),
        Rectangle(10, 12, 10, 12),
        Rectangle(11, 12, 11, 12),
        Rectangle(12, 12, 12, 12),
        Rectangle(13, 12, 13, 12),
        Rectangle(14, 12, 14, 12),
        Rectangle(15, 12, 15, 12),
        Rectangle(16, 12, 16, 12),
        Rectangle(17, 12, 17, 12),
        Rectangle(18, 12, 18, 12),
        Rectangle(19, 12, 19, 12),
        Rectangle(20, 12, 20, 12),
        Rectangle(21, 12, 21, 12),
        Rectangle(22, 12, 22, 12),
        Rectangle(23, 12, 23, 12),
        Rectangle(24, 12, 24, 12),
        Rectangle(25, 12, 25, 12),
        Rectangle(30, 12, 30, 12),
        Rectangle(31, 12, 31, 12),
        Rectangle(32, 12, 32, 12),
        Rectangle(33, 12, 33, 12),
        Rectangle(34, 12, 34, 12),
        Rectangle(35, 12, 35, 12),
        Rectangle(36, 12, 36, 12),
        Rectangle(37, 12, 37, 12),
        Rectangle(38, 12, 38, 12),
        Rectangle(39, 12, 39, 12),
        Rectangle(10, 13, 10, 13),
        Rectangle(11, 13, 11, 13),
        Rectangle(12, 13, 12, 13),
        Rectangle(13, 13, 13, 13),
        Rectangle(14, 13, 14, 13),
        Rectangle(15, 13, 15, 13),
        Rectangle(16, 13, 16, 13),
        Rectangle(17, 13, 17, 13),
        Rectangle(18, 13, 18, 13),
        Rectangle(19, 13, 19, 13),
        Rectangle(20, 13, 20, 13),
        Rectangle(21, 13, 21, 13),
        Rectangle(22, 13, 22, 13),
        Rectangle(23, 13, 23, 13),
        Rectangle(24, 13, 24, 13),
        Rectangle(25, 13, 25, 13),
        Rectangle(30, 13, 30, 13),
        Rectangle(31, 13, 31, 13),
        Rectangle(32, 13, 32, 13),
        Rectangle(33, 13, 33, 13),
        Rectangle(34, 13, 34, 13),
        Rectangle(35, 13, 35, 13),
        Rectangle(36, 13, 36, 13),
        Rectangle(37, 13, 37, 13),
        Rectangle(38, 13, 38, 13),
        Rectangle(39, 13, 39, 13),
        Rectangle(0, 14, 0, 14),
        Rectangle(1, 14, 1, 14),
        Rectangle(2, 14, 2, 14),
        Rectangle(7, 14, 7, 14),
        Rectangle(8, 14, 8, 14),
        Rectangle(9, 14, 9, 14),
        Rectangle(10, 14, 10, 14),
        Rectangle(11, 14, 11, 14),
        Rectangle(12, 14, 12, 14),
        Rectangle(13, 14, 13, 14),
        Rectangle(14, 14, 14, 14),
        Rectangle(15, 14, 15, 14),
        Rectangle(16, 14, 16, 14),
        Rectangle(17, 14, 17, 14),
        Rectangle(18, 14, 18, 14),
        Rectangle(19, 14, 19, 14),
        Rectangle(20, 14, 20, 14),
        Rectangle(21, 14, 21, 14),
        Rectangle(22, 14, 22, 14),
        Rectangle(23, 14, 23, 14),
        Rectangle(24, 14, 24, 14),
        Rectangle(25, 14, 25, 14),
        Rectangle(30, 14, 30, 14),
        Rectangle(31, 14, 31, 14),
        Rectangle(32, 14, 32, 14),
        Rectangle(33, 14, 33, 14),
        Rectangle(34, 14, 34, 14),
        Rectangle(35, 14, 35, 14),
        Rectangle(36, 14, 36, 14),
        Rectangle(37, 14, 37, 14),
        Rectangle(38, 14, 38, 14),
        Rectangle(39, 14, 39, 14),
        Rectangle(0, 15, 0, 15),
        Rectangle(1, 15, 1, 15),
        Rectangle(2, 15, 2, 15),
        Rectangle(7, 15, 7, 15),
        Rectangle(8, 15, 8, 15),
        Rectangle(9, 15, 9, 15),
        Rectangle(10, 15, 10, 15),
        Rectangle(11, 15, 11, 15),
        Rectangle(12, 15, 12, 15),
        Rectangle(13, 15, 13, 15),
        Rectangle(14, 15, 14, 15),
        Rectangle(15, 15, 15, 15),
        Rectangle(16, 15, 16, 15),
        Rectangle(17, 15, 17, 15),
        Rectangle(18, 15, 18, 15),
        Rectangle(19, 15, 19, 15),
        Rectangle(20, 15, 20, 15),
        Rectangle(21, 15, 21, 15),
        Rectangle(22, 15, 22, 15),
        Rectangle(23, 15, 23, 15),
        Rectangle(24, 15, 24, 15),
        Rectangle(25, 15, 25, 15),
        Rectangle(30, 15, 30, 15),
        Rectangle(31, 15, 31, 15),
        Rectangle(32, 15, 32, 15),
        Rectangle(33, 15, 33, 15),
        Rectangle(34, 15, 34, 15),
        Rectangle(35, 15, 35, 15),
        Rectangle(36, 15, 36, 15),
        Rectangle(37, 15, 37, 15),
        Rectangle(38, 15, 38, 15),
        Rectangle(39, 15, 39, 15),
        Rectangle(0, 16, 0, 16),
        Rectangle(1, 16, 1, 16),
        Rectangle(2, 16, 2, 16),
        Rectangle(7, 16, 7, 16),
        Rectangle(8, 16, 8, 16),
        Rectangle(9, 16, 9, 16),
        Rectangle(10, 16, 10, 16),
        Rectangle(11, 16, 11, 16),
        Rectangle(12, 16, 12, 16),
        Rectangle(13, 16, 13, 16),
        Rectangle(14, 16, 14, 16),
        Rectangle(15, 16, 15, 16),
        Rectangle(16, 16, 16, 16),
        Rectangle(17, 16, 17, 16),
        Rectangle(18, 16, 18, 16),
        Rectangle(0, 17, 0, 17),
        Rectangle(1, 17, 1, 17),
        Rectangle(2, 17, 2, 17),
        Rectangle(7, 17, 7, 17),
        Rectangle(8, 17, 8, 17),
        Rectangle(9, 17, 9, 17),
        Rectangle(10, 17, 10, 17),
        Rectangle(11, 17, 11, 17),
        Rectangle(12, 17, 12, 17),
        Rectangle(13, 17, 13, 17),
        Rectangle(14, 17, 14, 17),
        Rectangle(15, 17, 15, 17),
        Rectangle(16, 17, 16, 17),
        Rectangle(17, 17, 17, 17),
        Rectangle(18, 17, 18, 17),
        Rectangle(14, 18, 14, 18),
        Rectangle(15, 18, 15, 18),
        Rectangle(16, 18, 16, 18),
        Rectangle(17, 18, 17, 18),
        Rectangle(18, 18, 18, 18),
        Rectangle(14, 19, 14, 19),
        Rectangle(15, 19, 15, 19),
        Rectangle(16, 19, 16, 19),
        Rectangle(17, 19, 17, 19),
        Rectangle(18, 19, 18, 19),
        Rectangle(14, 20, 14, 20),
        Rectangle(15, 20, 15, 20),
        Rectangle(16, 20, 16, 20),
        Rectangle(17, 20, 17, 20),
        Rectangle(18, 20, 18, 20),
        Rectangle(14, 21, 14, 21),
        Rectangle(15, 21, 15, 21),
        Rectangle(16, 21, 16, 21),
        Rectangle(17, 21, 17, 21),
        Rectangle(18, 21, 18, 21),
        Rectangle(14, 22, 14, 22),
        Rectangle(15, 22, 15, 22),
        Rectangle(16, 22, 16, 22),
        Rectangle(17, 22, 17, 22),
        Rectangle(18, 22, 18, 22),
        Rectangle(14, 23, 14, 23),
        Rectangle(15, 23, 15, 23),
        Rectangle(16, 23, 16, 23),
        Rectangle(17, 23, 17, 23),
        Rectangle(18, 23, 18, 23),
    };
}

Level::Level(int _numMaps, vector<Rectangle> _maps, vector<Rectangle> _obstacles, vector<int> _numOfEnemies, int _enemyShootingRange) {
    numMaps = _numMaps;
    maps = _maps;
    obstacles = _obstacles;
    numOfEnemies = _numOfEnemies;
    enemyShootingRange = _enemyShootingRange;
}

