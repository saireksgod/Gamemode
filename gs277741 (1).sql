-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Хост: localhost
-- Время создания: Ноя 27 2024 г., 17:22
-- Версия сервера: 10.3.31-MariaDB-0+deb10u1
-- Версия PHP: 7.3.31-1~deb10u1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `gs277741`
--

-- --------------------------------------------------------

--
-- Структура таблицы `hardware_bans`
--

CREATE TABLE `hardware_bans` (
  `id` int(11) NOT NULL,
  `uid` int(11) NOT NULL DEFAULT -1,
  `hardware_id` varchar(250) NOT NULL,
  `type` int(11) NOT NULL DEFAULT -1,
  `reason` varchar(32) NOT NULL DEFAULT 'Нет'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Структура таблицы `houses`
--

CREATE TABLE `houses` (
  `id` int(11) NOT NULL,
  `price` int(11) NOT NULL,
  `owner_id` int(11) NOT NULL DEFAULT -1,
  `owner_name` varchar(32) NOT NULL,
  `improvements` int(11) NOT NULL,
  `rent_date` int(11) NOT NULL,
  `rent_price` int(11) NOT NULL,
  `lock` int(11) NOT NULL,
  `type` int(11) NOT NULL,
  `pos` varchar(64) NOT NULL,
  `exit_pos` varchar(64) NOT NULL,
  `lives` varchar(8) NOT NULL DEFAULT '-1,-1,-1',
  `closet_pos` varchar(16) NOT NULL DEFAULT '0.0,0.0,0.0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `houses`
--

INSERT INTO `houses` (`id`, `price`, `owner_id`, `owner_name`, `improvements`, `rent_date`, `rent_price`, `lock`, `type`, `pos`, `exit_pos`, `lives`, `closet_pos`) VALUES
(1, 123, 6, 'Tema_Kovalev', 4, 0, 500, 0, 1, '-2476.3105,2819.6809,37.6340', '-2474.2856,2815.0244,37.4386,193.545', '-1,-1,-1', '0.0,0.0,0.0');

-- --------------------------------------------------------

--
-- Структура таблицы `items`
--

CREATE TABLE `items` (
  `id` int(11) NOT NULL,
  `uid` int(11) NOT NULL DEFAULT -1,
  `container` int(11) NOT NULL DEFAULT 1,
  `SLOT1` varchar(240) NOT NULL DEFAULT '-1;-1;0;0;0;None;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0',
  `SLOT2` varchar(240) NOT NULL DEFAULT '-1;-1;0;0;0;None;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0',
  `SLOT3` varchar(240) NOT NULL DEFAULT '-1;-1;0;0;0;None;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0',
  `SLOT4` varchar(240) NOT NULL DEFAULT '-1;-1;0;0;0;None;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0',
  `SLOT5` varchar(240) NOT NULL DEFAULT '-1;-1;0;0;0;None;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0',
  `SLOT6` varchar(240) NOT NULL DEFAULT '-1;-1;0;0;0;None;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0',
  `SLOT7` varchar(240) NOT NULL DEFAULT '-1;-1;0;0;0;None;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0',
  `SLOT8` varchar(240) NOT NULL DEFAULT '-1;-1;0;0;0;None;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0',
  `SLOT9` varchar(240) NOT NULL DEFAULT '-1;-1;0;0;0;None;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0',
  `SLOT10` varchar(240) NOT NULL DEFAULT '-1;-1;0;0;0;None;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0',
  `SLOT11` varchar(240) NOT NULL DEFAULT '-1;-1;0;0;0;None;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0',
  `SLOT12` varchar(240) NOT NULL DEFAULT '-1;-1;0;0;0;None;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0',
  `SLOT13` varchar(240) NOT NULL DEFAULT '-1;-1;0;0;0;None;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0',
  `SLOT14` varchar(240) NOT NULL DEFAULT '-1;-1;0;0;0;None;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0',
  `SLOT15` varchar(240) NOT NULL DEFAULT '-1;-1;0;0;0;None;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0',
  `SLOT16` varchar(240) NOT NULL DEFAULT '-1;-1;0;0;0;None;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0',
  `SLOT17` varchar(240) NOT NULL DEFAULT '-1;-1;0;0;0;None;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0',
  `SLOT18` varchar(240) NOT NULL DEFAULT '-1;-1;0;0;0;None;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0',
  `SLOT19` varchar(240) NOT NULL DEFAULT '-1;-1;0;0;0;None;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0',
  `SLOT20` varchar(240) NOT NULL DEFAULT '-1;-1;0;0;0;None;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Структура таблицы `promocode`
--

CREATE TABLE `promocode` (
  `id` int(11) NOT NULL,
  `type` int(11) NOT NULL,
  `amount` int(11) NOT NULL,
  `usings` int(11) NOT NULL,
  `paydays` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Структура таблицы `promocode_activations`
--

CREATE TABLE `promocode_activations` (
  `id` int(11) NOT NULL,
  `code` varchar(32) NOT NULL,
  `uid` int(11) NOT NULL,
  `paydays` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Структура таблицы `users`
--

CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `Name` varchar(32) NOT NULL,
  `Email` varchar(47) NOT NULL,
  `Pass` varchar(32) NOT NULL,
  `Sex` int(11) NOT NULL,
  `Skin` int(11) NOT NULL,
  `Money` varchar(22) NOT NULL DEFAULT '0',
  `Level` int(11) NOT NULL,
  `EXP` int(11) NOT NULL,
  `admin` int(11) NOT NULL,
  `reg_ip` varchar(16) NOT NULL DEFAULT '127.0.0.1',
  `last_ip` varchar(16) NOT NULL DEFAULT '127.0.0.1',
  `SkinBD` int(11) NOT NULL,
  `Fullness` int(11) NOT NULL,
  `Referal` int(11) NOT NULL,
  `AdminPassword` varchar(32) NOT NULL DEFAULT '-1'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `users`
--

INSERT INTO `users` (`id`, `Name`, `Email`, `Pass`, `Sex`, `Skin`, `Money`, `Level`, `EXP`, `admin`, `reg_ip`, `last_ip`, `SkinBD`, `Fullness`, `Referal`, `AdminPassword`) VALUES
(1, 'Matvey_Rudkov', 'scamer@mail.ru', '123123', 1, 15354, '247893186', 2, 0, 8, '127.0.0.1', '127.0.0.1', 0, 0, 0, '666666'),
(3, 'Matvey_Dev', 'asd@rum.ru', '123123', 1, 15355, '150000000', 2, 0, 8, '46.172.30.39', '46.172.30.39', 0, 0, 1, '123123'),
(5, 'Matvey_Rudkova', 'asd@masdmasd.ru', '123123', 1, 213, '150000000', 2, 0, 8, '46.172.30.39', '46.172.30.39', 0, 0, 0, '-1'),
(6, 'Tema_Kovalev', 'fjfhjfhdjfdjfd@mail.ru', '123123', 1, 15353, '149001000', 2, 0, 8, '', '', 0, 0, 0, '123321');

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `hardware_bans`
--
ALTER TABLE `hardware_bans`
  ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `houses`
--
ALTER TABLE `houses`
  ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `items`
--
ALTER TABLE `items`
  ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `promocode`
--
ALTER TABLE `promocode`
  ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `promocode_activations`
--
ALTER TABLE `promocode_activations`
  ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `hardware_bans`
--
ALTER TABLE `hardware_bans`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT для таблицы `houses`
--
ALTER TABLE `houses`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT для таблицы `items`
--
ALTER TABLE `items`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=22;

--
-- AUTO_INCREMENT для таблицы `promocode`
--
ALTER TABLE `promocode`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT для таблицы `promocode_activations`
--
ALTER TABLE `promocode_activations`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT для таблицы `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
