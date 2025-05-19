const projects = [
  {
    title: "Project One",
    description: "A cool project about something interesting.",
    image: "images/project1.jpg",
    link: "https://github.com/prabh/project-one"
  },
  {
    title: "Project Two",
    description: "Another amazing project showcasing skills.",
    image: "images/project2.jpg",
    link: "https://github.com/prabh/project-two"
  },
  {
    title: "Project Three",
    description: "Final project showing mastery in JS.",
    image: "images/project3.jpg",
    link: "https://github.com/prabh/project-three"
  }
];

const projectGallery = document.getElementById("projectGallery");

const createProjectCard = ({title, description, image, link}) => {
  return `
    <div class="project-card">
      <img src="${image}" alt="${title}" />
      <div class="project-content">
        <h3>${title}</h3>
        <p>${description}</p>
        <a href="${link}" target="_blank" rel="noopener">View Project</a>
      </div>
    </div>
  `;
};

const loadProjects = () => {
  projectGallery.innerHTML = projects.map(createProjectCard).join("");
};

loadProjects();

// Form validation

const form = document.getElementById("contactForm");

const showError = (input, message) => {
  const errorElem = input.nextElementSibling;
  errorElem.textContent = message;
  input.classList.add("error");
};

const clearError = (input) => {
  const errorElem = input.nextElementSibling;
  errorElem.textContent = "";
  input.classList.remove("error");
};

const validateEmail = (email) => {
  return /^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(email);
};

form.addEventListener("submit", (e) => {
  e.preventDefault();

  let isValid = true;

  const nameInput = form.name;
  const emailInput = form.email;
  const messageInput = form.message;

  // Name validation
  if (!nameInput.value.trim() || nameInput.value.trim().length < 3) {
    showError(nameInput, "Name must be at least 3 characters");
    isValid = false;
  } else {
    clearError(nameInput);
  }

  // Email validation
  if (!validateEmail(emailInput.value.trim())) {
    showError(emailInput, "Please enter a valid email");
    isValid = false;
  } else {
    clearError(emailInput);
  }

  // Message validation
  if (!messageInput.value.trim()) {
    showError(messageInput, "Message cannot be empty");
    isValid = false;
  } else {
    clearError(messageInput);
  }

  if (isValid) {
    alert("Thank you! Your message has been sent.");
    form.reset();
  }
});
