from flask import Flask, request, jsonify
from flask_cors import CORS
import subprocess

app = Flask(__name__)
CORS(app)   

@app.route("/analyze", methods=["POST"])
def analyze():
    text = request.json["text"]

    process = subprocess.Popen(
        ["fallacy.exe"],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )

    output, error = process.communicate(text)

    return jsonify({
        "raw_output": output
    })

if __name__ == "__main__":
    app.run(debug=True)
