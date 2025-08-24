const Sequelize = require('sequelize');

// set up sequelize to point to our postgres database
const sequelize = new Sequelize('SenecaDB', 'neondb_owner', 'npg_OtH2iGjBsLb3', {
  host: 'ep-young-brook-ad53qa6z-pooler.c-2.us-east-1.aws.neon.tech',
  dialect: 'postgres',
  port: 5432,
  dialectOptions: {
2    ssl: { rejectUnauthorized: false },
  },
});

// Define a "Project" model

const Project = sequelize.define('Project', {
  title: Sequelize.STRING,
  description: Sequelize.TEXT,
});

// synchronize the Database with our models and automatically add the
// table if it does not exist

sequelize.sync().then(() => {
  // create a new "Project" and add it to the database
  Project.create({
    title: 'Project1',
    description: 'First Project',
  })
    .then((project) => {
      // you can now access the newly created Project via the variable project
      console.log('success!');
    })
    .catch((error) => {
      console.log('something went wrong!');
    });
});
