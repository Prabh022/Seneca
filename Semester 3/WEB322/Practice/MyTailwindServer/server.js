const express = require('express');
const app = express();
const HTTP_PORT = process.env.PORT || 8080;
const path = require('path');

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