/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/ 
import Navbar from '@/components/Navbar';
import Header from '@/components/Header';
import Footer from '@/components/Footer';
import Link from 'next/link';
import { useAtom } from 'jotai';
import { useEffect } from 'react';
import { pageAtom, searchHistoryAtom } from '@/atoms/atoms';
import { getHistory, deleteHistory } from 'lib/userService';
import { readToken } from 'lib/authClient';

export default function History() {
	const [history, setHistory] = useAtom(searchHistoryAtom);
	const [, setPage] = useAtom(pageAtom);

	useEffect(() => {
		setPage(0);
		loadHistory();
	}, [setPage]);

	async function loadHistory() {
		const tokenData = readToken();
		if (tokenData && tokenData._id) {
			try {
				const historyData = await getHistory(tokenData._id);
				setHistory(historyData);
			} catch (error) {
				console.error('Error fetching search history:', error);
			}
		}
	}

	async function handleDelete(historyId) {
		const tokenData = readToken();
		if (tokenData && tokenData._id) {
			try {
				await deleteHistory(historyId);
				setHistory((prevHistory) => prevHistory.filter((item) => item._id !== historyId));
			} catch (error) {
				console.error('Failed to delete history entry:', error);
			}
		}
	}

	return (
		<div className='content-container'>
			<Navbar />
			<Header title='Search History' />
			<div className='container my-4 flex-grow-1'>
				{history && history.length > 0 ? (
					<ul className='list-group'>
						{history.map((item) => (
							<li
								key={item._id}
								className='list-group-item 
                                            d-flex 
                                            justify-content-between 
                                            align-items-center
                                            bg-dark'>
								<div>
									<Link
										href={`/?q=${encodeURIComponent(item.query)}`}
										style={{ color: '#EEEEEE' }}>
										{item.query}
									</Link>
									<br />
									<small style={{ color: '#AAAAAA' }}>{new Date(item.timestamp).toLocaleString()}</small>
								</div>
								<button
									className='btn btn-danger btn-sm'
									onClick={() => handleDelete(item._id)}>
									Delete
								</button>
							</li>
						))}
					</ul>
				) : (
					<p class='product-text'>No search history found.</p>
				)}
			</div>
			<Footer />
		</div>
	);
}
