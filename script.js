function analyze() {
    let text = document.getElementById("argument").value;

    if (text.trim() === "") {
        alert("Please enter an argument");
        return;
    }

    fetch("http://127.0.0.1:5000/analyze", {
        method: "POST",
        headers: {
            "Content-Type": "application/json"
        },
        body: JSON.stringify({ text: text })
    })
    .then(response => response.json())
    .then(data => {
        document.getElementById("fallacy").innerText = data.raw_output;
    })
    .catch(error => {
        console.error("Error:", error);
        alert("Backend not responding");
    });
}
