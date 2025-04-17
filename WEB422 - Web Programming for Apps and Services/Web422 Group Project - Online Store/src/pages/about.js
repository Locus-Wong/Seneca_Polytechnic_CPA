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
import AboutContent from '@/components/AboutContent';
import Footer from '@/components/Footer';

export default function About() {
	return (
		<div>
			<Navbar />
			<Header title='About' />
			<AboutContent />
			<Footer />
		</div>
	);
}
