const mongoose = require('mongoose');
let schema = mongoose.Schema;

//connect to your mongodb atlas database
mongoose.connect('mongodb+srv://Prabh_Kang:prabh@sandboxdb.mkqhphc.mongodb.net/?retryWrites=true&w=majority&appName=sandboxdb')

let companySchema = new schema ({
    companyName: {
        type: String,
        unique: true,
    },
    address: String,
    phone: String,
    employeeCount: {
        type: Number,
        default: 0,
    },
    country: String,
});

let Company = mongoose.model('companies', companySchema);
/*
// create a new company
let kwikEMart = new Company({
  companyName: 'The Kwik-E-Mart',
  address: 'Springfield',
  phone: '212-842-4923',
  employeeCount: 3,
  country: 'U.S.A',
});

// save the company
kwikEMart
  .save()
  .then(() => {
    console.log('The Kwik-E-Mart company was saved to the companies collection');
    process.exit();
  })
  .catch((err) => {
    console.log('There was an error saving the Kwik-E-Mart company');
    process.exit();
  });
  */
 Company.find({ companyName: 'The Kwik-E-Mart' })
  .exec()
  .then((company) => {
    if (!company) {
      console.log('No company could be found');
    } else {
      console.log(company);
    }
    // exit the program after saving and finding
    process.exit();
  })
  .catch((err) => {
    console.log(`There was an error: ${err}`);
    process.exit();
  });