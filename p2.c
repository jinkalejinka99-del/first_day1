import requests
import psutil
from datetime import datetime
from tabulate import tabulate

# ---------------- WEATHER FUNCTION ----------------
def get_weather(city, api_key):
    url = f"http://api.openweathermap.org/data/2.5/weather?q={city}&appid={api_key}&units=metric"
    
    try:
        response = requests.get(url)
        data = response.json()

        if data["cod"] != 200:
            return "City not found", "-", "-", "-"

        weather = data["weather"][0]["description"]
        temp = data["main"]["temp"]
        humidity = data["main"]["humidity"]
        return weather, temp, humidity, "OK"

    except Exception as e:
        return "Error", "-", "-", "-"


# ---------------- SYSTEM INFO FUNCTION ----------------
def get_system_info():
    cpu = psutil.cpu_percent(interval=1)
    ram = psutil.virtual_memory().percent
    return cpu, ram


# ---------------- MAIN PROGRAM ----------------
def main():
    api_key = "YOUR_API_KEY"  # Replace with your API key
    
    city = input("Enter city name: ")

    # Get weather
    weather, temp, humidity, status = get_weather(city, api_key)

    # Get system info
    cpu, ram = get_system_info()

    # Get date & time
    now = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

    # Table data
    table = [
        ["City", city],
        ["Weather", weather],
        ["Temperature (°C)", temp],
        ["Humidity (%)", humidity],
        ["CPU Usage (%)", cpu],
        ["RAM Usage (%)", ram],
        ["Date & Time", now]
    ]

    print("\n📊 System & Weather Info\n")
    print(tabulate(table, tablefmt="fancy_grid"))


# ---------------- RUN ----------------
if __name__ == "__main__":
    main()
