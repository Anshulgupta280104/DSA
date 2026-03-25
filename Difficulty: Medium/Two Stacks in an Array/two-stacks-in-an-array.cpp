class twoStacks {
  public:
    int *arr;
    int Top1, Top2;
    int size;

    twoStacks(int n = 100) {
        arr = new int[n];
        size = n;
        Top1 = -1;
        Top2 = n;
    }

    // Push into stack1
    void push1(int x) {
        if (Top1 + 1 == Top2)
            return;

        Top1++;
        arr[Top1] = x;
    }

    // Push into stack2
    void push2(int x) {
        if (Top2 - 1 == Top1)
            return;

        Top2--;
        arr[Top2] = x;
    }

    // Pop from stack1
    int pop1() {
        if (Top1 == -1)
            return -1;

        int element = arr[Top1];
        Top1--;
        return element;
    }

    // Pop from stack2
    int pop2() {
        if (Top2 == size)
            return -1;

        int element = arr[Top2];
        Top2++;
        return element;
    }
};