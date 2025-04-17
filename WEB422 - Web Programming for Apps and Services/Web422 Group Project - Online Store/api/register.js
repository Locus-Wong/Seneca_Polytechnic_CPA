/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/ 
const userService = require('../server/userDbService');
const bcrypt = require('bcryptjs');

const registerUser = async function (userData) {
	await userService.connect(); // Connect to the database
	return new Promise(function (resolve, reject) {
		bcrypt
			.hash(userData.password, 10)
			.then((hash) => {
				// Hash the password using a Salt that was generated using 10 rounds
				userData.password = hash;

				let newUser = new userService.User(userData);

				newUser
					.save()
					.then((savedUser) => {
						resolve(savedUser);
					})
					.catch((err) => {
						if (err.code == 11000) {
							// error code 11000 indicates a duplicate key error
							reject('User Name already taken');
						} else {
							reject('There was an error creating the user: ' + err);
						}
					});
			})
			.catch((err) => reject(err));
	});
};

module.exports = async (req, res) => {
	if (req.method !== 'POST') {
		return res.status(405).json({ message: 'Method Not Allowed' });
	}

	registerUser(req.body)
		.then((msg) => {
			res.json({ message: msg });
		})
		.catch((msg) => {
			res.status(422).json({ message: msg });
		});
};
