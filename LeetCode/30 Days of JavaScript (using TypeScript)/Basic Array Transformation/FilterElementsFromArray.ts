function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
    let newArr: number[] = [], sz: number = arr.length;
    for (let i: number = 0; i < sz; i++) {
        if (fn(arr[i], i)) newArr.push(arr[i]);
    }
    return newArr;
};