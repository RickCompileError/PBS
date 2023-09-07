function chunk(arr: any[], size: number): any[][] {
    let chunked: any[] = [];
    let ind = 0;
    while (ind < arr.length) {
        chunked.push(arr.slice(ind, ind + size));
        ind += size;
    }
    return chunked;
};