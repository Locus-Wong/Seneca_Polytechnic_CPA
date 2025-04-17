/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/ 
import { getToken } from 'lib/authClient';

export async function updateFavourite(favourites) {
	const token = getToken();
	const response = await fetch(`/api/user/updateFavourite`, {
		method: 'PUT',
		headers: {
			'Content-Type': 'application/json',
			Authorization: `jwt ${token}`,
		},
		body: JSON.stringify({ favourites }),
	});

	if (!response.ok) {
		throw new Error('Failed to update favourites');
	}

	return await response.json();
}

export async function getFavourites() {
	const token = getToken();
	const response = await fetch(`/api/user/getFavourites`, {
		method: 'GET',
		headers: {
			'Content-Type': 'application/json',
			Authorization: `jwt ${token}`,
		},
	});

	if (!response.ok) {
		throw new Error('Failed to fetch favourites');
	}

	return await response.json();
}

export async function getHistory() {
	const token = getToken();
	const response = await fetch(`/api/user/getHistory`, {
		method: 'GET',
		headers: {
			'Content-Type': 'application/json',
			Authorization: `jwt ${token}`,
		},
	});

	if (!response.ok) {
		throw new Error('Failed to fetch search history');
	}

	return await response.json();
}

export async function updateHistory(query) {
	const token = getToken();
	const response = await fetch(`/api/user/updateHistory`, {
		method: 'PUT',
		headers: {
			'Content-Type': 'application/json',
			Authorization: `jwt ${token}`,
		},
		body: JSON.stringify({ query }),
	});

	if (!response.ok) {
		throw new Error('Failed to update search history');
	}

	return await response.json();
}

export async function deleteHistory(historyId) {
	const token = getToken();
	const response = await fetch(`/api/user/deleteHistory`, {
		method: 'DELETE',
		headers: {
			'Content-Type': 'application/json',
			Authorization: `jwt ${token}`,
		},
		body: JSON.stringify({ historyId }),
	});

	if (!response.ok) {
		throw new Error('Failed to delete search history entry');
	}

	return await response.json();
}
