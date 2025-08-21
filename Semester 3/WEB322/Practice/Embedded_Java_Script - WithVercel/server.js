// For local development and deployment to Vercel
// This file sets up an Express server with EJS templating and static file serving.
const express = require("express");
const path = require("path");

const app = express();
// Export as serverless function for Vercel
module.exports = app;         
// ejs setup
app.set("views", path.join(__dirname, "views"));
app.set("view engine", "ejs");

// static files
app.use(express.static(path.join(__dirname, "public")));

// routes
app.get("/", (req, res) => {
  res.render("home", { title: "Home Page" });
});

app.get("/about", (req, res) => {
  res.render("about", { title: "About Page" });
});
app.get('/viewData', (req, res) => {
  const data = {
    name: "John Doe",
    age: 30,
    occupation: "Developer",
    company: "Tech Corp"
  };

  res.render('viewdata', { data });
});


// listen (local only)
const PORT = process.env.PORT || 3000;
app.listen(PORT, () => console.log(`Server running on port ${PORT}`));
