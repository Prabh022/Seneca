const express = require('express');
const app = express();
const path = require('path');
const HTTP_PORT = process.env.PORT || 8080;

// Middleware must come first
app.use(express.json());

// Serve static HTML
app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, '/views/index.html'));
});

// API routes
app.get('/api/users', (req, res) => {
  res.send({ message: 'fetch all users' });
});

app.post('/api/users', (req, res) => {
  res.send({ message: `add the user: ${req.body.fName} ${req.body.lName}` });
});

app.get('/api/users/:userId', (req, res) => {
  res.send({ message: `get user with Id: ${req.params.userId}` });
});

app.put('/api/users/:userId', (req, res) => {
  res.send({ message: `update User with Id: ${req.params.userId} to ${req.body.fName} ${req.body.lName}` });
});

app.delete('/api/users/:userId', (req, res) => {
  res.send({ message: `delete User with Id: ${req.params.userId}` });
});

// Start server
app.listen(HTTP_PORT, () => {
  console.log(`Express http server listening on: ${HTTP_PORT}`);
});
