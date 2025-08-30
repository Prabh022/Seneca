let companySchema = new Schema({
  companyName: String,
  address: String,
  phone: String,
  employeeCount: {
    type: Number,
    default: 0,
  },
  country: String,
});

let Company = mongoose.model('companies', companySchema);
// Create
let newCompany = new Company({
  companyName: 'Initech',
  address: '123 Business Rd, Business City, BC 54321',
    phone: '555-123-4567',
    employeeCount: 250,
    country: 'USA',
}); 
newCompany
  .save()
  .then(() => { 
    console.log('New company saved successfully');
    // Read
    return Company.find({ companyName: 'Initech' }).exec();
  })
  .then((companies) => {
    console.log('Companies found:', companies); 
    // Update
    return Company.updateOne(
      { companyName: 'Initech' },
      { $set: { phone: '555-765-4321' } }
    ).exec();
  })
  .then(() => {
    console.log('Company updated successfully');
    // Delete
    return Company.deleteOne({ companyName: 'Initech' }).exec();
  } )
  .then(() => {
    console.log('Company deleted successfully');
    process.exit();
  })
  .catch((err) => {
    console.error('Error during CRUD operations:', err);
    process.exit();
  });