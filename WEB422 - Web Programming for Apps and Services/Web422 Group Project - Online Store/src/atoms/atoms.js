/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/ 
import { atom } from 'jotai';
import { atomWithStorage } from 'jotai/utils';
const productsAtom = atom(null);
const categoriesAtom = atom(null);
const pageAtom = atom(0);
const favouritesAtom = atomWithStorage('favourites', []);
const searchHistoryAtom = atomWithStorage('searchHistory', []);

export { productsAtom, categoriesAtom, pageAtom, favouritesAtom, searchHistoryAtom };
