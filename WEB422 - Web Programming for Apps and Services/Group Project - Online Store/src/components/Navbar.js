/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
import { faMagnifyingGlass, faCircleUser } from '@fortawesome/free-solid-svg-icons';
import Link from 'next/link';
import { useAtom } from 'jotai';
import { categoriesAtom, favouritesAtom, pageAtom, searchHistoryAtom } from '@/atoms/atoms';
import { removeToken, isAuthenticated, readToken } from 'lib/authClient';
import { useState, useEffect } from 'react';
import { useRouter } from 'next/router';
import { updateHistory } from '../lib/userService';

export default function Navbar() {
	const [categories] = useAtom(categoriesAtom);
	const [, setFavourites] = useAtom(favouritesAtom);
	const [, setPage] = useAtom(pageAtom);
	const [searchQuery, setSearchQuery] = useState('');
	const router = useRouter();
	const [, setSearchHistory] = useAtom(searchHistoryAtom);

	const [mounted, setMounted] = useState(false);
	useEffect(() => {
		setMounted(true);
	}, []);

	async function logout() {
		removeToken();
		setFavourites([]);
		setSearchHistory([]);
		setPage(0);
	}

	function handleCategoryClick() {
		setPage(0);
	}

	const handleSearch = async (e) => {
		e.preventDefault();
		if (searchQuery.trim()) {
			if (mounted && isAuthenticated()) {
				try {
					const tokenData = readToken();
					if (tokenData && tokenData._id) {
						await updateHistory(searchQuery);
					}
				} catch (error) {
					console.error('Failed to update search history:', error);
				}
			}
			setPage(0);
			router.push(`/?q=${encodeURIComponent(searchQuery)}`);
		}
	};

	if (!mounted) {
		return null;
	}

	return (
		<nav
			className='navbar navbar-expand-lg navbar-dark bg-dark'
			role='navigation'>
			<div className='container-fluid py-2 px-4'>
				<Link
					className='navbar-brand'
					href='/'>
					Website Logo
				</Link>
				<button
					className='navbar-toggler'
					type='button'
					data-bs-toggle='collapse'
					data-bs-target='#navbarSupportedContent'
					aria-controls='navbarSupportedContent'
					aria-expanded='false'
					aria-label='Toggle navigation'>
					<span className='navbar-toggler-icon'></span>
				</button>
				<div
					className='collapse navbar-collapse justify-content-between'
					id='navbarSupportedContent'>
					<ul className='navbar-nav'>
						<li className='nav-item'>
							<Link
								className='nav-link'
								href='/'>
								Dashboard
							</Link>
						</li>
						<li className='nav-item dropdown'>
							<Link
								className='nav-link dropdown-toggle'
								href='#'
								id='navbarDropdown'
								role='button'
								data-bs-toggle='dropdown'
								aria-expanded='false'>
								Categories
							</Link>
							<ul className='dropdown-menu'>
								{categories && categories.length > 0 ? (
									categories.map((item) => (
										<li key={item.id}>
											<Link
												className='dropdown-item'
												href={`/categories/${item.id}`}
												onClick={handleCategoryClick}>
												{item.name}
											</Link>
										</li>
									))
								) : (
									<span>Loading...</span>
								)}
							</ul>
						</li>
						<li className='nav-item'>
							<Link
								className='nav-link'
								href='/about'>
								About
							</Link>
						</li>
						<li className='nav-item'>
							<Link
								className='nav-link'
								href='/contact'>
								Contact Us
							</Link>
						</li>
					</ul>
					<ul className='navbar-nav align-items-center'>
						<form
							className='d-flex'
							onSubmit={handleSearch}>
							<input
								className='form-control-sm rounded-pill px-3 input-field'
								style={{ width: '300px' }}
								type='search'
								placeholder='Search'
								aria-label='Search'
								value={searchQuery}
								onChange={(e) => setSearchQuery(e.target.value)}
							/>
							<button
								className='btn'
								type='submit'>
								<FontAwesomeIcon
									icon={faMagnifyingGlass}
									size='lg'
									inverse
								/>
							</button>
						</form>
						<li className='nav-item dropdown'>
							<Link
								className='nav-link dropdown-toggle'
								href='#'
								id='navbarDropdown'
								role='button'
								data-bs-toggle='dropdown'
								aria-expanded='false'>
								<FontAwesomeIcon
									icon={faCircleUser}
									size='2xl'
								/>
							</Link>
							<ul className='dropdown-menu dropdown-menu-end'>
								{isAuthenticated() ? (
									<>
										<li>
											<Link
												className='dropdown-item'
												href='/favourite'>
												Favourites
											</Link>
										</li>
										<li>
											<Link
												className='dropdown-item'
												href='/history'>
												Search History
											</Link>
										</li>
										<li>
											<a
												className='dropdown-item'
												href='/'
												onClick={logout}>
												Logout
											</a>
										</li>
									</>
								) : (
									<>
										<li>
											<Link
												className='dropdown-item'
												href='/login'>
												My account
											</Link>
										</li>
									</>
								)}
							</ul>
						</li>
					</ul>
				</div>
			</div>
		</nav>
	);
}
