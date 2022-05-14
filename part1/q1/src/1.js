var canvas = document.getElementById('canvas')
var ctx = canvas.getContext("2d")

// translate to center of canvas
ctx.translate(canvas.width / 2, canvas.height / 4)

// initialize a koch curve L-System that uses final functions
// to draw the fractal onto a Canvas element.
// F: draw a line with length relative to the current iteration (half the previous length for each step)
//    and translates the current position to the end of the line
// +: rotates the canvas 60 degree
// -: rotates the canvas -60 degree


var lsytem = new LSystem({
  axiom: 'G',
  productions: {

    'G': 'X-G-X',
    'X': 'G+Y+G',
    'Y': '[+F]F[-F]'
  },

  finals: {

    '+': () => { ctx.rotate((Math.PI / 180) * 30) },
    '-': () => { ctx.rotate((Math.PI / 180) * -30) },
    'F': () => {
      ctx.beginPath()
      ctx.moveTo(0, 0)
      ctx.lineTo(0, 200/ (lsytem.iterations + 1))
      ctx.stroke()
      ctx.translate(0, 200/ (lsytem.iterations + 1))
    },
    
   
    "[": () => { ctx.save() },
    "]": () => { ctx.restore() }

  },


})

lsytem.iterate(10)
lsytem.final()






 
 
  
 
