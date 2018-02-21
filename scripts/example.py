import native_code

def init():
    print("Hello from Python!")
    native_code.some_function()
    result = native_code.add(40, 2)
    return result
