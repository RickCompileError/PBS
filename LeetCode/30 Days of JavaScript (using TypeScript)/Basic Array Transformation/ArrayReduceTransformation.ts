type Fn = (accum: number, curr: number) => number

function reduce(nums: number[], fn: Fn, init: number): number {
    let val = init;
    for (let num of nums) {
        val = fn(val, num);
    }
    return val;
};

function reduce2(nums: number[], fn: Fn, init: number): number {
    let val = init;
    nums.forEach(num => val = fn(val, num));
    return val;
};