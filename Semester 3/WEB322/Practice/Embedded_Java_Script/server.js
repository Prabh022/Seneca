const express = require('express');
const path = require('path');
const expressLayouts = require('express-ejs-layouts');

const app = express();
const HTTP_PORT = process.env.PORT || 8080;

// ✅ Instead of app.listen(), export the app
module.exports = app;

// View engine & layouts
app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));
app.use(expressLayouts);

// Static files
app.use(express.static(path.join(__dirname, 'public')));

// Routes
app.get('/', (req, res) => {
  res.render('home', { title: "Home" });
});

app.get('/about', (req, res) => {
  res.render('about', { title: "About" });
});

app.get('/viewData', (req, res) => {
  const someData = {
    name: 'John',
    age: 23,
    occupation: 'developer',
    company: 'Scotiabank',
  };
  res.render('viewData', { title: "View Data", data: someData });
});

// Start server
app.listen(HTTP_PORT, () => {
  console.log(`Server running on port ${HTTP_PORT}`);
});

