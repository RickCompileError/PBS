async function addTwoPromises(promise1: Promise<number>, promise2: Promise<number>): Promise<number> {
    return new Promise((resolve) => {
        let waitingPromise = 2, result = 0;
        const handler = (n: number) => {
            result += n;
            waitingPromise--;
            if (waitingPromise == 0) resolve(result);
        }
        promise1.then(handler);
        promise2.then(handler);
    })
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */