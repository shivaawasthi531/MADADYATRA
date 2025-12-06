from flask import Flask, render_template, request
import subprocess
import os

app = Flask(__name__)


BUS_EXE_PATH = os.path.join(os.getcwd(), "bus.exe")

@app.route("/", methods=["GET", "POST"])
def index():
    result_html = ""
    
    if request.method == "POST":
        start = request.form.get("start", "").strip()
        destination = request.form.get("destination", "").strip()

        if start and destination:
            try:
                
                process = subprocess.Popen(
                    [BUS_EXE_PATH, start, destination],
                    stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE,
                    text=True
                )

                output, error = process.communicate()

                if error:
                    result_html = f"<p style='color:red;'>Error: {error}</p>"
                else:
                    result_html = output

            except Exception as e:
                result_html = f"<p style='color:red;'>Exception: {str(e)}</p>"
        else:
            result_html = "<p style='color:red;'>Please enter both start and destination.</p>"

    return render_template("index.html", result_html=result_html)


if __name__ == "__main__":
    app.run(debug=True)
