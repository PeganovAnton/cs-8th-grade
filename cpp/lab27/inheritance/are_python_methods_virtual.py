class A:
    def foo(self):
        print("foo in A")
        self.spam()

    def spam(self):
        print("spam in A")


class B(A):
    def bar(self):
        print("bar in B")
        self.foo()

    def spam(self):
        print("spam in B")



if __name__ == '__main__':
    b = B()
    b.bar()


# Conclusion: Python methods are virtual

