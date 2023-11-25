const canvas =<HTMLCanvasElement> document.getElementById("canvas");
const ctx = <CanvasRenderingContext2D> canvas.getContext('2d');

canvas.width=window.innerWidth;
canvas.height=window.innerHeight;

const keysPressed = [] as boolean[];
const paddleSpeed = 20;

window.addEventListener('keydown', function (e) { keysPressed[e.keyCode] = true; });

window.addEventListener('keyup', function (e) { keysPressed[e.keyCode] = false; });

function vec2(x: number, y: number) : {x: number, y: number} { return {x, y}; };

class	ballClass
{
	_pos: {x: number, y: number};
	_velocity: {x: number, y: number};
	_radius: number;

	constructor(startpos: { x: number, y: number }, velocity: { x: number, y: number }, radius: number)
	{
		this._pos = startpos;
		this._velocity = velocity;
		this._radius = radius;
	}

	update = function()
	{
		this._pos.x += this._velocity.x;
		this._pos.y += this._velocity.y;
	}

	draw = function()
	{
		ctx.fillStyle = "#ff0000";
		ctx.strokeStyle = "#ff0000";
		ctx.beginPath();
		ctx.arc(this._pos.x, this._pos.y, this._radius, 0, Math.PI * 2);
		ctx.fill();
		ctx.stroke();
	}
}

class	paddleClass
{
	_pos: {x: number, y: number};
	_velocity: {x: number, y: number};
	_width: number;
	_height: number;
	_keyUpPressed: number;
	_keyDownPressed: number;
	_score: number;

	constructor(startpos: {x: number, y: number}, velocity: {x: number, y: number},
		width: number, height: number, keyUpPressed: number, keyDownPressed: number)
	{
		this._pos = startpos;
		this._velocity = velocity;
		this._width = width;
		this._height = height;
		this._keyUpPressed = keyUpPressed;
		this._keyDownPressed = keyDownPressed;
		this._score = 0;
	}

	update = function()
	{
		if (keysPressed[this._keyUpPressed])
			this._pos.y -= this._velocity.y;
		if (keysPressed[this._keyDownPressed])
			this._pos.y += this._velocity.y;
	}

	draw = function()
	{
		ctx.fillStyle = "#33ff00";
		ctx.fillRect(this._pos.x, this._pos.y, this._width, this._height);
	}

	getHalfWidth = function () { return (this._width / 2); }
	getHalfHeight = function () { return (this._height / 2); }
	getCenter = function() {  return vec2(this._pos.x + this.getHalfWidth(), this._pos.y + this.getHalfHeight()); }
}

function	paddleCollision_Edges(paddle: paddleClass)
{
	if (paddle._pos.y <= 0)
		paddle._pos.y = 0;
	if (paddle._pos.y + paddle._height >= canvas.height)
		paddle._pos.y = canvas.height - paddle._height;
}

function ballCollisionEdges(ball: ballClass)
{
	if ((ball._pos.y + ball._radius >= canvas.height) || (ball._pos.y - ball._radius <= 0))
		ball._velocity.y *= -1;
};

function	respawnBall(ball: ballClass)
{
	if (ball._velocity.x > 0)
	{
		ball._pos.x = canvas.width - 150;
		ball._pos.y = (Math.random() * (canvas.height - 200)) + 100;
	}

	if (ball._velocity.x < 0)
	{
		ball._pos.x = 150;
		ball._pos.y = (Math.random() * (canvas.height - 200)) + 100;
	}
	ball._velocity.x *= -1;
}

function increaseScore(ball: ballClass, paddle1: paddleClass, paddle2: paddleClass)
{
	if (ball._pos.x <= -ball._radius)
	{
		paddle2._score++;
		document.getElementById("player2Score").innerHTML = paddle2._score.toString();
		respawnBall(ball);
	}

	if (ball._pos.x >= canvas.width + ball._radius)
	{
		paddle1._score++;
		document.getElementById("player1Score").innerHTML = paddle1._score.toString();
		respawnBall(ball);
	}
}

function	PlayerOne_PaddleCollision(paddle1 : paddleClass) : void
{
	if (ball._pos.x - (ball._radius / 2) < paddle1._pos.x
		&& ball._pos.y + ball._radius >= paddle1._pos.y
		&& ball._pos.y + ball._radius <= (paddle1._pos.y + (paddle1._height / 4)))
		{
			ball._velocity.x = -10;
			return ;
		}
	if (ball._pos.x - (ball._radius / 2) < paddle1._pos.x
		&& (ball._pos.y + ball._radius) >= (paddle1._pos.y + paddle1._height - (paddle1._height / 4))
		&& (ball._pos.y - ball._radius) <= (paddle1._pos.y + paddle1._height))
		{
			ball._velocity.x = -10;
			return ;
		}
	if (ball._pos.x - ball._radius >= paddle1._pos.x
		&& ball._pos.x - ball._radius <= paddle1._pos.x + paddle1._width
		&& ball._pos.y + ball._radius >= paddle1._pos.y
		&& ball._pos.y + ball._radius <= paddle1._pos.y + (paddle1._height / 4))
		{
			ball._velocity.y = -10
			ball._velocity.x = 10; 
		}
	if (ball._pos.x - ball._radius >= paddle1._pos.x
		&& ball._pos.x - ball._radius <= paddle1._pos.x + paddle1._width
		&& ball._pos.y - ball._radius <= paddle1._pos.y + paddle1._height
		&& ball._pos.y + ball._radius >= paddle1._pos.y + paddle1._height - (paddle1._height / 4))
		{
			ball._velocity.y = 10
			ball._velocity.x = 10; 
		}
}

