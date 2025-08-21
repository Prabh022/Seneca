// api/index.js
const express = require("express");
const serverless = require("serverless-http");
const path = require("path");

const app = express();

// EJS setup
app.set("views", path.join(__dirname, "../views"));
app.set("view engine", "ejs");

// Static files
app.use(express.static(path.join(__dirname, "../public")));

// Routes
app.get("/", (req, res) => {
  res.render("home", { title: "Home Page" });
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

// Export as serverless function
module.exports = app;
module.exports.handler = serverless(app);
