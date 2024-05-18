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

// All of our data is available on the global `window` object.
// Create local variables to work with it in this file.
const { artists, songs } = window;

function generateArtistButtons(artists) {
  const menu = document.querySelector("#menu");

  if (artists) {
    artists.forEach(function (artist) {
      const artistButton = document.createElement("button"); // create a button element
      artistButton.textContent = artist.name; // set button text to artist name
      menu.appendChild(artistButton);
      if (artist.name === artists[0].name) {
        //Display the first artist's top 5 songs by default
        const header = document.getElementById("selected-artist"); // select the h2 element with id selected-artist
        header.textContent =
          "Top 5 Songs Most Streamed by " + artist.name + " ";
        const Wikipedia = document.createElement("a");
        Wikipedia.href = artist.urls[0].url; // set the href attribute of the anchor to the artist's Instagram URL
        Wikipedia.textContent = "(Wikipedia,";
        header.appendChild(Wikipedia); // append the anchor to the header
        const Instagram = document.createElement("a");
        Instagram.href = artist.urls[1].url; // set the href attribute of the anchor to the artist's Instagram URL
        Instagram.textContent = " Instagram)";
        header.appendChild(Instagram); // append the anchor to the header
        createSongCards(artist.artistId);
      }

      artistButton.addEventListener("click", () => {
        const cards = document.getElementById("cards");
        cards.innerHTML = ""; // clear the main element
        const header = document.getElementById("selected-artist"); // select the h2 element with id selected-artist
        header.textContent =
          "Top 5 Songs Most Streamed by " + artist.name + " ";
        const Wikipedia = document.createElement("a");
        Wikipedia.href = artist.urls[0].url; // set the href attribute of the anchor to the artist's Instagram URL
        Wikipedia.textContent = "(Wikipedia,";
        header.appendChild(Wikipedia); // append the anchor to the header
        const Instagram = document.createElement("a");
        Instagram.href = artist.urls[1].url; // set the href attribute of the anchor to the artist's Instagram URL
        Instagram.textContent = " Instagram)";
        header.appendChild(Instagram); // append the anchor to the header
        createSongCards(artist.artistId);
      });
    });
  }
}

function createSongCards(artistId) {
  const cards = document.getElementById("cards");
  let songsByArtist = songs.filter((song) => song.artistId === artistId); // get the array of songs by the artist
  songsByArtist.forEach((song) => {
    const card = createSongCard(song);
    if (card)
      // check if the card is not null
      cards.appendChild(card);
  });
}

function createSongCard(song) {
  if (song.explicit === false) {
    const card = document.createElement("div");
    card.className = "card";

    const songImg = document.createElement("img");
    songImg.src = song.imageUrl;
    songImg.className = "card-image";

    const songURL = document.createElement("a");
    songURL.href = song.url;
    songURL.target = "_blank";
    card.appendChild(songURL);
    songURL.appendChild(songImg);

    const songName = document.createElement("h2");
    songName.textContent = song.title;
    songName.className = "title";
    card.appendChild(songName);

    const annotation = document.createElement("div");
    annotation.className = "annotation";
    card.appendChild(annotation);

    const songYear = document.createElement("span");
    songYear.textContent = "Year : " + song.year;
    songYear.className = "year";
    annotation.appendChild(songYear);

    const songDuration = document.createElement("span");
    const songMinutes = Math.floor(song.duration / 60); // round down the minutes to the nearest whole number
    const songSeconds = song.duration % 60;
    if (songSeconds > 10) {
      songDuration.textContent =
        "Duration : " + songMinutes + ":" + songSeconds;
    } else {
      songDuration.textContent =
        "Duration : " + songMinutes + ":0" + songSeconds;
    }
    songDuration.className = "duration";
    annotation.appendChild(songDuration);

    return card;
  }
}

function addArtist() {
  const addArtistButton = document.querySelector("#add-artist");
  addArtistButton.addEventListener("click", () => {
    addURL();
  });
}

function addURL() {
  let count = 1;
  const urlLabel = document.createElement("label");
  const urlInput = document.createElement("input");
  const addButton = document.querySelector("#add-url");
  urlInput.type = "url";
  urlInput.required = true;
  urlInput.classList.add("input-url");
  const form = document.querySelector("#add-artist");

  if (form) {
    addButton.addEventListener("click", () => {
      urlLabel.textContent = `Additional URLs:`;
      const id = `artist-songs${count}`;
      console.log("add-artist is clicked");
      urlLabel.setAttribute("for", id);
      urlInput.id = id;
      urlInput.name = id;

      form.appendChild(urlLabel);
      form.appendChild(urlInput);
      count++;
      console.log(count);
    });
  }
}
function main() {
  console.log("page is loaded");
  generateArtistButtons(artists);
  addArtist();
}
window.addEventListener("load", main); // Make sure you don’t do anything to the DOM until it’s fully loaded.
