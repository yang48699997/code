class Student:

    def get_name(self) -> str:
        return self.name

    def __init__(self, name, gender):
        self.name = name
        self.gender = gender

    def __str__(self):
        return f"{self.name},{self.gender}"
    # def get_name(self, msg) -> str:
    #     return msg

    def __lt__(self, other):
        return self.name<other.name

    def __le__(self, other):
        return self.name<=other.name

stu_1 = Student("a","a")
stu_1.name = "yu"
stu_1.gender = "male"
stu_2 = Student("yang","female")
print(stu_1.get_name())
print(stu_1)
print(stu_1>=stu_2)
