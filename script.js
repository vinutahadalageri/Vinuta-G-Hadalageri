/* =====================================================
   IoTRONICS — WEBSITE INTERACTIONS
   ===================================================== */


/* MOBILE MENU */

const menuButton = document.getElementById("menuButton");
const navbar = document.querySelector(".navbar");

menuButton.addEventListener("click", () => {

    navbar.classList.toggle("menu-open");

});


/* CLOSE MOBILE MENU WHEN LINK IS CLICKED */

const navLinks = document.querySelectorAll(".nav-links a");

navLinks.forEach(link => {

    link.addEventListener("click", () => {

        navbar.classList.remove("menu-open");

    });

});


/* SCROLL REVEAL */

const revealElements = document.querySelectorAll(
    ".section, .service-card, .project-card, .process-item, .stat, .cta"
);

revealElements.forEach(element => {
    element.classList.add("reveal");
});


const revealObserver = new IntersectionObserver(
    (entries, observer) => {

        entries.forEach(entry => {

            if (entry.isIntersecting) {

                entry.target.classList.add("visible");

                observer.unobserve(entry.target);

            }

        });

    },
    {
        threshold: 0.12
    }
);


revealElements.forEach(element => {
    revealObserver.observe(element);
});


/* NUMBER COUNTER */

const counters = document.querySelectorAll(".counter");

const counterObserver = new IntersectionObserver(
    (entries, observer) => {

        entries.forEach(entry => {

            if (!entry.isIntersecting) return;

            const counter = entry.target;

            const target = Number(
                counter.getAttribute("data-target")
            );

            let current = 0;

            const duration = 1400;
            const increment = target / (duration / 16);

            const updateCounter = () => {

                current += increment;

                if (current < target) {

                    counter.textContent =
                        Math.floor(current);

                    requestAnimationFrame(updateCounter);

                } else {

                    counter.textContent = target;

                }

            };

            updateCounter();

            observer.unobserve(counter);

        });

    },
    {
        threshold: 0.8
    }
);


counters.forEach(counter => {
    counterObserver.observe(counter);
});


/* HERO MOUSE PARALLAX */

const heroVisual = document.querySelector(".hero-visual");

if (heroVisual) {

    heroVisual.addEventListener("mousemove", (event) => {

        const rect =
            heroVisual.getBoundingClientRect();

        const x =
            (event.clientX - rect.left) / rect.width - 0.5;

        const y =
            (event.clientY - rect.top) / rect.height - 0.5;

        const nodes =
            heroVisual.querySelectorAll(".node");

        nodes.forEach((node, index) => {

            const strength = (index + 1) * 5;

            node.style.transform =
                `translate(${x * strength}px, ${y * strength}px)`;

        });

    });


    heroVisual.addEventListener("mouseleave", () => {

        const nodes =
            heroVisual.querySelectorAll(".node");

        nodes.forEach(node => {

            node.style.transform = "";

        });

    });

}


/* CARD GLOW FOLLOWING MOUSE */

const cards = document.querySelectorAll(
    ".service-card, .project-card"
);

cards.forEach(card => {

    card.addEventListener("mousemove", (event) => {

        const rect = card.getBoundingClientRect();

        const x =
            event.clientX - rect.left;

        const y =
            event.clientY - rect.top;

        card.style.background = `
            radial-gradient(
                250px circle at ${x}px ${y}px,
                rgba(184,255,61,0.07),
                rgba(14,20,22,0.75) 45%
            )
        `;

    });


    card.addEventListener("mouseleave", () => {

        card.style.background = "";

    });

});


/* ACTIVE NAVIGATION */

const sections = document.querySelectorAll("section[id]");

const observerOptions = {
    rootMargin: "-40% 0px -50% 0px"
};

const sectionObserver =
    new IntersectionObserver(
        (entries) => {

            entries.forEach(entry => {

                if (entry.isIntersecting) {

                    navLinks.forEach(link => {

                        link.classList.remove("active");

                    });

                    const activeLink =
                        document.querySelector(
                            `.nav-links a[href="#${entry.target.id}"]`
                        );

                    if (activeLink) {

                        activeLink.classList.add("active");

                    }

                }

            });

        },
        observerOptions
    );


sections.forEach(section => {
    sectionObserver.observe(section);
});


/* SMOOTH BUTTON RIPPLE */

const buttons =
    document.querySelectorAll(".primary-button");

buttons.forEach(button => {

    button.addEventListener("click", function(event) {

        const ripple =
            document.createElement("span");

        ripple.style.position = "absolute";
        ripple.style.width = "10px";
        ripple.style.height = "10px";
        ripple.style.borderRadius = "50%";
        ripple.style.background = "rgba(255,255,255,.5)";
        ripple.style.transform = "scale(0)";
        ripple.style.pointerEvents = "none";

        const rect =
            button.getBoundingClientRect();

        ripple.style.left =
            `${event.clientX - rect.left}px`;

        ripple.style.top =
            `${event.clientY - rect.top}px`;

        button.style.position = "relative";
        button.style.overflow = "hidden";

        button.appendChild(ripple);

        ripple.animate(
            [
                {
                    transform: "scale(0)",
                    opacity: 0.8
                },
                {
                    transform: "scale(20)",
                    opacity: 0
                }
            ],
            {
                duration: 600,
                easing: "ease-out"
            }
        );

        setTimeout(() => {

            ripple.remove();

        }, 600);

    });

});


/* CONSOLE MESSAGE */

console.log(
    "%c IoTRONICS ",
    "background:#b8ff3d;color:#050708;font-size:20px;font-weight:bold;padding:5px;"
);

console.log(
    "%c Engineering the connected future.",
    "color:#b8ff3d;font-size:13px;"
);