var canvas = document.getElementById('canvas')
var ctx = canvas.getContext("2d")

// translate to center of canvas
ctx.translate(canvas.width / 2, canvas.height / 4)


var lsytem3 = new LSystem({
    axiom: 'X',
    productions: {
    'X': {
    successors: [
    { weight: 50, successor: "F-[[-X]+X]+F[+FX]-X" },
    { weight: 50, successor: "F+[[+X]-X]-F[-FX]+X[X]" }
    ]
    },
    'F': {
    successors: [
    { weight: 100 / 3, successor: "F[F]F" },
    { weight: 100 / 3, successor: "F[+]F" },
    { weight: 100 / 3, successor: " F[FF]F" }
    ]
    }
   
   
    
    },
    finals: {
    '+': () => { ctx.rotate((Math.PI / 180) * 12.5) },
    '-': () => { ctx.rotate((Math.PI / 180) * -12.5) },
    'F': () => {
    ctx.beginPath()
    ctx.moveTo(0, 0)
    ctx.lineTo(0, 40 / (lsytem3.iterations + 1))
    ctx.stroke()
    ctx.translate(0, 40 / (lsytem3.iterations + 1))
    },
    "[": () => { ctx.save() },
    "]": () => { ctx.restore() }
    }
   
   
    
})
lsytem3.iterate(5)
 lsytem3.final()
