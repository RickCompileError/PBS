async function promiseAll<T>(functions: (() => Promise<T>)[]): Promise<T[]> {
    return new Promise((resolve, reject) => {
        const result = new Array(functions.length);
        let count = 0;
        for (let i = 0; i < functions.length; i++) {
            functions[i]()
            .then(val => {
                result[i] = val;
                count++;
                if (count == result.length) resolve(result);
            })
            .catch(reason => reject(reason));
        }
    })
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */