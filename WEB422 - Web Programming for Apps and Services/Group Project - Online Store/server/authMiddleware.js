/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/ 
const passport = require('passport');
const passportJWT = require('passport-jwt');
const dotenv = require('dotenv');
dotenv.config();

// JWT Setup
const ExtractJwt = passportJWT.ExtractJwt;
const JwtStrategy = passportJWT.Strategy;

const SECRET_OR_KEY = process.env.JWT_SECRET || 'web422_group9_default_secret_key';

// Configure jwt options
const jwtOptions = {
	jwtFromRequest: ExtractJwt.fromAuthHeaderWithScheme('jwt'),
	secretOrKey: SECRET_OR_KEY,
};

// Define JWT strategy
const strategy = new JwtStrategy(jwtOptions, function (jwt_payload, next) {
	if (jwt_payload) {
		next(null, {
			_id: jwt_payload._id,
			userName: jwt_payload.userName,
			email: jwt_payload.email,
		});
	} else {
		next(null, false);
	}
});

// Initialize passport with JWT strategy
passport.use(strategy);

// Authentication middleware
const authenticate = passport.authenticate('jwt', { session: false });

// Export things needed by other modules
module.exports = {
	passport,
	jwtOptions,
	authenticate,
	SECRET_OR_KEY,
};
