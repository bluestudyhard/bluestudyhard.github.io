function _defineProperty(obj, key, value) {if (key in obj) {Object.defineProperty(obj, key, { value: value, enumerable: true, configurable: true, writable: true });} else {obj[key] = value;}return obj;}const gravity = new Vector(0, 0.03);
const particles = [];

const path_num2 = new Path2D(pathData_num2);
const path_num0 = new Path2D(pathData_num0);
const path_num3 = new Path2D(pathData_num3);
function setup() {
  for (let i = 0; i < 25; i++) {
    setTimeout(() => {
      const f = new Firework();
      particles.push(f);
    }, i * 25);
  }
}

function draw(e) {
  // background(hsl(0, 0, 8, 0.2));
  if (particles.length < 25) {
    const f = new Firework();
    particles.push(f);
  }
  ctx.shadowOffsetX = 0;
  ctx.shadowOffsetY = 0;
  lineCap('round');
  push();
  // const time = e * 0.001;
  for (let i = particles.length - 1; i >= 0; i--) {
    const p = particles[i];
    if (p instanceof Particle) {
      if (e > p.created + p.life) {
        particles.splice(i, 1);
        continue;
      }
      p.posPrev.set(p.pos);
      p.pos.add(p.vel.add(gravity).mult(0.999));
      if (mouseDown) {
        p.vel.add(mousePos._.sub(p.pos).limit(1));
      }
      const _r = ease.expo.out(map(e, p.created, p.created + p.life, 1, 0));
      const r = p.r * _r;
      const color = hsl(p.color, 90, 55);
      ctx.shadowBlur = 15 * _r;
      ctx.shadowColor = color;
      beginPath();
      line(p.posPrev._.sub(p.pos).mult(5 * _r).add(p.pos), p.pos);
      stroke(color, r * 2);
    } else
    if (p instanceof Firework) {
      if (e > p.created + p.life) {
        particles.splice(i, 1);
        for (let i = 0; i < p.particleCount; i++) {
          const t = i / p.particleCount;
          const p2 = new Particle();
          p2.color = p.color + random(-20, 20);
          p2.pos.set(p.pos);
          const mag = p2.vel.mag();
          p2.vel.set(Vector.fa(t * TAU, mag));
          particles.push(p2);
        }
        continue;
      }
      p.pos.add(p.vel.add(gravity).mult(0.999));
      const r = 4 * map(e, p.created, p.created + p.life, 1, 0);
      ctx.shadowBlur = 0;
      beginPath();
      circle(p.pos, r);
      fill(hsl(p.color, 80, 40));
    }
  }
  pop();

  translate(width_half - 175, height_half - 72);

  compositeOperation(compOper.xor);

  lineWidth(8);
  ctx.shadowBlur = 0;
  ctx.shadowOffsetX = 2;
  ctx.shadowOffsetY = 5;
  ctx.shadowColor = hsl(e * 0.15, 80, 60);
  // filter('blur(4px)');
  strokeStyle(hsl(0, 0, 100));
  stroke(path_num2);
  translate(89, 0);
  stroke(path_num0);
  translate(92, 0);
  stroke(path_num2);
  translate(89, 0);
  stroke(path_num3);
}

class Particle {constructor() {_defineProperty(this, "pos",
    new Vector());_defineProperty(this, "posPrev",
    new Vector());_defineProperty(this, "vel",
    Vector.fa(random(TAU), random(0.5, 3)));_defineProperty(this, "r",
    random(1, 7));_defineProperty(this, "color",
    random(360));_defineProperty(this, "created",
    performance.now());_defineProperty(this, "life",
    random(1, 3) * 1000);}}


class Firework {constructor() {_defineProperty(this, "pos",
    new Vector(random(width), height));_defineProperty(this, "vel",
    Vector.fa(random(-1, 1) * EIGHTH_PI + PI * 1.5, random(4, 9)));_defineProperty(this, "color",
    random(360));_defineProperty(this, "created",
    performance.now());_defineProperty(this, "life",
    random(0.5, 2.25) * 1000);_defineProperty(this, "particleCount",
    random(7, 12));}}