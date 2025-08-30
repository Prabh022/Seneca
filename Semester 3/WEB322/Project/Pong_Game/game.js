const canvas = document.getElementById('pongCanvas');
const ctx = canvas.getContext('2d');

// Game settings
const paddleWidth = 16;
const paddleHeight = 90;
const ballRadius = 12;
const playerX = 20;
const aiX = canvas.width - playerX - paddleWidth;

let playerY = canvas.height / 2 - paddleHeight / 2;
let aiY = canvas.height / 2 - paddleHeight / 2;

let ballX = canvas.width / 2;
let ballY = canvas.height / 2;
let ballSpeedX = 6;
let ballSpeedY = 4;

let playerScore = 0;
let aiScore = 0;

// Mouse movement for player paddle
canvas.addEventListener('mousemove', function(event) {
    const rect = canvas.getBoundingClientRect();
    const mouseY = event.clientY - rect.top;
    playerY = mouseY - paddleHeight / 2;
    // Clamp within canvas
    if (playerY < 0) playerY = 0;
    if (playerY > canvas.height - paddleHeight) playerY = canvas.height - paddleHeight;
});

// Draw everything
function draw() {
    // Clear
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    // Middle line
    ctx.setLineDash([8, 18]);
    ctx.strokeStyle = '#fff4';
    ctx.beginPath();
    ctx.moveTo(canvas.width/2, 0);
    ctx.lineTo(canvas.width/2, canvas.height);
    ctx.stroke();
    ctx.setLineDash([]);

    // Player paddle
    ctx.fillStyle = "#fff";
    ctx.fillRect(playerX, playerY, paddleWidth, paddleHeight);

    // AI paddle
    ctx.fillStyle = "#fff";
    ctx.fillRect(aiX, aiY, paddleWidth, paddleHeight);

    // Ball
    ctx.beginPath();
    ctx.arc(ballX, ballY, ballRadius, 0, Math.PI * 2);
    ctx.fillStyle = "#0ff";
    ctx.fill();

    // Scores
    ctx.font = "40px Arial";
    ctx.textAlign = "center";
    ctx.fillStyle = "#fff";
    ctx.fillText(playerScore, canvas.width / 4, 50);
    ctx.fillText(aiScore, (canvas.width * 3) / 4, 50);
}

// Update game state
function update() {
    // Ball movement
    ballX += ballSpeedX;
    ballY += ballSpeedY;

    // Collision with top/bottom
    if (ballY - ballRadius < 0) {
        ballY = ballRadius;
        ballSpeedY *= -1;
    }
    if (ballY + ballRadius > canvas.height) {
        ballY = canvas.height - ballRadius;
        ballSpeedY *= -1;
    }

    // Player paddle collision
    if (
        ballX - ballRadius < playerX + paddleWidth &&
        ballY > playerY &&
        ballY < playerY + paddleHeight
    ) {
        ballX = playerX + paddleWidth + ballRadius; // Prevent sticking
        ballSpeedX *= -1.1; // Slightly increase speed
        // Add some spin based on where it hits the paddle
        let collidePoint = ballY - (playerY + paddleHeight / 2);
        ballSpeedY += collidePoint * 0.2;
    }

    // AI paddle collision
    if (
        ballX + ballRadius > aiX &&
        ballY > aiY &&
        ballY < aiY + paddleHeight
    ) {
        ballX = aiX - ballRadius; // Prevent sticking
        ballSpeedX *= -1.1;
        let collidePoint = ballY - (aiY + paddleHeight / 2);
        ballSpeedY += collidePoint * 0.2;
    }

    // Score (ball out of bounds)
    if (ballX < 0) {
        aiScore++;
        resetBall();
    }
    if (ballX > canvas.width) {
        playerScore++;
        resetBall();
    }

    // AI paddle movement (simple)
    let aiCenter = aiY + paddleHeight / 2;
    if (aiCenter < ballY - 25) {
        aiY += 6;
    } else if (aiCenter > ballY + 25) {
        aiY -= 6;
    }
    // Clamp AI paddle
    if (aiY < 0) aiY = 0;
    if (aiY > canvas.height - paddleHeight) aiY = canvas.height - paddleHeight;
}

// Reset ball to center
function resetBall() {
    ballX = canvas.width / 2;
    ballY = canvas.height / 2;
    // Randomize direction
    ballSpeedX = (Math.random() > 0.5 ? 6 : -6);
    ballSpeedY = (Math.random() > 0.5 ? 4 : -4);
}

// Main game loop
function gameLoop() {
    update();
    draw();
    requestAnimationFrame(gameLoop);
}

gameLoop();