function	PlayerTwo_PaddleCollision(paddle2 : paddleClass) : void
{
	if (ball._pos.x + (ball._radius / 2) > paddle2._pos.x
		&& ball._pos.y + ball._radius >= paddle2._pos.y
		&& ball._pos.y + ball._radius <= (paddle2._pos.y + (paddle2._height / 4)))
		{
			ball._velocity.x = 10;
			return ;
		}
	if (ball._pos.x + (ball._radius / 2) > paddle2._pos.x
		&& (ball._pos.y - ball._radius) <= (paddle2._pos.y + paddle2._height)
		&& (ball._pos.y - ball._radius) >= (paddle2._pos.y + paddle2._height - (paddle2._height / 4)))
		{
			ball._velocity.x = 10;
			return ;
		}
	if (ball._pos.x + ball._radius >= paddle2._pos.x
		&& ball._pos.x + ball._radius <= paddle2._pos.x + paddle2._width
		&& ball._pos.y + ball._radius >= paddle2._pos.y
		&& ball._pos.y + ball._radius <= paddle2._pos.y + (paddle2._height / 4))
		{
			ball._velocity.y = -10
			ball._velocity.x = -10; 
		}
	if (ball._pos.x + ball._radius >= paddle2._pos.x
		&& ball._pos.x + ball._radius <= paddle2._pos.x + paddle2._width
		&& ball._pos.y - ball._radius <= paddle2._pos.y + paddle2._height
		&& ball._pos.y - ball._radius >= paddle2._pos.y + paddle2._height - (paddle2._height / 4))
		{
			ball._velocity.y = 10
			ball._velocity.x = -10; 
		}
}

function	ballPaddleCollision(ball: ballClass, paddle: paddleClass)
{
	PlayerOne_PaddleCollision(paddle1)
	PlayerTwo_PaddleCollision(paddle2)
	if (
		ball._pos.x + ball._radius > paddle._pos.x &&
		ball._pos.x - ball._radius < paddle._pos.x + paddle._width &&
		ball._pos.y + ball._radius > paddle._pos.y &&
		ball._pos.y - ball._radius < paddle._pos.y + paddle._height
	)
		ball._velocity.x *= -1;
}

const ball = new ballClass(vec2(canvas.width / 2, canvas.height / 2), vec2(10, 10), 20);
const paddle1 = new paddleClass(vec2(20, canvas.height / 2), vec2(paddleSpeed, paddleSpeed), 20, 160, 87, 83);
const paddle2 = new paddleClass(vec2(canvas.width - 30, canvas.height / 2), vec2(paddleSpeed, paddleSpeed), 20, 160, 38, 40);

function	gameUpdate()
{
	// console.log(paddle1._pos.x + paddle1._width);
	ball.update();
	paddle1.update();
	paddle2.update();
	paddleCollision_Edges(paddle1);
	paddleCollision_Edges(paddle2);
	ballCollisionEdges(ball);
	ballPaddleCollision(ball,paddle1);
	ballPaddleCollision(ball,paddle2);
	increaseScore(ball, paddle1, paddle2);

}

function	gameDraw()
{
	ball.draw();
	paddle1.draw();
	paddle2.draw();
}

function	gameLoop()
{
	ctx.fillStyle = 'rgba(0, 0, 0, 0.3)';
	ctx.fillRect(
		0,
		0,
		canvas.width,
		canvas.height
	)
	ctx.fillStyle = '#999900'
	ctx.strokeStyle = '#999900'
	ctx.beginPath()
	ctx.arc(
		canvas.width / 2 - 5,
		canvas.height / 2,
		50,
		0,
		Math.PI * 2
	)
	ctx.fill()
	ctx.stroke()
	ctx.fillStyle = '#000000'
	ctx.beginPath()
	ctx.arc(
		canvas.width / 2 - 5,
		canvas.height / 2,
		40,
		0,
		Math.PI * 2
	)
	ctx.fill()
	ctx.fillStyle = '#999900'
	ctx.fillRect(
		canvas.width / 2 - 10,
		0,
		10,
		canvas.height
	)
	ctx.fillStyle = '#ff5c00'
	ctx.strokeStyle = '#ff5c00'

	window.requestAnimationFrame(gameLoop);

	gameUpdate();
	gameDraw();
}

gameLoop();