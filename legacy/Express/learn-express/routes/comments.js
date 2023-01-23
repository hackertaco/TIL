const express = require('express');
const router = express.Router();
const {User, Comment} = require('../models')
/* GET users listing. */
router.get('/:id', async function(req, res, next) {
  try{
    const comments = await Comment.findAll({
      include:{
        model:User,
        where: {id: req.params.id}
      }
    })
    res.json(comments)
  }catch (e) {
    next(e)
  }
});

router.post('/', async function(req, res, next){
  try{
    const createdComment = await Comment.create({
      commenter: req.body.id,
      comment: req.body.comment,
    })

    res.status(201).json(createdComment)
  }catch (e) {
    next(e)
  }
})

router.patch('/:id', async function(req, res, next){
  try{
    const updatedComment = await Comment.update({
      comment: req.body.comment,
    }, {
      where: {
        id:req.params.id
      }
    })

    res.json(updatedComment)
  }catch (e) {
    next(e)
  }
})

router.delete('/:id', async function(req,res,next){
  try{
    const deletedComment = await Comment.destroy({
      where: {
        id:req.params.id
      }
    })

    res.json(deletedComment)
  }catch (e) {
    next(e)
  }
})

module.exports = router;
