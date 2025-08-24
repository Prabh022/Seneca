const { Sequelize, DataTypes } = require('sequelize');

// set up sequelize to point to our postgres database
const sequelize = new Sequelize('SenecaDB', 'neondb_owner', 'npg_OtH2iGjBsLb3', {
  host: 'ep-young-brook-ad53qa6z-pooler.c-2.us-east-1.aws.neon.tech',
  dialect: 'postgres',
  port: 5432,
  dialectOptions: {
    ssl: { rejectUnauthorized: false }, // only needed if connecting to cloud DBs
  },
});

// Define a simple model
const Test = sequelize.define('Test', {
  name: {
    type: DataTypes.STRING,
    allowNull: false,
  },
});

// Main test function
(async () => {
  try {
    await sequelize.authenticate();
    console.log('✅ Connection has been established successfully.');

    await sequelize.sync({ force: true }); // recreate tables
    console.log('✅ Database synchronized.');

    // Insert sample row
    const row = await Test.create({ name: 'Hello Sequelize' });
    console.log('✅ Row created:', row.toJSON());

    // Query rows
    const rows = await Test.findAll();
    console.log('✅ Rows in DB:', rows.map(r => r.toJSON()));
  } catch (err) {
    console.error('❌ Unable to connect or run queries:', err);
  } finally {
    await sequelize.close();
  }
})();
