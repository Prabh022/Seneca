# Embedded JavaScript (EJS) Practice Project
This is a simple **Express.js web application** demonstrating the use of **EJS templates**, **partials**, **layouts**, and **static assets**.

## Project Structure
- `server.js` — Express server  
- `package.json` — Node dependencies  
- `public/` — Static files  
  - `css/style.css` — Stylesheet  
- `views/` — EJS templates  
  - `layout.ejs` — Main layout  
  - `home.ejs` — Home page  
  - `about.ejs` — About page  
  - `viewData.ejs` — Page showing sample data  
  - `partials/` — Header and footer partials  
    - `header.ejs` — Header partial  
    - `footer.ejs` — Footer partial

## Installation
1. Clone the repository:  
   `git clone <your-repo-url>`  
   `cd my-app`  
2. Install dependencies:  
   `npm install`  
   This installs `express`, `ejs`, and `express-ejs-layouts`.

## Running the App
1. Start the server:  
   `node server.js`  
2. Open your browser and visit:  
   - http://localhost:8080/ → Home page  
   - http://localhost:8080/about → About page  
   - http://localhost:8080/viewData → View sample data

## Features
- **EJS Templates** — Dynamic rendering with `<%= %>` and `<%- %>` tags  
- **Layouts** — `layout.ejs` provides a common structure for all pages  
- **Partials** — `header.ejs` and `footer.ejs` reused across all pages  
- **Static Assets** — CSS and other static files served from `public/`  
- **Data Rendering** — `/viewData` route shows how to render dynamic data in a table

## Adding Pages
1. Create a new `.ejs` file in `views/`.  
2. Add your page content (header/footer is handled by the layout).  
3. Add a route in `server.js`, for example:  
   `app.get('/newPage', (req, res) => { res.render('newPage', { title: "New Page" }); });`

## Notes
- All `.ejs` files must exist in the `views` folder  
- Static CSS files should be in `public/css/`  
- The server uses **Express 4+** and **Node.js 18+**
