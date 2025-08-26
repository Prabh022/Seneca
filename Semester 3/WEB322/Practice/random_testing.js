const Sequelize = require('sequilize');
const Name = Sequelize.define('Name', {
    fName: Sequelize.STRING,  // first name
    lName: Sequelize.STRING,  // last name
});
//Creating the user
Sequelize.sync().then(() => {
    Name.create({
        fName: 'Kyler',
        lName: 'Odin',
    }).then(() => {
        console.log('Kyler Odin Created');
    });

    Name.create({
        fName: 'Adin',
        lName: 'Ross',
    }).then(() => {
        console.log('Adin Ross Created');
    });
    Name.create({
        fName: 'Darren',
        lName: 'Watkins',
    }).then(() => {
         console.log('Darren Watkins Created');
    });
});

//Reading the User
//finding all Users
Sequelize.sync().then(() => {
    Name.findAll({
        attributes: [fName],
    }).then((data) => {
        console.log('All first Names are:');
        for(let i = 0; i < data.length;i ++){
            console.log(data[i].fName);
        }
    });
// return all first names where id = 2
Sequelize.sync().then(() => {
    Name.findAll({
        attributes: [fName],
        where: {
            id: 2,
        },
    }).then((data) => {
        console.log('All first names where id == 2');
        for (let i = 0;i < data.length;i++) {
            console.log(data[i],fName);
        }
    });
});
/*
sequelize.sync().then(() => {
  // return all first names only
  Name.findAll({ order: ['fName'] }).then((data) => {
    console.log('All data');
    for (let i = 0; i < data.length; i++) {
      console.log(data[i].fName);
    }
  });
});
*/

//Updating the user
sequelize.sync().then(() => {
  // update User 2's last name to "James"
  // NOTE: this also updates the "updatedAt field"
  Name.update(
    {
      lName: 'James',
    },
    {
      where: { id: 2 }, // only update user with id == 2
    }
  ).then(() => {
    console.log('successfully updated user 2');
  });
});

//Deleting the user
sequelize.sync().then(() => {
  // remove User 3 from the database
  Name.destroy({
    where: { id: 3 }, // only remove user with id == 3
  }).then(() => {
    console.log('successfully removed user 3');
  });
});
});