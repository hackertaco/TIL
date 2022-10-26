const express = require('express');
const router = express.Router();
const User = require('../models').User
/* GET users listing. */
router.get('/', async function(req, res, next) {
  try{
    const users = await User.findAll()
    res.json(users)
  }catch (e) {
    next(e)
  }
});

router.post('/', async function(req, res, next){
  try{
    const createdUser = await User.create({
      name: req.body.name,
      age: req.body.age,
      married: req.body.married
    })

    res.status(201).json(createdUser)
  }catch (e) {
    next(e)
  }
})

module.exports = router;
