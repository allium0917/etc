let quizData = [];
let current = 0;
let correct = 0;
let incorrectList = [];
let currentAnswers = [];

const quizContainer = document.getElementById("quiz-container");
const characterSpan = document.getElementById("character");
const answerInput = document.getElementById("answerInput");
const result = document.getElementById("result");
const progress = document.getElementById("progress");
const retryBtn = document.getElementById("retryBtn");
const resetBtn = document.getElementById("resetBtn");
const submitBtn = document.getElementById("submitBtn");
const daySelection = document.getElementById("daySelection");

const resultList = document.getElementById("resultList");
const detailView = document.getElementById("detailView");
const detailContent = document.getElementById("detailContent");

// ✅ 퀴즈 시작 버튼
document.getElementById("startBtn").addEventListener("click", async () => {
  const selectedDays = Array.from(
    document.querySelectorAll('#dayCheckboxes input[type="checkbox"]:checked')
  ).map(cb => cb.value);

  if (selectedDays.length === 0) {
    alert("Day를 하나 이상 선택해주세요.");
    return;
  }

  try {
    quizData = [];
    for (const day of selectedDays) {
      const res = await fetch(`data/${day}.json`);
      const data = await res.json();
      quizData.push(...data);
    }

    quizData = shuffle(quizData);
    startQuiz();
  } catch (e) {
    alert("문제 로딩 실패! data 폴더와 JSON 파일이 있는지 확인하세요.");
  }
});

function startQuiz() {
  daySelection.style.display = "none";
  quizContainer.style.display = "block";
  current = 0;
  correct = 0;
  incorrectList = [];
  currentAnswers = [];
  retryBtn.style.display = "none";
  resetBtn.style.display = "none";
  result.textContent = "";
  answerInput.value = "";
  answerInput.focus();
  showQuestion();
}

function showQuestion() {
  if (current >= quizData.length) {
    finishQuiz();
    return;
  }

  const q = quizData[current];
  characterSpan.textContent = q.character;
  progress.textContent = `문제 ${current + 1} / ${quizData.length}`;
  answerInput.value = "";
  answerInput.style.display = "inline-block";
  submitBtn.style.display = "inline-block";
  answerInput.focus();
  result.textContent = "";
}

function submitAnswer() {
  const userAnswer = answerInput.value.trim();
  const q = quizData[current];
  const correctAnswer = q.meaning.trim();

  if (userAnswer === "") {
    result.textContent = "뜻을 입력해주세요.";
    result.style.color = "orange";
    return;
  }

  const isCorrect = userAnswer === correctAnswer;

  if (isCorrect) {
    correct++;
    result.textContent = "정답입니다!";
    result.style.color = "green";
  } else {
    incorrectList.push(q);
    result.textContent = `오답입니다. 정답은 "${correctAnswer}" 입니다.`;
    result.style.color = "red";
  }

  // 상세 기록 저장
  currentAnswers.push({
    character: q.character,
    userAnswer,
    correctAnswer,
    isCorrect
  });

  submitBtn.disabled = true;
  answerInput.disabled = true;

  setTimeout(() => {
    current++;
    submitBtn.disabled = false;
    answerInput.disabled = false;
    showQuestion();
  }, 1000);
}

submitBtn.addEventListener("click", submitAnswer);
answerInput.addEventListener("keydown", e => {
  if (e.key === "Enter") submitAnswer();
});

retryBtn.addEventListener("click", () => {
  if (incorrectList.length === 0) return;
  quizData = shuffle([...incorrectList]);
  current = 0;
  correct = 0;
  incorrectList = [];
  currentAnswers = [];
  result.textContent = "";
  retryBtn.style.display = "none";
  resetBtn.style.display = "none";
  answerInput.style.display = "inline-block";
  submitBtn.style.display = "inline-block";
  showQuestion();
});

resetBtn.addEventListener("click", () => {
  quizContainer.style.display = "none";
  daySelection.style.display = "block";
  resetForm();
});

function resetForm() {
  quizData = [];
  current = 0;
  correct = 0;
  incorrectList = [];
  currentAnswers = [];
  document.querySelectorAll('#dayCheckboxes input[type="checkbox"]').forEach(cb => cb.checked = false);
  result.textContent = "";
}

function finishQuiz() {
  const total = quizData.length;
  const percent = ((correct / total) * 100).toFixed(1);
  result.innerHTML = `✅ 완료!<br/>정답: ${correct} / ${total} (${percent}%)`;

  if (incorrectList.length > 0) {
    retryBtn.style.display = "inline-block";
  }
  resetBtn.style.display = "inline-block";
  progress.textContent = "";
  characterSpan.textContent = "";
  answerInput.style.display = "none";
  submitBtn.style.display = "none";

  // ✅ localStorage에 저장
  saveResultToLocalStorage({
    timestamp: new Date().toLocaleString(),
    correct,
    total,
    percent,
    answers: currentAnswers
  });

  loadSavedResults();
}

function shuffle(array) {
  return array.sort(() => Math.random() - 0.5);
}

function saveResultToLocalStorage(resultObj) {
  const results = JSON.parse(localStorage.getItem("hanjaResults") || "[]");
  results.unshift(resultObj);
  localStorage.setItem("hanjaResults", JSON.stringify(results));
}

function loadSavedResults() {
  const results = JSON.parse(localStorage.getItem("hanjaResults") || "[]");
  resultList.innerHTML = "";

  results.forEach((res, index) => {
    const li = document.createElement("li");
    li.innerHTML = `<a href="#" data-index="${index}">${res.timestamp} - 정답 ${res.correct} / ${res.total} (${res.percent}%)</a>`;
    resultList.appendChild(li);
  });

  // 상세 보기 이벤트 연결
  document.querySelectorAll("#resultList a").forEach(a => {
    a.addEventListener("click", e => {
      e.preventDefault();
      const index = a.getAttribute("data-index");
      showDetail(index);
    });
  });
}

function showDetail(index) {
  const results = JSON.parse(localStorage.getItem("hanjaResults") || "[]");
  const result = results[index];

  if (!result) return;

  let html = `<p><strong>${result.timestamp}</strong><br/>정답: ${result.correct} / ${result.total} (${result.percent}%)</p>`;
  html += "<ul style='list-style:none; padding:0;'>";

  result.answers.forEach((a, i) => {
    html += `<li style="margin-bottom:10px;">
      <strong>${i + 1}. ${a.character}</strong><br/>
      당신의 답: <span style="color:${a.isCorrect ? 'green' : 'red'}">${a.userAnswer}</span><br/>
      정답: ${a.correctAnswer}
    </li>`;
  });

  html += "</ul>";

  detailContent.innerHTML = html;
  detailView.style.display = "block";
}

function closeDetail() {
  detailView.style.display = "none";
}

function clearResults() {
  if (confirm("정말로 모든 결과를 삭제하시겠습니까?")) {
    localStorage.removeItem("hanjaResults");
    loadSavedResults();
    closeDetail();
  }
}

// 초기 로딩 시 이전 결과 불러오기
loadSavedResults();
