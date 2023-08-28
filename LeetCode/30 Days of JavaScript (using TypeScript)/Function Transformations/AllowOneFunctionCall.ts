type Fn = (...args: any[]) => any

function once(fn: Fn): Fn {
    let called: boolean = true;
    let result: any;

    return (...args) => {
        if (called) {
            result = fn(...args);
            called = false;
            return result;
        }
        return undefined;
    }
}

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */