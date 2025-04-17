/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/ 
const userService = require('../server/userDbService');
const jwt = require('jsonwebtoken');
const { SECRET_OR_KEY } = require('../server/authMiddleware');
const bcrypt = require('bcryptjs');

const checkUser = async function (userData) {
	await userService.connect(); // Connect to the database
	return new Promise(function (resolve, reject) {
		userService.User.find({ email: userData.userName })
			.limit(1)
			.exec()
			.then((users) => {
				if (users.length == 0) {
					reject('Unable to find user ' + userData.userName);
				} else {
					bcrypt.compare(userData.password, users[0].password).then((res) => {
						if (res === true) {
							resolve(users[0]);
						} else {
							reject('Incorrect password for user ' + userData.userName);
						}
					});
				}
			})
			.catch((err) => {
				reject('Unable to find user ' + userData.userName);
			});
	});
};

module.exports = async (req, res) => {
	if (req.method !== 'POST') {
		return res.status(405).json({ message: 'Method Not Allowed' });
	}

	checkUser(req.body)
		.then((user) => {
			let payload = {
				_id: user._id,
				userName: user.userName,
				email: user.email,
			};
			// Add expiration time to the token
			let token = jwt.sign(payload, SECRET_OR_KEY, { expiresIn: '1h' });
			res.json({ message: 'login successful', token: token });
		})
		.catch((msg) => {
			res.status(422).json({ message: msg });
		});
};
