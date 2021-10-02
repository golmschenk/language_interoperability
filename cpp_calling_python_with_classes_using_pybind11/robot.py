class Robot:
    def __init__(self):
        self.position: float = 0

    def move_forward(self, distance: float):
        print('Message from Python.')
        self.position += distance
        print(f'Position in Python is {self.position}.')
