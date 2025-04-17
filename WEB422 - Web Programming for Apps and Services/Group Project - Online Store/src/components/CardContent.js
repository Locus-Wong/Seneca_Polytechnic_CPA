/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/
import ProductCard from '@/components/ProductCard';
var chunk = require('lodash/chunk');

import { useAtom } from 'jotai';
import { pageAtom } from '@/atoms/atoms';

import { useState, useEffect } from 'react';

export default function CardContent({ products }) {
	const [list, setList] = useState(chunk(products, 6));
	const [page, setPage] = useAtom(pageAtom);

	useEffect(() => {
		setList(chunk(products, 6)); // Update list whenever products change
	}, [products]);

	// Changes Product Page
	const changePage = (index) => {
		if (index >= 0 && index < list.length && index != page) {
			setPage(index);
		}
	};

	return (
		<div
			className='container-fluid 
                        d-flex 
                        flex-column 
                        flex-grow-1 
                        gap-5 
                        mt-5'
			style={{ background: 'rgb(40, 44, 48)' }}>
			{chunk(list[page], 3).map((row, rowIndex) => (
				<div
					key={rowIndex}
					className='container-fluid 
								d-flex 
								flex-row 
								justify-content-center
								gap-5'>
					{row.map((item, itemIndex) => (
						<ProductCard
							key={itemIndex}
							product={item}
						/>
					))}
				</div>
			))}
			<div className='container-fluid d-flex justify-content-center mb-3'>
				<button
					className='pagination-button'
					onClick={() => changePage(page - 1)}>
					&lt;
				</button>
				{list.map((_, index) =>
					index === page ? (
						<button
							key={index}
							disabled
							className='pagination-button-disabled'
							onClick={() => changePage(index)}>
							{index + 1}
						</button>
					) : (
						<button
							key={index}
							className='pagination-button'
							onClick={() => changePage(index)}>
							{index + 1}
						</button>
					)
				)}
				<button
					className='pagination-button'
					onClick={() => changePage(page + 1)}>
					&gt;
				</button>
			</div>
		</div>
	);
}
