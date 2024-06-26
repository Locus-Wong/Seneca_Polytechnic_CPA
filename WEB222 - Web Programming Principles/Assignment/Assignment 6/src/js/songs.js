/**
 * WEB222 – Assignment 06
 *
 * I declare that this assignment is my own work in accordance with
 * Seneca Academic Policy. No part of this assignment has been
 * copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Please update the following with your information:
 *
 *      Name:       Tsz Wa Wong
 *      Student ID: 152181228
 *      Date:       14 Apr 2024
 */

window.songs = [
  /* TODO */
  {
    // shawn Mendes
    songId: "SID-27159388",
    artistId: "AID-37343",
    title: "Stitches",
    year: "2015",
    duration: 239,
    url: "https://www.youtube.com/watch?v=VbfpW0pbvaU",
    imageUrl: "./album/Handwritten.jpg",
    explicit: false,
  },
  {
    songId: "SID-27159389",
    artistId: "AID-37343",
    title: "Treat You Better",
    year: "2016",
    duration: 256,
    url: "https://www.youtube.com/watch?v=lY2yjAdbvdQ",
    imageUrl: "./album/Shawn-Mendes.jpg",
    explicit: true,
  },
  {
    songId: "SID-27159390",
    artistId: "AID-37343",
    title: "In My Blood",
    year: "2018",
    duration: 217,
    url: "https://www.youtube.com/watch?v=36tggrpRoTI",
    imageUrl: "./album/Shawn-Mendes.jpg",
    explicit: false,
  },
  {
    songId: "SID-27159391",
    artistId: "AID-37343",
    title: "If I Can't Have You",
    year: "2019",
    duration: 191,
    url: "https://www.youtube.com/watch?v=oTJ-oqwxdZY",
    imageUrl: "./album/Shawn-Mendes.jpg",
    explicit: true,
  },
  {
    songId: "SID-27159392",
    artistId: "AID-37343",
    title: "Senorita",
    year: "2019",
    duration: 205,
    url: "https://www.youtube.com/watch?v=Pkh8UtuejGw",
    imageUrl: "./album/Shawn-Mendes.jpg",
    explicit: false,
  },
  {
    //ed sheeran
    songId: "SID-27159393",
    artistId: "AID-92377",
    title: "Shape of You",
    year: "2017",
    duration: 263,
    url: "https://www.youtube.com/watch?v=JGwWNGJdvx8",
    imageUrl: "./album/Divide.jpg",
    explicit: false,
  },
  {
    songId: "SID-27159394",
    artistId: "AID-92377",
    title: "Castle on the Hill",
    year: "2017",
    duration: 288,
    url: "https://www.youtube.com/watch?v=K0ibBPhiaG0",
    imageUrl: "./album/Divide.jpg",
    explicit: false,
  },
  {
    songId: "SID-27159395",
    artistId: "AID-92377",
    title: "Perfect",
    year: "2017",
    duration: 279,
    url: "https://www.youtube.com/watch?v=2Vv-BfVoq4g",
    imageUrl: "./album/Divide.jpg",
    explicit: true,
  },
  {
    songId: "SID-27159396",
    artistId: "AID-92377",
    title: "Shivers",
    year: "2021",
    duration: 237,
    url: "https://www.youtube.com/watch?v=Il0S8BoucSA",
    imageUrl: "./album/Equal.jpg",
    explicit: false,
  },
  {
    songId: "SID-27159397",
    artistId: "AID-92377",
    title: "Eyes Closed",
    year: "2023",
    duration: 215,
    url: "https://www.youtube.com/watch?v=u6wOyMUs74I",
    imageUrl: "./album/Subtract.jpg",
    explicit: false,
  },
  // Taylor Swift
  {
    songId: "SID-27159398",
    artistId: "AID-64700",
    title: "Love Story",
    year: "2008",
    duration: 236,
    url: "https://www.youtube.com/watch?v=8xg3vE8Ie_E",
    imageUrl: "./album/Fearless.jpg",
    explicit: false,
  },
  {
    songId: "SID-27159399",
    artistId: "AID-64700",
    title: "You Belong With Me",
    year: "2009",
    duration: 228,
    url: "https://www.youtube.com/watch?v=VuNIsY6JdUw",
    imageUrl: "./album/Fearless.jpg",
    explicit: false,
  },
  {
    songId: "SID-27159400",
    artistId: "AID-64700",
    title: "Shake It Off",
    year: "2014",
    duration: 241,
    url: "https://www.youtube.com/watch?v=nfWlot6h_JM",
    imageUrl: "./album/1989.jpg",
    explicit: false,
  },
  {
    songId: "SID-27159401",
    artistId: "AID-64700",
    title: "Blank Space",
    year: "2014",
    duration: 272,
    url: "https://www.youtube.com/watch?v=e-ORhEE9VVg",
    imageUrl: "./album/1989.jpg",
    explicit: false,
  },
  {
    songId: "SID-27159402",
    artistId: "AID-64700",
    title: "Bad Blood",
    year: "2015",
    duration: 244,
    url: "https://www.youtube.com/watch?v=QcIy9NiNbmo",
    imageUrl: "./album/1989.jpg",
    explicit: false,
  },
  // Bruno Mars
  {
    songId: "SID-27159403",
    artistId: "AID-30751",
    title: "The Lazy Song",
    year: "2011",
    duration: 199,
    url: "https://www.youtube.com/watch?v=fLexgOxsZu0",
    imageUrl: "./album/Doo-Wops.jpg",
    explicit: false,
  },
  {
    songId: "SID-27159404",
    artistId: "AID-30751",
    title: "Locked Out of Heaven",
    year: "2012",
    duration: 234,
    url: "https://www.youtube.com/watch?v=e-fA-gBCkj0",
    imageUrl: "./album/Unorthodox.jpg",
    explicit: false,
  },
  {
    songId: "SID-27159405",
    artistId: "AID-30751",
    title: "Just The Way You Are",
    year: "2010",
    duration: 236,
    url: "https://www.youtube.com/watch?v=LjhCEhWiKXk",
    imageUrl: "./album/Doo-Wops.jpg",
    explicit: false,
  },
  {
    songId: "SID-27159406",
    artistId: "AID-30751",
    title: "That’s What I Like",
    year: "2017",
    duration: 210,
    url: "https://www.youtube.com/watch?v=PMivT7MJ41M",
    imageUrl: "./album/24K-magic.jpg",
    explicit: true,
  },
  {
    songId: "SID-27159407",
    artistId: "AID-30751",
    title: "24K Magic",
    year: "2016",
    duration: 226,
    url: "https://www.youtube.com/watch?v=UqyT8IEBkvY",
    imageUrl: "./album/24K-magic.jpg",
    explicit: false,
  },
];
