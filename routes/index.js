var express = require('express');
var router = express.Router();
var addon = require('/factorial.node');
console.log(addon.factorial(10), 'should equal', factorial(10));
/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Get Factorial' });
});

module.exports = router;