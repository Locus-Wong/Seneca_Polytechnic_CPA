/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/ 
import Loading from '@/components/Loading';
import Navbar from '@/components/Navbar';
import Header from '@/components/Header';
import Footer from '@/components/Footer';
import CardContent from '@/components/CardContent';

import { useEffect } from 'react';
import { getProducts, getCategories } from '../app';
import { useAtom } from 'jotai';
import { productsAtom, categoriesAtom } from '@/atoms/atoms';
import { useRouter } from 'next/router';

export default function Home() {
	const [products, setProducts] = useAtom(productsAtom);
	const [categories, setCategories] = useAtom(categoriesAtom);
	const router = useRouter();
	const { q } = router.query;

	const filteredProducts = products?.filter((product) => product.title.toLowerCase().includes(q?.toLowerCase()));

	// Retrieve Products
	useEffect(() => {
		if (!products) {
			getProducts().then((data) => setProducts(data));
		}
	}, []);

	// Retrieve Categories
	useEffect(() => {
		if (!categories) {
			getCategories().then((data) => setCategories(data));
		}
	}, []);

	if (!products) return <Loading />;

	return (
		<div className='content-container'>
			<Navbar />
			<Header title={q ? `Results for "${q}"` : 'Products'} />
			<CardContent products={q ? filteredProducts : products} />
			<Footer />
		</div>
	);
}
