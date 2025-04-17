/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/ 
import { useRouter } from 'next/router';
import { useState, useEffect } from 'react';
import { isAuthenticated } from '../lib/authClient';

const PUBLIC_PATHS = ['/login', '/register', '/about', '/contact', '/', '/categories/[id]', '/_error'];

export default function RouteGuard({ children }) {
	const router = useRouter();
	const [authorized, setAuthorized] = useState(false);

	useEffect(() => {
		authCheck(router.asPath);

		const handleRouteChange = (url) => {
			authCheck(url);
		};

		router.events.on('routeChangeComplete', handleRouteChange);
		return () => {
			router.events.off('routeChangeComplete', handleRouteChange);
		};
	}, []);

	function authCheck(url) {
		const path = url.split('?')[0];
		const searchQuery = new URLSearchParams(url.split('?')[1] || '').get('q');

		// this allows access if it's on the public path exact or dynamic [id] path
		// or the user is authed
		if (
			(PUBLIC_PATHS.some(
				(publicPath) =>
					path === publicPath || (publicPath.includes('[id]') && path.startsWith(publicPath.replace('/[id]', '/')))
			) &&
				!searchQuery) ||
			isAuthenticated()
		) {
			setAuthorized(true);
		} else {
			setAuthorized(false);
			router.push('/login');
		}
	}

	return <>{authorized && children}</>;
}
