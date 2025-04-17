/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/
import AdrianAboutCard from '@/components/AdrianAboutCard';
import LocusAboutCard from '@/components/LocusAboutCard';
import JustinAboutCard from '@/components/JustinAboutCard';

export default function AboutContent() {
	return (
		<div
			className='container-fluid 
						d-flex 
						justify-content-center 
						gap-5 py-5'
			style={{ background: 'rgb(40, 44, 48)' }}>
			<AdrianAboutCard />
			<LocusAboutCard />
			<JustinAboutCard />
		</div>
	);
}
