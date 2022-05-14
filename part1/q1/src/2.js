var canvas = document.getElementById('canvas')
var ctx = canvas.getContext("2d")

// translate to center of canvas
ctx.translate(canvas.width / 2, canvas.height / 4)

var lsytem1 = new LSystem({
    axiom: 'X',
    productions: {
      'X': 'F[-X]X[+X][+X]F-[-X]+X[-X]',
      'F': 'FF'
    },
  
    finals: {
  
      '+': () => { ctx.rotate((Math.PI / 180) * 4) },
      '-': () => { ctx.rotate((Math.PI / 180) * -4) },
      'F': () => {
        ctx.beginPath()
        ctx.moveTo(0, 0)
        ctx.lineTo(0, 40 / (lsytem1.iterations + 1))
        ctx.stroke()
        ctx.translate(0, 40 / (lsytem1.iterations + 1))
      },
      "[": () => { ctx.save() },
      "]": () => { ctx.restore() }
    }
  
})
lsytem1.iterate(5)
lsytem1.final()
