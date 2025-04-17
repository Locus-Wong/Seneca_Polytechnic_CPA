/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/ 
import { useRouter } from 'next/router';
import { useAtom } from 'jotai';
import { productsAtom, categoriesAtom } from '@/atoms/atoms';
import Navbar from '@/components/Navbar';
import Header from '@/components/Header';
import CardContent from '@/components/CardContent';
import Footer from '@/components/Footer';
import Loading from '@/components/Loading';

export default function CategoryPage() {
	const router = useRouter();
	const { id } = router.query;
	const [products] = useAtom(productsAtom);
	const [categories] = useAtom(categoriesAtom);

	const categoryId = Number(id);

	if (!router.isReady || !products || !categories) {
		return <Loading />;
	}

	const currentCategory = categories.find((cat) => cat.id === categoryId);

	const filteredProducts = products.filter((product) => product.category?.id === categoryId);

	return (
		<div className='content-container'>
			<Navbar />
			<Header title={currentCategory?.name || 'Category'} />
			<CardContent products={filteredProducts} />
			<Footer />
		</div>
	);
}
