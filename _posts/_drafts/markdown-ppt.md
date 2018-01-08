# markdown-ppt

index.html

```html
<!DOCTYPE html>
<html>
  <head>
 
    <meta charset="utf-8">
    <title>hello world</title>
    <link rel="stylesheet" href="http://fonts.googleapis.com/css?family=Anonymous+Pro:400,700,400italic,700italic">
 
    <link rel="stylesheet" href="css/default.css" media="screen">
 
    <!-- math formula -->
   <script type="text/javascript" src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
   
  </head>
  <body>
    <textarea id="source">
class: center, middle, inverse
 
# hello world

This is my first slide 
---
## good bye

:)
    </textarea>
    <script src="http://remarkjs.com/downloads/remark-latest.min.js" type="text/javascript"></script>
    <script type="text/javascript">
      var slideshow = remark.create({
        highlightStyle: 'monokai',
        highlightLanguage: 'remark'
      });
    </script>
 </body>
</html>
```