print("Welcome to the Project!")

def greet_user(name):
    return f"Hello, {name}! Welcome aboard."

def login(username, password):
    if username == "shashi" and password == "9999":
        return "Login successful "
    else:
        return "Login failed "


if __name__ == "__main__":
    name = input("Enter your name: ")
    print(greet_user(name))

    username = input("Enter username: ")
    password = input("Enter password: ")
    print(login(username, password))

   

