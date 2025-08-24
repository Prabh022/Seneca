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
// Define our "User" and "Task" models

const User = sequelize.define('User', {
  fullName: Sequelize.STRING, // the user's full name (ie: "Jason Bourne")
  title: Sequelize.STRING, // the user's title within the project (ie, developer)
});

const Task = sequelize.define('Task', {
  title: Sequelize.STRING, // title of the task
  description: Sequelize.TEXT, // main text for the task
});

// Associate Task with User & automatically create a foreign key
// relationship on "Task" via an automatically generated "UserId" field

Task.belongsTo(User);
sequelize.sync().then(() => {
  // Create user "Jason Bourne"
  User.create({
    fullName: 'Jason Bourne',
    title: 'developer',
  }).then((user) => {
    console.log('user created');

    // Create "Task 1" for the new user
    Task.create({
      title: 'Task 1',
      description: 'Task 1 description',
      UserId: user.id, // set the correct Userid foreign key
    }).then(() => {
      console.log('Task 1 created');
    });

    // Create "Task 2" for the new user
    Task.create({
      title: 'Task 2',
      description: 'Task 2 description',
      UserId: user.id, // set the correct Userid foreign key
    }).then(() => {
      console.log('Task 2 created');
    });
  });
});