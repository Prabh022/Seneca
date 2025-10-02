//Setup
const express = require('express');
const path = require('path');
const app = express();
const HTTP_PORT = process.env.port || 3000;

//Middleware or Add support for incoming JSON entities
app.use(express.json());

//Deliver the app's home page to the browser clients
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, '/index.html'));
});

//Get all
app.get('/', (req, res)=> {
    res.json({message: 'Hello from the server!'});
});

// Add new
// This route expects a JSON object in the body, e.g. { "firstName": "Peter", "lastName": "McIntyre" }
app.post('/api/items', (req, res) => {
    // must returns HTTP 201
    res.status(201).json({message: 'Item created', item: req.body});
});

//Update existing
// This route expects a JSON object in the body, e.g. { "firstName": "Peter", "lastName": "McIntyre" }
app.put('/api/items/:id', (req, res) => {
    // must returns HTTP 200
    res.status(200).json({message: `Item ${req.params.id} updated`, item: req.body});
});

//Delete existing
app.delete('/api/items/:id', (req, res) => {
    // must returns HTTP 204
    res.status(204).send();
});
// Resource not found (this should be at the end)
app.use((req, res) => {
  res.status(404).send('Resource not found');
});

// Tell the app to start listening for requests
app.listen(HTTP_PORT, () => {
  console.log('Ready to handle requests on port ' + HTTP_PORT);
});