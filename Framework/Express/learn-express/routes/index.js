const express = require('express');
const router = express.Router();
const User = require('../models').User;
/* GET home page. */
router.get('/', async function(req, res, next) {
  try{
    const users = await User.findAll()
     res.render('sequelize', {users})

  }catch(error){
    next(error)
  }
});

module.exports = router;
