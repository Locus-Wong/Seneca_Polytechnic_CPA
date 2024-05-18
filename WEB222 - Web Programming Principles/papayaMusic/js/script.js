/**
 * WEB222 – Assignment 04
 *
 * I declare that this assignment is my own work in accordance with
 * Seneca Academic Policy. No part of this assignment has been
 * copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Please update the following with your information:
 *
 *      Name:       <YOUR_NAME>
 *      Student ID: <YOUR_STUDENT_ID>
 *      Date:       <SUBMISSION_DATE>
 */

// All of our data is available on the global `window` object.
// Create local variables to work with it in this file.
const { artists, songs } = window;

// For debugging, display all of our data in the console. You can remove this later.
console.log({ artists, songs }, "App Data");

function generateArtistButtons(artists) {
    console.log("generating artists")

    const menu = document.querySelector('#menu')
    artists.forEach(function(artist) {
        const artistButton = document.createElement('button')
        const artistImg = document.createElement('img')
        artistImg.src = artist.image
        artistImg.className = "artistImg"
        // artistButton.textContent = artist.name
        artistButton.className = "artistButton"


        artistButton.appendChild(artistImg)
        artistButton.addEventListener("click", (e) => {


            const header = document.getElementById("selected-artist")
            header.textContent = artist.name

            const existingCards = document.getElementById("cards")
            if (existingCards) {
                existingCards.remove()
            }
    
            const cards = document.createElement('div')
            cards.id = "cards"
    
            const main = document.querySelector('main')
            main.appendChild(cards)

            generateSongs(artist.artistID)
        })

        menu.appendChild(artistButton)
    })
}

function generateSongs(artistID) {
    let songsByArtist = songs.filter((song) => song.artistID == artistID)

    // const tbody = document.getElementById("songs")
    // tbody.remove()
    // const tbodyReset = document.createElement('tbody')
    // tbodyReset.id = "songs"
    // const table = document.querySelector('table')
    // table.appendChild(tbodyReset)

    // const cardsDiv = document.getElementById("cards")
    // cardsDiv.remove()

    // const cardsDivReset = document.createElement('div')
    // cardsDivReset.id = "cards"

    // const cardsDiv = document.getElementById("cards")



    songsByArtist.forEach((song) => {
        // const tbody = document.getElementById("songs")

        // const tableRow = document.createElement('tr')
        // tableRow.addEventListener("click", (e) => {
        //     console.log(song)
        // })
        // tbody.appendChild(tableRow)

        const cards = document.getElementById("cards")

        const card = document.createElement('div')
        card.className = "card"

        cards.appendChild(card)

        const img = document.createElement('img')
        img.src = song.albumCover
        
        const h4 = document.createElement('h4')
        h4.textContent = song.albumName

        const p = document.createElement('p')
        p.textContent = song.title
        
        card.appendChild(img)
        card.appendChild(h4)
        card.appendChild(p)



    })
    
} 


function main() {
    console.log("page loaded")
    // main function here 
    generateArtistButtons(artists)
}

window.addEventListener("load", main)