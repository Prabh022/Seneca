// Setup
const express = require('express');
const path = require('path');
const app = express();
const HTTP_PORT = process.env.PORT || 8080;

// Add support for incoming JSON entities
app.use(express.json());

// Deliver the app's home page to browser clients
app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, '/index.html'));
});

// Get all
app.get('/api/items', (req, res) => {
  res.json({ message: 'fetch all items' });
});

// Get one
app.get('/api/items/:itemId', (req, res) => {
  res.json({ message: `get item with identifier: ${req.params.itemId}` });
});

// Add new
// This route expects a JSON object in the body, e.g. { "firstName": "Peter", "lastName": "McIntyre" }
app.post('/api/items', (req, res) => {
  // MUST return HTTP 201
  res.status(201).json({ message: `added a new item: ${req.body.firstName} ${req.body.lastName}` });
});

// Edit existing
// This route expects a JSON object in the body, e.g. { "id": 123, "firstName": "Peter", "lastName": "McIntyre" }
app.put('/api/items/:itemId', (req, res) => {
  res.json({
    message: `updated item with identifier: ${req.params.itemId} to ${req.body.firstName} ${req.body.lastName}`,
  });
});

// Delete item
app.delete('/api/items/:itemId', (req, res) => {
  res.status(200).json({ message: `deleted item with identifier: ${req.params.itemId}` });
});

// Resource not found (this should be at the end)
app.use((req, res) => {
  res.status(404).send('Resource not found');
});
// Array of strings
let colours = ['Red', 'Green', 'Blue', 'Yellow', 'Aqua', 'Fuschia'];

// Tell the app to start listening for requests
app.listen(HTTP_PORT, () => {
  console.log('Ready to handle requests on port ' + HTTP_PORT);
});
