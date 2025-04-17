/*****************************************************************************
 * WEB422 – Project
 * I declare that this assignment is my own work in accordance with SenecaAcademic Policy.
 * No part of this assignment has been copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Group member Name: Tsz Wa Wong(152181228), Justin Ah-Chong(171708225), Adrian Curammeng(173513227) Date: 13 April 2025
 *****************************************************************************/ 
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
import { faEnvelope } from '@fortawesome/free-regular-svg-icons';
import { faLocationDot } from '@fortawesome/free-solid-svg-icons';
import { faLinkedin, faGithub } from '@fortawesome/free-brands-svg-icons';

export default function JustinAboutCard() {
	return (
		<div className='card p-5 about-card'>
			<div className='card-body'>
				<h2 className='card-title'>Justin Ah-Chong</h2>
				<p className='card-text'>
					Hello, I'm Justin, an aspiring web developer currently studying at Seneca Polytechnic. Feel free to reach out
					to me below if you have any questions.
				</p>
				<div className='container d-flex p-0 mb-3 gap-5'>
					<div>
						<span>Skills:</span>
						<ul className='card-text'>
							<li>Node.js</li>
							<li>React</li>
							<li>MongoDB</li>
							<li>Express</li>
						</ul>
					</div>
					<div>
						<span>Hobbies:</span>
						<ul className='card-text'>
							<li>Traveling</li>
							<li>VideoGames</li>
							<li>Handicraft</li>
							<li>ModelBuilding</li>
						</ul>
					</div>
				</div>
				<h5>Contact</h5>
				<ul className='card-text p-0'>
					<li className='contact-item'>
						<FontAwesomeIcon
							icon={faEnvelope}
							size='lg'
							className='me-2 contact-logo'
						/>
						jah-chong@myseneca.ca
					</li>
					<li className='contact-item'>
						<FontAwesomeIcon
							icon={faLocationDot}
							size='lg'
							className='me-2 contact-logo'
						/>
						Vaughan, ON
					</li>
					<li className='contact-item'>
						<FontAwesomeIcon
							icon={faLinkedin}
							size='lg'
							className='me-2 contact-logo'
						/>
						<a
							href='https://www.linkedin.com/in/justin-ah-chong-03a686229/'
							target='_blank'>
							Justin Ah-Chong
						</a>
					</li>
					<li className='contact-item'>
						<FontAwesomeIcon
							icon={faGithub}
							size='lg'
							className='me-2 contact-logo'
						/>
						<a
							href='https://github.com/justinahchong'
							target='_blank'>
							justinahchong
						</a>
					</li>
				</ul>
			</div>
		</div>
	);
}
