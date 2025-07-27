let problems = [];
let currentIdx = 0;
let wrongProblems = [];
let currentSet = [];
let isRetryMode = false;

const daySelector = document.getElementById("daySelector");
const quizArea = document.getElementById("quizArea");
const hanjaChar = document.getElementById("hanjaChar");
const userInput = document.getElementById("userInput");
const submitBtn = document.getElementById("submitBtn");
const progress = document.getElementById("progress");
const resultArea = document.getElementById("resultArea");
const resultSummary = document.getElementById("resultSummary");
const retryWrongBtn = document.getElementById("retryWrongBtn");

daySelector.addEventListener("change", async () => {
  if (!daySelector.value) return;
  const response = await fetch(`data/${daySelector.value}.json`);
  problems = await response.json();
  currentSet = shuffle([...problems]);
  currentIdx = 0;
  wrongProblems = [];
  isRetryMode = false;
  quizArea.classList.remove("hidden");
  resultArea.classList.add("hidden");
  retryWrongBtn.classList.add("hidden");
  showProblem();
});

submitBtn.addEventListener("click", handleSubmit);
userInput.addEventListener("keypress", e => {
  if (e.key === "Enter") handleSubmit();
});

retryWrongBtn.addEventListener("click", () => {
  currentSet = shuffle([...wrongProblems]);
  currentIdx = 0;
  wrongProblems = [];
  isRetryMode = true;
  quizArea.classList.remove("hidden");
  resultArea.classList.add("hidden");
  retryWrongBtn.classList.add("hidden");
  showProblem();
});

function showProblem() {
  const problem = currentSet[currentIdx];
  hanjaChar.textContent = problem.character; // ← 고침
  userInput.value = "";
  userInput.focus();
  progress.textContent = `${currentIdx + 1} / ${currentSet.length}`;
}

function handleSubmit() {
  const answer = userInput.value.trim();
  const current = currentSet[currentIdx];
  const correctAnswer = current.meaning; // ← 고침

  if (answer === correctAnswer) {
    // 정답 처리 (필요 시 시각 효과 추가 가능)
  } else {
    wrongProblems.push(current);
  }

  currentIdx++;

  if (currentIdx < currentSet.length) {
    showProblem();
  } else {
    showResult();
  }
}

function showResult() {
  quizArea.classList.add("hidden");
  resultArea.classList.remove("hidden");

  const correct = currentSet.length - wrongProblems.length;
  const total = currentSet.length;
  const rate = ((correct / total) * 100).toFixed(1);

  resultSummary.textContent = `정답: ${correct} / ${total} (정답률: ${rate}%)`;

  if (wrongProblems.length > 0) {
    retryWrongBtn.classList.remove("hidden");
  }
}

function shuffle(arr) {
  return arr.sort(() => Math.random() - 0.5);
}
