const express = require('express');
const app = express();
const HTTP_PORT = process.env.PORT || 8080;
const path = require('path');
require('pg');
const Sequelize = require('sequelize');

// Tell Express where views folder is
app.set('views', __dirname + '/views');

// Serve static files from the 'public' folder
app.use(express.static(__dirname + '/public'));


app.get('/', (req,res) => {
    //res.send('Hello, World!');
    res.sendFile(path.join(__dirname, '/views/home.html'));
});
app.get('/about', (req, res) => {
    res.send('About this application'); 
    res.sendFile(path.join(__dirname, '/views/about.html'));
});

app.listen(HTTP_PORT, () => {
    console.log(`Server running on port ${HTTP_PORT}`);
});