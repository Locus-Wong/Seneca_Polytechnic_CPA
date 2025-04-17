/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/ 
import { jwtDecode } from 'jwt-decode';

function setToken(token) {
	localStorage.setItem('access_token', token);
}

export function getToken() {
	return localStorage.getItem('access_token');
}

export function readToken() {
	try {
		const token = getToken();
		if (!token) return null;

		const decoded = jwtDecode(token);

		// Check if token is expired
		const currentTime = Date.now() / 1000;
		if (decoded.exp && decoded.exp < currentTime) {
			// Token expired, remove it
			removeToken();
			return null;
		}

		return decoded;
	} catch (err) {
		console.error('Error reading token:', err);
		removeToken(); // Remove invalid token
		return null;
	}
}

export function isAuthenticated() {
	const token = readToken();
	return !!token;
}

export function removeToken() {
	localStorage.removeItem('access_token');
}

export async function authenticateUser(user, password) {
	const res = await fetch('/api/login', {
		method: 'POST',
		body: JSON.stringify({ userName: user, password: password }),
		headers: {
			'content-type': 'application/json',
		},
	});

	const data = await res.json();

	if (res.status === 200) {
		setToken(data.token);
		return true;
	} else {
		alert(data.message);
		return false;
	}
}

export async function registerUser(user, password, email) {
	const res = await fetch('/api/register', {
		method: 'POST',
		body: JSON.stringify({ userName: user, password: password, email: email }),
		headers: {
			'content-type': 'application/json',
		},
	});

	const data = await res.json();

	if (res.status === 200) {
		setToken(data.token);
		return true;
	} else {
		alert(data.message);
		return false;
	}
}
